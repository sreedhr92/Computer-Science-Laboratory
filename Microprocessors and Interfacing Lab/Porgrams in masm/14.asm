mov a, r1
anl a, #0f0h
swap a
add a ,#30h
mov r3, a
mov a , r1
anl a, #00fh
add a ,#30h
mov r4 ,a
here : sjmp here