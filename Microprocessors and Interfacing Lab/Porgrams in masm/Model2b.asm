mov r4,#00h ; for carry
mov a,r1
mov b,r3
subb a,b ; subtracting the lower nibble
mov r6,a
mov a,r0
mov b,r2
subb a,b ; subtracting the higher nibble
mov r5,a
jnc here ; if there is no carry exit
inc r4
mov a,r6 ; 2's complementing the result 
cpl a
mov r6,a
mov a,r5
cpl a   ; complement works on only accumulator.
mov r5,a
mov a,r6
add a,#01h
mov r6,a ; if there is no carry exit,else add 01h to get 2's comp
jnc here
mov a,r5
add a,#01h
mov r5,a
here: sjmp here