#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* prev;
    Node* next;
    Node() : val(0), next(nullptr), prev(nullptr) {} 
    Node(int x) : val(x), next(nullptr), prev(nullptr) {} 
    Node(int x, Node *next, Node *prev) : val(x), next(next), prev(prev) {}
};

class Solution {
public:
    Node* removeDuplicate(Node* head) {
        if (head == nullptr || head->next == nullptr) return head;
        
        // Initialize two pointers to traverse the list
        Node* temp1 = head;
        Node* temp2 = head->next;
        
        // Traverse the list and remove duplicates
        while (temp2 != nullptr) {

            // If the current node's value is not equal to the next node's value, move both pointers forward
            if (temp1->val != temp2->val) {
                temp1->next = temp2; // Update the next pointer of the first node
                temp2->prev = temp1; // Update the previous pointer of the second node
                temp1 = temp2;       // Move the first pointer forward
                temp2 = temp2->next; // Move the second pointer forward
            }

            // If the current node's value is equal to the next node's value, remove the duplicate node
            else {
                Node* dup = temp2; // Store the duplicate node to be deleted
                temp2 = temp2->next; // Move the second pointer forward to skip the duplicate node
                temp1->next = temp2; // Update the next pointer of the first node to skip the duplicate node
                
                // If the next node is not null, update its previous pointer to point to the first node
                if (temp2)
                    temp2->prev = temp1;

                delete dup;

            }
        }
        
        return head;
    }
};


int main() { 
    Solution solution; 
    Node* head = new Node(1); 
    head->next = new Node(1, nullptr, head); 
    head->next->next = new Node(2, nullptr, head->next); 
    head->next->next->next = new Node(2, nullptr, head->next->next); 
    head->next->next->next->next = new Node(4, nullptr, head->next->next->next); 
    head = solution.removeDuplicate(head); // Print the modified list 
    Node* temp = head;
    while (temp != nullptr) { 
        cout << temp->val << " "; 
        temp = temp->next;     
        } 
        cout << endl;

    return 0;
}