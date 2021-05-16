assume cs:code,ds:data 
data segment
    hour db ?
    minute db ?
    second db ?
data ends
code segment 
    org 0100h
start:  mov ax,data 
        mov ds,ax

        mov ah,2ch
        int 21h

        mov si,offset hour
        mov [si],ch

        mov si,offset minute 
        mov [si],cl

        mov si,offset second
        mov [si],dh

        mov ah,4ch
        int 21h
code ends
end start