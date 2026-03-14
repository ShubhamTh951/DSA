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

    double optimal(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        if (n1 > n2) 
            return optimal(nums2, nums1);

        int low = 0, high = n1;

        while (low <= high) {
            int cut1 = (low + high) / 2;
            int cut2 = (n1 + n2 + 1) / 2 - cut1;

            int l1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
            int l2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];

            int r1 = (cut1 == n1) ? INT_MAX : nums1[cut1];
            int r2 = (cut2 == n2) ? INT_MAX : nums2[cut2];

            if (l1 <= r2 && l2 <= r1) {

                if ((n1 + n2) % 2 == 0)
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                else
                    return max(l1, l2);
            }

            else if (l1 > r2)
                high = cut1 - 1;
            else
                low = cut1 + 1;
        }

        return 0.0;
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};

    double median = sol.findMedianSortedArrays(nums1, nums2);
    cout << "Median: " << median << endl;
    cout << "Median = " << sol.optimal(nums1, nums2) << endl;

    return 0;
}