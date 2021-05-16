assume cs:code,ds:data 
data segment
    org 00h
    x dd 20.4375
    org 10h
    y dd 0.125
    org 20h
    diff dd ?
data ends

code segment
start : mov ax,data 
        mov ds,ax

        finit
        fld x
        fld y

        fsub st(0),st(1)

        fst diff

        mov ah,4ch
        int 21h
code ends
end start