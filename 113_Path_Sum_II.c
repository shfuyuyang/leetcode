/*
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

Note: A leaf is a node with no children.

Example:

Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \    / \
7    2  5   1
Return:

[
   [5,4,11,2],
   [5,8,4,5]
]
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
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

struct List
{
    int val;
    struct List *next;
};

int ** result=NULL;
int *resultSize=NULL;
int result_i=0;
int buffSize=1000;

int getPath(struct TreeNode *root,int sumNow,int sumAll,struct List *node,struct List *head)
{
    int left=0;
    int right=0;
    if(root==NULL)
    {
        return 0;
    }
    node->val=root->val;
    node->next=malloc(sizeof(struct List));
    node->next->val=0;
    node->next->next=NULL;
    if((root->left==NULL)&&(root->right==NULL)&&sumAll==root->val)
    {
        int i=0;
        result[result_i]=malloc(sizeof(int)*buffSize);
        for(i=0;(head!=NULL);i++)
        {
            result[result_i][i]=head->val;
            head=head->next;
            if(head==NULL)
            {
                break;
            }
        }
        resultSize[result_i]=i;
        result_i++;
        return 1;
    }


    left=getPath(root->left,root->val,sumAll-root->val,node->next,head);
    right=getPath(root->right,root->val,sumAll-root->val,node->next,head);
    return left+right;
}

int** pathSum(struct TreeNode* root, int sum, int** columnSizes, int* returnSize) {

    struct List *list=malloc(sizeof(struct List));
    list->val=0;
    list->next=NULL;

    result=malloc(sizeof(int*)*buffSize);
    resultSize=malloc(sizeof(int)*buffSize);
    result_i=0;
    getPath(root,0,sum,list,list);
    *returnSize=result_i;
    *columnSizes=resultSize;

    return result;
}
