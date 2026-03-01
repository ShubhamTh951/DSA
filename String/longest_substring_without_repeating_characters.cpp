#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int left = 0, right = 0, maxLength = 0;

        while (right < s.length()) {
            if (st.find(s[right]) == st.end()) {
                st.insert(s[right]);
                maxLength = max(maxLength, right - left + 1);
                right++;
            } else {
                st.erase(s[left]);
                left++;
            }
        }

        return maxLength;
    }
};

int main() {
    Solution solution;
    string s = "abcabcbb";
    int result = solution.lengthOfLongestSubstring(s);
    cout << "Length of the longest substring without repeating characters: " << result << endl;
    return 0;
}