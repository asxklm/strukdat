#include <bits/stdc++.h>
#include <iostream>
using namespace std;


//1 2 3 4 5
int main(){
    int a, b, count = 0, dvd = 0;
    double tot = 0, res = 0, end = 0, y, sum;
    string x;
    cin >> a;
    cin >> b;
    for(int i = 0; i < a; i++){
        cin >> x;
        if(x != "GASS"){
            cin >> y;
            tot = tot + y;
            count++;
        }
        else{
            res = tot/count;
            cout << fixed << setprecision(2) << res << endl;
            end = end + res;
            dvd++;
        }
    }
    sum = end/dvd;
        cout << sum << " ";
        if(0.5*b <= sum && 1.5*b >= sum){
            cout << "AMAN";
        }
        else{
            cout << "LOH";
        }
}