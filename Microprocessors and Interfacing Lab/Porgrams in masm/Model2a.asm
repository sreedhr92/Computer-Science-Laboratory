mov r4,#00h ;for carry
mov a,r1
mov b,r3
add a,b
mov r6,a ;result lower byte in r6
mov a,r0
mov b,r2
addc a,b
mov r5,a ;result higher byte in r5
jnc here
inc r4
here: sjmp here