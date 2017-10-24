//Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
//

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct LsitNode * mergeList(struct ListNode * l1,struct ListNode * l2,struct ListNode ** result)
{
    if(l1==NULL&&l2==NULL)
    {
        *result=NULL;
    }
    else if(l1==NULL&&l2!=NULL)
    {
        *result=l2;
    }
    else if(l1!=NULL&&l2==NULL)
    {
        *result=l1;
    }
    else
    {
        *result=malloc(sizeof(struct ListNode *));
        if(l1->val<l2->val)
        {
            (*result)->val=l1->val;
            mergeList(l1->next,l2,&(*result)->next);
        }
        else
        {
            (*result)->val=l2->val;
            mergeList(l1,l2->next,&(*result)->next);
        }
    }
    return NULL;
}

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode * result;

    mergeList(l1,l2,&result);

    return result;
}
