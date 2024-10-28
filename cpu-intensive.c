#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define N 1000000000

void sieve_of_eratosthenes(bool *prime) {
    for (int p = 2; p * p <= N; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= N; i += p)
                prime[i] = false;
        }
    }
}

int main() {
    bool *prime = (bool *)calloc(N + 1, sizeof(bool));
    clock_t start, end;
    double cpu_time_used;

    for (int i = 2; i <= N; i++)
        prime[i] = true;

    start = clock();

    sieve_of_eratosthenes(prime);

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    int count = 0;
    for (int p = 2; p <= N; p++)
        if (prime[p])
            count++;

    printf("Found %d prime numbers\n", count);
    printf("Time taken: %f seconds\n", cpu_time_used);

    free(prime);
    return 0;
}
