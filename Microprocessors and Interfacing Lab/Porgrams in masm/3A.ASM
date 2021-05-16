assume cs:code,ds:data,es:extra
data segment
	source db 11h,12h,13h,14h
data ends
extra segment
	dest db ?
extra ends
code segment
start : mov ax,data
		mov ds,ax

		mov ax,extra
		mov es,ax

		mov si,offset source
		mov di,offset dest
		mov cx,0004h
		cld

rep 	movsb

		mov ah,4ch
		int 21h
code ends
end start