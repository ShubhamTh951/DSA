#include <iostream>
#include <vector>
#include <unordered_set>
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

    int optimal(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int longest = 1;
        unordered_set<int> st;
        for (int i = 0; i < n; i++) {
            st.insert(nums[i]);
        }
        for (auto it : st) {
            if (st.find(it - 1) == st.end()) {
                int cnt = 1;
                int x = it;
                while (st.find(x + 1) != st.end()) {
                    cnt++;
                    x = x + 1;
                }
                longest = max(longest, cnt);
                            }
        }
        return longest;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    // cout << sol.longestConsecutive(nums) << endl; 
    cout << sol.optimal(nums) << endl;
    return 0;
}