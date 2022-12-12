#include <iostream>

using namespace std;

// node tree
struct Node{
  string name;
  Node *left, *right, *parent;
};

Node *root, *newNode; 

// membuat tree
void createTree( string name )
{
    root = new Node();
    root->name = name;
    root->left = NULL;
    root->right = NULL;
    root->parent = NULL;
    cout << "\nOrang " << name << " berhasil dibuat menjadi parent utama." << endl;
}

// tambah anak kiri
Node *addLeft( string name, Node *node )
{
    // cek apakah anak kiri ada atau tidak
    if( node->left != NULL ){
      // kalau ada
      cout << "\nOrang "<< node->name << " sudah ada anak kiri!!" << endl;
      return NULL;
    }else{
      // kalau tidak ada
      newNode = new Node();
      newNode->name = name;
      newNode->left = NULL;
      newNode->right = NULL;
      newNode->parent = node;
      node->left = newNode;
      cout << "\nOrang " << name << " berhasil ditambahkan ke anak kiri " << newNode->parent->name << endl;
      return newNode;
    }

  }

// tambah anak kanan
Node *addRight( string name, Node *node )
{
    // cek apakah anak kanan ada atau tidak
    if( node->right != NULL ){
      // kalau ada
      cout << "\nOrang " << node->name << " sudah ada anak kanan!!" << endl;
      return NULL;
    }else{
      // kalau tidak ada
      newNode = new Node();
      newNode->name = name;
      newNode->left = NULL;
      newNode->right = NULL;
      newNode->parent = node;
      node->right = newNode;
      cout << "\nOrang " << name << " berhasil ditambahkan ke anak kanan " << newNode->parent->name << endl;
      return newNode;
    }
  }

// Cek apakah tree kosong atau tidak?
bool empty()
{
  if( root == NULL )
    return true;
  else
    return false;
}

// Mengupdate node atau orang didalam tree
void update(string name, Node *node)
{
   
      string temp = node->name;
      node->name = name;
      cout << "\nnama orang " << temp << " berhasil diubah menjadi " << name << endl;
 }

// cari node atau orang didalam tree
void search( Node *node )
{
    if( !node )
      cout << "\nOrang yang ditunjuk tidak ada!!" << endl;
    else{
      cout << "\nnama orang : " << node->name << endl;
    }
  }

// Metode transversal preOrder
void preOrder( Node *node = root )
{
    if( node != NULL ){
      cout << node->name << " -> ";
      preOrder(node->left);
      preOrder(node->right);
    }
  }

// Metode transversal inOrder
void inOrder( Node *node = root )
{
    if( node != NULL ){
      inOrder(node->left);
      cout << node->name << " -> ";
      inOrder(node->right);
    }
  }

// Metode transversal postOrder
void postOrder( Node *node = root )
{
    if( node != NULL ){
      postOrder(node->left);
      postOrder(node->right);
      cout << node->name << " -> ";
    }
  }

