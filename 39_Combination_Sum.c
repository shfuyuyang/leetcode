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
        //当前路径数组长度为0，或者数组中最后一个数小于正要添加的数。如果大于则正在添加的这条路径之前被计算过
        if(pathSize==0||path[pathSize-1]<=candidates[i])
        {
            path[pathSize]=candidates[i];   //将正在计算的数添加到路径数组中
            pathSize++;                     
            if(target==candidates[i])       //这个数等于目标值，说明这是个正确的路径
            {        
                //记录这条路径
                result[*returnSize]=malloc(sizeof(int)*pathSize);
                memcpy(result[*returnSize],path,sizeof(int)*pathSize);
                (*columnSizes)[*returnSize]=pathSize;
                //printf("pathSize=%d,i=%d:",pathSize,i);
                //printfArray(result[*returnSize],(*columnSizes)[*returnSize]);
                (*returnSize)++;
            }
            else if(target>candidates[i])       //或者在目标数大于当前数的情况下，在进入下一轮循环。如果目标数小于当前遍历的数，说明这条路径是错的
            {
                dfs(candidates,candidatesSize,target-candidates[i],columnSizes,returnSize,result,path,pathSize);
                pathSize--;       //下一轮遍历结束后将正在遍历的这个数从路径中删除，因为下一轮循环要遍历下一个数。这一轮循环的数属于同一位置
            }   
            else    //由于后续的都是大数，所以肯定大于目标数target，因此直接跳出这一轮dfs
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
    int *path=malloc(sizeof(int)*target);           //记录路径数组
    int pathSize=0;                                 //记录路径数组的实际长度
    
    qsort(candidates,candidatesSize,sizeof(int),cmp);       //先将数据排序，为了后面筛选重复
    dfs(candidates,candidatesSize,target,columnSizes,returnSize,result,path,pathSize);
    return result;
}