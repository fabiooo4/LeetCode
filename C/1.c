#include <stdio.h>
#include <stdlib.h>

int *twoSum(int *nums, int numsSize, int target, int *returnSize) {
  *returnSize = 2;
  int *output = (int *)malloc(*returnSize * sizeof(int));

  for (int i = 0; i < numsSize; i++) {
    for (int j = i + 1; j < numsSize; j++) {
      if (nums[i] + nums[j] == target) {
        output[0] = i;
        output[1] = j;
        printf("i = %d  j = %d \n", i, j);
        return output;
      }
    }
  }
  printf("No result found");
  output[0] = -1;
  output[1] = -1;
  return output;
}

int main() {
  int numsSize = 4;
  int target = 9;
  int *returnSize = malloc(2 * sizeof(int));
  int *nums = (int *)malloc(numsSize * sizeof(int));

  if (nums != NULL) {
    nums[0] = 2;
    nums[1] = 7;
    nums[2] = 11;
    nums[3] = 15;
  }
  twoSum(nums, numsSize, target, returnSize);
}
