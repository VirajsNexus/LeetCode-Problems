/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {

        //  Logic: 
        //      First Traverse both lists till there end
        //      After reaching to the last node Set Pointers to the other list
        //      ALso chceck for THERE NODE IS EQUAL OR NOT?
        ListNode* FirstPtr = headA;     // Pointer for 1st list
        ListNode* SecondPtr = headB;    // pointer for 2nd list

        while(FirstPtr != SecondPtr)
        {
            FirstPtr = (FirstPtr != nullptr) ? FirstPtr ->next : headB;     // Runs till last node of 1st list and then sets to the head of second list and traverse once again in that second list

            SecondPtr = (SecondPtr != nullptr) ? SecondPtr -> next :headA;  // Runs till last node of 2st list and then sets to the head of 1st list and traverse once again in that 1st list
        }    

        // Finally we gets the traversing both list (n traversals)
        // How n traversals?
        // Traversal by FirstPtr = lengths of list1 and List2
        // Traversal by SeconfPtr = lengths of list2 and list1

        return FirstPtr;       // Intersection Node found
    }
};