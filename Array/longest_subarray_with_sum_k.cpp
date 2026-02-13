#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestSubarrayWithSumk(vector<int>& nums, int k) {
        int len = 0;
        for (int i = 0; i < nums.size(); i++) {
            int sum = 0;
            for (int j = i; j < nums.size(); j++) {
                sum += nums[j];
                if (sum == k) {
                    len = max(len, j - i + 1);
                }
            }
        }
        return len;
    }

    int optimal(vector<int>& nums, int k) {
        unordered_map<int,int> preSum;
        int sum = 0, maxLen = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (sum == k) maxLen = max(maxLen, i + 1);
            int rem = sum - k;
            if (preSum.find(rem) != preSum.end()) {
                int len = i - preSum[rem];
                maxLen = max(len, maxLen);
            }
            if (preSum.find(sum) == preSum.end()) {
                preSum[sum] = i;
            }
        }
        return maxLen;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, -1, 5, -2, 3};
    int k = 3;
    // cout << sol.longestSubarrayWithSumk(nums, k) << endl;
    cout << sol.optimal(nums, k) << endl; 
    return 0;
}