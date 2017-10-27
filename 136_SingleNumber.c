/*
Given an array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/

#if 0

int cmp(const void * a,const void * b)
{
    return (*(int *)a)-(*(int *)b);
}

int singleNumber(int* nums, int numsSize) {
    int i=0;
    qsort(nums,numsSize,sizeof(int),cmp);
/*
    for(i=0;i<numsSize;i++)
    {
        printf("%d,",nums[i]);
    }
*/
    for(i=0;i<numsSize-2;i+=2)
    {
        if(nums[i]!=nums[i+1])
        {
            if(nums[i+1]==nums[i+2])
            {
                return nums[i];
            }
            else
            {
                return nums[i+1];
            }
        }
    }
    return nums[i];
}

#else

int singleNumber(int* nums, int numsSize)
{
    int result=0;
    int i=0;
    for(i=0;i<numsSize;i++)
    {
        result^=nums[i];
    }
    return result;
}

#endif
