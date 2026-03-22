#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* back;
    Node* next;
    
    public:
    Node(int d, Node* n, Node* b) {
        data = d;
        next = n;
        back = b;
    }
    
    Node(int d) {
        data = d;
        next = nullptr;
        back = nullptr;
    }
};

// Creation
Node* convertArr2DLL(vector<int> &arr) {
    if (arr.empty()) return nullptr;
    
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

void print(Node* head) {
    while (head != nullptr) {
        cout << head->data;
        if (head->next) cout << " <-> ";
        head = head-> next;
    }
}

// deletion
Node* deleteHead(Node* head) {
    if (head == nullptr) return nullptr;
    
    if (head->next == nullptr) {
        delete head;
        return nullptr;
    }
    
    Node* prev = head;
    head = head->next;
    head->back = nullptr;
    prev->next = nullptr;
    delete prev;
    return head;
}

Node* deleteTail(Node* head) {
    if (head == nullptr) return nullptr;
    
    if (head->next == nullptr) {
        delete head;
        return nullptr;
    }
    
    Node* tail = head;
    while (tail->next != nullptr) { 
        tail = tail->next;
    }
    Node* prev = tail->back;
    prev->next = nullptr;
    tail->back = nullptr;
    delete tail;
    return head;
}

Node* deleteK(Node* head, int k) {
    if (head == nullptr) return nullptr;
    int cnt = 0;
    Node* temp = head;
    while(temp != nullptr) {
        cnt++;
        if (cnt == k) {
            break;
        }
        temp = temp->next;
    }
    
    if (temp == nullptr) return head;
    
    Node* prev = temp->back;
    Node* front = temp->next;
    
    if (prev == nullptr && front == nullptr) {
        delete temp;
        return nullptr;
    }
    else if (prev == nullptr) {
        return deleteHead(head);
    }
    else if (front == nullptr) {
        return deleteTail(head);
    }
    prev->next = front;
    front->back = prev;
    temp->next = nullptr;
    temp->back = nullptr;
    delete temp;
    return head;
}

// Insertion
Node* insertionHead(Node* head, int val) {
    Node* newHead = new Node(val, head, nullptr);
    if (head != nullptr) head->back = newHead;
    
    return newHead;
}

Node* insertBeforeTail(Node* head, int val) {
    if (head == nullptr) return nullptr;
    
    if (head->next == nullptr) {
        return insertionHead(head, val);
    }
    Node* tail = head;
    while (tail->next != nullptr) {
        tail = tail->next;
    }
    
    Node* prev = tail->back;
    Node* newNode = new Node(val, tail, prev);
    prev->next = newNode;
    tail->back = newNode;
    return head;
}

Node* insertAtK(Node* head, int val, int k) {
    if ( k <= 0) return head;
    
    if (k == 1) return insertionHead(head, val);
    
    Node* temp = head;
    int cnt = 0;
    while (temp != nullptr) {
        cnt++;
        if (cnt == k) break;
        temp = temp->next;
    }
    Node* prev = temp->back;
    Node* newNode = new Node(val, temp, prev);
    prev->next = newNode;
    temp->back = newNode;
    return head;
}

int main() {
    vector<int> arr = {1,5,3,8,5,2,9,0};
    Node* head = convertArr2DLL(arr);
    // head = deleteHead(head);
    // head = deleteTail(head);
    // head = deleteK(head, 3);
    
    // head = insertionHead(head, 5);
    // head = insertBeforeTail(head, 7);
    head = insertAtK(head, 2, 6);
    
    print(head);
    
    return 0;
}