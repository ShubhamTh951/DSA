# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

class Solution { 
public:
    void rotateArray(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        vector<int> rotate;
        for (int i = n - k; i < n; i++) {
            rotate.push_back(nums[i]);
        }
        for (int i = 0; i < n - k; i++) {
            rotate.push_back(nums[i]);
        }
        nums = rotate;
    }

    void optimalRotateArray(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;

        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;

    // sol.rotateArray(nums, k);
    sol.optimalRotateArray(nums, k);

    cout << "Rotated array: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}