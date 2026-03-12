#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n ; i++) {
            sum += nums[i];
        }
        return sum % k;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3, 9, 7};
    int k = 5;

    int result = sol.minOperations(nums, k);
    cout << "Minimum operations to make array sum divisible by " << k << ": " << result << endl;

    return 0;
}