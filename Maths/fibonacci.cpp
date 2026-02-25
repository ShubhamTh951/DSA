#include <iostream>
using namespace std;

class solution {
public:
    int fib(int n) {
        if (n <= 1) {
            return n;
        }
        int a = 0, b = 1, c;
        for (int i = 2; i <= n; i++) {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }

    void printSeries(int n) {
        int a = 0, b = 1, c;
        for (int i = 0; i < n; i++) {
            cout << a << " ";
            c = a + b;
            a = b;
            b = c;
        }
        cout << endl;
    }
};

int main() {
    solution s;
    int n = 10;
    cout << "The " << n << "th Fibonacci number is: " << s.fib(n) << endl;
    cout << "The first " << n << " Fibonacci numbers are: ";
    s.printSeries(n);
    return 0;
}