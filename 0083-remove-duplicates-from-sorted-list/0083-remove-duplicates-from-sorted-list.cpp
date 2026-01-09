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
    ListNode* deleteDuplicates(ListNode* head) 
    {

        // IMP note : Linked list is already sorted means duplicate element is present exactly next to Operating node position 

        //TempPtr to Traverse Linked List
        ListNode* TempPtr = head;

        // Traverse till End
        while(TempPtr != nullptr && TempPtr -> next != nullptr)
        {
            // Check current node value with its next node that is it equal or not
            if(TempPtr -> val == TempPtr -> next -> val)
            {
                // Duplicate found
                // skip that next node and update next pointer 
                TempPtr ->next = TempPtr -> next -> next;
            }
            else
            {
                //Duplicate node not foud move TempPtr as normal(next node)
                TempPtr = TempPtr -> next;
            }

        } 
            return head;        // Updated linked list
    }   
};