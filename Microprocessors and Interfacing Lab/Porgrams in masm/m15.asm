mov r3,#06h
mov r0,#10h
loop1 :mov r1,#10h
	   mov r2,#06h
loop2 :mov b,@r1
	   mov a,@r0
	   cjne a,b,next
next : jc next1
	   mov @r1,a
	   mov @r0,b
next1: inc r1
	   djnz r2,loop2
	   inc r0
	   djnz r3,loop1 ; sorting

