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
        //Two pointers Technique

        // Case 1 - Empty List or Single node linked list
        if(NULL == head || NULL == head -> next)
        {
            return head;
        }

        // Now We know that linked list is present and having 2 or more nodes
        //calculate length of Linked List for travesing purpose
        ListNode* Current = head;       //Current ptr initialized and placed at head
        int length = 0;                 // initially length  = 0
        while(Current)
        {
            ++length;
            Current = Current ->next;
        }
         //Handling 'k'
         // Total rotations without optimization = length of linked list + k
         // Here we can see that we can get our expected output just doing k rotations, no need of length of linked list while for rotations

         // optimized K
         k %= length;       // returns optimized count of linked list that we need

        if(k == 0)          // no need of rotation 
        {
            return head;
        }

        // finding rotation point using two pointers first and last respectively
        //Initialize First and Last Pointers
        ListNode* First = head;
        ListNode* Last = head;


        // move First pointer k steps ahead to create gap
        while(k--)
        {
            First = First -> next;
        }

        // move both pointers together untill first reaches to the last node
        while(First -> next)
        {
            First = First -> next;
            Last = Last -> next;
        }

        // Now, First is at last node and Last is at node before new head 

        // Actual Rotation
        //Place new head after Last Pointer
        ListNode* newHead= Last -> next;

        // remove link at the point of rotation means remove contact between Last and newHead
        // Hence, This will become last node of rotated list
        Last -> next = nullptr;

        //connect initial last node to first node to complete the linked list
        First -> next = head;

         return newHead;        // rotated linked list
    }
};