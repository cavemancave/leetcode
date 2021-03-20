#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}
void addRes(int **res, int *returnSize, int a, int b, int c)
{
    int *resLine = (int *)malloc(sizeof(int) * 3);
    resLine[0] = a;
    resLine[1] = b;
    resLine[2] = c;
    res[(*returnSize)++] = resLine;
}

int **threeSumInner(int *nums, int numsSize, int *returnSize, int **returnColumnSizes)
{
    if (numsSize < 3)
    {
        *returnSize = 0;
        return NULL;
    }
    *returnSize = 0;
    qsort(nums, numsSize, sizeof(int), comp);

    int **res = (int **)malloc(10000 * sizeof(int *));

    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] > 0)
        {
            return res;
        }
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        int L = i + 1;
        int R = numsSize - 1;
        while (L < R)
        {
            int sum = nums[i] + nums[L] + nums[R];
            if (sum == 0)
            {
                addRes(res, returnSize, nums[i], nums[L], nums[R]);
                while (L < R && nums[L] == nums[L + 1])
                    L++;
                while (L < R && nums[R] == nums[R - 1])
                    R--;
                L++;
                R--;
            }
            else if (sum > 0)
            {
                R--;
            }
            else
            {
                L++;
            }
        }
    }
    return res;
}
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **threeSum(int *nums, int numsSize, int *returnSize, int **returnColumnSizes)
{
    int **res = threeSumInner(nums, numsSize, returnSize, returnColumnSizes);
    if (*returnSize == 0)
    {
        free(res);
        return NULL;
    }

    *returnColumnSizes = (int *)malloc((*returnSize) * sizeof(int));
    for (int i = 0; i < (*returnSize); i++)
        (*returnColumnSizes)[i] = 3;
    return res;
}

int main()
{

    int nums[] = {-1, 0, 1, 2, -1, -4};
    int numsSize = sizeof(nums) / sizeof(int);
    int returnSize = 0;
    int *returnColumnSizes;
    int **res;
    res = threeSum(nums, numsSize, &returnSize, &returnColumnSizes);
    if (numsSize == 0)
        return 1;
    for (int i = 0; i < returnSize; i++)
    {
        for (int j = 0; j < returnColumnSizes[i]; j++)
        {
            printf("%d ", res[i][j]);
        }
        printf("\n");
        free(res[i]);
    }
    free(res);
    free(returnColumnSizes);

    return 0;
}