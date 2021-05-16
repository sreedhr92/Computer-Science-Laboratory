assume cs:code,ds:data ;fibo
data segment
	series db ?
data ends
code segment
start :
       mov ax,data
       mov ds,ax

       mov al,00h
       mov bl,01h
       mov cx,10h

       mov si,offset series
here : mov [si],al
	   mov dl,bl
	   add bl,al
	   mov al,dl
	   inc si
	   loop here
	   mov ah,4ch
	   int 21h

code ends
end start


