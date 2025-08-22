#include <stdio.h>
#include <time.h>

#define ITER 100000000

int local_var_add() {
    int sum = 0, x = 1, y = 2;
    int i = -1;
    while (++i < ITER) sum += x + y;
    return sum;
}

int param_add(register int x, register int y) {
    int sum = 0;
    int i = -1;
    while (++i < ITER) sum += x + y;
    return sum;
}

int main() {
    clock_t start, end;
    double time_local, time_param;

    start = clock();
    local_var_add();
    end = clock();
    time_local = (double)(end - start) / CLOCKS_PER_SEC;
    printf("time_local: %.3fs\12", time_local);

    start = clock();
    param_add(1, 2);
    end = clock();
    time_param = (double)(end - start) / CLOCKS_PER_SEC;
    printf("time_param: %.3fs\12", time_param);

    return 0;
}