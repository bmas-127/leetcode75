#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;

        ListNode *new_head = head;
        ListNode *cur = head->next;
        ListNode *next;
         
        while(cur != nullptr){
            next = cur->next;
            cur->next = new_head;
            new_head = cur;
            cur = next;
        }

        head->next = nullptr;
        return new_head;
    }
};