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
    ListNode* middleNode(ListNode* head) 
    {
        // Hint :- take two pointers and move any one of it 2 steps forward and remained pointer single step respectively until pointer which is moving two steps forward reaches to the last node

        //initialize two pointers First and Last respectively
        ListNode* FirstPtr = head;
        ListNode* LastPtr = head;

        //condition
        while(FirstPtr != nullptr && FirstPtr -> next != nullptr)
        {
            FirstPtr = FirstPtr->next->next;       // double node traversal

            LastPtr = LastPtr -> next;  // Single node traversal
        } 

        return LastPtr;
    }
};