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
private:

    // Function to find the middle node of the linked list
    Node* findMiddle(Node* head) {
        Node* slow = head;
        Node* fast = head->next; // Start fast one step ahead to find the middle for even-length lists
        while (fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    // Function to merge two sorted linked lists
    Node* merge(Node* left, Node* right) {

        // Create a dummy node to simplify the merging process
        Node *dummy = new Node(0);
        // Use a temporary pointer to build the merged list
        Node* temp = dummy;

        // Merge the two lists while both have nodes
        while (left != nullptr && right != nullptr) {
            
            // Compare the data of the two nodes and attach the smaller one to the merged list
            if (left->data < right->data) {
                temp->next = left;
                left = left->next;
            }
            else {
                temp->next = right;
                right = right->next;
            }
            temp = temp->next;
        }

        // If there are remaining nodes in either list, attach them to the merged list
        if (left != nullptr)
            temp->next = left;

        if (right != nullptr)
            temp->next = right;

        // The merged list starts from the next of the dummy node
        Node* result = dummy->next;
        delete dummy; // Free the memory allocated for the dummy node
        return result;
    }

public:
    Node* sortList(Node* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        // Find the middle of the linked list
        Node* mid = findMiddle(head);
        // Split the linked list into two halves
        Node* left = head;
        Node* right = mid->next;

        // Disconnect the left half from the right half
        mid->next = nullptr;

        // Recursively sort both halves
        left = sortList(left);
        right = sortList(right);

        // Merge the sorted halves
        return merge(left, right);
    }
};

int main() {
    Solution solution;
    Node* head = new Node(4);
    head->next = new Node(2);
    head->next->next = new Node(1);
    head->next->next->next = new Node(3);

    cout << "Original list: ";
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;

    head = solution.sortList(head);

    cout << "Sorted list: ";
    current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;

    return 0;
}