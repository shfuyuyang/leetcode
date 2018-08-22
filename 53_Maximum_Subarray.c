/*

Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Follow up:

If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

*/

#if 1

int maxSubArray(int* nums, int numsSize)
{
    int i=0;
    int sum=0;
    int max=-2147483647;
    for(i=0;i<numsSize;i++)
    {
        if(sum>=0)      //sum的值最初为0，因此第一次要加上第一个数字
        {
            sum+=nums[i];
        }
        else
        {
            sum=nums[i];
        }
        if(sum>max)
        {
            max=sum;
        }
    }
    return max;
}

#else
//二分法
int maxSubArray(int* nums, int numsSize) {
    int left=0;     //和最大的子数组在左侧的情况
    int right=0;    //和最大的子数组在右侧的情况
    int mid=0;      //和最大的子数组包含中间点的情况
    int i=0;
    int sumTemp=0;
    int maxL=-9999;
    int maxR=-9999;

    if(numsSize==0)
    {
        return 0;
    }
    if(numsSize==1)
    {
        return nums[0];
    }

    //求出最大和的子数组跨过中间节点的情况
    for(i=numsSize/2-1;i>=0;i--)
    {
        sumTemp+=nums[i];
        if(sumTemp>maxL)
        {
            maxL=sumTemp;
        }
    }
    sumTemp=0;
    for(i=0;i<numsSize/2+numsSize%2;i++)
    {
        sumTemp+=(nums+numsSize/2)[i];
        if(sumTemp>maxR)
        {
            maxR=sumTemp;
        }
    }
    mid=maxR+maxL;
    //采用递归调用的方式分别求出左侧与右侧最大的结果
    left=maxSubArray(nums,numsSize/2);
    right=maxSubArray(nums+numsSize/2,numsSize/2+numsSize%2);

    //将左右中三个结果进行比较
    sumTemp=(left>right?left:right);
    return sumTemp>mid?sumTemp:mid;
}

#endif
