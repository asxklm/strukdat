#include<iostream>
#include<vector>


using namespace std;
struct dat {               
  long long int key;
  struct dat *kiri;
  struct dat *kanan;
  long long int height;
  long long int child_kiri ;
  long long int child_kanan;
  long long int count ;
};

 

long long int height(struct dat *n){ 
  if(n == NULL){
    return 0;
  }
  else{
    return n->height;
  }
}

struct dat *kananRotate(struct dat *y){  
  struct dat *x = y->kiri;
  struct dat *z = x->kanan;
  x->kanan = y;
  y->kiri = z;
  y->height = max(height(y->kiri),height(y->kanan))+1;
  x->height = max(height(x->kiri),height(x->kanan))+1;
  y->child_kiri = x->child_kanan;
  x->child_kanan = (y->child_kanan+y->child_kiri)+1;
  return x;
}
struct dat *leftRotate(struct dat *y){      
  struct dat *x = y->kanan;
  struct dat *z = x->kiri;
  x->kiri = y;
  y->kanan = z;
  y->height = max(height(y->kiri),height(y->kanan))+1;
  x->height = max(height(x->kiri),height(x->kanan))+1;
  y->child_kanan = x->child_kiri;
  x->child_kiri = (y->child_kiri + y->child_kanan)+1;
  return x;

}

long long int getBalance(struct dat *n){  
  if(n == NULL){
    return 0;
  }
  return height(n->kiri) - height(n->kanan);
}

struct dat *insert(struct dat *n, long long int key){
  if(n == NULL){;
    struct dat* temp = new dat();
    temp->key = key;
    temp->kiri = NULL;
    temp->kanan = NULL;
    temp->height = 1;
    temp->child_kiri = 0;
    temp->child_kanan = 0;
    temp->count = 1;
    return temp;
  }
  if(key == n->key){    
    n->count+=1;
    return n;
  }
  if(key < n->key){
    n->kiri = insert(n->kiri,key);
  }
  else if(key > n->key){
    n->kanan = insert(n->kanan,key);
  }
  else{
    return n;
  }
  n->height = max(height(n->kiri),height(n->kanan))+1;
  if(n->kanan != NULL ){ 
  n->child_kanan = (n->kanan->child_kanan)+ (n->kanan->child_kiri)+1;
}
  if(n->kiri != NULL){    
  n->child_kiri = (n->kiri->child_kanan)+ (n->kiri->child_kiri)+1;
  
}
  
  long long int balance = getBalance(n);
  if(balance > 1 && key < n->kiri->key){
    return kananRotate(n);
  }
  if(balance < -1 && key > n->kanan->key){
    return leftRotate(n);
  }
  if(balance > 1 && key > n->kiri->key){
    n->kiri = leftRotate(n->kiri);
    return kananRotate(n);
  }
  if(balance < -1 && key < n->kanan->key){
    n->kanan = kananRotate(n->kanan);
    return leftRotate(n);
  }
  


  return n;

}

struct dat *getMin(struct dat *n){
  struct dat *curr = n;
  while(curr->kiri != NULL){
    curr = curr->kiri;
  }
  return curr;
}
struct dat *delnode(struct dat* root, long long int key){
  if(root==NULL){
    return root;
  }
  if(key < root->key){
    root->kiri = delnode(root->kiri,key);
    root->child_kiri-=1;
  }
  else if(key > root->key){
    root->kanan = delnode(root->kanan,key);
    root->child_kanan-=1;
  }
  else{
    if((root->kiri == NULL) || (root->kanan == NULL)){
      struct dat *temp = root->kiri ? root->kiri : root->kanan;
      if(temp == NULL){
        temp = root;
        root = NULL;
      }
      else{
        root = temp;
      }
    }
    else{
      struct dat *temp = getMin(root->kanan);
      root->key = temp->key;
      root->child_kanan = (root->child_kanan)-1;
      root->kanan = delnode(root->kanan,temp->key);
    }
  }
  if(root == NULL){
    return root;
  }
  root->height = 1 + max(height(root->kiri),height(root->kanan));
  if(root->kanan != NULL ){
  root->child_kanan = (root->kanan->child_kanan)+ (root->kanan->child_kiri)+1;
}
  if(root->kiri != NULL){
  root->child_kiri = (root->kiri->child_kanan)+ (root->kiri->child_kiri)+1;
}
  long long int balance  = getBalance(root);
  if (balance > 1 && getBalance(root->kiri) >= 0)
        return kananRotate(root);

    if (balance > 1 && getBalance(root->kiri) < 0)
    {
        root->kiri =  leftRotate(root->kiri);
        return kananRotate(root);
    }

    if (balance < -1 && getBalance(root->kanan) <= 0)
        return leftRotate(root);

    if (balance < -1 && getBalance(root->kanan) > 0)
    {
        root->kanan = kananRotate(root->kanan);
        return leftRotate(root);
    }

    return root;

}
void inorder(struct dat * root){
  if(root==NULL){
    return ;
  }
  if(root->kiri != NULL){
    inorder(root->kiri);
  }
  cout<<root->key<<" "<<root->child_kiri<<" "<<root->child_kanan<<endl;
  if(root->kanan != NULL){
    inorder(root->kanan);
  }
}

long long int findkthsmallest(struct dat *root,long long int k){
  if(root == NULL){
    return -1;
  }
  if(k == root->child_kiri+1){
    return root->key;
  }
  if(root->child_kiri >= k){
    return findkthsmallest(root->kiri,k);
  }
  else{
    return findkthsmallest(root->kanan,k-(root->child_kiri+1));
  }
}
bool ifPresent(struct dat * root, long long int key){
  if(root==NULL){
    return false;
  }
  if(root->key == key){
    return true;
  }
  else if(root->key < key){
    return ifPresent(root->kanan,key);
  }
  else{
    return ifPresent(root->kiri,key);
  }
}
long long int findRank(struct dat *root, long long int key){
   if(root->key == key){
     return root->child_kiri+ 1;
   }
   else if ( root->key < key){
     return  (root->child_kiri)+ 1 + findRank(root->kanan,key);
   }
   else{
     return findRank(root->kiri,key);
   }

}
long long int smllest(struct dat *root){
  while(root->kiri != NULL){
    root = root->kiri;
  }
  return root->key;
}
int main(){
  long long int n;
  cin>>n;
  struct dat *root = NULL;

  for(long long int i = 1; i<= n;i++){
    long long int x;
    cin>>x;
    if(x == 1){
      long long int y;
      cin>>y;
      root = insert(root,y);
    }
    else{
       long long int y;
       cin>>y;
       if(ifPresent(root,y)==false){
         cout<<"Data tidak ada"<<endl;
       }
       else{
         cout<<findRank(root,y)<<endl;
       }
     }
  }
}
