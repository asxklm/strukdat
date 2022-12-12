#include <iostream>
#include <deque> 
using namespace std;

void printKMax( int arr[],  int n,  int k){
    deque<int> q;
    int last_max = 0;
    
    for (int i = 0; i < n; i++)
    {
        last_max = max(last_max, arr[i]);
        q.push_back(arr[i]);
        
        if (i < k-1)
        {
            continue;   
        }
        
        if (i > k-1)
        {
            int old = q.front();
            q.pop_front();
            
            if (old == last_max)
            {
                last_max = 0;
                for (auto itr = q.begin(); itr != q.end(); ++itr)
                {
                    last_max = max(last_max, *itr);
                }
            }
        }
        
        cout << last_max << " ";
        
    }
    cout << endl;
}


int main(){
  
	int t;
	cin >> t;
	while(t>0) {
		int n,k;
    	cin >> n >> k;
    	int i;
    	int arr[n];
    	for(i=0;i<n;i++)
      		cin >> arr[i];
    	printKMax(arr, n, k);
    	t--;
  	}
  	return 0;
}
