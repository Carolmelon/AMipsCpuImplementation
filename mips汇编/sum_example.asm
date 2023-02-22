main:
	add $t1, $0, 0
	add $t2, $0, 1
	add $t4, $0, 50 #Ñ­»·ÖÕµã
.a:
	add $t1, $t1, $t2
	add $t2, $t2, 1
	slt $t3, $t2, $t4
	beq $t3, 1, .a
	
	sw $t1, 0x10010000($0)
	
	jal .a
	j