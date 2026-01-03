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
    ListNode* removeElements(ListNode* head, int val) 
    {
           //Creating NewNode
           ListNode* DeleteNode = new ListNode();
           DeleteNode -> next = head;

           //Temporary pointer "Temp" trevrse the linked list
           ListNode* Temp = DeleteNode;

           //traversing linked list till end
           while(Temp -> next != NULL)
           {
                // Checking next node's value with temp's value
                if(Temp -> next -> val == val)
                {
                    //if yes then skip the node
                    // This will removes node from the list

                    Temp -> next = Temp -> next -> next;
                }
                else
                {
                    //move to next node if not equal or same
                    //also checks that newly addded nodes are not skipped
                    Temp = Temp ->next;
                }
           }
           return DeleteNode -> next;
    }
};