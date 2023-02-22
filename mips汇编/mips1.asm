syscall
sll $0, $0, 0
add $s0, $s1, $s2
slt $s0, $s1, $s2
addi $s1, $s2, 100
lw $s1, 100($2)
sw $s1, 100($2)
beq $0, $0, end
bne $0, $0, end
next:
#addi $s1, $s2, 100
#nor $s1, $0, $1
#add $s1, $0, $1
#lw $s1, 100($2)
#sw $s1, 100($2)
end:
