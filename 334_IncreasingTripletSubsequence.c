/*
Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.

Formally the function should:
Return true if there exists i, j, k
such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false.
Your algorithm should run in O(n) time complexity and O(1) space complexity.

Examples:
Given [1, 2, 3, 4, 5],
return true.

Given [5, 4, 3, 2, 1],
return false.

Credits:
Special thanks to @DjangoUnchained for adding this problem and creating all test cases.
*/

bool increasingTriplet(int* nums, int numsSize) {
    int i=0,min1=nums[0],min2=2147483647;

    for(i=1;i<numsSize;i++)
    {
        if(nums[i]<min1)
        {
            min1=nums[i];
        }
        else if(nums[i]<min2&&nums[i]!=min1)
        {
            min2=nums[i];
        }
        if(nums[i]>min2)
        {
            printf("%d",i);
            return true;
        }
    }
    return false;
}
