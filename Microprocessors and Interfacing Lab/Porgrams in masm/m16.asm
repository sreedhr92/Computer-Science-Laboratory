mov a,r1
mov b,#64h
div ab
mov r1,a
mov a,b
mov b,#0ah
div ab
swap a
add a,b
mov r2,a 
here:sjmp here;hex to bcd