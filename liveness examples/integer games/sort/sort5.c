extern int __VERIFIER_nondet_int(void);
extern float __VERIFIER_nondet_float(void);
extern void __VERIFIER_assume(int);
extern void __VERIFIER_error(void);

/*
 5 variable Sorting Example taken from the paper "Reactive Synthesis Modulo Theories using Abstraction Refinement"
 Spec: FG (a>=b, b>=c, c>=d, d>=e)
*/

// Environment move (Skip)
void environment(int *a, int *b, int *c, int *d, int *e) {
    // No changes for environment move
}

// swaping a and b
void move1(int *a, int *b, int *c, int *d, int *e){
    int temp = *a;
    *a = *b;
    *b = temp;
}

// swaping b and c
void move2(int *a, int *b, int *c, int *d, int *e){
    int temp = *b;
    *b = *c;
    *c = temp;
}

// swaping c and d
void move3(int *a, int *b, int *c, int *d, int *e){
    int temp = *c;
    *c = *d;
    *d = temp;
}

// swap d and e
void move4(int *a, int *b, int *c, int *d, int *e){
    int temp = *d;
    *d = *e;
    *e = temp;
}

// skip
void move5(int *a, int *b, int *c, int *d, int *e){
    // no change
}


int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int c = __VERIFIER_nondet_int();
    int d = __VERIFIER_nondet_int();
    int e = __VERIFIER_nondet_int();

    while(!(a <= b && b <= c && c <= d && d <= e)) {
        if(a > b) {
            move1(&a, &b, &c, &d, &e);
        } 
        else if(b > c) {
            move2(&a, &b, &c, &d, &e);
        }
        else if(c > d){
            move3(&a, &b, &c, &d, &e);
        }
        else if(d > e){
            move4(&a, &b, &c, &d, &e);
        }

    }
    
    //@ assert(a <= b && b <= c && c <= d && d <= e);

    return 0;
}