     .globl   goprotectedmod
     .type    goprotectedmod,%function

goprotectedmod:
    mov $0x00,%AH
    int $0x1A
    ret

