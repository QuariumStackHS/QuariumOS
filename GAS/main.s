.intel_syntax noprefix

go_to_protected:
    mov ah,89
    int 15
    ret