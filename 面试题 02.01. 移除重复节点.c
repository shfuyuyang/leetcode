/*
编写代码，移除未排序链表中的重复节点。保留最开始出现的节点。

示例1:

 输入：[1, 2, 3, 3, 2, 1]
 输出：[1, 2, 3]
示例2:

 输入：[1, 1, 1, 1, 2]
 输出：[1, 2]
提示：

链表长度在[0, 20000]范围内。
链表元素在[0, 20000]范围内。
进阶：

如果不得使用临时缓冲区，该怎么解决？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-duplicate-node-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#if 0

struct ListNode* removeDuplicateNodes(struct ListNode* head){
    if(head!=NULL)
    {
        struct ListNode *result=NULL;
        struct ListNode *resultTemp=NULL;

        while(head!=NULL)
        {
            if(result==NULL)
            {
                result=malloc(sizeof(struct ListNode));
                result->val=head->val;
                result->next=NULL;
            }
            resultTemp=result;
            while(resultTemp!=NULL)
            {
                if(resultTemp->val==head->val)
                {
                    break;
                }

                if(resultTemp->next==NULL)
                {
                    resultTemp->next=malloc(sizeof(struct ListNode));
                    resultTemp->next->val=head->val;
                    resultTemp->next->next=NULL;
                    resultTemp=resultTemp->next;
                    break;
                }
                resultTemp=resultTemp->next;
            }
            head=head->next;
        }
        return result;
    }
    return head;
}

#else

struct ListNode* removeDuplicateNodes(struct ListNode* head)
{
    int table[20000]={0};
    struct ListNode *temp=head;
    struct ListNode *last=head;

    while(head!=NULL)
    {
        if(table[head->val]==0)
        {
            table[head->val]=1;
            last=head;
            head=head->next;
        }
        else
        {
            last->next=head->next;
            head=head->next;
            if(head==NULL)
            {
                return  temp;
            }
        }
    }
    return  temp;
}

#endif
