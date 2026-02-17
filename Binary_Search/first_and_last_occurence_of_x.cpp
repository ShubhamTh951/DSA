#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int firstOccurence(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int first = -1;
        while (low <= high) {
            int mid = low + (high - low ) / 2;
            if (nums[mid] == target) {
                first = mid;
                high = mid - 1;
            }
            else if (nums[mid] < target) low = mid + 1;
            else high = mid - 1;
        }
        return first;
    }

    int lastOccurence(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int last = -1;
        while (low <= high) {
            int mid = low + (high - low ) / 2;
            if (nums[mid] == target) {
                last = mid;
                low = mid + 1;
            }
            else if (nums[mid] < target) low = mid + 1;
            else high = mid - 1;
        }
        return last;
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 4, 4, 4, 5, 6};
    int target = 4;
    Solution sol;
    cout << "First Occurence: " << sol.firstOccurence(nums, target) << endl;
    cout << "Last Occurence: " << sol.lastOccurence(nums, target) << endl;
    return 0;
}