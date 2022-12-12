#include <set>
#include <bits/stdc++.h>

using namespace std;

int main() {
    set<int> s;
    int num, y, x;
    
    cin >> num;
    
    while(num--)
    {
        cin >> y >> x;
        
        if (y == 1)
        {
            s.insert(x);
        }
        else if (y == 2)
        {
            s.erase(x);
        }
        else if (y == 3)
        {
            set<int>::const_iterator itr = s.find(x);
            cout << ( (itr != s.end()) ? "Yes" : "No") << endl;
        }
    }
    return 0;
}
