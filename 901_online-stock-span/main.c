#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct {
    int *nums;
    int i;
    int *stack; 
    int top;
} StockSpanner;


StockSpanner* stockSpannerCreate() {
    StockSpanner* obj = (StockSpanner*)malloc(sizeof(StockSpanner0));
    obj->nums = (int*)malloc(10001*sizeof(int));
    memset(obj->nums, 0, 10001*sizeof(int));
    obj->i = 0;

    obj->stack = (int*)malloc(10001*sizeof(int));
    memset(obj->stack, 0, 10001*sizeof(int));
    obj->top = 0;
    return obj;
}

int stockSpannerNext(StockSpanner* obj, int price) {
    
    int res = 1;
    int* nums = obj->nums;
    int* stack = obj->stack;
    int* top = &(obj->top);

    while(*top && price > nums[stack[*top]]){
        res 
        res = obj->stack[obj->top]
    }
}

void stockSpannerFree(StockSpanner* obj) {
    free(obj->stack);
    free(obj);
}

/**
 * Your StockSpanner struct will be instantiated and called as such:
 * StockSpanner* obj = stockSpannerCreate();
 * int param_1 = stockSpannerNext(obj, price);
 
 * stockSpannerFree(obj);
*/

int main(void){

    return 0;
}