assume cs:code,ds:data 
data segment 
    opr1 db 99h
    opr2 db 99h
    carry db 00h
    result db 00h
    
data ends
code segment
    org 0100h

start:  mov ax,data 
        mov ds,ax

        mov al , opr1
        mov bl , opr2
        mov ch , 00h
        add al , bl 
        daa
        jnc here 
        inc ch

here:   mov result,al
        mov carry ,ch
        mov ah,4ch
        int 21h

code ends
end start

        
