assume cs:code, ds:data ;32-bit sub 
data segment
abc dd 9ABCDEF0h
org 0010h
def dd 12345678h
org 0020h
result dw ?
data ends
 
code segment
org 0100h
start:
mov ax,data
mov ds,ax
mov dl,00h
mov ax, word ptr abc
mov bx, word ptr def
sub ax,bx
mov word ptr result,ax
mov ax, word ptr abc+2
mov bx, word ptr def+2
sbb ax,bx
mov word ptr result+2,ax
jnc move
inc dl
move: mov byte ptr result+4,dl
mov ah,4ch
int 21h
code ends
end start