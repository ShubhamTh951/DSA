#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int singleNumber(const vector<int>& nums) {
        unordered_map<int, int> countMap;
        for (int num : nums) {
            countMap[num]++;
        }
        for (auto pair : countMap) {
            if (pair.second == 1) {
                return pair.first;
            }
        }
        return -1;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {4, 1, 2, 1, 2};
    cout << "The element that appears only once is: " << solution.singleNumber(nums) << endl;
    return 0;
}