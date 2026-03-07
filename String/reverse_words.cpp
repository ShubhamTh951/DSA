#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string reverseWord(string s) {
        // Reverse the entire string
        reverse(s.begin(), s.end());

        int start = 0;
        for (int i = 0; i <= s.length(); i++) {
            if (i == s.length() || s[i] == ' ') {
                reverse(s.begin() + start, s.begin() + i);
                start = i + 1;
            }
        }

        return s;
    }
};

int main() {
    Solution sol;
    string str = "Hello world";
    
    string reversed = sol.reverseWord(str);
    cout << reversed << endl;

    return 0;
}
