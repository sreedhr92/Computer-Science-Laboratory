assume cs:code,ds:data 
data segment 
    opr1 db 33h
    opr2 db 35h
    result db 00h
    carry db 00h
data ends
code segment
    org 0100h

start:  mov ax,data 
        mov ds,ax

        mov al , opr1
        mov bl , opr2
        mov ch , 00h
        sub al , bl 
        das
        jnc here
        inc ch
        mov cl, 99h
        sub cl,al 
        add cl ,ch 
        mov al,cl
        das

here:   mov result,al
        mov carry ,ch
        mov ah,4ch
        int 21h

code ends
end start