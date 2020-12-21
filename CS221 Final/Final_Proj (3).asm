.data
	mol: .asciiz "There is no meaning to life LOL! You're existance is meaningles. Have a nice day"

.text
.globl m_o_life

#Function to print the final message to the display console
m_o_life:
	la $a0, mol #Loads addres of the string into $a0
	la $a2, 0xFFFF0008 #Loads address MMIO console
char_loop:
	lb $t0, ($a0) #Loads 1st character of string into $t0
	beqz $t0, finished #Exits loop once end of string is reached
	not_ready:
		lw $t1, ($a2) #Reads control console bits
		andi $t1, $t1, 1 #Isolates the ready bit
		beqz $t1, not_ready #If it's not ready, loops back
	sw $t0, 4($a2) #Writes character to console
	addi $a0, $a0, 1 #Moves to next character in string
	b char_loop #Loops back to beginning of loop
	
finished:
	jr $ra #Return