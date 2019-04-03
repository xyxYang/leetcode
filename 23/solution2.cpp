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
		if (lists.size() == 0){
			return NULL;
		}
		if (lists.size() == 1){
			return lists[0];
		}

		int right = lists.size();
		int mid = lists.size() / 2;
		while (mid < right){
			for (int i=0; i<mid; i++){
				if (mid + i + 1 <= right){
					lists[i] = mergeTwoLists(lists[i], lists[mid+i+1]);
				}
			}
			right = mid;
			mid = right / 2;
		}
		return lists[0];
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *preListNode = new ListNode(0);
        ListNode *retListNode = preListNode;
        while(true){
            if(l1 == NULL && l2 == NULL){
                return preListNode->next;
            }   
            else if(l1 == NULL){
                retListNode->next = l2; 
                return preListNode->next;
            }   
            else if(l2 == NULL){
                retListNode->next = l1; 
                return preListNode->next;
            }   
            else{
                if(l1->val < l2->val){
                    retListNode->next = l1; 
                    retListNode = l1; 
                    l1 = l1->next;
                }   
                else{
                    retListNode->next = l2; 
                    retListNode = l2; 
                    l2 = l2->next;
                }   
            }   
        }   
	}
};
