.data
    n:	.word	5

    lbracket:	.string	"["
    rbracket:	.string	"]\n"
    comma:	.string	","

.text

main:
    # allocate space for returned array
    lw	t0, n
    slli	t0, t0, 2
    sub sp, sp, t0

    # count bits
    lw	a0, n
    mv	a1, sp
    jal	count_bits
    
    # print the result
    mv	a0, sp
    lw	a1, n
    slli	a1, a1, 2
    jal print

    # restore sp
    lw	t0, n
    slli	t0, t0, 2
    add	sp, sp, t0

    # exit the program
    li	a7, 10
    ecall

popcnt:
    li	t2, 0 # population
    mv	t3, a0

popcnt_conti:
    beq	t3, x0, popcnt_end

    # apply a &= (a - 1)
    addi	t4, t3, -1
    and	t3, t3, t4
    addi	t2, t2, 1
    j	popcnt_conti

popcnt_end:
    mv	a0, t2
    ret

count_bits:
    addi	sp, sp, -4
    sw	ra, 0(sp) # store the return address
    mv	t5, a1 # base address of the array

    mv	t0, a0 # n
    li	t1, 0 # i

loop:
    mv	a0, t1 # load the argument
    jal	popcnt
    sw	a0, 0(t5)

    addi	t1, t1, 1
    addi	t5, t5, 4
    bge	t0, t1, loop
    
    lw	ra, 0(sp)
    addi	sp, sp, 4
    ret

print:
    mv	t0, a0 # sp value
    mv	t1, a1 # boundary
    add	t1, t1, t0

    # print left bracket
    la	a0, lbracket
    li	a7, 4
    ecall

    # print first number
    lw	a0, 0(t0)
    li	a7, 1
    ecall

    addi	t0, t0, 4
    blt	t1, t0, print_end

print_conti:
    # print comma
    la	a0, comma
    li	a7, 4
    ecall

    # print number
    lw	a0, 0(t0)
    li	a7, 1
    ecall

    addi	t0, t0, 4
    bge	t1, t0, print_conti

print_end:
    # print right bracket
    la	a0, rbracket
    li	a7, 4
    ecall
    ret

