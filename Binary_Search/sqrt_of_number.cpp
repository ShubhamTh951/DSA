#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        long long low = 0, high = x;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (mid * mid <= x) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return high;
    }
};

int main() {
    Solution solution;
    int x;
    cin >> x;
    cout << "The square root of " << x << " is: " << solution.mySqrt(x) << endl;
    return 0;
}