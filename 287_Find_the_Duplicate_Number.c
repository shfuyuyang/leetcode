/*
Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.

Note:
You must not modify the array (assume the array is read only).
You must use only constant, O(1) extra space.
Your runtime complexity should be less than O(n2).
There is only one duplicate number in the array, but it could be repeated more than once.
*/


//此题可以作为有环链表求连接点问题

//假设数组中没有重复，那我们可以做到这么一点，就是将数组的下标和1到n每一个数一对一的映射起来。比如数组是213,则映射关系为0->2, 1->1, 2->3。
//假设这个一对一映射关系是一个函数f(n)，其中n是下标，f(n)是映射到的数。
//如果我们从下标为0出发，根据这个函数计算出一个值，以这个值为新的下标，再用这个函数计算，以此类推，直到下标超界。
//实际上可以产生一个类似链表一样的序列。比如在这个例子中有两个下标的序列，0->2->3。

//但如果有重复的话，这中间就会产生多对一的映射，比如数组2131,则映射关系为0->2, {1，3}->1, 2->3。
//这样，我们推演的序列就一定会有环路了，这里下标的序列是0->2->3->1->1->1->1->...，而环的起点就是重复的数。

#if 1

int findDuplicate(int* nums, int numsSize) {
    int slow=0;
    int fast=0;
    int temp=0;

    slow=nums[0];       //设定一个慢下标，每次走一步
    fast=nums[nums[0]]; //设定一个快下标，每次走两步
    while(fast!=slow)
    {
        slow=nums[slow];
        fast=nums[nums[fast]];
    }
    //因为快下标的速度是慢下标的两倍，因此，从原点到连接点的距离等于从相遇点顺序走到连接点的距离。

    //因此再定义一个下标从原点出发，当两个下标的值相等则说明他们在相遇点上，返回这一点的值
    fast=0;

    while(fast!=slow)
    {
        slow=nums[slow];
        fast=nums[fast];
    }
    return slow;
}

#else

int cmp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}

int findDuplicate(int* nums, int numsSize) {
    int i=0;
    qsort(nums,numsSize,sizeof(int),cmp);
    for(i=1;i<numsSize;i++)
    {
        if(nums[i]==nums[i-1])
        {
            return nums[i];
        }
    }
    return 0;
}

#endif
