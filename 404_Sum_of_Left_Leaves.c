/*

Find the sum of all left leaves in a given binary tree.

Example:

    3
   / \
  9  20
    /  \
   15   7

There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.


*/

int getSum(struct TreeNode* root,int flag)
{
    int sum=0;
    if(root==NULL)
    {
        return 0;
    }
    if(root->left==NULL&&root->right==NULL)
    {
        return flag*root->val;        
    }
    if(root->left!=NULL)
    {
        sum+=getSum(root->left,1);  
    }
    if(root->right!=NULL)
    {
        sum+=getSum(root->right,0);
    }
    return sum;
}

int sumOfLeftLeaves(struct TreeNode* root) {
    return getSum(root,0);
}