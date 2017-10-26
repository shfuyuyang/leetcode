/*

Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

测试案例：
80
[[4,5,7,7,4,6,7,3,1,4,8,9,7],
 [6,7,9,2,5,0,3,0,3,9,3,1,6],
 [8,3,8,4,6,2,9,6,0,6,4,7,9],
 [5,4,7,4,1,5,3,1,0,0,1,3,1],
 [7,5,4,8,3,2,3,1,8,2,4,8,0],
 [6,4,4,3,5,1,9,5,7,1,0,3,2],
 [0,3,5,6,4,4,3,0,4,8,5,8,9],
 [3,2,5,3,2,1,9,6,7,5,9,6,2],
 [6,9,2,9,3,5,5,9,3,9,5,6,2],
 [0,4,9,0,5,2,2,1,8,4,4,7,2],
 [3,4,1,0,6,9,1,9,1,5,6,6,6],
 [9,7,1,7,9,3,3,8,3,8,3,5,1],
 [1,1,6,8,3,9,3,6,1,1,8,3,2],
 [9,0,8,7,6,9,4,9,8,6,3,1,4],
 [6,0,9,4,3,0,7,1,1,1,1,6,9]]

77
[[9,9,0,8,9,0,5,7,2,2,7,0,8,0,2,4,8],
 [4,4,2,7,6,0,9,7,3,2,5,4,6,5,4,8,7],
 [4,9,7,0,7,9,2,4,0,2,4,4,6,2,8,0,7],
 [7,7,9,6,6,4,8,4,8,7,9,4,7,6,9,6,5],
 [1,3,7,5,7,9,7,3,3,3,8,3,6,5,0,3,6],
 [7,1,0,7,5,0,6,6,5,3,2,6,0,0,9,5,7],
 [6,5,6,3,8,1,8,6,4,4,3,4,9,9,3,3,1],
 [1,0,2,9,7,9,3,1,7,5,1,8,2,8,4,7,6],
 [9,6,7,7,4,1,4,0,6,5,1,9,0,3,2,1,7],
 [2,0,8,7,1,7,4,3,5,6,1,9,4,0,0,2,7],
 [9,8,1,3,8,7,1,2,8,3,7,3,4,6,7,6,6],
 [4,8,3,8,1,0,4,4,1,0,4,1,4,4,0,3,5],
 [6,3,4,7,5,4,2,2,7,9,8,4,5,6,0,3,9],
 [0,4,9,7,1,0,7,7,3,2,1,4,7,6,0,0,0]]

*/

int getMinPathSum(int ** grid,int startX,int startY,int gridRowSize,int gridColSize,int ** map)
{
    int right=0;
    int down=0;
    int result=0;

    if(map[startY][startX]!=-99)
    {
        return map[startY][startX];
    }

    if(startX<gridColSize)
    {
        right=getMinPathSum(grid,startX+1,startY,gridRowSize,gridColSize,map)+grid[startY][startX];
    }
    if(startY<gridRowSize)
    {
        down=getMinPathSum(grid,startX,startY+1,gridRowSize,gridColSize,map)+grid[startY][startX];
    }

    //此处做边界判断的时候不能根据right和down的值是否为零进行判断
    if(startX<gridColSize&&startY<gridRowSize)
    {
        result= right<=down?right:down;
    }
    else if(startX==gridColSize&&startY<gridRowSize)
    {
        result= down;
    }
    else if(startX<gridColSize&&startY==gridRowSize)
    {
        result= right;
    }
    else
    {
        result= grid[startY][startX];
    }

    map[startY][startX]=result;

    return result;
}

//采用动态规划方法
int minPathSum(int** grid, int gridRowSize, int gridColSize) {
    int result=0;
    int ** map=NULL;
    int i=0,j=0;
    map=malloc(sizeof(int *)*gridRowSize+1);


    for(i=0;i<=gridRowSize;i++)
    {
        *(map+i)=malloc(sizeof(int)*gridColSize);
        for(j=0;j<gridColSize;j++)
        {
            map[i][j]=-99;
        }
    }

    //动态规划方法，递归计算一个点到终点的距离。
    result=getMinPathSum(grid,0,0,gridRowSize-1,gridColSize-1,map);

    return result;
}
