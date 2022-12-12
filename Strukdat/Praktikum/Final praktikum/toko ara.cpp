#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int x;
    cin >> x;
    priority_queue<int> high; 
    priority_queue<int, vector<int>, greater<int> > low; 
    int total_prize = 0; 
    for (int i = 0; i < x; i++)
    {
        int a;
        cin >> a;
        for (int b = 0; b < a; b++)
        {
            int transaction;
            cin >> transaction;
            high.push(transaction);
            low.push(transaction);
        }
        total_prize += high.top() - low.top(); 
        high.pop();
        low.pop();
    }
    cout << total_prize << endl;
    return 0;
}