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
        ListNode* findMid(ListNode* head)
        {
            ListNode* slow = head;
            ListNode* fast = head -> next;

            while(fast && fast -> next)
            {
                slow = slow -> next;
                fast =  fast -> next -> next;
            }
            return slow;
        }

    ListNode* merge(ListNode* left, ListNode* right)
    {
        ListNode temp(0);
        ListNode* tail = &temp;

        while(left && right)
        {
            if(left -> val <= right -> val)
            {
                tail -> next = left;
                left = left -> next;
            }
            else
            {
                tail -> next = right;
                right = right -> next;
            }
           tail = tail -> next;
        }

        if(left)
        {
            tail -> next = left;
        }
        else
        {
            tail -> next = right;
        }
        return temp.next;
    }

    ListNode* sortList(ListNode* head) 
    {
        if(head == nullptr || head -> next == nullptr)
            return head;

        //Split list
        ListNode* mid = findMid(head);
        ListNode* right = mid -> next;
        mid -> next = nullptr;
        ListNode* left = head;

        //sort both halves
        left = sortList(left);
        right = sortList(right);

        //Merge Sorted halves
        return merge(left, right);
    }
};