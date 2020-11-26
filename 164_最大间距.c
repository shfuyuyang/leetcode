/*

Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

Return 0 if the array contains less than 2 elements.

Example 1:

Input: [3,6,9,1]
Output: 3
Explanation: The sorted form of the array is [1,3,6,9], either
             (3,6) or (6,9) has the maximum difference 3.
Example 2:

Input: [10]
Output: 0
Explanation: The array contains less than 2 elements, therefore return 0.
Note:

You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.
Try to solve it in linear time/space.

*/

int maximumGap(int* nums, int numsSize)
{
    long max=INT32_MIN;
    long min=INT32_MAX;
    int i=0;
    int *map=calloc((numsSize)*2,sizeof(int));
    if(numsSize<2)
    {
        return 0;
    }
    for(i=0;i<numsSize;i++)
    {
        if(nums[i]>max)
        {
            max=nums[i];
        }
        if(nums[i]<min)
        {
            min=nums[i];
        }
    }

    map[0]=min;
    map[1]=min;
    map[(numsSize-1)*2]=max;
    map[(numsSize-1)*2+1]=max;
    for(i=0;i<numsSize;i++)
    {
        int index=0;
        if(max-min!=0)
        {
            index=(long)abs((int)(nums[i]-1-min))*numsSize/(max-min);
        }
        index=(index)*2;
        if(map[index]!=0)
        {
            if(nums[i]<map[index])
            {
                map[index]=nums[i];
            }
            else if(nums[i]>map[index+1])
            {
                map[index+1]=nums[i];
            }
        }
        else
        {
            map[index]=nums[i];
            map[index+1]=nums[i];
        }
    }
    max=-1;
    for(i=1;i<numsSize;i++)
    {
        if(map[i*2]==0)
        {
            map[i*2]=map[(i-1)*2];
            map[i*2+1]=map[(i-1)*2+1];
        }
        if(map[i*2]-map[(i-1)*2+1]>max)
        {
            max=map[i*2]-map[(i-1)*2+1];
        }
    }
    free(map);
    return max;
}
