inc:
.L2:
    lw a5,0(a0) // int a5 = a0
    sw a5,4(a0) // a0[1] = a5
    addi a0,a0,-4 // a0 = a0 - 1 // a0--
    lw a5,0(a0) // a5 = a0
    bgt a5,a1,.L2 // a5>a1 -> L2
    sw a1,0(a0) // a0[0] = a1
    ret