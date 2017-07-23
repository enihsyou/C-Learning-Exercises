data segment
    cipher db -6, 3, -6, 0, -1, 5, 5, -5, 6, 3, -2, -1, -4, -1, 5, -4, -2, 3
    string db '黄春翔1517440121', 13, 10, '$'
    encode db 'xxxxxxxxxxxxxxxx', 13, 10, '$'
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
    test [bx + si], 80h ; negetive
    jnz left
right:
    push cx
    mov cl, [bx + si]
    a1:
        ror al, 1
    loop a1
    pop cx
    jmp then1
left:
    push cx
    mov cl, [bx + si]
    not cl
    inc cl ; 2's complementary
    a2:
        rol al, 1
    loop a2
    pop cx
then1:
    mov bx, offset encode
    mov [bx + si], al ; write back to result array

    inc cx
    cmp cx, 15
    jg print
    jmp s
;print ciphered text
print:
    mov dx, offset encode
    mov ah, 09h
    int 21h
;decipher
    mov cx, 0h
r:
    mov si, cx ; use offset
    mov bx, offset encode
    mov al, [bx + si] ; text
    mov bx, offset cipher
    test [bx + si], 80h
    jnz left2
right2:
    push cx
    mov cl, [bx + si]
    a3:
        rol al, 1
    loop a3
    pop cx
    jmp then2
left2:
    push cx
    mov cl, [bx + si]
    not cl
    inc cl ; 2's complementary
    a4:
        ror al, 1
    loop a4
    pop cx
then2:
    mov bx, offset encode
    mov [bx + si], al ; write back to result array

    inc cx
    cmp cx, 15
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
