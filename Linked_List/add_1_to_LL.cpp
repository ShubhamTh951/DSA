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
private:
    ListNode* reverseLL(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

public:
    ListNode* addOne(ListNode* head) {
        head = reverseLL(head);
        ListNode* temp = head;
        int carry = 1;
        while (temp != nullptr) {
            temp->val = temp->val + carry;
            if (temp->val < 10) {
                carry = 0;
                break;
            }
            else {
                temp->val = 0;
                carry = 1;
            }
            temp = temp->next;
        }
        if (carry == 1) {
            ListNode* newNode = new ListNode(1);
            head = reverseLL(head);
            newNode->next = head;
            return newNode;
        }
        head = reverseLL(head);
        return head;
    }
};

int main() {
    Solution solution;
    ListNode* head = new ListNode(9);
    head->next = new ListNode(9);
    head->next->next = new ListNode(9);

    ListNode* resultHead = solution.addOne(head);

    cout << "Linked List after adding 1: ";
    while (resultHead != nullptr) {
        cout << resultHead->val << " ";
        resultHead = resultHead->next;
    }
    cout << endl;

    return 0;
}