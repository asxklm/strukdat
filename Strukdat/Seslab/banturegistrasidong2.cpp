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
        map <string,int> y;
        while(n--)
        {
            cin>>x;
            if(y.find(x)==y.end())
            {
                y[x]=1;
                cout<<"OK"<<endl;
            }
            else
            {
                cout<<x<<y[x]++<<endl;
            }
        }
    }
    return 0;
}
