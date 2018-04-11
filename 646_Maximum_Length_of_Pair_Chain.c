/*
You are given n pairs of numbers. In every pair, the first number is always smaller than the second number.

Now, we define a pair (c, d) can follow another pair (a, b) if and only if b < c. Chain of pairs can be formed in this fashion.

Given a set of pairs, find the length longest chain which can be formed. You needn't use up all the given pairs. You can select pairs in any order.

Example 1:
Input: [[1,2], [2,3], [3,4]]
Output: 2
Explanation: The longest chain is [1,2] -> [3,4]
*/

#define EMPTY   0
#define START   1
#define MID     2
#define END     3

#define SUCCESS 1;
#define FAIL    0;

int *map;
int range=3000;
int offset=1500;

int *table1;
int *table2;

int addPair(int * pair)
{
    int i=0;

    for(i=pair[0];i<=pair[1];i++)
    {
        if(map[i+offset]!=EMPTY)
        {
            return FAIL;
        }
    }

    for(i=pair[0];i<=pair[1];i++)
    {
        if(i==pair[0])
        {
            map[i+offset]=START;
        }
        else if(i==pair[1])
        {
            map[i+offset]=END;
        }
        else
        {
            map[i+offset]=MID;
        }
    }
    return SUCCESS;
}

void delPair(int * pair)
{
    int i=0;

    for(i=pair[0];i<=pair[1];i++)
    {
        map[i+offset]=EMPTY;
    }
}

int dp(int ** pairs,int pairsRowSize)
{
    int result1=0;
    int result2=0;
    int i=0;
    if(pairsRowSize==0)
    {
        //计算map结果
        for(i=0;i<=range;i++)
        {
            if(map[i]==START)
            {
                result1++;
            }
        }
        return result1;
    }

    if(table1[pairsRowSize-1]==-1)
    {
        //首先把这个部分加入串中计算结果
        if(1==addPair(*pairs))
        {
            result1=dp(pairs+1,pairsRowSize-1);
            delPair(pairs[0]);
        }

        //然后计算这个部分不在串中的结果
        result2=dp(pairs+1,pairsRowSize-1);
        table1[pairsRowSize-1]=result1>result2?result1:result2;
    }
    else
    {
        return table1[pairsRowSize-1];
    }
    return result1>result2?result1:result2;
}

int findLongestChain(int** pairs, int pairsRowSize, int pairsColSize) {
    int i=0;
    map=malloc(sizeof(int)*range);

    table1=malloc(sizeof(int)*pairsRowSize);
    table2=malloc(sizeof(int)*pairsRowSize);

    for(i=0;i<pairsRowSize;i++)
    {
        table1[i]=-1;
        table2[i]=-1;
    }

    for(i=0;i<range;i++)
    {
        map[i]=EMPTY;
    }
    return dp(pairs,pairsRowSize);
}
