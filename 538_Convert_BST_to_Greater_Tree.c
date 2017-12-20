/*

Given a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus sum of all keys greater than the original key in BST.

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int sum=0;
void rightBST(struct TreeNode * root)
{
    int temp=0;
    if(root==NULL)
    {
        return 0;
    }
    rightBST(root->right);
    root->val=root->val+sum;
    sum=root->val;
    rightBST(root->left);
}

struct TreeNode* convertBST(struct TreeNode* root) {
    sum=0;
    rightBST(root);
    return root;
}
