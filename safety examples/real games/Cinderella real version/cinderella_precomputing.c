#include <stdio.h>

extern int __VERIFIER_nondet_int(void);
extern float __VERIFIER_nondet_float(void);
extern void __VERIFIER_assume(int);
extern void __VERIFIER_error(void);

const int NUM_BUCKETS = 5;
const float MAX_CAPACITY = 2;
const float STEPMOTHER_WATER = 1;
const int ITERATIONS = 3;

void cinderella(int buckets[]) {
    int max_index = 0;
    int max_count = buckets[0];

    // Find the bucket with the maximum amount of water
    for (int i = 1; i < NUM_BUCKETS; i++) {
        if (buckets[i] >= buckets[max_index]) {
            max_index = i;
            max_count = buckets[i];
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
    
    float buckets[NUM_BUCKETS] = {0};
    float stepmother[ITERATIONS][NUM_BUCKETS] = {0};

    // computing stepmother moves before hand
    for(int i = 0; i < ITERATIONS; i++) {
        float water_remaining = STEPMOTHER_WATER; 
        for (int j = 0; j < NUM_BUCKETS - 1; j++) {
            float added_water = __VERIFIER_nondet_int(); // amount of water to be added in jth bucket of ith round by stepmother
            __VERIFIER_assume(added_water >= 0 && added_water <= water_remaining);
            stepmother[i][j] += added_water;
            water_remaining -= added_water; // updating remaining water
        }
        stepmother[i][NUM_BUCKETS - 1] = water_remaining;
    }

    for(int i = 0; i < ITERATIONS; i++) {
        // stepmother move (which are precomputed)
        for (int j = 0; j < NUM_BUCKETS; j++) {
            buckets[j] += stepmother[i][j];
            //@ assert buckets[j] <= MAX_CAPACITY;
        }

        // cinderella moves
        cinderella(buckets);
    }
    
    return 0;
}