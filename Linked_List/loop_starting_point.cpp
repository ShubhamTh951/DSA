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
    List* startingPoint(List* head){
        List* slow = head;
        List* fast = head;  

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (fast == slow) {
                slow = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
            }
                return slow; // Starting point of the loop
            }
        }
        return nullptr;
    }
};

int main() {
    List* head = new List(1);
    head->next = new List(2);
    head->next->next = new List(3);
    head->next->next->next = new List(4);
    head->next->next->next->next = head->next; // Creating a loop

    Solution sol;
    List* loopStart = sol.startingPoint(head);
    if (loopStart) {
        cout << "Loop starts at node with data: " << loopStart->data << endl;
    } else {
        cout << "No loop detected." << endl;
    }

    return 0;
}