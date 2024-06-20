extern int __VERIFIER_nondet_int(void);
extern float __VERIFIER_nondet_float(void);
extern void __VERIFIER_assume(int);
extern void __VERIFIER_error(void);

/*
 Evasion game: Neider et. al., TACAS 2016 and DTSynth Tool, FMCAD 2019
 Two robots are moving in an infinite, discrete two-dimensional grid world. The robots take turns
 moving at most one cell in any direction. Each players
 controls one robot. Player 0's objective is to avoid getting
 caught by Player 1's robot

 Specification: Safety: G(formula) where formula = Not(And(x1==x2, y1==y2))
*/


int main() {
    int x1 = 0;
    int y1 = 0;
    int x2 = 1;
    int y2 = 1;

    for(int it = 0; it < 1000; it++){
        // controller moves
        if(x1 <= x2 ){
            if(y1 <= y2){
                x2++;
                y2++;
            }
            else{
                x2++;
                y2--;
            }
        }
        else{
            if(y1 <= y2){
                x2--;
                y2++;
            }
            else{
                x2--;
                y2--;
            }
        }

        // environment moves
        int z = __VERIFIER_nondet_int();
        __VERIFIER_assume(z >= 1 && z <= 9);

        if(z == 1){
            x1 = x1;
            y1 = y1;
        }
        else if(z == 2){
            x1 = x1 + 1;
            y1 = y1;
        }
        else if(z == 3){
            x1 = x1 - 1;
            y1 = y1;
        }
        else if(z == 4){
            x1 = x1;
            y1 = y1 + 1;
        }
        else if(z == 5){
            x1 = x1 + 1;
            y1 = y1 + 1;
        }
        else if(z == 6){
            x1 = x1 - 1;
            y1 = y1 + 1;
        }
        else if(z == 7){
            x1 = x1;
            y1 = y1 - 1;
        }
        else if(z == 8){
            x1 = x1 + 1;
            y1 = y1 - 1;
        }
        else if(z == 9){
            x1 = x1 - 1;
            y1 = y1 - 1;
        }
        

        //@ assert(!(x1 == x2 && y1 == y2));
    }
    
    

    return 0;
}