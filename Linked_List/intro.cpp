#include <iostream>
#include <vector>
using namespace std;

struct Node {
    public:
    int data;
    Node* next;
    
    public:
    Node(int d, Node* node) {
        data = d;
        next = node;
    }
    
    Node(int d) {
        data = d;
        next = nullptr;
    }
};

Node* convertAll2LL(vector<int>& arr) {
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void print(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Deletion in Linked list
Node* removehead(Node* head) {
    if (head == nullptr) return head;
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

Node* removeTail(Node* head) {
    if (head == nullptr || head->next == nullptr) return nullptr;
    Node* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
    
    return head;
}

Node* removeFromPosition(Node* head, int k) {
    if (head == nullptr) return head;
    
    if (k == 1) {
        head = removehead(head);
    }
    
    Node* temp = head;
    Node* prev = nullptr;
    int cnt = 0;
    while (temp != nullptr) {
        cnt++;
        if (cnt == k) {
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

// Insertion
Node* insertAtHead(Node* head, int val) {
    Node* temp = new Node(val);
    temp->next = head;
    return temp;
}

Node* insertAtLast(Node* head, int val) {
    if (head == nullptr) {
        return new Node(val);
    }
    
    Node* mover = head;
    Node* temp = new Node(val);
    while (mover->next != nullptr) {
        mover = mover->next;
    }
    mover->next = temp;
    
    return head;
}

Node* insertK(Node* head, int val, int k) {
    if (head == nullptr) {
        if (k == 1) return new Node(val);
        else return head;
    }
    
    if (k == 1) {
        Node* temp = new Node(val);
        temp->next = head;
        return temp;
    }
    
    Node* temp = head;
    Node* x = new Node(val);
    int cnt = 0;
    while (temp != nullptr) {
        cnt++;
        if (cnt == k - 1) {
            x->next = temp->next;
            temp->next = x;
            break;
        }
        temp = temp->next;
    }
    return head;
}

int main() {
    vector<int> arr = {2, 5, 8, 7, 2, 1, 8, 9};
    Node* head = convertAll2LL(arr);
    // head = removehead(head);
    // head = removeTail(head);
    // head = removeFromPosition(head, 2);
    
    // head = insertAtHead(head, 4);
    // head = insertAtLast(head, 5);
    head = insertK(head, 6, 2);
    print(head);
    return 0;
}