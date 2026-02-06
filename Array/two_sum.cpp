#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;    

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for (int i = 0;i < nums.size(); i++) {
            int need = target - nums[i];
            if (mp.find(need) != mp.end()) {
                return {mp[need], i};
            }
            mp[nums[i]] = i;
        }
        return {-1, -1};
    }
};      

int main() {
    Solution s;
    vector<int> nums = {2, 7, 11, 15};
    int target = 14;
    vector<int> result = s.twoSum(nums, target);
    cout << "Indices: " << result[0] << ", " << result[1] << endl;
    return 0;
}