assume cs:code,ds:data

data segment 
    ; assuming N to be 10
    array db 05h,03h,02h,07h,06h,01h,00h,09h,08h,04h
data ends
code segment
    org 0100h 

start : mov ax,data 
        mov ds,ax 

        mov ch , 09h

loop1 : mov si ,offset array 
        mov cl , 09h

loop2 : mov al , [si]
        mov ah , [si+1] ; simplified mov ax ,[si]
        cmp ah , al
        jnc skip
        xchg al,ah 
        mov [si] ,al
        mov [si+1],ah ; simplified mov [si],ax

skip:   inc si 
        dec cl 
        jnz loop2
        dec ch 
        jnz loop1 

        mov ah,4ch 
        int 21h 
code ends
end start

