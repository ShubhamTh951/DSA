#include <iostream>
#include <vector>
#include <limits>  
using namespace std;

class Solution {
public:
    int findSecondLargest(const vector<int>& nums) {
        int largest = nums[0];
        int slargest = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > largest) {
                slargest = largest;
                largest = nums[i];
            } else if (nums[i] < largest) {
                if (slargest == -1 || nums[i] > slargest) {
                    slargest = nums[i];
                }
            }
        }
        return slargest;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {12, 35, 1, 10, 34, 1};
    int secondLargest = sol.findSecondLargest(nums);
    if (secondLargest != -1) {
        cout << "The second largest element is: " << secondLargest << endl;
    } else {
        cout << "There is no second largest element." << endl;
    }
    return 0;
}
