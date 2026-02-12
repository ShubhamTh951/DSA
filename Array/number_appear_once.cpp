#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int appearOnce(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            int cnt = 0;
            for (int j = 0; j < nums.size(); j++) {
                if (num == nums[j]) {
                    cnt++;
                }
            }
            if (cnt == 1) return num;
        }
        return -1;
    }

    int optimal(vector<int>& nums) {
        int XOR = 0;
        for (int i = 0; i < nums.size(); i++) {
            XOR ^= nums[i];
        }
        return XOR;
    }
};

int main() {
    vector<int> nums = {1, 1, 2, 2, 3, 4, 4};
    
    Solution sol;
    
    // int result = sol.appearOnce(nums);
    int result = sol.optimal(nums);
    cout << result << endl;

    return 0;
}