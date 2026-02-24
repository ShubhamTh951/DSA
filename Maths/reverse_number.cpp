#include <iostream>
using namespace std;   

class Solution {
public:
    int reverseNumber(int n) {
        int reversed = 0;
        while (n > 0) {
            int digit = n % 10;
            reversed = reversed * 10 + digit; 
            n /= 10; 
        }
        return reversed;
    }   
};

int main() {
    Solution solution;
    int n = 12345;
    int reversed = solution.reverseNumber(n);
    cout << "Original number: " << n << endl;
    cout << "Reversed number: " << reversed << endl;
    return 0;
}