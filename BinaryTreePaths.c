#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

char* intToString(int num)
{
    char * result;
    int temp=0;
    int len=0;
    temp=num;
    for(len=0;temp!=0;len++)
    {
        temp=temp/10;
    }
    result=malloc(sizeof(char)*(len+1));
    temp=num;
    *(result+len)='\0';
    for(;len>=0;len--)
    {
        *(result+len-1)=(char)((temp%10)+'0');
        temp=temp/10;
    }

    return result;
}

void getBinaryTreePaths(struct TreeNode* root,int * num)
{
    if(root==NULL)
    {
        return;
    }
    if(root->left==NULL&&root->right==NULL)
    {
        (*num)=(*num)+1;
        return;
    }
    getBinaryTreePaths(root->left,num);
    getBinaryTreePaths(root->right,num);
}

void getBinaryTreePathsString(struct TreeNode* root,int * num,char * dest)
{
    int val=0;
    char * str2;
    if(root==NULL)
    {
        return;
    }
    val=root->val;
    strcat(dest,"->");
    str2=intToString(val);
    strcat(dest,str2);
    if(root->left==NULL&&root->right==NULL)
    {
        (*num)=(*num)+1;
        return;
    }

    getBinaryTreePathsString(root->left,num,dest);
    getBinaryTreePathsString(root->right,num,dest);
}

char** binaryTreePaths(struct TreeNode* root, int* returnSize) {

    int path=0;
    int i=0;
    int val=0;
    val=root->val;
    char** result;
    getBinaryTreePaths(root,&path);
    *returnSize=path;
    result=malloc(sizeof(char*)*path);
    for(i=0;i<path;i++)
    {
        *(result+i)="1";//intToString(val);
        //getBinaryTreePathsString(root,&path,*(result+i));
    }

    return result;
}

void main()
{
    char * a;
    a=intToString(1234321);
    printf(a);
}
