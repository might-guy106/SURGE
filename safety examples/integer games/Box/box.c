extern int __VERIFIER_nondet_int(void);
extern float __VERIFIER_nondet_float(void);
extern void __VERIFIER_assume(int);
extern void __VERIFIER_error(void);

/*
  Box example: Neider et. al., TACAS 2016 and DTSynth Tool, FMCAD 2019
  A variation of the diagonal game. Both players
  can move the robot in an vertical, horizontal or diagonal
  direction by one cell. Player 0 wins if the robot stays
  within a horizontal stripe of width three.

  Specification: Safety: G(formula) where formula = And(x<=3, x>=0)
*/

// both environment and system have same moves

void move1(int *x, int *y){
    x = x;
    y = y;
}

void move2(int *x, int *y){
    x = x + 1;
    y = y;
}

void move3(int *x, int *y){
    x = x - 1;
    y = y;
}

void move4(int *x, int *y){
    x = x;
    y = y + 1;
}

void move5(int *x, int *y){
    x = x + 1;
    y = y + 1;
}

void move6(int *x, int *y){
    x = x - 1;
    y = y + 1;
}

void move7(int *x, int *y){
    x = x;
    y = y - 1;
}

void move8(int *x, int *y){
    x = x + 1;
    y = y - 1;
}

void move9(int *x, int *y){
    x = x - 1;
    y = y - 1;
}


int main() {
    int x = 0;
    int y = 0;

    for(int it = 0; it < 1000; it++){
        // controller moves
        if(x < 1){
            move2(&x, &y);
        }
        else if(x > 2){
            move3(&x, &y);
        }

        // environment moves
        int z = __VERIFIER_nondet_int();
        __VERIFIER_assume(z >= 1 && z <= 9);

        if(z == 1){
            move1(&x, &y);
        }
        else if(z == 2){
            move2(&x, &y);
        }
        else if(z == 3){
            move3(&x, &y);
        }
        else if(z == 4){
            move4(&x, &y);
        }
        else if(z == 5){
            move5(&x, &y);
        }
        else if(z == 6){
            move6(&x, &y);
        }
        else if(z == 7){
            move7(&x, &y);
        }
        else if(z == 8){
            move8(&x, &y);
        }
        else if(z == 9){
            move9(&x, &y);
        }

        //@ assert(x >= 0 && x <= 3);
    }
    
    

    return 0;
}