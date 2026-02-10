#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> temp;
        for (int n : nums) {
            if (n != 0) {
                temp.push_back(n);
            }
        }
        for (int i = 0; i < temp.size(); i++) {
            nums[i] = temp[i];
        }
        int nonZeroCount = temp.size();
        for (int i = nonZeroCount; i < nums.size(); i++) {
            nums[i] = 0;
        }
    }
    
    void optimal(vector<int>& nums) {
        int i = 0;
        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] != 0) {
                swap(nums[i], nums[j]);
                i++;
            }
        }
    }
};

int main() {
    Solution sol;

    vector<int> arr = {0, 1, 0, 3, 12};

    cout << "Original array: ";
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;

    // sol.moveZeroes(arr);
    sol.optimal(arr);

    cout << "Array after moving zeroes: ";
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}