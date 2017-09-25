/*
Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

For example,
Given [3,2,1,5,6,4] and k = 2, return 5.

Note:
You may assume k is always valid, 1 ≤ k ≤ array's length.

Credits:
Special thanks to @mithmatt for adding this problem and creating all test cases.
*/

//方法一采用排序法

#if 0

int cmp(const void * a,const void *b)
{
    return *(int *)b-*(int *)a;
}

int findKthLargest(int* nums, int numsSize, int k) {
    qsort(nums,numsSize,sizeof(int),cmp);
    return nums[k-1];
}

#else

//快速排序，参数为数组、数组长度和枢纽数下标，返回值为排序后枢纽数所在位置
int quickSort(int * nums,int numsSize,int index)
{
    int * result;
    int i=0,result_i=0;
    int count1=0,count2=numsSize-1;

    result=malloc(sizeof(int)*numsSize);

    for(i=0;i<numsSize;i++)
    {
        if(i==index)
        {
            continue;
        }
        if(nums[i]<nums[index])
        {
            result[count2--]=nums[i];
        }
        else
        {
            result[count1++]=nums[i];
        }
    }
    result[count1]=nums[index];
    memcpy(nums,result,numsSize*sizeof(int));
    return count1;
}
/*
采用快速排序方式，每次取总长度中间的一个点做枢纽点。将大于枢纽点的数据放到左侧，小于枢纽点的数据放到右侧同时返回快速排序后枢纽点的位置
判断K值在枢纽点的哪一侧，然后重新划定数组范围，计算中间长度的枢纽点，同时更新K值在新的数组中的位置
如果排序后枢纽点的位置等于K，那么直接返回枢纽点的值
*/

int findKthLargest(int* nums, int numsSize, int k) {
    int qsResult=0;
    int qsIndex=0;

    for(qsIndex=numsSize/2;qsResult!=k;)
    {
        qsResult=quickSort(nums,numsSize,qsIndex);
        qsResult++;
        if(qsResult>k)
        {
            numsSize=qsResult-1;
            qsIndex=numsSize/2;
        }
        else if(qsResult<k)
        {
            numsSize=numsSize-qsResult;
            k-=qsResult;
            qsIndex=numsSize/2;
            nums+=qsResult;
            qsResult=0;
        }
        else if(qsResult==k)
        {
            return nums[qsResult-1];
        }
    }
    return nums[qsResult];
}

#endif
