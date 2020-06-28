/*

Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ≥ s. If there isn't one, return 0 instead.

Example: 

Input: s = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: the subarray [4,3] has the minimal length under the problem constraint.
Follow up:
If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n). 

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-size-subarray-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/


int minSubArrayLen(int s, int* nums, int numsSize){
    int step1=0;
    int step2=0;
    int sum=0;
    int res=0;
    if(numsSize==0)
        return 0;
    sum=nums[0];
    for(step1=0;step1<numsSize;)
    {
        if(sum<s)
        {
            step1++;
            if(step1<numsSize)
                sum+=nums[step1];
        }
        else
        {
            if(res>(step1-step2+1)||res==0)
            {
                res=step1-step2+1;
            }
            sum-=nums[step2];
            if(step1>step2)
            {
                step2++;
            }
            else
            {
                return 1;
            }
        }
    }
    return res;
}
