#include <stdio.h>

extern int __VERIFIER_nondet_int(void);
extern float __VERIFIER_nondet_float(void);
extern void __VERIFIER_assume(int);
extern void __VERIFIER_error(void);

const int NUM_BUCKETS = 5;
const int MAX_CAPACITY = 20;
const int STEPMOTHER_WATER = 10;
const int ITERATIONS = 3;

void stepmother(int *b1, int *b2, int *b3, int *b4, int *b5) {
    int added_water1 = __VERIFIER_nondet_int();
    __VERIFIER_assume(added_water1 >= 0 && added_water1 <= 5);
    int added_water2 = __VERIFIER_nondet_int();
    __VERIFIER_assume(added_water2 >= 0 && added_water2 <= 5);
    int added_water3 = __VERIFIER_nondet_int();
    __VERIFIER_assume(added_water3 >= 0 && added_water3 <= 5);
    int added_water4 = __VERIFIER_nondet_int();
    __VERIFIER_assume(added_water4 >= 0 && added_water4 <= 5);
    int added_water5 = __VERIFIER_nondet_int();
    __VERIFIER_assume(added_water5 >= 0 && added_water5 <= 5);
    int total = added_water1 + added_water2 + added_water3 + added_water4 + added_water5;
    __VERIFIER_assume(total == STEPMOTHER_WATER);

    *b1 += added_water1;
    *b2 += added_water2;
    *b3 += added_water3;
    *b4 += added_water4;
    *b5 += added_water5;
}

void cinderella(int buckets[]) {
    int max_index = 0;

    // Find the bucket with the maximum amount of water
    for (int i = 1; i < NUM_BUCKETS; i++) {
        if (buckets[i] > buckets[max_index]) {
            max_index = i;
        }
    }

    // Determine which adjacent bucket has the most water
    int left_index = (max_index - 1 + NUM_BUCKETS) % NUM_BUCKETS;
    int right_index = (max_index + 1) % NUM_BUCKETS;
    int max_adjacent_index = (buckets[left_index] > buckets[right_index]) ? left_index : right_index;

    // Empty the bucket with the maximum amount of water and its adjacent bucket with the most water
    buckets[max_index] = 0;
    buckets[max_adjacent_index] = 0;
}

int main() {

    int buckets[NUM_BUCKETS] = {0};

    for(int i = 0; i < ITERATIONS; i++) {

        // stepmother move
        stepmother(&buckets[0], &buckets[1], &buckets[2], &buckets[3], &buckets[4]);
        //@ assert(buckets[0] <= MAX_CAPACITY && buckets[1] <= MAX_CAPACITY && buckets[2] <= MAX_CAPACITY && buckets[3] <= MAX_CAPACITY && buckets[4] <= MAX_CAPACITY);

        // cinderella moves
        cinderella(buckets);
    }
    
    return 0;
}