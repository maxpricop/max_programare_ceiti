#include <iostream>

using namespace std;

// Fibonacci sequence in for loop
int main() {
    // n = how many numbers to display
    // i = first number
    // j = second number
    int n = 8, i = 0, j = 1;
    for (int k = 0; k++ < n; j = i + j, i = j - i){
        cout << j << endl;
    }
};