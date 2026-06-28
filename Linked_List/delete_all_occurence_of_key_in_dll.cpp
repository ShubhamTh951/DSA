#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node* prev;
    Node() : data(0), next(nullptr), prev(nullptr) {}
    Node(int x) : data(x), next(nullptr), prev(nullptr) {}
    Node(int x, Node *next, Node *prev) : data(x), next(next), prev(prev) {}
};

class Solution {
public:
    // Function to delete all occurrences of a given key in a doubly linked list
    Node* deleteAllOccurrences(Node* head, int key) {
        Node* temp = head;

        // Traverse the list and delete nodes with the specified key
        while (temp != nullptr) {
            
            // Check if the current node's data matches the key
            if (temp->data == key) {
                
                // If the node to be deleted is the head, update the head pointer
                if (temp == head) {
                    head = head->next;
                }

                // Store the next and previous nodes
                Node* nextNode = temp->next;
                Node* prevNode = temp->prev;
                
                // Update the next and previous pointers to bypass the deleted
                if (nextNode) nextNode->prev = prevNode;
                if (prevNode) prevNode->next = nextNode;
                delete temp; // Free the memory of the deleted node
                temp = nextNode; // Move to the next node
            }

            else {
                temp = temp->next; // Move to the next node if no deletion
            }
        }
        return head; // Return the new head of the list
    }
};

int main() {
    Solution solution;
    Node* head = new Node(1);
    head->next = new Node(2, nullptr, head);
    head->next->next = new Node(3, nullptr, head->next);
    head->next->next->next = new Node(2, nullptr, head->next->next);
    head->next->next->next->next = new Node(4, nullptr, head->next->next->next);

    int key = 2;
    head = solution.deleteAllOccurrences(head, key);

    // Print the modified list
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    // Free the remaining nodes
    while (head != nullptr) {
        Node* nextNode = head->next;
        delete head;
        head = nextNode;
    }

    return 0;
}