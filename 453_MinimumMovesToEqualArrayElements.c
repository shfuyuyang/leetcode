/*
Given a non-empty integer array of size n, find the minimum number of moves required to make all array elements equal, where a move is incrementing n - 1 elements by 1.

Example:

Input:
[1,2,3]

Output:
3

Explanation:
Only three moves are needed (remember each move increments two elements):

[1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]
*/
int minMoves(int* nums, int numsSize) {
    long int i=0;
    long int min=2147483648;
    long int sum=0;
    for(i=0;i<numsSize;i++)
    {
        if(min>nums[i])
        {
            min=nums[i];
        }
        sum+=nums[i];
    }
    return sum-min*numsSize;
}
