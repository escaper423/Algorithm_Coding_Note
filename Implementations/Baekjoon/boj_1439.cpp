#include <string>
#include <iostream>

using namespace std;

int flip(string s) {
    int res = 0;
    char prev = s[0];
    for (int i = 1; i < s.length(); i++) {
        if (prev != s[i]) {
            res++;
        }
        prev = s[i];
    }
    res >>= 1;
    if (s[0] != prev)
        res++;

    return res;
}
int main() {
    string s;
    cin >> s;
    cout << flip(s);
    return 0;
}

