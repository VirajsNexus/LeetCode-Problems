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
    ListNode* reverseList(ListNode* head) 
    {
        ListNode* DuplicateNode = new ListNode();

        ListNode* CurrentNode = head;

        while(CurrentNode != nullptr)
        {
            ListNode* nextNode = CurrentNode -> next;
            
            CurrentNode -> next = DuplicateNode -> next;

            DuplicateNode -> next = CurrentNode;

            CurrentNode = nextNode;

        }
        return DuplicateNode -> next;
    }
};