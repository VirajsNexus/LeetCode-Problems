/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution 
{
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) 
    {
        // Step 1: reach node just before 'a'
        ListNode* prevA = list1;
        for(int i = 0; i < a - 1; i++) 
        {
            prevA = prevA->next;
        }

        // Step 2: reach node 'b'
        ListNode* currB = prevA;
        for(int i = a - 1; i <= b; i++) 
        {
            currB = currB->next;
        }

        // currB is now (b+1)th node
        ListNode* nextB = currB;

        // Step 3: find last node of list2
        ListNode* tail2 = list2;
        while(tail2->next != NULL) 
        {
            tail2 = tail2->next;
        }

        // Step 4: connections
        prevA->next = list2;
        tail2->next = nextB;

        return list1;
    }
};