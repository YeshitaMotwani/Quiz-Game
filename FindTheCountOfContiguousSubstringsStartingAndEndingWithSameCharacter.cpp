#include <iostream>
using namespace std;

int countSubstrings(string s) {
    int count = 0;
    int n = s.length();

    // Loop over the string
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            if (s[i] == s[j]) {
                count++;
            }
        }
    }

    return count;
}

int main() {
    string S = "abcab";
    cout << "Count of substrings: " << countSubstrings(S) << endl;
    return 0;
}
