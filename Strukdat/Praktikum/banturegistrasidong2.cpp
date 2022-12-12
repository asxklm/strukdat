#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <map>
using namespace std;
#define LL long long
int main()
{
    ios::sync_with_stdio(false);
    int n;string x;
    while(cin>>n)
    {
        map <string,int> m;
        while(n--)
        {
            cin>>x;
            if(m.find(x)==m.end())
            {
                m[x]=1;
                cout<<"OK"<<endl;
            }
            else
            {
                cout<<x<<m[x]++<<endl;
            }
        }
    }
    return 0;
}
