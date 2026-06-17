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
    ListNode* deleteMiddle(ListNode* head) { 
        if (head == nullptr || head->next == nullptr) return nullptr; 
        ListNode* slow = head; 
        ListNode* fast = head; 
        fast = fast->next->next;

        while (fast != nullptr && fast->next != nullptr) { 
            slow = slow->next; 
            fast = fast->next->next; 
        }

        ListNode* middle = slow->next; 
        slow->next = slow->next->next; 
        delete middle; 
        return head; 
    } 
};

int main() {
    Solution solution;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original list: ";
    ListNode* current = head;
    while (current != nullptr) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;

    head = solution.deleteMiddle(head);

    cout << "List after deleting the middle node: ";
    current = head;
    while (current != nullptr) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;

    return 0;
}