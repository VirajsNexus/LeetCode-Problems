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
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode* TempNode = new ListNode(0, head);

        // Initializing two pointers
        ListNode* FirstPtr = TempNode;
        ListNode* SecondPtr = TempNode;

        //Moving First Pointer n nodes ahead of Second Pointer
        while(n--)
        {
            FirstPtr = FirstPtr -> next;
        }

        // Gap of n nodes created
        //Let's Move both pointers till the First Reaches to the end
        while(FirstPtr -> next != nullptr)
        {
            SecondPtr = SecondPtr -> next;
            FirstPtr = FirstPtr -> next;
        }

        // Now Second pointer is at one node before deleting node
        ListNode* DeleteNode = SecondPtr -> next;
        SecondPtr -> next = SecondPtr -> next -> next;

        delete DeleteNode;

        ListNode* Head2 = TempNode -> next;
        delete TempNode;

        return Head2;
        }
};