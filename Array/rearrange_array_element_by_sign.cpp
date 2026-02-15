#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rearrange(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        int posIndex = 0, negIndex = 1;
        for (int num : nums) {
            if (num >= 0 && posIndex < n) {
                ans[posIndex] = num;
                posIndex += 2;
            } else if (num < 0 && negIndex < n) {
                ans[negIndex] = num;
                negIndex += 2;
            }
        }
        nums = ans;
    }
};

int main() {
    Solution solution;
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    solution.rearrange(nums);
    cout << "Rearranged array: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}