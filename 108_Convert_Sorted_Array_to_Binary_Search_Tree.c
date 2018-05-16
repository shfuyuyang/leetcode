/*

Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example:

Given the sorted array: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    struct TreeNode *result=NULL;
    if(numsSize==0)
    {
        return NULL;
    }
    if(numsSize==1)
    {
        result=malloc(sizeof(struct TreeNode));
        result->val=nums[0];
        result->left=NULL;
        result->right=NULL;
        return result;
    }
    if(numsSize==2)
    {
        result=malloc(sizeof(struct TreeNode));
        result->val=nums[1];
        result->left=malloc(sizeof(struct TreeNode));
        result->left->val=nums[0];
        result->left->left=NULL;
        result->left->right=NULL;
        result->right=NULL;
        return result;
    }
    if(numsSize==3)
    {
        result=malloc(sizeof(struct TreeNode));
        result->val=nums[1];
        result->left=malloc(sizeof(struct TreeNode));
        result->left->val=nums[0];
        result->left->left=NULL;
        result->left->right=NULL;

        result->right=malloc(sizeof(struct TreeNode));
        result->right->val=nums[2];
        result->right->left=NULL;
        result->right->right=NULL;
        return result;
    }
    result=malloc(sizeof(struct TreeNode));
    result->val=nums[numsSize/2];
    result->left=sortedArrayToBST(nums,numsSize/2);
    result->right=sortedArrayToBST(nums+numsSize/2+1,numsSize-numsSize/2-1);
    return result;
}
