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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr){
            return head;
        }
        
        ListNode *preHead = new ListNode(0);
        preHead->next = head;
        ListNode *pre = preHead;
        while(pre != nullptr && pre->next != nullptr ){
            ListNode *next = nullptr;
            ListNode *node = pre->next;
            stack <ListNode *> listNodeStack;
            for(int i=0; i<k; ++i){
                if(node == nullptr){
                    # 不需要继续翻转了
                    head = preHead->next;
                    delete preHead;
                    return head;
                }
                listNodeStack.push(node);
                node = node->next;
            }
            
            next = node;
            node = pre;
            while(!listNodeStack.empty()){
                node->next = listNodeStack.top();
                listNodeStack.pop();
                node = node->next;
            }
            node->next = next;
            pre = node;
        }
        
        head = preHead->next;
        delete preHead;
        return head;
    }

};
