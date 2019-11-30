/*

Given a non-negative integer represented as non-empty a singly linked list of digits, plus one to the integer.

You may assume the integer do not contain any leading zero, except the number 0 itself.

The digits are stored such that the most significant digit is at the head of the list.

Example :

Input: [1,2,3]
Output: [1,2,4]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/plus-one-linked-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int isPlusOne(struct ListNode *head)
{
    int res=0;
    if(head->next!=NULL)
    {
        head->val+=isPlusOne(head->next);
    }
    else
    {
        head->val++;
    }
    if(head->val>=10)
    {
        res=head->val/10;
        head->val=head->val%10;
    }
    return res;
}

struct ListNode* plusOne(struct ListNode* head){
    struct ListNode *res=head;
    int temp=isPlusOne(head);
    if(temp!=0)
    {
        res=malloc(sizeof(struct ListNode));
        res->val=temp;
        res->next=head;
    }
    return res;
}
