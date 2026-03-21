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
    // Function to reverse linked list
        ListNode* reverse(ListNode* head) 
        {
            ListNode* prev = nullptr;
            while (head) 
            {
                ListNode* next = head->next;
                head->next = prev;
                prev = head;
                head = next;
            }
        return prev;
    }

    ListNode* doubleIt(ListNode* head) 
    {
        // Step 1: Reverse the list
        head = reverse(head);

        ListNode* temp = head;
        int carry = 0;

        // Step 2: Multiply by 2
        while (temp) 
        {
            int val = temp->val * 2 + carry;
            temp->val = val % 10;
            carry = val / 10;

            if (!temp->next && carry) 
            {
                temp->next = new ListNode(carry);
                carry = 0;
                break;
            }
            temp = temp->next;
        }

        // Step 3: Reverse again
        return reverse(head);
    
    }
};