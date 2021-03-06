/*
You are given a list of non-negative integers, a1, a2, ..., an, and a target, S.
 Now you have 2 symbols + and -. For each integer,
 you should choose one from + and - as its new symbol.

Find out how many ways to assign symbols to make sum of integers equal to target S.

Example 1:
Input: nums is [1, 1, 1, 1, 1], S is 3.
Output: 5
Explanation:

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3

There are 5 ways to assign symbols to make the sum of nums be target 3.
Note:
The length of the given array is positive and will not exceed 20.
The sum of elements in the given array will not exceed 1000.
Your output answer is guaranteed to be fitted in a 32-bit integer.
*/

#if 0

struct BTMap
{
    int val;
    struct BTMap *  left;   //-
    struct BTMap * right;   //+
};

int count=0;

void scan(struct BTMap * root,int * nums,int numsSize,int s,int level)
{
    if(numsSize>1)
    {
        root->left=malloc(sizeof(struct BTMap));
        root->right=malloc(sizeof(struct BTMap));
        
        root->left->val=root->val-nums[0];
        root->left->left=NULL;
        root->left->right=NULL;
        scan(root->left,nums+1,numsSize-1,s,level+1);
        
        root->right->val=root->val+nums[0];
        root->right->left=NULL;
        root->right->right=NULL;
        scan(root->right,nums+1,numsSize-1,s,level+1);
    }
    else
    {
        if(root->val+nums[0]==s)
        {
            count++;
        }
        if(root->val-nums[0]==s)
        {
            count++;
        }
    }
}

int findTargetSumWays(int* nums, int numsSize, int S) {
    struct BTMap * root;
    count=0;
    root=malloc(sizeof(struct BTMap));
    root->val=0;
    root->left=NULL;
    root->right=NULL;
    scan(root,nums,numsSize,S,0);
    return count;
}

#else 

int count=0;
int **map;
int *numsHead=0;
int numsSizeBak=0;

struct HashNode
{
    int sum;
    int val;
    struct HashNode * next;
};

int searchMap(int numsIndex,int sum)
{
    return map[numsIndex][sum+1000];
}

void addMap(int numsIndex,int sum,int val)
{
    map[numsIndex][sum+1000]=val;
}

int dp(int * nums,int numsSize,int s,int sum)
{
    int sum1=0;
    int sum2=0;
    if(numsSize>1)
    {
        sum1=searchMap(nums+1-numsHead,sum+nums[0]);
        sum2=searchMap(nums+1-numsHead,sum-nums[0]);
        if(sum1==-99999)
        {
            sum1=dp(nums+1,numsSize-1,s,sum+nums[0]);
            addMap(nums+1-numsHead,sum+nums[0],sum1);
        }
        if(sum2==-99999)
        {
            sum2=dp(nums+1,numsSize-1,s,sum-nums[0]);
            addMap(nums+1-numsHead,sum-nums[0],sum2);
        }
    }
    else
    {
        if(sum+nums[0]==s)
        {
            sum1=1;
        }
        if(sum-nums[0]==s)
        {
            sum2=1;
        }
    }
    return sum1+sum2;
}

int findTargetSumWays(int* nums, int numsSize, int S) 
{
    int i=0;
    int j=0;
    count=0;
    numsHead=nums;
    numsSizeBak=numsSize;
    map=malloc(sizeof(int *)*numsSize);
    
    for(i=0;i<numsSize;i++)
    {
        map[i]=malloc(sizeof(int)*2000);
        for(j=0;j<2000;j++)
        {
            map[i][j]=-99999;
        }
    }
    
    return dp(nums,numsSize,S,0);
}
    

#endif
