#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> arr3;
        int n = nums1.size();
        int m = nums2.size();
        int i = 0;
        int j = 0;
        while (i < n && j < m) {
            if (nums1[i] < nums2[j]) arr3.push_back(nums1[i++]);
            else arr3.push_back(nums2[j++]);
        }

        while (i < n) arr3.push_back(nums1[i++]);
        while (j < m) arr3.push_back(nums2[j++]);

        int p = n + m;
        if (p % 2 == 1) return arr3[p/2];

        return (double) ((double)(arr3[p/2]) + (double)(arr3[p/2 - 1])) / 2.0;
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};

    double median = sol.findMedianSortedArrays(nums1, nums2);
    cout << "Median: " << median << endl;

    return 0;
}