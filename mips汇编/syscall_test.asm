add $a0, $0, 0x1234
sll $a0, $a0, 16
add $t1, $0, 0x56
sll $t1, $t1, 8
add $t2, $0, 0x78
or $t1, $t1, $t2

or $a0, $a0, $t1
add $v0, $0, 34
syscall
sw $a0, 4($0)
lw $a1, 4($0)
 addi   $v0,$zero,50         # system call for exit
 syscall                  # we are out of here. 