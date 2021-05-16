assume cs:code,ds:data ; sum of elements in a list
data segment
	list db 00h,10h,20h,30h,40h,50h,60h,70h,80h,90h
	org 0010h
	sum dw ?
data ends
code segment
start : mov ax,data
		mov ds,ax

		mov si,offset list
		mov bx,00h
		mov cx,0ah
		clc


loop1 : mov al,[si]
		mov ah,00h
		adc bx,ax
		inc si
		loop loop1
		mov sum,bx
		mov ah,4ch
		int 21h
code ends 
end start
