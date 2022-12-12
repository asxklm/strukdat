#include <iostream>
using namespace std;


int main() {
    int n, i, v, genap[5000];
    cin >> n;
    
    for(i = 1; i <= n; i++){
        cin >> v;
        if( (i % 2) == 0 ){
            genap[i] = v;
        }
        else{
            cout << v << " ";
        }
    }
    
    for(i = 1; i<= n; i++){
        if(genap[i] != 0){
            cout << genap[i] << " ";
        }
        else{
            continue;
        }
    }      
    return 0;
}