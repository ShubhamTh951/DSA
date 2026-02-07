#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> unionOfTwoSortedArrays(vector<int>& nums1, vector<int>& nums2, int n, int m) {
        int i = 0;
        int j = 0;
        vector<int> temp;
        
        while (i < n && j < m) {
            if (nums1[i] <= nums2[j]) {
                if (temp.size() == 0 || temp.back() != nums1[i]) {
                    temp.push_back(nums1[i]);
                }
                i++;
            }
            else {
                if (temp.size() == 0 || temp.back() != nums2[j]) {
                    temp.push_back(nums2[j]);
                }
                j++;
            }
        }

        while (i < n) {
            if (temp.size() == 0 || temp.back() != nums1[i]) {
                temp.push_back(nums1[i]);
            }
            i++;
        }

        while (j < m) {
            if (temp.size() == 0 || temp.back() != nums2[j]) {
                    temp.push_back(nums2[j]);
            }
            j++;
        }

        return temp;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1, 2, 2, 3, 4};
    vector<int> nums2 = {2, 3, 5, 5, 6};

    int n = nums1.size();
    int m = nums2.size();

    vector<int> result = sol.unionOfTwoSortedArrays(nums1, nums2, n, m);

    cout << "Union of arrays: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}