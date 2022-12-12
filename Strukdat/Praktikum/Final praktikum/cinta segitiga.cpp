#include <bits/stdc++.h>

using namespace std;

int main() {
    int v, a[3001];
    cin >> v;
    for(int i = 0; i < v; ++i) {
        cin >> a[i];
        --a[i];
    }

    for(int i = 0; i < v; ++i) {
        if(a[i] == a[a[a[a[i]]]]) {
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;

    return 0;
}
