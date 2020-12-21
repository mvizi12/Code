#Program to ask user 3 riddles and reward them with treasure should they answer correctly
.data
	prompt1: .asciiz "Welcome to your treasure game. In order to attain what you seek, you must first answer 3 riddles\n"
	prompt2: .asciiz "Let's get started shall we\n"
	congrats: .asciiz "Congratulations you've attained all 3 treasure, you are truly a great treasure hunter\n"
	f_message: .asciiz "Now that you've achieved all 3 divine treasure, you are now worthy of being told the meaning of life. The message will appear in MMIO format"

.text
	main:   #Prints out prompt1 and 2
		li $v0, 4
		la $a0, prompt1
		syscall
		li $v0, 4
		la $a0, prompt2
		syscall
	
		#Sets up a call to spiritual riddle function
		addiu $sp, $sp, -4
		sw $ra, 0($sp)
		jal spiritual
		lw $ra, 0($sp)
		addiu $sp, $sp, 4
		
		#Sets up a call to physical riddle function
		addiu $sp, $sp, -4
		sw $ra, 0($sp)
		jal physical
		lw $ra, 0($sp)
		addiu $sp, $sp, 4
		
		#Sets up a call to cosmic riddle function
		addiu $sp, $sp, -4
		sw $ra, 0($sp)
		jal cosmic
		lw $ra, 0($sp)
		addiu $sp, $sp, 4
			
		#Congratulatory message
		li $v0, 4
		la $a0, congrats
		syscall
		
		#Prints the final message
		li $v0, 4
		la $a0, f_message
		syscall
		 
		#Sets up a call to meaning of life function
		addiu $sp, $sp, -4
		sw $ra 0($sp)
		jal m_o_life
		lw $ra 0($sp)
		addiu $sp, $sp, 4
	
		#Terminates program
		li $v0, 10
		syscall
