extern int __VERIFIER_nondet_int(void);
extern float __VERIFIER_nondet_float(void);
extern void __VERIFIER_assume(int);
extern void __VERIFIER_error(void);

/*
 3 variable Sorting Example taken from the paper "Reactive Synthesis Modulo Theories using Abstraction Refinement"
 Spec: FG (a>=b, b>=c)
*/

// swaping a and b
void move1(int *a, int *b, int *c){
    int temp = *a;
    *a = *b;
    *b = temp;
}

// swaping b and c
void move2(int *a, int *b, int *c){
    int temp = *b;
    *b = *c;
    *c = temp;
}

// skip
void move3(int *a, int *b, int *c){
    // no changes
}


int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int c = __VERIFIER_nondet_int();

    while(!(a <= b && b <= c)) {
        if(a > b) {
            move1(&a, &b, &c);
        } 
        else if(b > c) {
            // move2(&a, &b, &c);
        } 
    }
    
    //@ assert(a <= b && b <= c);

    return 0;
}