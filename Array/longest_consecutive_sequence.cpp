#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
private:
    bool linearSearch(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) return true;
        }
        return false;
    }

public:
    int longestConsecutive(vector<int>& nums) {
        int longest = 0;
        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];
            int cnt = 0;
            while (linearSearch(nums, x + 1)) {
                cnt++;
                x++;
            }
            longest = max(longest, cnt + 1);    
        }
        return longest;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    cout << sol.longestConsecutive(nums) << endl; // Output: 4
    return 0;
}