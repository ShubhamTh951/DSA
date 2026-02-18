#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low = 1;
        int high = arr.size() - 1; 
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int missing = arr[mid] - (mid + 1);
            if (missing < k)  low = mid + 1;
            else high = mid - 1;
        }
        return k + high + 1;
    }
};

int main() {
    Solution solution;
    vector<int> arr = {2, 3, 4, 7, 11};
    int k = 5;
    int result = solution.findKthPositive(arr, k);
    cout << "The " << k << "th missing positive number is: " << result << endl;
    return 0;
}