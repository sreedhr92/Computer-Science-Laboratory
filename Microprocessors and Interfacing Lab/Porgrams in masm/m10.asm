assume ds:data,cs:code ; adding odd numbers in a list
data segment
	list db 01h,02h,03h,04h,05h,06h,07h,08h,09h,0Ah
	sum dw ?
	count dw 000Ah
data ends
code segment
org 0100h
start:
	mov ax,data
	mov ds,ax
	clc
	mov cx,count
	mov bx,0000h
	mov ah,00h
	mov si,offset list
loop1:	
	mov al,[si]
	mov dl,al
	ror dl,01h
	jnc here ; jc for even.
	clc
	adc bx,ax
here:	inc si
	loop loop1
	mov sum,bx
	mov ah,4ch
	int 21h
code ends
end start
	