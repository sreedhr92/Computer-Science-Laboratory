assume cs:code,ds:data,es:extra

data segment

source db 10h,20h,30h,40h
status dw 0000h

data ends

extra segment

dest db 10h,22h,30h,40h

extra ends

code segment
org 0100h

start : mov ax,data
		mov ds,ax

		mov ax,extra
		mov es,ax

		mov si,offset source
		mov di,offset dest
		mov cx,0004h
		inc cx
		cld

repe	cmpsb

		mov status,cx

		mov ah,4ch
		int 21h

code ends
end start
