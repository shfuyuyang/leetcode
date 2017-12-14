/*
Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

Find the maximum area of an island in the given 2D array. (If there is no island, the maximum area is 0.)

Example 1:
[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]
Given the above grid, return 6. Note the answer is not 11, because the island must be connected 4-directionally.
Example 2:
[[0,0,0,0,0,0,0,0]]
Given the above grid, return 0.
Note: The length of each dimension in the given grid does not exceed 50.
*/

int getArea(int** grid,int gridRowSize, int gridColSize,int i,int j)
{
    int up=0,down=0,left=0,right=0;

    if(grid[i][j]==0)
    {
        return 0;
    }
    //printf("(%d,%d),",i,j);
    grid[i][j]=0;
    //将原点清零目的在于减少后续的运算
    if(i>0)
    {
        up=getArea(grid,gridRowSize,gridColSize,i-1,j);
    }
    if(i<(gridRowSize-1))
    {
        down=getArea(grid,gridRowSize,gridColSize,i+1,j);
    }
    if(j>0)
    {
        left=getArea(grid,gridRowSize,gridColSize,i,j-1);
    }
    if(j<(gridColSize-1))
    {
        right=getArea(grid,gridRowSize,gridColSize,i,j+1);
    }

    return up+down+left+right+1;
}

int maxAreaOfIsland(int** grid, int gridRowSize, int gridColSize) {

    int i=0,j=0;
    int max=0;
    int temp=0;
    for(i=0;i<gridRowSize;i++)
    {
        for(j=0;j<gridColSize;j++)
        {
            if(grid[i][j]==1)
            {
                //printf("%d,%d\n",i,j);
                //printf("L:");
                temp=getArea(grid,gridRowSize,gridColSize,i,j);
                //printf("%d\n",temp);
                if(temp>max)
                {
                    max=temp;
                }

            }
        }
    }
    return max;
}
