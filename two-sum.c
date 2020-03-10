#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numSize, int target, int* returnSize){
    int *returnArray = malloc(2*sizeof(int));

    for(int i = 0; i < numSize - 1; i++){
        for(int j = i+1; j < numSize ;j++){
            if(nums[i] + nums[j] == target){
                returnArray[0] = i;
                returnArray[1] = j;
            }
        }
    }
    return returnArray;
}

int main (){
    int nums[] = {2, 7, 11, 15};
    int target = 13;
    int numSize = sizeof(nums)/sizeof(int);
    int *returnSize;

    int* result = twoSum(nums, numSize, target, returnSize);

    for(int k = 0; k <2; k++){
        printf("%d \n", result[k]);
    }

    free(result);
}