int main()
{

  createTree("Buyut");

  Node *orang1, 
  *orang2, 
  *orang11, 
  *orang12, 
  *orang111,
  *orang112,
  *orang1112,
  *orang1111,
  *orang1121,
  *orang1122, 
  *orang121, 
  *orang122, 
  *orang1211, 
  *orang1212, 
  *orang22,
  *orang21,
  *orang1221,
  *orang1222,
  *orang2111,
  *orang2112,
  *orang2121,
  *orang2122,
  *orang2211,
  *orang2212,
  *orang2221,
  *orang2222,
  *orang11111,
  *orang11112,
  *orang11121,
  *orang11122,
  *orang11211,
  *orang11212,
  *orang11221,
  *orang11222,
  *orang12111,
  *orang12112,
  *orang12121,
  *orang12122,
  *orang12211,
  *orang12212,
  *orang12221,
  *orang12222,
  *orang21111,
  *orang21112,
  *orang21121,
  *orang21122,
  *orang21211,
  *orang21212,
  *orang21221,
  *orang21222,
  *orang22111,
  *orang22112,
  *orang22121,
  *orang22122,
  *orang22211,
  *orang22212,
  *orang22221,
  *orang211,
  *orang212,
  *orang221,
  *orang222,
  *orang22222;

  orang1 = addLeft("Agus", root);
  orang2 = addRight("Ari", root);
  orang11 = addLeft("Amel", orang1);
  orang12 = addRight("Arya", orang1);
  orang21 = addLeft("Ade ", orang2);
  orang22 = addRight("Anggi", orang2);
  orang211 = addLeft("Bagas", orang21);
  orang212 = addRight("Budi", orang21);
  orang221 = addLeft("Bagus", orang22);
  orang222 = addRight("Bayu", orang22);
  orang111 = addLeft("Chika", orang11);
  orang112 = addRight("Cinta", orang11);
  orang121 = addLeft("Citra", orang12);
  orang122 = addRight("Candra", orang12);
  orang1111 = addLeft("Dimas", orang111);
  orang1112 = addRight("Dinda", orang111);
  orang1121 = addLeft("Dika", orang112);
  orang1122 = addRight("Erwin", orang112);
  orang1211 = addLeft("Eka", orang121);
  orang1212 = addRight("Elin", orang121);
  orang1221 = addLeft("Ema", orang122);
  orang1222 = addRight("Fikri", orang122);
  orang2111 = addLeft("Fitri", orang211);
  orang2112 = addRight("Fika", orang211);
  orang2121 = addLeft("Fani", orang212);
  orang2122 = addRight("Farid", orang212);
  orang2211 = addLeft("Galih", orang221);
  orang2212 = addRight("Guntur", orang221);
  orang2221 = addLeft("Gilang", orang222);
  orang2222 = addRight("Gibran", orang222);
  orang11111 = addLeft("Hilmi", orang1111);
  orang11112 = addRight("Hisyam", orang1111);
  orang11121 = addLeft("Harun", orang1112);
  orang11122 = addRight("Haikal", orang1112);
  orang11211 = addLeft("Ilham", orang1121);
  orang11212 = addRight("Indra", orang1121);
  orang11221 = addLeft("Ikbal", orang1122);
  orang11222 = addRight("Irwan", orang1122);
  orang12111 = addLeft("Irfan", orang1211);
  orang12112 = addRight("Joko", orang1211);
  orang12121 = addLeft("Jefri", orang1212);
  orang12122 = addRight("Kirana", orang1212);
  orang12211 = addLeft("Keisya", orang1221);
  orang12212 = addRight("Kevin", orang1221);
  orang12221 = addLeft("Latif", orang1222);
  orang12222 = addRight("Lukman", orang1222);
  orang21111 = addLeft("Mila", orang2111);
  orang21112 = addRight("Monika", orang2111);
  orang21121 = addLeft("Maya", orang2112);
  orang21122 = addRight("Mira", orang2112);
  orang21211 = addLeft("Malik", orang2121);
  orang21212 = addRight("Nanda", orang2121);
  orang21221 = addLeft("Naila", orang2122);
  orang21222 = addRight("Nisa", orang2122);
  orang22111 = addLeft("Nadia", orang2211);
  orang22112 = addRight("Okta", orang2211);
  orang22121 = addLeft("Oki", orang2212);
  orang22122 = addRight("Putri", orang2212);
  orang22211 = addLeft("Putra", orang2221);
  orang22212 = addRight("Sinta", orang2221);
  orang22221 = addLeft("Ririn", orang2222);
  orang22222 = addRight("Rafi", orang2222);

cout << "\nCetak urutan traversal metode PreOrder :" << endl;
preOrder();

cout << "\n\nMencari name file yang akan direname :"<<endl;
search(orang212);

cout << "\nCetak hasil rename file tersebut :"<<endl;
update("nama1", orang212);

cout << "\n\n"<<endl;

cout << "\nCetak urutan traversal metode inOrder :" << endl;
inOrder();

cout << "\n\nMencari name file yang akan direname :"<<endl;
search(orang211);

cout << "\nCetak hasil rename file tersebut :"<<endl;
update("nama2l", orang211);

cout << "\n\n"<<endl;

cout << "\nCetak urutan traversal metode postOrder :" << endl;
postOrder();

cout << "\n\nMencari name file yang akan direname :"<<endl;
search(orang221);

cout << "\nCetak hasil rename file tersebut :"<<endl;
update("nama3", orang221);

cout << "\n\n"<<endl;

cout << "\nCetak urutan traversal ketiga metode"<<endl;

cout << "\nCetak urutan traversal metode preOrder :" << endl;
preOrder();

cout << "\n\nCetak urutan traversal metode inOrder :" << endl;
inOrder();

cout << "\n\nCetak urutan traversal metode postOrder :" << endl;
postOrder();

}
