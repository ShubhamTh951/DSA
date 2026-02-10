#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        vector<int> visited(nums2.size(), 0);
        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size(); j++) {
                if (nums1[i] == nums2[j] && visited[j] == 0) {
                    result.push_back(nums1[i]);
                    visited[j] = 1;
                    break;
                }
                if (nums1[i] < nums2[j]) {
                    break;
                }
            }
        }
        return result;
    }

    vector<int> optimal(vector<int>& nums1, vector<int>& nums2) {
        int i = 0;
        int j = 0;
        vector<int> ans;

        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j]) i++;
            else if (nums1[i] > nums2[j]) j++;
            else {
                ans.push_back(nums1[i]);
                i++;
                j++;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1, 2, 4, 5, 6};
    vector<int> nums2 = {2, 3, 5, 7};

    // vector<int> result = sol.intersection(nums1, nums2);
    vector<int> result = sol.optimal(nums1, nums2);
    
    cout << "Intersection of the two sorted arrays: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}