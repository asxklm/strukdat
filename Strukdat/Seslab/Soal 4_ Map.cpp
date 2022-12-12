#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;


int main() {
    
map<string,int>m;
    int q, qtype, mark;
       
    cin >> q;
    string name;
     
    for (int i; i<q; i++){
        cin >> qtype >> name;
        switch (qtype) {
        case 1: 
            cin >> mark;
            if (m.find(name) != m.end()){
                m[name] += mark;
            } 
            else {
                m.insert(make_pair(name, mark));
            }
            break; 
        case 2: 
            m.erase(name);
            break;
        case 3: 
            if (m.find(name) != m.end()){
                cout << m[name] << endl;
            }
            else {
                cout << 0 << endl;
            }
            break;
        }
    }
    return 0;
}
