assume cs:code,ds:data 
data segment 
count equ 10h 
data ends
code segment
start : mov ax,data 
        mov ds,ax 

        mov cx,count
l1    : mov ah,1
        int 21h
        cmp al,60h
        jnc upper
        add al,20h
        jmp skip

upper : sub al,20h
skip  : mov ah,2h 

        mov dl,al 
        int 21h
        loop l1

        mov ah,4ch
        int 21h
code ends
end start
