#include <stdio.h>
#define MAXN 1001

struct Node {
    int Value;      // node's value
    int Left,Right;    // pointer to left and right child
    int nodeLeft,nodeRight;  // angka node di sebelah left dan right
} n[MAXN];

int nCk[MAXN][MAXN], S, M = 1000003;

void add(int &root, int val){
    if (root==-1){
        n[root = S++] = (Node){ val,-1,-1,0,0 };    // new node
    } else {
        Node &r = n[root];
        if (val < r.Value)              // insert to the left if the value is < root's
            add(r.Left, val), r.nodeLeft++;  // insert to the left, and increment left node count
        else
            add(r.Right, val), r.nodeRight++;  // insert to the right, and increment right node count
    }
}

long long f(int root){
    if (root==-1) return 1;
    Node &r = n[root];
    long long ret = nCk[r.nodeLeft + r.nodeRight][r.nodeLeft]; // how many ways can we insert
    ret = ret * f(r.Left) % M;     // applied recursively
    ret = ret * f(r.Right) % M;     // applied recursively
    return ret;
}

int main(){
    nCk[0][0] = 1;
    for (int i=1; i<MAXN; i++){
        nCk[i][0] = 1;
        for (int j=1; j<MAXN; j++)
            nCk[i][j] = (nCk[i-1][j-1] + nCk[i-1][j]) % M;
    }

    int TC;
    scanf("%d",&TC);
    while (TC--){
        int N,T,val,root=-1; S = 1;
        scanf("%d %d",&N,&T);
        for (int i=0; i<N; i++) scanf("%d",&val), add(root,val);
        printf("%d\n", int( f(root) * nCk[T][N] % M )); // choose N labels out of available T
    }
}
