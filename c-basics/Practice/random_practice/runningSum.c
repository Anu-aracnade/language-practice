#include <stdio.h>
#include <stdlib.h>

int *runningSum(int *nums, int numsSize, int *returnSize)
{
    int *ans = (int *)malloc(numsSize * sizeof(int));
    int sum = 0;
    for (int i = 0; i < numsSize; i++)
    {
        sum += nums[i];
        ans[i] = sum;
    }
    *returnSize = numsSize;
    return ans;
}

int main()
{
    int n;

    printf("Enter array size :");
    scanf("%d", &n);
    int A[n];
    printf("Enter the array elements :\n");

    for (int i = 0; i < n; i++)
    {
        printf("A[%d] = ", i);
        scanf("%d", &A[i]);
    }
    int returnSize;
    int *result = runningSum(A, n, &returnSize);
    printf("The Running sum array is : ");
    for (int i = 0; i < returnSize; i++)
    {
        printf("%d ", result[i]);
    }
    free(result);
    return 0;
}