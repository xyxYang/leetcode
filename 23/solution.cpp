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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *preListNode = new ListNode(0);
		ListNode *retListNode = preListNode;
		while(true){
			ListNode *nextListNode = NULL;
			int min_index = -1;
			for (int i=0; i<lists.size(); i++){
				if (lists[i] == NULL){
					continue;
				}
				if (nextListNode == NULL){
					nextListNode = lists[i];
					min_index = i;
					continue;
				}

				if (nextListNode->val > lists[i]->val){
					nextListNode = lists[i];
					min_index = i;
				}
			}
			if (min_index == -1 || nextListNode == NULL){
				break;
			}
			else{
				retListNode->next = nextListNode;
				retListNode = nextListNode;
				lists[min_index] = lists[min_index]->next;
			}
		}
		return preListNode->next;
    }
};
