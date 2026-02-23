#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isPrime(int n) {
        if (n <= 1) {
            return false;
        }
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }

    vector<int> generatePrimes(int limit) {
        vector<int> primes;
        for (int i = 2; i <= limit; i++) {
            if (isPrime(i)) {
                primes.push_back(i);
            }
        }
        return primes;
    }

    vector<int> sieveOfEratosthenes(int limit) {
        vector<bool> isPrime(limit + 1, true);
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i * i <= limit; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= limit; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        vector<int> primes;
        for (int i = 2; i <= limit; i++) {
            if (isPrime[i]) {
                primes.push_back(i);
            }
        }
        return primes;
    }

};

int main() {
    Solution solution;
    int n = 29;
    // Check if n is a prime number
    if (solution.isPrime(n)) {
        cout << n << " is a prime number." << endl;
    } else {
        cout << n << " is not a prime number." << endl;
    }

    // Generate and print prime numbers up to a certain limit
    vector<int> primes = solution.generatePrimes(30);
    cout << "Primes up to 30: ";
    for (int prime : primes) {
        cout << prime << " ";
    }
    cout << endl;

    // Generate and print prime numbers using Sieve of Eratosthenes
    vector<int> sievePrimes = solution.sieveOfEratosthenes(30);
    cout << "Primes up to 30 (Sieve of Eratosthenes): ";
    for (int prime : sievePrimes) {
        cout << prime << " ";
    }
    cout << endl;
    return 0;
}