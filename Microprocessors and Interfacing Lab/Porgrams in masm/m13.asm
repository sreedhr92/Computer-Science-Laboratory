mov a,r1
mov b, #10h
div ab
mov r3,b
mov b,#0ah
mul ab
add a,r3
mov r2,a
mov r3,#00
here:sjmp here ; bcd to hex

a A block of 10 data is stored in the memory from XX00 to XX09 . Write an ALP using 8086 to transfer the data to the memory location YY00 to YY09 in the reverse order.

1.b Write ALPs using 8086 to perform 32 bit addition and subtraction.