#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int N, d, f[10000];
    
    cin >> N;
    
    cin >> d;
    
    for(int i = 0; i < N; i++){
        cin >> f[i];
        if(f[i] == d){
            cout << "Berhasil, HORE!";
            return 0;
        }
    }
    cout << "Yah gagal";
    return 0;
}
