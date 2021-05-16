assume cs:code,ds:data 
data segment
    hexa db 0ffh
    decimal dw ?
data ends
code segment
start : mov ax,data 
        mov ds,ax

        mov ah,00h
        mov al,hexa
        mov bl,64h

        div bl

        mov dl,al
        mov al,ah
        mov ah,00h
        mov bl,0ah

        div bl

        mov cl,004h
        rol al,cl
        mov dh,ah

        add dh,al

        mov decimal,dx
		mov ah,4ch
		int 21h

code ends
end start   
