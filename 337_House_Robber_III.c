/*

The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the "root." Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that "all houses in this place forms a binary tree". It will automatically contact the police if two directly-linked houses were broken into on the same night.

Determine the maximum amount of money the thief can rob tonight without alerting the police.

Example 1:
     3
    / \
   2   3
    \   \
     3   1
Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
Example 2:
     3
    / \
   4   5
  / \   \
 1   3   1
Maximum amount of money the thief can rob = 4 + 5 = 9.

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

#define tableLen     1000
#define defaultVal  -487326

struct TreeTable
{
    int val;
    int sumL0;
    int sumL1;
    int sumR0;
    int sumR1;
    struct TreeNode * point;
    struct TreeTable * next;
};

int travelTree(struct TreeTable ** hashTable,struct TreeNode * root,int flag)
{
    int sum1=0;
    int sum2=0;
    int sum3=0;
    int sum4=0;
    int sum5=0;
    int sum6=0;
    struct TreeTable * temp;
    struct TreeTable * tempLast;
    if(root==NULL)
    {
        return 0;
    }

    temp=hashTable[root->val%tableLen];     //找到二叉树当前值在哈希表中的对应位置
    tempLast=temp;                          //并且将这个节点进行备份

    //首先判断，这个位置是否被存储过数据。如果存储过则进行查找，如果没找到或没存储过，temp移动到一个空位置进行存储接下来的结果
    if(temp->val!=defaultVal)
    {
        //printf("L1\n");
        while(temp!=NULL&&temp->point!=root)
        {
            //printf("L2\n");
            tempLast=temp;
            temp=temp->next;
        }
        if(temp!=NULL&&temp->val==root->val)
        {
            //printf("L3\n");
            sum1=temp->sumL0;
            sum2=temp->sumR0;
            sum3=temp->sumL1;
            sum4=temp->sumR1;

            if(flag==1)
            {
                return root->val+temp->sumL0+temp->sumR0;
            }
        }
    }

    //flag为1表示当前节点偷窃，则下个节点必须不能偷窃
    if(flag==1)
    {
        //到此步骤说明flag为0的情况这时没有找到值，需要进行计算并存入哈希表
        sum1=travelTree(hashTable,root->left,0);
        sum2=travelTree(hashTable,root->right,0);

        temp->val=root->val;
        temp->point=root;
        temp->sumL0=sum1;
        temp->sumR0=sum2;
        temp->sumL1=sum3;
        temp->sumR1=sum4;
        temp->next=malloc(sizeof(struct TreeTable));
        temp->next->val=defaultVal;
        temp->next->point=NULL;
        temp->next->next=NULL;

        return sum1+sum2+root->val;
    }
    else
    {
        //printf("%d\n",temp->val);
        if(temp==NULL||temp->val==defaultVal)
        {
            //printf("L4\n");
            //到此步骤说明flag为1的情况这时没有找到值，需要进行计算并存入哈希表
            temp=tempLast;
            sum1=travelTree(hashTable,root->left,0);
            sum2=travelTree(hashTable,root->right,0);

            sum3=travelTree(hashTable,root->left,1);
            sum4=travelTree(hashTable,root->right,1);

            temp->val=root->val;
            temp->point=root;
            temp->sumL0=sum1;
            temp->sumR0=sum2;
            temp->sumL1=sum3;
            temp->sumR1=sum4;
            temp->next=malloc(sizeof(struct TreeTable));
            temp->next->val=defaultVal;
            temp->next->point=NULL;
            temp->next->next=NULL;
        }
        //printf("L5\n");
        //printf("%d,%d,%d,%d\n",sum1,sum2,sum3,sum4);

        sum5=(sum1>sum3?sum1:sum3);
        sum6=(sum2>sum4?sum2:sum4);

        //flag==3表示这是第一次调用的根节点
        if(flag==3)
        {
            return (sum1+sum2+root->val)>(sum5+sum6)?(sum1+sum2+root->val):(sum5+sum6);
        }

        return sum5+sum6;
    }
}

int rob(struct TreeNode* root) {

    int sum=0;
    int i=0;
    struct TreeTable ** hashTable;
    hashTable=malloc(sizeof(struct TreeTable *)*tableLen);

    for(i=0;i<tableLen;i++)
    {
        hashTable[i]=malloc(sizeof(struct TreeTable));
        hashTable[i]->val=defaultVal;
        hashTable[i]->point=NULL;
        hashTable[i]->next=NULL;
    }

    sum=travelTree(hashTable,root,3);

    return sum;

}
