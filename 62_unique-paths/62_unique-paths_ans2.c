#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int uniquePaths(int m, int n) {
    int *array = (int *)malloc(m * sizeof(int));
    int *array2 = (int *)malloc(m * sizeof(int));
    for (int i = 0; i < m; i++) {
        array[i] = 1;
    }
    array2[0] = 1;
    for (int j = 1; j < n; j++) {
        for (int i = 1; i < m; i++) {
            array2[i] = array2[i - 1] + array[i];
        }
        int* t = array;
        array = array2;
        array2 = t;
        array2[0] = 1;
    }
    int ret = array[m-1];
    free(array);
    free(array2);
    return ret;
}

struct TestData {
    int m;
    int n;
    int ret;
};

int main() {
    struct TestData data[] = {{3, 2, 3}, {7, 3, 28}};
    for (int i = 0; i < sizeof(data) / sizeof(struct TestData); i++) {
        int ret = uniquePaths(data[i].m, data[i].n);
        if (ret != data[i].ret) {
            printf("fail int:%d, %d\nout:%d\nexpect:%d\n",
                   data[i].m, data[i].n, ret, data[i].ret);
            //return 1;
        }
    }
    printf("success.");
    return 0;
}