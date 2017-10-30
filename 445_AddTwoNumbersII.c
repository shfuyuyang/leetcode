/*

You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Follow up:
What if you cannot modify the input lists? In other words, reversing the lists is not allowed.

Example:

Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 8 -> 0 -> 7

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int getListNodeLen(struct ListNode * l)
{
    int result=0;
    while(l!=NULL)
    {
        l=l->next;
        result++;
    }
    return result;
}

#if 0   //将链表转换为整数的方法，时间复杂度暂时无法计算，但所能计算的链表长度有限

long long int listNodeToInt(struct ListNode * l)
{
    long long int result=0;
    while(l!=NULL)
    {
        result+=l->val;
        result*=10;
        l=l->next;
    }
    return result/10;
}

struct ListNode * intToListNode(long long int num)
{
    struct ListNode * result;
    long long int temp=num;
    result=malloc(sizeof(struct ListNode));

    result->val=temp%10;
    result->next=NULL;
    temp/=10;
    while(temp!=0)
    {
        struct ListNode * head;
        head=malloc(sizeof(struct ListNode));
        head->val=temp%10;
        head->next=result;
        result=head;
        temp/=10;
    }
    return result;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    long long int l1Int=0,l2Int=0;
    long long int result=0;
    struct ListNode * l;
    l1Int=listNodeToInt(l1);
    l2Int=listNodeToInt(l2);
    //printf("%d,%d",l1Int,l2Int);
    result=l1Int+l2Int;
    l=intToListNode(result);

    return l;
}

#else    //采用递归方式从后向前计算链表的和，同时将进位作为传出参数通过指针返回

struct ListNode * addTwoNumbersRet(struct ListNode * l1,struct ListNode * l2,int * ret)
{
    int lenL1=0,lenL2=0;
    int retNow=0;
    struct ListNode * result;

    result=malloc(sizeof(struct ListNode));
    lenL1=getListNodeLen(l1);
    lenL2=getListNodeLen(l2);

    if(l1->next==NULL&&l2->next==NULL)
    {
        result->val=(l1->val+l2->val)%10;
        result->next=NULL;
        *ret=(l1->val+l2->val)/10;
        return result;
    }

    if(lenL1>lenL2)
    {
        result->next=addTwoNumbersRet(l1->next,l2,&retNow);
        result->val=(l1->val+retNow)%10;
        *ret=(l1->val+retNow)/10;
    }
    else if(lenL1<lenL2)
    {
        result->next=addTwoNumbersRet(l1,l2->next,&retNow);
        result->val=(l2->val+retNow)%10;
        *ret=(l2->val+retNow)/10;
    }
    else
    {
        result->next=addTwoNumbersRet(l1->next,l2->next,&retNow);
        result->val=(l1->val+l2->val+retNow)%10;
        *ret=(l1->val+l2->val+retNow)/10;
    }
    return result;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode * result;
    int ret=0;
    result=malloc(sizeof(struct ListNode));

    result->next=addTwoNumbersRet(l1,l2,&ret);
    result->val=ret;

    if(ret==0)
    {
        result=result->next;
    }
    return result;
}

#endif
