/*

Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once. You can return the answer in any order.

You must write an algorithm that runs in linear runtime complexity and uses only constant extra space.

 

Example 1:

Input: nums = [1,2,1,3,2,5]
Output: [3,5]
Explanation:  [5, 3] is also a valid answer.
Example 2:

Input: nums = [-1,0]
Output: [-1,0]
Example 3:

Input: nums = [0,1]
Output: [1,0]

*/

//数组中只有两个数只出现一次，其他元素都出现两次，两种方法。1.排序查重。2.异或和

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#if 0
int cmp(const void *a,const void *b)
{
    int n1=(*(int*)a);
    int n2=(*(int*)b);
    if(n1>n2)
    {
        return 1;
    }
    if(n1==n2)
    {
        return 0;
    }
    return -1;
}

int* singleNumber(int* nums, int numsSize, int* returnSize){
    int i=0;
    int *res=malloc(sizeof(int)*2);
    int cnt=0;
    *returnSize=2;
    qsort(nums,numsSize,sizeof(int),cmp);
    for(i=0;i<numsSize-1;i++)
    {
        if(nums[i]!=nums[i+1])
        {
            res[cnt++]=nums[i];
            if(cnt==2)
            {
                return res;
            }
        }
        else
        {
            i++;
        }
    }
    if(cnt==1)
    {
        res[cnt]=nums[i];
    }

    return res;
}

#else
int* singleNumber(int* nums, int numsSize, int* returnSize){
    int i=0;
    int *res=malloc(sizeof(int)*2);
    int xorSum=0;
    int noZeorBit=0;
    *returnSize=2;
    //Get the xor sum
    for(i=0;i<numsSize;i++)
    {
        xorSum^=nums[i];
    }
    i=0;
    //The xor sum is the two single number xor sum
    //Get one bit which is not zero, so the bit of the two number must different
    while((xorSum&(0x01u<<i))==0)
    {
        i++;
    }
    noZeorBit=i;
    res[0]=xorSum;
    res[1]=xorSum;
    for(i=0;i<numsSize;i++)
    {
        //Re scan the nums, refer this bit, we can divisn the nums to two buff.
        if(nums[i]&(0x01u<<noZeorBit))
        {
            res[0]^=nums[i];
        }
        else
        {
            res[1]^=nums[i];
        }
    }
    return res;
}
#endif
