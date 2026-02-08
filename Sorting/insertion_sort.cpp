#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void insertionSort(vector<int>& arr) {
        for (int i = 0; i < arr.size(); i++) {
            int j = i;
            while (j > 0 && arr[j] < arr[j - 1]) {
                swap(arr[j], arr[j - 1]);
                j--;
            }
        }
    }
};

int main() {
    Solution sol;

    vector<int> arr = {12, 11, 13, 5, 6};

    cout << "Original array: ";
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;

    sol.insertionSort(arr);

    cout << "Sorted array: ";
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}