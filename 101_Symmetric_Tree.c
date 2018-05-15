/*

Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following [1,2,2,null,3,null,3] is not:
    1
   / \
  2   2
   \   \
   3    3
Note:
Bonus points if you could solve it both recursively and iteratively.

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
  * Definition for a binary tree node.
  * struct TreeNode {
  *     int val;
  *     struct TreeNode *left;
  *     struct TreeNode *right;
  * };
  */
 bool compairTree(struct TreeNode *rootR,struct TreeNode *rootL)
 {
     if(rootR!=NULL&&rootL!=NULL)
     {
         if(rootR->val!=rootL->val)
         {
             return false;
         }

         compairTree(rootR->right,rootL->left);
         if(compairTree(rootR->right,rootL->left)==false)
         {
             return false;
         }

         if(compairTree(rootR->left,rootL->right)==false)
         {
             return false;
         }
     }
     else if(rootR!=rootL)
     {
         return false;
     }
     return true;
 }

 bool isSymmetric(struct TreeNode* root) {
     if(root!=NULL)
     {
         return compairTree(root->left,root->right);
     }
     return true;
 }
