/*

Given an array of integers A sorted in non-decreasing order, return an array of the squares of each number, also in sorted non-decreasing order.



Example 1:

Input: [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Example 2:

Input: [-7,-3,2,3,11]
Output: [4,9,9,49,121]


Note:

1 <= A.length <= 10000
-10000 <= A[i] <= 10000
A is sorted in non-decreasing order.

*/



/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#if 0
int cmp(void *a,void *b)
{
    return *(int*)a-*(int*)b;
}

int* sortedSquares(int* A, int ASize, int* returnSize){
    int *result=malloc(sizeof(int)*ASize);
    int i=0;
    *returnSize=ASize;
    for(i=0;i<ASize;i++)
    {
        result[i]=A[i]*A[i];
    }
    qsort(result,ASize,sizeof(int),cmp);
    return result;
}

#else

int* sortedSquares(int* A, int ASize, int* returnSize){
    int *result=malloc(sizeof(int)*ASize);
    int i=0,j=ASize-1;
    int cnt=ASize-1;
    int sq1=0,sq2=0;
    *returnSize=ASize;
    while(cnt>=0)
    {
        sq1=A[i]*A[i];
        sq2=A[j]*A[j];
        if(sq1>=sq2)
        {
            result[cnt--]=sq1;
            i++;
        }
        else
        {
            result[cnt--]=sq2;
            j--;
        }
    }
    return result;
}

#endif
