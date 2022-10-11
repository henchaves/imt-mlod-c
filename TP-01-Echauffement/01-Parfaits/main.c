#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

int sum_dividers(uint64_t n) {
    long sum = 0, max_num_dividers = n/2, i;

    for (i = 1; i <= max_num_dividers; i++) {
        if (n % i == 0) sum += i;
    }

    return sum;
}

bool is_perfect(uint64_t n) {
    return sum_dividers(n) == n;
}

int main (void) {
    long max_number;
    
    printf( "Insert the max number to find if it is perfect (range 6 - n) : " );
    scanf("%ld", &max_number);

    for (long i = 6; i < max_number; i++) {
        if(is_perfect(i)) {
            printf("%ld is perfect!\n", i);
        }
    }

    return 0;
}

