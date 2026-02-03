#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:         
    bool containsDuplicate(const vector<int>& nums) {
        unordered_set<int> seen;
        for (const int& num : nums) {
            if (seen.find(num) != seen.end()) {
                return true;
            }
            seen.insert(num);
        }
        return false; 
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3, 4, 5, 1};
    if (solution.containsDuplicate(nums)) {
        cout << "Contains duplicates" << endl;
    } else {
        cout << "No duplicates" << endl;
    }
    return 0;
}