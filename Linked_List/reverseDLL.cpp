// Online C++ compiler to run C++ program online
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

Node* reverseDLL(Node* head) {
    if (head == nullptr || head->next == nullptr) return head;
    
    Node* prev = nullptr;
    Node* current = head;
    while (current != nullptr) {
        prev = current->back;
        current->back = current->next;
        current->next = prev;
        
        if (current->back == nullptr) return current;
        current = current->back;
    }
    return head;
}

Node* reverseDLLStack(Node* head) {
    if (head == nullptr || head->next == nullptr) return head;
    
    stack<int> st;
    Node* temp = head;
    while (temp != nullptr) {
        st.push(temp->data);
        temp = temp->next;
    }
    
    temp = head;
    while (temp != nullptr) {
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }
    return head;
}

int main() {
    vector<int> arr = {1,5,3,8,5,2,9,0};
    Node* head = convertArr2DLL(arr);
    
    // head = reverseDLL(head);
    head = reverseDLLStack(head);
    print(head);
    
    return 0;
}