assume ds:data,cs:code,es:extra
data segment
	source db 01h,10h,20h,30h,40h,50h,60h,70h,80h,90h
	count dw 000Ah
data ends 
extra segment
	dest db ?
extra ends
code segment 
org 0100h
start : mov ax,data
		mov ds,ax
		mov ax,extra
		mov es,ax
		mov cx,count 
		mov si,offset source
		mov di,offset dest
		add si,09h  ;increment source offset by 9 to point at end
loop1:
		std ; set the direction flag
		lodsb ; load a byte from si into al
		cld ; clear the direction flag
		stosb ; Store byte into di from al
		loop loop1

		mov ah,4ch
		int 21h
code ends
end start
