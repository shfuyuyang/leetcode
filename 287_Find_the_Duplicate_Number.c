/*
Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.

Note:
You must not modify the array (assume the array is read only).
You must use only constant, O(1) extra space.
Your runtime complexity should be less than O(n2).
There is only one duplicate number in the array, but it could be repeated more than once.
*/


//���������Ϊ�л����������ӵ�����

//����������û���ظ��������ǿ���������ôһ�㣬���ǽ�������±��1��nÿһ����һ��һ��ӳ������������������213,��ӳ���ϵΪ0->2, 1->1, 2->3��
//�������һ��һӳ���ϵ��һ������f(n)������n���±꣬f(n)��ӳ�䵽������
//������Ǵ��±�Ϊ0����������������������һ��ֵ�������ֵΪ�µ��±꣬��������������㣬�Դ����ƣ�ֱ���±곬�硣
//ʵ���Ͽ��Բ���һ����������һ�������С�����������������������±�����У�0->2->3��

//��������ظ��Ļ������м�ͻ�������һ��ӳ�䣬��������2131,��ӳ���ϵΪ0->2, {1��3}->1, 2->3��
//�������������ݵ����о�һ�����л�·�ˣ������±��������0->2->3->1->1->1->1->...���������������ظ�������

#if 1

int findDuplicate(int* nums, int numsSize) {
    int slow=0;
    int fast=0;
    int temp=0;

    slow=nums[0];       //�趨һ�����±꣬ÿ����һ��
    fast=nums[nums[0]]; //�趨һ�����±꣬ÿ��������
    while(fast!=slow)
    {
        slow=nums[slow];
        fast=nums[nums[fast]];
    }
    //��Ϊ���±���ٶ������±����������ˣ���ԭ�㵽���ӵ�ľ�����ڴ�������˳���ߵ����ӵ�ľ��롣

    //����ٶ���һ���±��ԭ��������������±��ֵ�����˵���������������ϣ�������һ���ֵ
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
