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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        auto st = head;
        auto en = head;
        
        while((n--) > 1){
            en = en->next;
        }
        
        if(!en->next)
            return head->next;
        
        auto pre = st;
        
        while(en->next){
            pre = st;
            st = st->next;
            en = en->next;
        }
        
        pre->next = st->next;
        delete(st);
        
        return head;
        
    }
};
