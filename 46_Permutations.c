/*

Given a collection of distinct numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]

*/

/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

int * row;
int * rowPoint;
int ** result;
int count=0;
int size=0;

void output()
{
    result[count]=malloc(sizeof(int)*size);
    memcpy(result[count],row,sizeof(int)*size);
    count++;
}

//主体思想为递归dfs，将每个元素排在第一个的情况进行深度优先遍历
//通过不断移动rowPiont指针，不断的修改当前正在计算的行的状态
void dfs(int *rowPoint,int * nums,int numsSize)
{
    int * numsBak;
    int i=0;

    if(numsSize<=2)
    {
        //当这一行还剩下两个元素的时候，进行翻转即可穷举
        *rowPoint=nums[0];
        *(rowPoint+1)=nums[1];
        output();

        *rowPoint=nums[1];
        *(rowPoint+1)=nums[0];
        output();
    }
    else
    {
        //当这一行的元素数大于两个时，循环取出一个元素与头位置元素进行交换，计算除了这个元素之外的其他元素的情况
        for(i=0;i<numsSize;i++)
        {
            *rowPoint=nums[i];
            nums[i]=nums[0];
            dfs(rowPoint+1,nums+1,numsSize-1);
            nums[i]=*rowPoint;
        }
    }
}


int** permute(int* nums, int numsSize, int* returnSize) {
    int i=1;
    row=malloc(sizeof(int)*numsSize);
    rowPoint=row;
    size=numsSize;
    *returnSize=1;
    for(i=1;i<=numsSize;i++)
    {
        *returnSize=(*returnSize)*i;
    }
    result=malloc(sizeof(int *)*(*returnSize));
    count=0;
    dfs(rowPoint,nums,numsSize);

    return result;
}
