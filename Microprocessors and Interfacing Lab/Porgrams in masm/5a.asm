assume cs:code,ds:data
data segment
	row1 db 03h
	row2 db 03h
	col1 db 02h
	col2 db 02h
	org 0010h
	mat1 db 03h,01h,01h,01h,03h,04h
	org 0020h
	mat2 db 07h,04h,03h,01h,08h,06h
	org 0030h
	result db ?
data ends
code segment
	org 0100h
start:  mov ax,data
	mov ds,ax
	mov cl,row1
	mov dl,row2
	cmp cl,dl
	jne over
	mov cl,col1
	mov dl,col2
	cmp cl,dl
	jne over
	mov al,row2
	mul cl	
	mov cx,ax
	mov si, offset mat1
	mov di, offset mat2
	mov bx, offset result
here:	mov ah,00h
	mov al, [si]
	add al, [di]
        jnc here1
	inc ah
here1:	mov [bx], al
	inc si
	inc di
	inc bx
        loop here
over:	mov ah,4ch
	int 21h
code ends
end start