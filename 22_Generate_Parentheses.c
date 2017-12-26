/*

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]

*/

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

 /**
  * Return an array of size *returnSize.
  * Note: The returned array must be malloced, assume caller calls free().
  */

 struct TreeNode2
 {
     char val;
     struct TreeNode2 *left;
     struct TreeNode2 *right;
 };

 int count=0;

 void buildTree(struct TreeNode2 * root,int n,int hadLeft,int hadRight)
 {
     if(hadLeft<n)       //右边分支（的数量小于n
     {
         root->left=malloc(sizeof(struct TreeNode2));
         root->left->val='(';
         root->left->left=NULL;
         root->left->right=NULL;
         buildTree(root->left,n,hadLeft+1,hadRight);
     }

     if(hadRight<hadLeft&&hadRight<n)        //左边分支）的数量小于已经填写的（的数量，并且小于总数n
     {
         root->right=malloc(sizeof(struct TreeNode2));
         root->right->val=')';
         root->right->left=NULL;
         root->right->right=NULL;
         buildTree(root->right,n,hadLeft,hadRight+1);
     }
 }

 int getNode(struct TreeNode2 * root)
 {
     int left=0,right=0;
     if(root->left==NULL&&root->right==NULL)
     {
         return 1;
     }
     if(root->left!=NULL)
     {
         left=getNode(root->left);
     }
     if(root->right!=NULL)
     {
         right=getNode(root->right);
     }
     return left+right;
 }

 void traverseTree(struct TreeNode * root,char * wayHead,char * wayLoc,char ** result)
 {
     if(root->left==NULL&&root->right==NULL)
     {
         *wayLoc=root->val;
         *(wayLoc+1)='\0';
         strcat(result[count],wayHead);
         count++;
     }
     if(root->left!=NULL)
     {
         *wayLoc=root->val;
         traverseTree(root->left,wayHead,wayLoc+1,result);
     }
     if(root->right!=NULL)
     {
         *wayLoc=root->val;
         traverseTree(root->right,wayHead,wayLoc+1,result);
     }
 }

 char** generateParenthesis(int n, int * returnSize) {
     struct TreeNode2 * root;
     struct TreeNode2 * root2;
     int i=0;
     char ** result;
     char * temp;
     char * temp2;

     root=malloc(sizeof(struct TreeNode2));
     root->val='(';
     root->left=NULL;
     root->right=NULL;
     buildTree(root,n,1,0);

     *returnSize=getNode(root);
     result=malloc(sizeof(char *)*(*returnSize));
     for(i=0;i<*returnSize;i++)
     {
         result[i]=malloc(sizeof(char)*2*n+1);
         result[i][0]='\0';
     }

     count=0;
     temp=malloc(sizeof(char)*2*n+1);
     temp2=temp;
     traverseTree(root,temp,temp2,result);

     return result;
 }
