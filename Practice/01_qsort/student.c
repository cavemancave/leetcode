#include <stdio.h>
#include <stdlib.h>
#define LEN 3
typedef struct {
    int age, score;
    char name[5];
}Student;

int comp(const void *a, const void* b){
    return ((Student*)a)->age - ((Student*)b)->age;
}
int main(void){
    Student arr[LEN] = {{14, 100, "apple"}, {100, 23, "bad"}, {23, 40, "change"}};

    qsort(arr, LEN, sizeof(Student), comp);
    for(int i=0;i<LEN;i++){
        printf("%d,%d,%s \n", arr[i].age, arr[i].score, arr[i].name);
    }
    return 0;
}