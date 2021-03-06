/*

Given an unsorted integer array, find the smallest missing positive integer.

Example 1:

Input: [1,2,0]
Output: 3
Example 2:

Input: [3,4,-1,1]
Output: 2
Example 3:

Input: [7,8,9,11,12]
Output: 1
Note:

Your algorithm should run in O(n) time and uses constant extra space.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/first-missing-positive
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/

int firstMissingPositive(int* nums, int numsSize){
    int* map=calloc(numsSize+1,sizeof(int));
    int i=0;

    for(i=0;i<numsSize;i++)
    {
        if(nums[i]>0&&nums[i]<(numsSize+1))
        {
            map[nums[i]]=1;
        }
    }

    for(i=1;i<numsSize+1;i++)
    {
        if(map[i]==0)
        {
            return i;
        }
    }
    return i;
}
