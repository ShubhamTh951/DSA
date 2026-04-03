#include <iostream>
#include<stack>
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
    bool isPalindrome(ListNode* head) {
        stack<int> st;
        ListNode* temp = head;
        while (temp != nullptr) {
            st.push(temp->val);
            temp = temp->next;
        }

        temp = head;
        while (temp != nullptr) {
            if (temp->val != st.top()) return false;
            temp = temp->next;
            st.pop();
        }

        return true;
    }

    bool isPalindrome2(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return true;

        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* newHead = reverseLL(slow->next);
        ListNode* first = head;
        ListNode* second = newHead;
        while (second != nullptr) {
            if (first->val != second->val) {
                reverseLL(newHead);
                return false;
            }
            first = first->next;
            second = second->next;
        }
        reverseLL(newHead);
        return true;
    }
};

int main() {
    Solution solution;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(1);

    bool result = solution.isPalindrome(head);
    cout << "Is the linked list a palindrome? " << (result ? "Yes" : "No") << endl;

    bool result2 = solution.isPalindrome2(head);
    cout << "Is the linked list a palindrome? " << (result2 ? "Yes" : "No") << endl;

    return 0;
}