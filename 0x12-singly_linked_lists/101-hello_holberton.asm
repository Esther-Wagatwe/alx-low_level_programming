global   main
extern   printf

section .data
msg: db "Hello, Holberton",0 ;string to be printed
fmt: db "%s",10,0 ;how to print string 10\n

section .text
main:push rbp;setting up the start frame
    mov   rdi, fmt
    mov   rsi, msg
    mov   rax, 0
    call  printf
    pop   rbp ;resore start
    mov   rax, 0
    ret

