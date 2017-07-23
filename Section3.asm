data segment
    cipher db 70, 80, 43, 230, 181, 174, 27, 52, 96, 137, 9
    string db 'Hello world', 13, 10, '$'
    encode db 'xxxxxxxxxxx', 13, 10, '$'
data ends

stack segment
        ;input stack segment code here
stack ends

code segment
    assume cs:code,ds:data,ss:stack
start:
    mov ax,data
    mov ds,ax

;print plain text
    mov dx, offset string
    mov ah, 09h
    int 21h
;ciphering
    mov cx, 0h
s:
    mov si, cx ; use offset
    mov bx, offset string
    mov al, [bx + si] ; text
    mov bx, offset cipher
    xor al, [si] ; text xor key
    mov bx, offset encode
    mov [bx + si], al ; write back to result array

    inc cx
    cmp cx, 10 ;11x
    jg print
    jmp s
;print cipher text
print:
    mov dx, offset encode
    mov ah, 09h
    int 21h
;decipher
    mov cx, 0h
r:
    mov si, cx ; use offset
    mov bx, offset encode ; encryped text
    mov al, [bx + si] ; text
    mov bx, offset cipher
    xor al, [si] ; text xor key
    mov bx, offset encode
    mov [bx + si], al ; write back to result array

    inc cx
    cmp cx, 10;11x
    jg print2
    jmp r

;print deciphered text
print2:
    mov dx, offset encode
    mov ah, 09h
    int 21h
quit:
    mov ah,4ch
    int 21h
code ends
end start
