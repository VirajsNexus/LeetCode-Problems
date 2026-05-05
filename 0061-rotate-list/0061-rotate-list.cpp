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
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if(NULL == head || NULL == head -> next)
            return head;

        //find length of list
        int n = 0;
        ListNode* temp = head;
        while(temp != NULL)
        {
            n++;
            temp = temp -> next;
        }    

        //minimize repetitive rotations
        k = k % n;
        if(k == 0)
            return head;
        
        //final k times rotation
        while(k--)
        {
            ListNode* previous = NULL;
            ListNode* current = head;

            //traverse to last node
            while(current -> next != NULL)
            {
                previous = current;
                current = current -> next;
            }

            //Last becomes first
            previous -> next = NULL;
            current -> next = head;
            head = current;
        }
        return head;
    }
};