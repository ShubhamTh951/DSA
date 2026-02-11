#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> findLeaders(vector<int>& arr) {
        vector<int> ans;
        for (int i = 0; i < arr.size(); i++) {
            bool leader = true;
            for (int j = i + 1; j < arr.size(); j++) {
                if (arr[j] > arr[i]) {
                    leader = false;
                    break;
                }
            }
            if (leader) {
                ans.push_back(arr[i]);
            }
        }
        return ans;
    }

    vector<int> optimal(vector<int>& arr) {
        vector<int> ans;
        int maxi = INT_MIN;
        for (int i = arr.size() - 1; i >= 0; i--) {
            if (arr[i] > maxi) {
                ans.push_back(arr[i]);
                maxi = arr[i];
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> arr = {16, 17, 4, 3, 5, 2};
    vector<int> leaders = solution.findLeaders(arr);
    cout << "Leaders in the array: ";
    for (int leader : leaders) {
        cout << leader << " ";
    }
    cout << endl; // Output: Leaders in the array: 17 5 2
    return 0;
}