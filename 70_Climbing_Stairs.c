/*
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Note: Given n will be a positive integer.
*/

//线性时间求斐波那契数列，方法一用递归+哈希表，方法二采用正向罗列，空间换时间。
#if 0
int hashtable[100]={0};
int climbStairs(int n) {
    int res1=0;
    int res2=0;
    if(n==0)
    {
        return 1;
    }
    if(n==1)
    {
        return 1;
    }

    if(hashtable[n-1]==0)
    {
        res1=climbStairs(n-1);
        hashtable[n-1]=res1;
    }
    if(hashtable[n-2]==0)
    {
        res2=climbStairs(n-2);
        hashtable[n-2]=res2;
    }
    return hashtable[n-1]+hashtable[n-2];
}
#else
int climbStairs(int n) {
    int i=0;
    int *list=malloc(sizeof(int)*n);
    if(n==0)
    {
        return 1;
    }
    if(n==1)
    {
        return 1;
    }
    list[0]=1;
    list[1]=1;
    for(i=2;i<n;i++)
    {
        list[i]=list[i-1]+list[i-2];
    }
    return list[i-1]+list[i-2];
}
#endif
