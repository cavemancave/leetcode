#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int uniquePaths(int m, int n) {
    int *array = (int *)malloc(m * n * sizeof(int));
    for (int i = 0; i < m; i++) {
        array[i] = 1;
    }
    for (int j = 0; j < n; j++) {
        array[j * m] = 1;
    }
    for (int j = 1; j < n; j++) {
        for (int i = 1; i < m; i++) {
            array[j * m + i] = array[j * m + i - 1] + array[(j-1) * m + i];
        }
    }
    free(array);
    return array[(n - 1) * m + (m - 1)];
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