struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        auto tmp = head;

        if(!head || !head->next){
            return nullptr;
        }

        int nodeNum = 0;
        while(tmp){
            nodeNum ++;
            tmp = tmp->next;
        }

        nodeNum /= 2;
        tmp = head;
        while(nodeNum > 1){
            tmp = tmp->next;
            nodeNum --;
        }
        tmp->next = tmp->next->next;
        
        return head;
    }
};