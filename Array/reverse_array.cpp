#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void reverseArray(vector<int>& arr) {
        int i = 0;
        int j = arr.size() - 1;
        while (i < j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
};

int main() {
    Solution solution;
    vector<int> arr = {1, 2, 3, 4, 5};
    solution.reverseArray(arr);
    cout << "Reversed array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}