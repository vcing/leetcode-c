#include <stdlib.h>

/**
 *  * Note: The returned array must be malloced, assume caller calls free().
 *   */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    if(numsSize < 2) {
        *returnSize = 0;
        return NULL;
    }
    int * first = nums;
    int * second = nums + 1;
    int firstPosition = 0;
    int secondPosition = 1;
    int * result = malloc(sizeof(int) * 2);

    while(firstPosition < numsSize - 1)
    {
        while(secondPosition < numsSize)
        {
            if(*first + *second == target)
            {
                *result = firstPosition;
                *(result + 1) = secondPosition;
                *returnSize = 2;
                return result;
            }
            second++;
            secondPosition++;
        }
        firstPosition++;
        first++;
        secondPosition = firstPosition + 1;
        second = first + 1;
    }

    *returnSize = 0;
    return NULL;

}
