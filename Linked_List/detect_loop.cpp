#include <iostream>
#include <unordered_map>
using namespace std;

struct List {
    int data;
    List *next;
    List() : data(0), next(nullptr) {}
    List(int x) : data(x), next(nullptr) {}
    List(int x, List *next) : data(x), next(next) {}
};
 
class Solution {
public:
    bool detectLoop(List* head){
        List* slow = head;
        List* fast = head;  

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (fast == slow) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    Solution solution;
    List* head = new List(1);
    head->next = new List(2);
    head->next->next = new List(3);
    head->next->next->next = new List(4);
    head->next->next->next->next = new List(5);
    head->next->next->next->next->next = head->next; // Creating a loop

    bool hasLoop = solution.detectLoop(head);
    cout << "Loop detected: " << (hasLoop ? "Yes" : "No") << endl;

    return 0;
}