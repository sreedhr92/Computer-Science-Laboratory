assume cs:code,ds:data,es:extra ; transfering data in reverse order
data segment
	org 0000h
	source db 00h,10h,20h,30h,40h,50h,60h,70h,80h,90h
data ends
extra segment 
	org 0010h
	desti db ?
extra ends
code segment
start : mov ax,data
		mov ds,ax

		mov ax,extra
		mov es,ax

		mov si,offset source
		mov di,offset desti
		add si,09h

		mov cx,0ah
loop1 : mov al,[si]
		mov [di],al
		dec si
		inc di
		loop loop1
		mov ah,4ch
		int 21h
code ends
end start