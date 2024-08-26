#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }

        auto cur = head->next->next;
        auto odd_tail = head;
        auto even_head = head->next;
        auto even_tail = head->next;

        while(cur != nullptr){
            auto cur_next = cur->next;

            odd_tail->next = cur;
            even_tail->next = cur_next;
            cur->next = even_head;

            if(cur_next == nullptr){
                break;
            }

            cur = cur_next->next;
            odd_tail = odd_tail->next;
            even_tail = cur_next;
        }

        return head;
    }

    ListNode* construct(vector<int> a){
        ListNode* head = new ListNode(a[0]);
        ListNode* tmp = head;

        for(int i = 1; i < a.size(); i ++){
            tmp->next = new ListNode(a[i]);
            tmp = tmp->next;
        }

        return head;
    }

    void print(ListNode* head){
        while(head != nullptr){
            cout << head->val << ' ';
            head = head->next;
        }
        cout << endl;
    }
};

int main(){
    Solution s;
    vector<int> a {1, 2, 3, 4, 5};
    vector<int> b {2, 1, 3, 5, 6, 4, 7};

    auto head = s.construct(a);
    s.print(head);

    head = s.oddEvenList(head);
    s.print(head);


    return 0;
}