/*

Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

The same repeated number may be chosen from candidates unlimited number of times.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: candidates = [2,3,6,7], target = 7,
A solution set is:
[
  [7],
  [2,2,3]
]
Example 2:

Input: candidates = [2,3,5], target = 8,
A solution set is:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]

*/

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void printfArray(int *nums,int numsSize)
{
    int i=0;
    for(i=0;i<numsSize;i++)
    {
        printf("%d,",nums[i]);
    }
    printf("\n");
}

void dfs(int* candidates, int candidatesSize, int target, int** columnSizes, int* returnSize,int **result,int *path,int pathSize)
{
    int i=0;
    for(i=0;i<candidatesSize&&target>=0;i++)
    {       
        //��ǰ·�����鳤��Ϊ0���������������һ����С����Ҫ��ӵ��������������������ӵ�����·��֮ǰ�������
        if(pathSize==0||path[pathSize-1]<=candidates[i])
        {
            path[pathSize]=candidates[i];   //�����ڼ��������ӵ�·��������
            pathSize++;                     
            if(target==candidates[i])       //���������Ŀ��ֵ��˵�����Ǹ���ȷ��·��
            {        
                //��¼����·��
                result[*returnSize]=malloc(sizeof(int)*pathSize);
                memcpy(result[*returnSize],path,sizeof(int)*pathSize);
                (*columnSizes)[*returnSize]=pathSize;
                //printf("pathSize=%d,i=%d:",pathSize,i);
                //printfArray(result[*returnSize],(*columnSizes)[*returnSize]);
                (*returnSize)++;
            }
            else if(target>candidates[i])       //������Ŀ�������ڵ�ǰ��������£��ڽ�����һ��ѭ�������Ŀ����С�ڵ�ǰ����������˵������·���Ǵ��
            {
                dfs(candidates,candidatesSize,target-candidates[i],columnSizes,returnSize,result,path,pathSize);
                pathSize--;       //��һ�ֱ������������ڱ������������·����ɾ������Ϊ��һ��ѭ��Ҫ������һ��������һ��ѭ����������ͬһλ��
            }   
            else    //���ں����Ķ��Ǵ��������Կ϶�����Ŀ����target�����ֱ��������һ��dfs
            {
                return;
            }
        }
    }
}

int cmp(const void *a,const void *b)
{
    return *(int*)a-*(int*)b;
}

int** combinationSum(int* candidates, int candidatesSize, int target, int** columnSizes, int* returnSize) {
    int **result=malloc(sizeof(int *)*200);
    *columnSizes=malloc(sizeof(int)*200);
    int *path=malloc(sizeof(int)*target);           //��¼·������
    int pathSize=0;                                 //��¼·�������ʵ�ʳ���
    
    qsort(candidates,candidatesSize,sizeof(int),cmp);       //�Ƚ���������Ϊ�˺���ɸѡ�ظ�
    dfs(candidates,candidatesSize,target,columnSizes,returnSize,result,path,pathSize);
    return result;
}