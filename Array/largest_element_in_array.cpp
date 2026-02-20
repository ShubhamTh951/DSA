#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findLargestElement(vector<int>& arr) {
        if (arr.empty()) return -1;
        int largest = arr[0];
        for (size_t i = 1; i < arr.size(); ++i) {
            if (arr[i] > largest) {
                largest = arr[i];
            }
        }
        return largest;
    }
};

int main() {
    Solution solution;
    vector<int> arr = {3, 1, 4, 1, 5, 9};
    int largest = solution.findLargestElement(arr);
    cout << "The largest element in the array is: " << largest << endl;
    return 0;
}