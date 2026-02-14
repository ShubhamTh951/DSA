#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lowerBound(vector<int>& nums, int target) {
        int left = 0; int right = nums.size() - 1;
        int ans = target;
        while (left <= right) {
            int mid = left + (right - left) /  2;
            if (nums[mid] >= target) {
                ans = nums[mid];
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }   
        }
        return ans;
    }

    int upperBound(vector<int>& nums, int target) {
        int left = 0; int right = nums.size() - 1;
        int ans = target;
        while (left <= right) {
            int mid = left + (right - left) /  2;
            if (nums[mid] > target) {
                ans = nums[mid];
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }   
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int target = 5;
    cout << "Lower Bound: " << sol.lowerBound(nums, target) << endl;
    cout << "Upper Bound: " << sol.upperBound(nums, target) << endl;
    return 0;
}