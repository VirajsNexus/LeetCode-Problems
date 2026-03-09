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
        int gcd(int a, int b)       //finding greatest common divisor of two nums
        {
            while(b != 0)
            {
                int temp = b;
                b = a % b;
                a = temp;
            }
            return a;
        }

    ListNode* insertGreatestCommonDivisors(ListNode* head) 
    {
        ListNode* current = head;               //current set at head

        while(current && current -> next)       //runs until current and its next is present
        {
            int a = current ->val;              //current node
            int b = current -> next -> val;     //next node of current node

            int GreatestCommonDivisor = gcd(a, b); //using gcd function for getting GreatestCommonDivisor of a and b
            ListNode* newNode = new ListNode(GreatestCommonDivisor);    //created newNode to be insert as GCD of two nodes
            newNode -> next = current -> next;  
            current -> next = newNode;

            current = newNode -> next;          //current moved forward
        }    
        return head;
    }
};