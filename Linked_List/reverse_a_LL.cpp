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
    ListNode* rev(ListNode* head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* nhead=rev(head->next);
        ListNode* temp=head->next;
        temp->next=head;
        head->next=NULL;
        return nhead;
    }
    ListNode* reverseList(ListNode* head) {
        return rev(head);
    }
};

int main() {
    Solution solution;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    ListNode* reversedHead = solution.reverseList(head);

    cout << "Reversed Linked List: ";
    while (reversedHead != nullptr) {
        cout << reversedHead->val << " ";
        reversedHead = reversedHead->next;
    }
    cout << endl;

    return 0;
}