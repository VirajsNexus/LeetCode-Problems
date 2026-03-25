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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) 
    {
        ListNode* dummyHead = new ListNode(0);  //dummyHead node with initial value 0
        dummyHead -> next =  head;
        ListNode* previous =  dummyHead;
        ListNode* current = head;

        unordered_set<int> numsSet(nums.begin(), nums.end());

        while(current != NULL)
        {
            if(numsSet.count(current -> val))
            {
                previous -> next = current -> next;
            }
            else
            {
                previous = previous -> next;
            }
            current = current -> next;
        }
        return dummyHead -> next;      
    }
};