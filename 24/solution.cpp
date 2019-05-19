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
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr){
            return head;
        }
        
        ListNode *preHead = new ListNode(0);
        preHead->next = head;
        ListNode *pre = preHead;
        while(pre->next != nullptr && pre->next->next != nullptr){
            ListNode *first = pre->next;
            ListNode *second = first->next;
            first->next = second->next;
            pre->next = second;
            second->next = first;
            
            pre = first;
        }
        
        head = preHead->next;
        delete preHead;
        return head;
    }
};
