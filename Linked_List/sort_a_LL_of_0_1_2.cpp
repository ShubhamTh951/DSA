#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node() : data(0), next(nullptr) {}
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, Node *next) : data(x), next(next) {}
};

class Solution {
public:
    Node* sortList(Node* head) {
        if (head == nullptr || head->next == nullptr) return head;
        
        Node* zeroHead = new Node(-1);
        Node* oneHead = new Node(-1);
        Node* twoHead = new Node(-1);
        Node* zero = zeroHead;
        Node* one = oneHead;
        Node* two = twoHead;
        Node* current = head;   
        while (current != nullptr) {
            if (current->data == 0) {
                zero->next = current;
                zero = zero->next;
            } else if (current->data == 1) {
                one->next = current;
                one = one->next;
            } else {
                two->next = current;
                two = two->next;
            }
            current = current->next;
        }
        zero->next = (oneHead->next) ? oneHead->next : twoHead->next;
        one->next = twoHead->next;
        two->next = nullptr;
        Node* newHead = zeroHead->next;

        delete oneHead;
        delete twoHead;
        delete zeroHead;

        return newHead;
    }
};

int main() {
    Solution sol;

    // linked list: 2 -> 1 -> 0 -> 1 -> 2
    Node* head = new Node(2);
    head->next = new Node(1);
    head->next->next = new Node(0);
    head->next->next->next = new Node(1);
    head->next->next->next->next = new Node(2);

    Node* result = sol.sortList(head);
    
    cout << "Result: ";
    while (result != nullptr) {
        cout << result->data << " ";
        result = result->next;
    }
    cout << endl;

    return 0;
}