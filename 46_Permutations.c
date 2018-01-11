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

//����˼��Ϊ�ݹ�dfs����ÿ��Ԫ�����ڵ�һ�����������������ȱ���
//ͨ�������ƶ�rowPiontָ�룬���ϵ��޸ĵ�ǰ���ڼ�����е�״̬
void dfs(int *rowPoint,int * nums,int numsSize)
{
    int * numsBak;
    int i=0;

    if(numsSize<=2)
    {
        //����һ�л�ʣ������Ԫ�ص�ʱ�򣬽��з�ת�������
        *rowPoint=nums[0];
        *(rowPoint+1)=nums[1];
        output();

        *rowPoint=nums[1];
        *(rowPoint+1)=nums[0];
        output();
    }
    else
    {
        //����һ�е�Ԫ������������ʱ��ѭ��ȡ��һ��Ԫ����ͷλ��Ԫ�ؽ��н���������������Ԫ��֮�������Ԫ�ص����
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
