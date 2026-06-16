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
private:
    int countNodes(List* slow, List* fast) {
        int count = 1; // Start counting from 1 since slow and fast are already at the meeting point
        fast = fast->next; // Move fast one step ahead to avoid counting the meeting point
        while (slow != fast) {
            count++;
            fast = fast->next;
        }
        return count;
    }

public:
    int findLength(List* head){
        List* slow = head;
        List* fast = head;  

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (fast == slow) {
                return countNodes(slow, fast);
            }
        }
        return 0;
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

    int loopLength = solution.findLength(head);
    cout << "Length of the loop: " << loopLength << endl;

    return 0;
}