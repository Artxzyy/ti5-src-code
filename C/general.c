#include <stdlib.h>
#include <string.h>

// results file

#define FILEPATH "results/results.csv"
#define FIRST_LINE "hardware_id,code_id,so,reps_per_iter,level,iter,total,mean,median,n"

const int reps = 25;

// time calculations

#define EVEN(a)(a % 2 == 0)

double float_sum(float *v, int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += v[i];
    }
    return sum;
}

double float_mean(float *v, int n) {
    return float_sum(v, n) / n;
}

double float_median(float *v, int n) {
    return EVEN(n) ? (v[((n / 2) - 1)] + v[(n / 2)]) / 2 : v[(n / 2)];
}

// write results file

void start_results(FILE *fstream) {
    fprintf(fstream, "%s\n", FIRST_LINE);
}

void write_results(FILE *fstream, int hardware_id, int code_id, int so, int reps_per_iter, int level, int iter, double total, double mean, double median, int n) {
    fprintf(fstream, "%d,%d,%d,%d,%d,%d,%lf,%lf,%lf,%d\n", hardware_id, code_id, so, reps_per_iter, level, iter, total, mean, median, n);
}

// vector and matrix generation functions

void fill_random_vector(int *v, int n) {
    for (int i = 0; i < n; i++) {
        v[i] = rand();
    }
}

void fill_random_matrix(int **m, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            m[i][j] = rand();
        }
    }
}