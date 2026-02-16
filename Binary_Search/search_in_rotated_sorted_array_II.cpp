#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) return true;

            if (nums[mid] == nums[low] && nums[mid] == nums[high]) {
                low = low + 1;
                high = high - 1;
                continue;
            }

            // left sorted 
            if (nums[mid] >= nums[low]) {
                if (nums[low] <= target && target <= nums[mid]) {
                    high = mid - 1;
                }
                else {
                    low = mid + 1;
                }
            }

            // right sorted
            else {
                if (nums[mid] <= target && target <= nums[high]) {
                    low = mid + 1 ;
                }
                else {
                    high = mid - 1;
                }
            }
        
        }

        return false;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2,5,6,0,0,1,2};

    cout << sol.search(nums, 0) << endl;
    cout << sol.search(nums, 3) << endl;

    return 0;
}
