extern int __VERIFIER_nondet_int(void);
extern float __VERIFIER_nondet_float(void);
extern void __VERIFIER_assume(int);
extern void __VERIFIER_error(void);

/*
 Diagonal example: Neider et. al., TACAS 2016 and DTSynth Tool, FMCAD 2019
 A robot moves in an infinite, discrete twodimensional grid world. Player 0 controls the robot's
 vertical movement, while Player 1 controls the horizontal.
 Player 0 wins if the robot stays within two cell around
 the diagonal
*/

int main() {
    int x = 0;
    int y = 0;

    for(int it = 0; it < 100; it++){
        // controller moves
        if(y > x){
            y--; // controller move 3
        }
        else if(y < x){
            y++; // controller move 2
        }

        // environment moves
        int z = __VERIFIER_nondet_int();
        __VERIFIER_assume(z >= 1 && z <= 3);

        if(z == 1){
            //no change // env move 1
        }
        else if(z == 2){
            x++; // env move 2
        }
        else if(z == 3){
            x--; // env move 3
        }

        //@ assert(y >= x - 2 && y <= x + 2);
    }

    return 0;
}