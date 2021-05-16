assume cs:code,ds:data

data segment

source db 11h,12h,13h,14h

dest db ?

data ends

code segment
org 0100h

start : mov ax,data
		mov ds,ax

		mov si,offset source
		mov di,offset dest
		mov cx,0004h
		cld

here: 	mov bl,[si]
		mov [di],bl
		inc si
		inc di
		loop here

		mov ah,4ch
		int 21h

code ends
end start