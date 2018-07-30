/*

Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Note: A leaf is a node with no children.

Example:

Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
return its minimum depth = 2.

*/

int minDepth(struct TreeNode* root) {
    int left=0;
    int right=0;
    if(root==NULL)
    {
        return 0;
    }
    left=minDepth(root->left);
    right=minDepth(root->right);
    if(left*right!=0)       //不为0选择较小的返回
    {
        return (left<right?left:right)+1;
    }
    else                        //有一个不为0，则返回不为零的那个
    {
        return left+right+1;
    }
}
