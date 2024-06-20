extern int __VERIFIER_nondet_int(void);
extern float __VERIFIER_nondet_float(void);
extern void __VERIFIER_assume(int);
extern void __VERIFIER_error(void);

/*
# 4 variable Sorting Example taken from the paper "Reactive Synthesis Modulo Theories using Abstraction Refinement"
# Spec: FG (a>=b, b>=c, c>=d)
*/

// Environment move (Skip)
void environment(int *a, int *b, int *c, int *d) {
    // No changes for environment move
}

// swaping a and b
void move1(int *a, int *b, int *c, int *d){
    int temp = *a;
    *a = *b;
    *b = temp;
}

// swaping b and c
void move2(int *a, int *b, int *c, int *d){
    int temp = *b;
    *b = *c;
    *c = temp;
}

// swaping c and d
void move3(int *a, int *b, int *c, int *d){
    int temp = *c;
    *c = *d;
    *d = temp;
}

// skip
void move4(int *a, int *b, int *c, int *d){
    // no change
}


int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int c = __VERIFIER_nondet_int();
    int d = __VERIFIER_nondet_int();

    while(!(a <= b && b <= c && c <= d)) {
        if(a > b) {
            move1(&a, &b, &c, &d);
        } 
        else if(b > c) {
            move2(&a, &b, &c, &d);
        }
        else if(c > d){
            move3(&a, &b, &c, &d);
        }
    }
    
    //@ assert(a <= b && b <= c && c <= d);

    return 0;
}