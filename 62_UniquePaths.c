/*

A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?

*/

int **result;
int count=0;

void runMap(int m,int n,int m_i,int n_i,int **map)
{
    if(map[m_i][n_i]==-999)
    {
        count++;
        return;
    }
    else
    {
        if(m_i<m-1)
        {
            if(result[m_i+1][n_i]!=-99)
            {
                count+=result[m_i+1][n_i];
            }
            else
            {
                int temp=count;
                runMap(m,n,m_i+1,n_i,map);
                result[m_i+1][n_i]=count-temp;
            }
        }
        if(n_i<n-1)
        {
            if(result[m_i][n_i+1]!=-99)
            {
                count+=result[m_i][n_i+1];
            }
            else
            {
                int temp=count;
                runMap(m,n,m_i,n_i+1,map);
                result[m_i][n_i+1]=count-temp;
            }
        }
    }
}

int uniquePaths(int m, int n) {
    int ** map;
    int i=0,j=0;


    map=malloc(sizeof(int*)*m);
    result=malloc(sizeof(int*)*m);
    for(i=0;i<m;i++)
    {
        map[i]=malloc(sizeof(int)*n);
        result[i]=malloc(sizeof(int)*n);
        for(j=0;j<n;j++)
        {
            result[i][j]=-99;
            map[i][j]=0;
        }
    }
    count=0;
    map[m-1][n-1]=-999;
    runMap(m,n,0,0,map);

    return count;
}
