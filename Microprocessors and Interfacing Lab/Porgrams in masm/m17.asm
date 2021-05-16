mov r1,#10h
mov b,#00h
mov r2,#06
loop1 : mov a, @r1
		rrc a
		jnc here
		mov a,b
		addc a,@r1
		mov b,a
here :  inc r1
		djnz r2,loop1
		mov r1,b
		mov r2,#00h
here1 : sjmp here1