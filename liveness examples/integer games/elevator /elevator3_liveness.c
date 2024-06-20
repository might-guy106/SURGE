extern int __VERIFIER_nondet_int(void);
extern float __VERIFIER_nondet_float(void);
extern void __VERIFIER_assume(int);
extern void __VERIFIER_error(void);

/*
 Three floor elevator example.
 Spec: General LTL (Liveness), G(1<=x<=3) and G(F(x==1) and F(x==2) and F(x==3))
*/

// Environment move (Skip)
void environment(int *x) {
    // No changes for environment move
}

int main() {
    int x = __VERIFIER_nondet_int();
    __VERIFIER_assume(x >= 1 && x <= 3);

    while(x != 1) {
        if(x > 1) x--; // move 3
        else x++; // move 2
    }
    
    //@ assert(x == 1);
    
    x++; // move 2
    
    //@ assert(x == 2);
    
    x++; // move 2
    
    //@ assert(x == 3);
    

    return 0;
}