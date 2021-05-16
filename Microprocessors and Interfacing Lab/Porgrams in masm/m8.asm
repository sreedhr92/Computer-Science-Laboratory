assume cs:code,ds:data ; min of a list
data segment
	list db 23h,56h,11h,88h,23h
	element db ?
data ends
code segment
org 0100h
start: mov ax,data
	   mov ds,ax

	   mov cx, 05h
	   mov si,offset list
	   mov bl ,[si]
	   inc si
	   dec cx

loop1: mov al,[si]
	   cmp bl,al
	   jc here ;jnc for max in a list
	   mov bl,al

here : inc si
	   loop loop1
	   mov element,bl
	   mov ah ,4ch
	   int 21h
code ends
end start