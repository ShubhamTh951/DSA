#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string reverseString(string s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            swap(s[left], s[right]);
            left++;
            right--;    
        }
        return s;
    }
};  

int main() {
    Solution solution;
    string s = "Hello, World!";
    string reversed = solution.reverseString(s);
    cout << "Original string: " << s << endl;
    cout << "Reversed string: " << reversed << endl;
    return 0;
}
