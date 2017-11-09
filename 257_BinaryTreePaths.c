/*
Given a binary tree, return all root-to-leaf paths.

For example, given the following binary tree:
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

//回溯法
//http://www.cnblogs.com/zhanghaiba/p/3536534.html

//struct ListNode
//{
//    int val;
//    struct ListNode * next;
//};

//求出一个二叉树中一共有多少个叶子节点，即路径的数目
int getPaths(struct TreeNode * root)
{
    int left=0,right=0;
    if(root->left==NULL&&root->right==NULL)
    {
        return 1;
    }
    if(root->left!=NULL)
    {
        left=getPaths(root->left);
    }
    if(root->right!=NULL)
    {
        right=getPaths(root->right);
    }
    return left+right;
}

//将整型转换为字符串，其中需要考虑到负数的情况，此部分代码有优化空间
char * intToString(int num)
{
    int i=0,l=0;
    int temp=0;
    char * result;
    char * pre;//返回字符串前缀，用来存储符号
    int flag=0;

    if(num==0)
    {
        return "0";
    }

    if(num<0)
    {
        temp=abs(num);
        num=temp;
        pre=malloc(sizeof(char)*2);
        pre[0]='-';
        pre[1]='\0';
    }
    else
    {
        temp=num;
        pre=malloc(sizeof(char));
        pre[0]='\0';
    }

    while(temp!=0)
    {
        l++;
        temp=temp/10;
    }
    result=malloc(sizeof(char)*(l+1));
    result[l]='\0';

    for(i=l-1;i>=0;i--)
    {
        result[i]=(char)((num%10)+0x30);
        num=num/10;
    }

    strcat(pre,result);

    return pre;
}

//将链表转换成字符串，中间用“->”连接
char * listNodeToString(struct ListNode * head)
{
    char * result=NULL;
    char * temp;
    int aa=0;
    result=malloc(sizeof(char));
    result[0]='\0';
    while(head!=NULL)
    {
        aa=head->val;
        temp=intToString(aa);
        strcat(result,temp);
        head=head->next;
        if(head!=NULL)  //最后一个节点后面不用增加“->”
        {
            strcat(result,"->");
        }
    }
    return result;
}

int count=0;

//递归调用，遍历二叉树。每遍历一个节点，就将这个节点的数据加入链表。如果这个节点是叶子节点，则直接将当前链表中的内容转化为字符串，然后存入buff
void binaryTreePathOut(struct TreeNode * root,char ** result,struct ListNode * head,struct ListNode * location)
{
    location->val=root->val;    //location用来记录链表走到的位置
    location->next=NULL;        //为了避免requires 8 byte alignment的报错
    if(root->left==NULL&&root->right==NULL)
    {
        //说明到了叶子节点，直接将到此为止的链表转换成字符串存储
        result[count]=malloc(sizeof(char));
        result[count][0]='\0';
        strcat(result[count],listNodeToString(head));
        count++;
        return;
    }

    location->next=malloc(sizeof(struct ListNode));
    location->next->next=NULL;
    //在进入下一个二叉树节点的时候链表当前位置被初始化，之前记录的这个节点之后的路径被丢弃，只保留这个节点之前的路径
    if(root->left!=NULL)
    {
        binaryTreePathOut(root->left,result,head,location->next);
    }
    if(root->right!=NULL)
    {
        binaryTreePathOut(root->right,result,head,location->next);
    }
}

char** binaryTreePaths(struct TreeNode* root, int* returnSize) {


    struct ListNode * head;     //定义一条链表，用来记录当前路径的所有节点
    struct ListNode * location;
    char ** result;
    char * str;

    if(root==NULL)
    {
        return NULL;
    }

    count=0;

    *returnSize=getPaths(root);

    result=(char **)malloc(sizeof(char*)*(*returnSize));
    head=malloc(sizeof(struct ListNode));
    location=head;

    binaryTreePathOut(root,result,head,location);

    free(head);

    return result;
}
