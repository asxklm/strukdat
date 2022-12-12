#include <iostream>
#include <list>
using namespace std;


int main() {
    int x, y, start = 0, flag = 0;
    list<int> arr[100];
    list<int>::iterator it;
    
    for(x = 0; x > -1; x++){
        cin >> y;
        if(y == 0){
            break;
        }
        for(it = arr[start].begin(); it != arr[start].end(); it++){
            if(y == *it){
                flag = 1;
            }
        }
        if(flag == 0){
            arr[start].push_back(y);
        }
        flag = 0;
    }
    
    arr[start].sort();
    
    for(it = arr[start].begin(); it != arr[start].end(); it++){
        cout << *it << endl;
    }
    
    
    return 0;
}