/*
Given the root of a tree, you are asked to find the most frequent subtree sum.
The subtree sum of a node is defined as the sum of all the node values formed
by the subtree rooted at that node (including the node itself).
So what is the most frequent subtree sum value?
If there is a tie, return all the values with the highest frequency in any order.
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

int hashSize=2000;      //设定hash表数组的大小，

struct hashNode     //定义hash表单个元素
{
    int key;
    int val;
    struct hashNode *next;
};

int getTreeNode(struct TreeNode * root)     //获取节点数
{
    if(root==NULL)
    {
        return 0;
    }
    return getTreeNode(root->left)+getTreeNode(root->right)+1;
}

int getSubtreeSum(struct hashNode ** sumTable,int offset,int *max,struct TreeNode * root)
{
    int sum=0;
    struct hashNode *temp;
    struct hashNode *tempLast;
    tempLast=NULL;
    if(root==NULL)
    {
        return 0;
    }
    //递归调用
    sum=getSubtreeSum(sumTable,offset,max,root->left)+getSubtreeSum(sumTable,offset,max,root->right)+root->val;

    //先计算出当前节点的和所在hash表中位置，取出链表第一个节点
    temp=sumTable[sum%offset+offset];
    while(temp!=NULL&&temp->key!=sum)   //寻找存储节点
    {
        //按顺序循环判断链表中的节点，找到一个节点的值与当前的值相等，或一个空节点，用来存储当前的值
        tempLast=temp;
        temp=temp->next;
    }
    if(temp==NULL)      //说明是一个没有存储过的节点
    {
        temp=malloc(sizeof(struct hashNode));   //为节点申请空间
        if(tempLast!=NULL)
        {
            tempLast->next=temp;        //将存储节点的上一个节点指向初始化后的存储节点
        }
        else                    //如果为NULL则表示这个节点为链表中的第一个节点
        {
            sumTable[sum%offset+offset]=temp;
        }
        //初始化这个节点
        temp->key=sum;
        temp->val=0;
        temp->next=NULL;
    }
    temp->val+=1;       //频率统计+1
    if(temp->val>(*max))    //计算最大频率
    {
        *max=temp->val;
    }

    return sum;
}

int* findFrequentTreeSum(struct TreeNode* root, int* returnSize) {
    int i=0;
    struct hashNode **sumTable;
    struct hashNode * temp;
    int offset=hashSize/2;
    int max=-1;
    int *result;
    result=malloc(sizeof(int)*getTreeNode(root));
    sumTable=malloc(sizeof(struct hashNode)*hashSize);
    for(i=0;i<hashSize;i++)
    {
        sumTable[i]=NULL;
    }

    getSubtreeSum(sumTable,offset,&max,root);

    for(i=0;i<hashSize;i++)
    {
        if(sumTable[i]!=NULL)   //说明此处有数据
        {
            temp=sumTable[i];   //先复制第一个元素
            while(temp!=NULL)   //循环查找直至这个链表的最末尾
            {
                if(temp->val==max)      //如果获取到了符合条件的值（max为最高的频率数），则添加到返回数组中
                {
                    result[*returnSize]=temp->key;
                    *returnSize+=1;
                }
                temp=temp->next;        //继续处理下一个节点
            }
        }
    }

    return result;
}
