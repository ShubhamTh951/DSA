#include <iostream>
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* t1 = l1;
        ListNode* t2 = l2;
        int carry = 0;
        ListNode* dummy = new ListNode(-1);
        ListNode* current = dummy;

        while (t1 != nullptr || t2 != nullptr) {
            int sum = carry;
            if (t1) sum += t1->val;
            if (t2) sum += t2->val;
            ListNode* newNode = new ListNode(sum % 10);
            carry = sum / 10;
            current->next = newNode;
            current = current->next;

            if (t1) t1 = t1->next;
            if (t2) t2 = t2->next;
        }

        if (carry) {
            ListNode* newNode = new ListNode(carry);
            current->next = newNode;
        }
        return dummy->next;
    }
};

int main() {
    Solution sol;

    // Create first linked list: 2 -> 4 -> 3
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    // Create second linked list: 5 -> 6 -> 4
    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    ListNode* result = sol.addTwoNumbers(l1, l2);
    
    cout << "Result: ";
    while (result != nullptr) {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;

    return 0;
}
