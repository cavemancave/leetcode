思路：需要2个栈，一个栈保存数字用来比较，一个栈用来保存弹出了几个元素

```

/*
typedef struct {
    int *stack;
    int *weight;
    int top;
} StockSpanner;
*/

StockSpanner* stockSpannerCreate() {
    StockSpanner* obj = (StockSpanner*)malloc(sizeof(StockSpanner));
    obj->stack=(int*)malloc(10001*sizeof(int));
    obj->weight = (int*)malloc(10001*sizeof(int));
    obj->top = 0;
    memset(obj->stack, 0, 10001*sizeof(int));
    memset(obj->weight, 0, 10001*sizeof(int));
    return obj;
}

int stockSpannerNext(StockSpanner* obj, int price) {
    int weight = 0;
    while(obj->top && price >= obj->stack[obj->top]){
        weight += obj->weight[obj->top];
        obj->weight[obj->top] = 0;
        obj->top--;
    }
    obj->top++;
    obj->stack[obj->top] = price;
    obj->weight[obj->top] += 1 + weight;
    return obj->weight[obj->top];
}

void stockSpannerFree(StockSpanner* obj) {
    free(obj->stack);
    free(obj->weight);
    free(obj);
}
```

```
TEST(project, add1)
{

    int nums[] = {28,14,28,35,46,53,66,80,87,88};
    int res[] = {1,1,3,4,5,6,7,8,9,10};
    StockSpanner* obj = stockSpannerCreate();
    int result;

    for(int i=0;i<sizeof(nums)/sizeof(int);i++){
        int result = stockSpannerNext(obj, nums[i]);
        ASSERT_EQ(result, res[i]);
    }
    stockSpannerFree(obj);
}
```
