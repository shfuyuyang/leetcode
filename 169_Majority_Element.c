/*
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

*/

#if 0

int cmp(const void *a ,const void *b)
{
    return *(int *)a-*(int *)b;
}

int majorityElement(int* nums, int numsSize) {
    qsort(nums,numsSize,sizeof(int),cmp);
    return nums[numsSize/2];
}

#else

int majorityElement(int * nums,int numsSize)
{
    int i=0;
    int result=0;
    int count=0;
    for(i=0;i<numsSize;i++)
    {
        if(count==0||result==nums[i])
        {
            result=nums[i];
            count++;
        }
        else
        {
            count--;
        }
    }
    return result;
}

#endif
