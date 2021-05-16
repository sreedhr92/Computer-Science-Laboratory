mov r1,#10h
mov b,@r1
mov r3,#06h
dec r3
l1: inc r1
    mov a,@r1
   cjne a,b,next
next : jc next1 ;jnc for min
	   mov b,a
next1 : dec r3
		cjne r3,#00,l1
mov r1,#00
mov r3,#00
mov r1,b
here: sjmp here

; finding the minimum/max of a list