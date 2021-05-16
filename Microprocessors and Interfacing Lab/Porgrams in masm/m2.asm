assume cs:code,ds:data ; no od 0's and 1's in 16bit data
data segment
	num dw 5556h
	org 0010h
	one db 00h
	zero db 00h
data ends
code segment 
	   org 0100h
start: mov ax,data
	   mov ds,ax

	   mov dl,00h
	   mov cx,10h
	   mov ax,num

loop1 : rol ax,01h
		jc here
		jmp here1
here  : inc dl
here1 : loop loop1
		mov one,dl
		mov bl,10h
		sub bl,dl
		mov zero,bl

		mov ah,4ch
		int 21h
code ends
end start
