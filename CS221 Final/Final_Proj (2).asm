.data
	#Challenge prompts
	sp1: .asciiz "I am you, yet I'm just a tiny piece of you. I can be as large as a mountain, yet as fragile as glass. What am I?\n"
	ph1: .asciiz "I am edible, yet consuming me will turn the very sea itself against you. All who eat me bear the mark of the devil. What am I?\n"
	co1: .asciiz "At the birth of the universe, there were 6 items that came into existance that each commanded great power. What were they?\n"
	
	#Answer locations
	asp1: .space 30
	aph1: .space 30
	aco1: .space 30
	
	#Answers
	ego: .asciiz "Ego"
	dev: .asciiz "Devil Fruit"
	inf: .asciiz "Infinity Stones"
	
	#Result prompts
	incorrect: .asciiz "Incorrect! Try again!\n"
	go: .asciiz "Game over! You will now suffer for all eternity"
	
	#Tresure prompts
	enl: .asciiz "Congratulations, you've reached enlightenment\n"
	dfruit: .asciiz "Congratulations, the most powerful Devil Fruit is yours\n"
	st: .asciiz "Congratulations, you've attained all 6 infinity stones\n"
	
.text
.globl spiritual, physical, cosmic
spiritual:
	#Ask 1st riddle
	li $v0, 4
	la $a0, sp1
	syscall
	
	li $t0, 0 #Loop counter	
	sp_ans_loop:
		#Recieve answer to spiritual challenge
		li $v0, 8
		la $a0, asp1
		li $a1, 30
		syscall
		
		la $s0, ego #Loads answer to riddle into $s0
		sp_char_loop:
			lb $t1, ($s0) #Loads 1st character of answer into $t1
			lb $t2, ($a0) #Loads 1st character of user input into $t2
			addi $s0, $s0, 1 #Move to next character in answer
			addi $a0, $a0, 1 #Move to next character in user input
			beq $t2, 10, sp_done #Branches once newline character is reached
			beq $t1, $t2, sp_char_loop #Restarts loop if the user's input and correct answer match
			
		sp_wrong:
			#If asnwer isn't correct tell them and give 2 more chance
			li $v0, 4
			la $a0, incorrect
			syscall
			
			addi $t0, $t0, 1 #Increments loop counter a maximum of 2 times so the user gets 2 extra chances
			blt $t0, 3, sp_ans_loop #Loops back to let user answer 2 more times if they were wrong at first
			
			#You lose
			li $v0, 4
			la $a0, go
			syscall
			
			#Terminate
			li $v0, 10
			syscall
			
	sp_done:
		li $v0, 4 #Prints out the correct prompt
		la $a0, enl
		syscall
		jr $ra #Return

physical:
	#Ask 2nd riddle
	li $v0, 4
	la $a0, ph1
	syscall
	
	li $t0, 0 #Loop counter	
	ph_ans_loop:
		#Recieve answer to physical challenge
		li $v0, 8
		la $a0, aph1
		li $a1, 30
		syscall
			
		la $s0, dev #Loads answer to riddle into $t1
		ph_char_loop:
			lb $t1, ($s0) #Loads 1st character of answer into $t1
			lb $t2, ($a0) #Loads 1st character of user input into $t2
			addi $s0, $s0, 1 #Move to next character in answer
			addi $a0, $a0, 1 #Move to next character in user input
			beq $t2, 10, ph_done  #Branches once newline character is reached
			beq $t1, $t2, ph_char_loop #Restarts loop if the user's input and correct answer match
			
		ph_wrong:
			#If asnwer isn't correct tell them and give 2 more chance
			li $v0, 4
			la $a0, incorrect
			syscall
			
			addi $t0, $t0, 1 #Increments loop counter a maximum of 2 times so the user gets 2 extra chances
			blt $t0, 3, ph_ans_loop #Loops back to let user answer 2 more times if they were wrong at first
			
			#You lose
			li $v0, 4
			la $a0, go
			syscall
			
			#Terminate
			li $v0, 10
			syscall
		
	ph_done:
		li $v0, 4 #Prints out the correct prompt
		la $a0, dfruit
		syscall
		jr $ra #Return

cosmic:
	#Ask 3rd riddle
	li $v0, 4
	la $a0, co1
	syscall
	
	li $t0, 0 #Loop counter		
	co_ans_loop:
		#Recieve answer to cosmic challenge
		li $v0, 8
		la $a0, aco1
		li $a1, 30
		syscall
			
		la $s0, inf #Loads answer to riddle into $t1
		co_char_loop:
			lb $t1, ($s0) #Loads 1st character of answer into $t1
			lb $t2, ($a0) #Loads 1st character of user input into $t2
			addi $s0, $s0, 1 #Move to next character in answer
			addi $a0, $a0, 1 #Move to next character in user input
			beq $t2, 10, co_done #Branches once newline character is reached
			beq $t1, $t2, co_char_loop #Restarts loop if the user's input and correct answer match
			
		co_wrong:
			#If asnwer isn't correct tell them and give 2 more chance
			li $v0, 4
			la $a0, incorrect
			syscall
			
			addi $t0, $t0, 1 #Increments loop counter a maximum of 2 times so the user gets 2 extra chances
			blt $t0, 3, co_ans_loop #Loops back to let user answer 2 more times if they were wrong at first
			
			#You lose
			li $v0, 4
			la $a0, go
			syscall
			
			#Terminate
			li $v0, 10
			syscall
		
	co_done:
		li $v0, 4 #Prints out the correct prompt
		la $a0, st
		syscall
		jr $ra #Return
