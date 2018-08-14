/*

Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

Example 1:
Input: [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.
Example 2:
Input: [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
Note: The length of the given binary array will not exceed 50,000.

*/
int findMaxLength(int* nums, int numsSize) {
    int i=0,j=0;
    int count=0;
    //用来存储从0到当前下标的算数和，将0用-1替换，两个相同的算数和之间的1与-1的个数相同。因此该问题可转换为求两个相同的算术和的最大下标差
    int *numSum=malloc(sizeof(int)*(numsSize));
    int *resultMap=calloc(numsSize*2+1,sizeof(int));    //用来记录每个算数和第一次出现的下标
    int offset=numsSize;
    int max=0;

    if(numsSize==0)
    {
        return 0;
    }

    for(i=0;i<=numsSize*2;i++)      //首先将结果哈希表中得值全部初始化为一个无效值
    {
        resultMap[i]=-123;
    }

    for(i=0;i<numsSize;i++)         //将所有0替换为-1
    {
        if(nums[i]==0)
        {
            nums[i]=-1;
        }
    }

    //统计算数和
    numSum[0]=nums[0];              //统计算数和
    resultMap[0+offset]=-1;         //resultMap用来记录每个算术和第一次出现的下标，首先将算术和0出现的下标标记为-1，因为在算术和数组0这个下标标示第一个元素的算数和
    resultMap[numSum[0]+offset]=0;
    for(i=1;i<numsSize;i++)
    {
        numSum[i]=numSum[i-1]+nums[i];      //求当前算数和
        if(resultMap[numSum[i]+offset]==-123)       //检查该算术和是否出现过，如果未出现过则记录下标，如果出现过则计算当前出现的下标与第一次出现的下标之差。
        {
            resultMap[numSum[i]+offset]=i;
        }
        else
        {
            if(i-resultMap[numSum[i]+offset]>max)
            {
                max=i-resultMap[numSum[i]+offset];
            }
        }
    }
    free(resultMap);
    return max;
}
