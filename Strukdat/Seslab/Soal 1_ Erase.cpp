#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<int> v;
int i,n,x,y,a,b;
int main() {
    cin >> n;
   
    for(i=0;i<n;i++){ 
      cin >> x;
      v.push_back(x);
    }
    cin >> x;
    v.erase(v.begin()+x-1);
    
    cin >> a;
    cin >> b;
    v.erase(v.begin()+a-1,v.begin()+b-1);
    
    y = v.size();
    cout << y << endl;
    cout << v.at(0);
    for ( i=1; i< y; i++)
       cout <<' '<< v.at(i);
    cout << "\n";
    
    return 0;
}
