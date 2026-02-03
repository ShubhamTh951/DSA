#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (nums.empty()) return 0;
        set<int> st(nums.begin(), nums.end());
        int index = 0;
        for (const int& num : st) {
            nums[index++] = num;
        }
        return st.size();
    }

    int optimizedRemoveDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int index = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[i - 1]) {
                nums[index++] = nums[i];
            }
        }
        return index;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    int new_length = solution.optimizedRemoveDuplicates(nums);
    
    cout << "New length: " << new_length << endl;
    cout << "Array after removing duplicates: ";
    for (int i = 0; i < new_length; ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;
    
    return 0;
}

