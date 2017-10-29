//
//翻转链表
//

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#if 0

//循环调用方法
struct ListNode* reverseList(struct ListNode* head)
{
    struct ListNode * listPre;
    struct ListNode * listTemp;
    struct ListNode * listNext;

    listPre=head;
    if(head==NULL||head->next==NULL)
    {
        return listPre;
    }
    else
    {
        listTemp=head->next;
    }
    head->next=NULL;

    while(listTemp!=NULL)
    {
        listNext=listTemp->next;
        listTemp->next=listPre;
        listPre=listTemp;
        listTemp=listNext;
    }
    return listPre;
}

 #else

//递归调用方法
struct ListNode* reverseList(struct ListNode* head)
{
    if(head==NULL||head->next==NULL)
    {
        return head;
    }
    else
    {
        struct ListNode * listReturn;   //
        listReturn=reverseList(head->next);         //先用递归的方式获得最后一个点，然后作为每次的返回值
        head->next->next=head;                      //将当前操作的节点设置为后一个节点的后续节点
        head->next=NULL;                            //将当前节点的后续节点清空
        return listReturn;
    }
}

 #endif
