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
    ListNode* partition(ListNode* head, int x) {
        if(!head || !head->next)
          return head;
        ListNode* l1 = new ListNode(-1);
        ListNode* l2 = new ListNode(0);
        ListNode* l1end = l1;
        ListNode* l2end = l2;
        ListNode* curr = head;
        int cnt = 0;
        while(curr != NULL){
          if(curr->val < x){
            cnt++;
            l1end->next = curr;
            l1end = l1end->next;
          }
          else{
            l2end->next = curr;
            l2end = l2end->next;
          }
          curr = curr->next;
        }
        l2end->next = NULL;
        if(cnt == 0)
          return l2->next;
        l1end->next = l2->next;
        return l1->next;
    }
};