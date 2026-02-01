#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int PeakElement(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] < nums[mid + 1]) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        return low;
    }
};

int main() {
    vector<int> nums = {1, 2, 1, 3, 5, 6, 4};
    Solution sol;

    int peakIndex = sol.PeakElement(nums);

    cout << "Peak index: " << peakIndex << endl;
    cout << "Peak element: " << nums[peakIndex] << endl;

    return 0;
}
