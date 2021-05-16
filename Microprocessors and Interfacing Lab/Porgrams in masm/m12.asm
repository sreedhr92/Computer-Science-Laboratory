assume ds:data,cs:code
data segment
	opr db 05h
	org 0010h
	cube dw ?
data ends
code segment
org 0100h
start:	mov ax,data
	mov ds,ax
	mov al,opr
	mov bl,opr
	mul bl
	mov bh,00h
	mul bx
	mov cube,ax
	mov ah,4ch
	int 21h
code ends
end start ;cube of a number
