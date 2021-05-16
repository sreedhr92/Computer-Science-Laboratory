assume ds:data,cs:code ; 32-bit add
data segment
	opr1 dd 9ABCDEF0h
	org 0010h
	opr2 dd 12345678h
	org 0020h
	carry db ?
	res dd ?
data ends
code segment
org 0100h
start:
	mov ax,data
	mov ds,ax
	
	mov ax,word ptr opr1
	mov bx,word ptr opr2
	sub ax,bx
	mov word ptr res,ax
	mov ax,word ptr opr1 + 2
	mov bx,word ptr opr2 + 2
	sbb ax,bx
	mov word ptr res + 2,ax
	jnc here
	mov bh,01h
	mov carry,bh
here : 	mov ah,4ch
	int 21h
code ends
end start