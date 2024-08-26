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
    int pairSum(ListNode* head) {
        vector<int> arr;
        ListNode *curr = head;

        while(curr != nullptr){
            arr.push_back(curr->val);
            curr = curr->next;
        }

        for(int i = 0; i <= arr.size() / 2; i ++){
            arr[i] += *(arr.end() - i - 1);
        } 

        return *max_element(arr.begin(), arr.end() - arr.size() / 2);
    }
};