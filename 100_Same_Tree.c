/*
Given two binary trees, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical and the nodes have the same value.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#if 0

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    bool resultLeft=false;
    bool resultRight=false;

    if(p==NULL&&q==NULL)
    {
        return true;
    }
    if(p==NULL||q==NULL)
    {
        return false;
    }

    if(p->val!=q->val)
    {
        return false;
    }
    resultLeft=isSameTree(p->left,q->left);
    resultRight=isSameTree(p->right,q->right);

    return resultLeft&&resultRight;
}

#else

bool isSameTree(struct TreeNode* p,struct TreeNode* q)
{
    if(p==NULL||q==NULL)
    {
        return p==q;
    }
    if(q->val==p->val)
    {
        return isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
    }
    return false;
}

#endif
