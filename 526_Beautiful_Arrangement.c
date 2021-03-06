/*

Suppose you have N integers from 1 to N. We define a beautiful arrangement as an array that is constructed by these N numbers successfully if one of the following is true for the ith position (1 <= i <= N) in this array:

The number at the ith position is divisible by i.
i is divisible by the number at the ith position.
Now given N, how many beautiful arrangements can you construct?

Example 1:
Input: 2
Output: 2
Explanation: 

The first beautiful arrangement is [1, 2]:

Number at the 1st position (i=1) is 1, and 1 is divisible by i (i=1).

Number at the 2nd position (i=2) is 2, and 2 is divisible by i (i=2).

The second beautiful arrangement is [2, 1]:

Number at the 1st position (i=1) is 2, and 2 is divisible by i (i=1).

Number at the 2nd position (i=2) is 1, and i (i=2) is divisible by 1.
Note:
N is a positive integer and will not exceed 15.

*/

int dfs(int *num,int numSize,int location_i)
{
    int sum=0;
    int i=0;
    int temp=0;
    for(i=0;i<numSize;i++)
    {
        //深度优先算法，判断当前位置的数是否合理，合理即保留当前位置并判断下一个位置（递归调用），不合理即在当前位置放入下一个数进行判断。
        if( num[i]!=0 && ( num[i]%(location_i+1)==0 || (location_i+1)%num[i]==0 ) )
        {
            
            if(location_i+1==numSize)
            {   //表示已经到了最后一个位置，当前路径为美丽的路径
                return 1;    
            }    
            temp=num[i];
            num[i]=0;
            sum+=dfs(num,numSize,location_i+1);
            num[i]=temp;
        }
    }
    return sum;
}

int countArrangement(int N) {
    int *num=calloc(N,sizeof(int));
    int i=0;
    int sum=0;

    for(i=0;i<N;i++)
    {
        num[i]=i+1;        
    }
    //调用深度优先算法
    sum=dfs(num,N,0);
    return sum;
}