add $t1, $0, 0x1234
add $t2, $0, 0x1
sll $t1, $t1, 16
sll $t2, $t2, 31
sra $t2, $t2, 31
srl $t1, $t1, 16

add $t3, $t1, $t2
sub $t4, $t1, $t2
add $t5, $0, 0x0f0f
and $t6, $t1, $t5
add $t7, $0, 0x1111
or $t7, $t1, $t7

slt $t3, $t2, $t1
sltu $t4, $t2, $t1

jr $t4
before:
	j before
	jal before
before2:
	bne $t1, $t2, before2
	beq $0, $t4, before2
addi $t1, $0,  0xccc
ori  $t1, $t1, 0x3333
slti $t1, $0, -1
add $t1, $0, 0x1234
sw $t1, 0($0)
lw $t2, 0($0)