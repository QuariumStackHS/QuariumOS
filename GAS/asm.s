     .globl   goprotectedmod
     .type    goprotectedmod,%function

goprotectedmod:
     mov $00,%ah
     mov $105,%bx
     #int $10
     nop
     ret

