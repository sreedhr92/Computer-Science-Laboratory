assume cs:code,ds:data
data segment
    decimal db 12h
    hexa dw 0000h
	r db 00h
data ends
code segment 
start : mov ax,data
		mov ds,ax

		mov al,decimal
		mov ah,00h
		mov bl,10h

		div bl

		mov r,ah
		mov bl,0ah

		mul bl

		mov bl,r 
		mov bh,00h

		add ax,bx

		mov hexa,ax
		mov ah,4ch
		int 21h

code ends
end start





