data segment
    AS dw 65,66,67,68,69,70,71,72,73
    num db 9
    ;AS dw 10h, 20h, 30h
    ;num db 3
    tmp dw ?
    max dw ?
    min dw ?
    source db 'source$'
    target db 'target$'
    titles db 'No.2',13,10,'$'
    max_str db 13,10,'Max: $'
    min_str db 13,10,'Min: $'
data ends

stack segment
    dw 10h dup(0)
stack ends

code segment
    assume cs:code,ds:data,ss:stack
start:
    mov ax, data
    mov ds, ax
    lea dx, titles
    mov ah, 09h
    int 21h

;save last element to temp variable
    mov bx, offset AS
    mov al, num
    dec ax
    add ax, ax
    xor ah, ah
    xlat ; last element
    mov tmp, ax
;save last item to 'max' 'min'
    mov max, ax
    mov min, ax
;right rotate
    mov ch, 0h
    mov cl, num
    r:
    mov di, cx
    dec di
    mov si, di
    dec si ;source on lower index
    add si, si ;double the size
    add di, di ;double the size
    push [di] ; stack processed item
    mov ax, [si]
    mov [di], ax ;move one position right

    pop ax
    cmp ax, max
    jle j1 ;if now > max overwrite max
    mov max, ax
    j1:
    cmp ax, min
    jge j2 ;if now < min overwrite min
    mov min, ax
    j2:
    loop r
    mov si, offset AS
    mov ax, tmp
    mov [si], ax

;print
    ;mov bx, offset table
    ;xor ah, ah
    mov cx, 0h
    s:
    mov si, cx
    add si, si; double size
    mov ax, [si]
    mov dl, al
    mov ah, 02h
    int 21h
    inc cx
    cmp cl, num
    jnz s

;print max
    lea dx, max_str
    mov ah, 09h
    int 21h
    mov dx, max
    mov ah, 02h
    int 21h
;print min
    lea dx, min_str
    mov ah, 09h
    int 21h
    mov dx, min
    mov ah, 02h
    int 21h

;copy string
    lea si, source
    lea di, target

    mov cx, 6
cpy:
    mov bl, [si]
    mov [di], bl
    inc si
    inc di
    dec cx
    jnz cpy
;print target result
    lea dl, 0h
    mov ah, 02h
    int 21h
    lea dx, target
    mov ah, 09h
    int 21h

quit:
    mov ah,4ch
    int 21h
code ends
end start

