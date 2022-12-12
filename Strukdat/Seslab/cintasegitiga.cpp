#include <bits/stdc++.h>

using namespace std;

int main() {
    int x, n[3001];
    cin >> x;
    for(int i = 0; i < x; ++i) {
        cin >> n[i];
        --n[i];
    }

    for(int i = 0; i < x; ++i) {
        if(n[i] == n[n[n[n[i]]]]) {
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;

    return 0;
}
