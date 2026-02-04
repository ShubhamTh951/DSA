#include <iostream>
#include <vector>
using namespace std;

class solution {
public:
    int linear_search(const vector<int>& arr, int target) {
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == target) {
                return i; 
            }
        }
        return -1; // Return -1 if not found
    }
};  

int main() {
    solution sol;
    vector<int> arr = {4, 2, 5, 1, 3};
    int target = 1;
    int result = sol.linear_search(arr, target);
    
    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }
    
    return 0;
}