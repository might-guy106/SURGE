extern int __VERIFIER_nondet_int(void);
extern float __VERIFIER_nondet_float(void);
extern void __VERIFIER_assume(int);
extern void __VERIFIER_error(void);

/*
 Limited Box example: Neider et. al., TACAS 2016 and DTSynth Tool, FMCAD 2019
 A variation of the box game. Player 0 can
 only control the robot's vertical movement and Player 1
 the horizontal.

 Specification: Safety: G(formula) where formula = And(x<=3, x>=0)
*/

// environment moves

void env1(int *x, int *y){
    x = x;
    y = y;
}

void env2(int *x, int *y){
    x = x + 1;
    y = y;
}

void env3(int *x, int *y){
    x = x - 1;
    y = y;
}

void con1(int *x, int *y){
    x = x;
    y = y;
}

void con2(int *x, int *y){
    x = x;
    y = y + 1;
}

void con3(int *x, int *y){
    x = x;
    y = y - 1;
}



int main() {
    int x = 0;
    int y = 0;

    for(int it = 0; it < 1000; it++){
        // controller moves
        // what should be the controller moves?

        // environment moves
        int z = __VERIFIER_nondet_int();
        __VERIFIER_assume(z >= 1 && z <= 3);

        if(z == 1){
            env1(&x, &y);
        }
        else if(z == 2){
            env2(&x, &y);
        }
        else if(z == 3){
            env3(&x, &y);
        }

        //@ assert(x >= 0 && x <= 3);
    }
    
    

    return 0;
}