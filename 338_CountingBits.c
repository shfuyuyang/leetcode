/*
Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.

Example:
For num = 5 you should return [0,1,1,2,1,2].
*/

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

//给出一个整数num，输出0~num之间每一个数字中1的个数。两种方法，第二种时间复杂度更优

#if 0

int getBitsOfNum(int num)
{
    int count=0;
    while(num!=0)
    {
        count+=num&0x01;
        num=num>>1;
    }
    return count;
}

int* countBits(int num, int* returnSize) {
    int i=0;
    int * result;
    result=malloc(sizeof(int)*(num+1));
    *returnSize=num+1;
    for(i=0;i<=num;i++)
    {
        result[i]=getBitsOfNum(i);
    }
    return result;
}

#else

int * countBits(int num, int* returnSize)
{
    int i=0;
    int count=0;
    int range=1;
    int * result;
    *returnSize=num+1;
    result=malloc(sizeof(int)*(num+1));
    result[0]=0;
    for(i=1;i<=num;i++)
    {
        result[i]=result[count]+1;
        count++;
        if(count==range)
        {
            count=0;
            range=range<<1;
        }
    }
    return result;
}

#endif
