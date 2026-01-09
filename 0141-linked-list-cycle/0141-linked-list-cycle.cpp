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
    bool hasCycle(ListNode *head) 
    {   
        //Case 1: Empty linked list
            if(NULL == head)
            {
                return false;
            }
        // case 2 : linked list present
            
            //Initialize two pointers for traversing linked list
            ListNode* First = head;
            ListNode* Last = head;

            // To traverse linked list Both pointers should have some gap between them 
            // so that it will check for cycle is present or not for all node conditions formed 

            // If if last nodes next returns nullptr it means Cycle is not present
            while(First != nullptr && First -> next != nullptr)
            {
                Last = Last -> next;            // traversing by single node only
                First = First ->next ->next;  // traversing by two nodes

            // IMP Logic : If cycle is present Fisrt and Last will met eventually
                if(First == Last)       // Checking for cycle
                {
                    // Cycle Found
                    return true;
                }
            }

            return false;       //No cycle Fouund
    }
};