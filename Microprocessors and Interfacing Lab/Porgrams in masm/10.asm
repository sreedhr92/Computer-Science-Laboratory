assume cs:code,ds:data 
data segment 
    message db "sample string$"
data ends
code segment
start : mov ax,data 
        mov ds,ax

        mov ah,9h
        mov dx,offset message
        int 21h

        mov ah,4ch
        int 21h
code ends
end start                  