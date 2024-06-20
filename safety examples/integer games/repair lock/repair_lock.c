#include <stdio.h>

extern int __VERIFIER_nondet_int(void);
extern void __VERIFIER_assume(int);
extern void __VERIFIER_error(void);

int main() {
    // Initial state variables
    int pc = 0;
    int l = 0;
    int gl = 0;

    // Simulating controller moves
    for (int it = 0; it < 10; it++) {

        if (pc == 0) {
            // controller strategy 
            if (l == 1){
                pc = 4; // move 2
            }
            else {
                pc = 2; // move 1
            }
        }
        else if (pc == 2) {
            if (l <= 0) {
                pc = 4; // move 3
            }
        }
        else if (pc == 4) {
            if (gl != 0) {
                pc = 5; // move 4
            }
            else {
                pc = 6; // move 5
            }
        }
        else if (pc == 5) {
            if (l >= 1) {
                pc = 6; // move 6
                l = 0;
            }
        }
        else if (pc == 6) {
            pc = 0; // move 7
        }


        // Check assertions
        //@ assert(!((pc == 2 && l == 1) || (pc == 5 && l == 0)));
    }

}
