#include <iostream>

using namespace std;

struct list{
    string nama;
    int umur;
    list *next;
};

list *head, *tail, *cur, *newnode, *del, *before;  

//membuat Single List kosong
void initSL(string nama){
    head = new list();
    head->nama = nama;
    head->next = NULL;
    tail = head;
}

//menghitung Singly list
int CountSL(){
  cur = head;
  int jumlah = 0;
  while( cur != NULL ){
    jumlah++;
    cur = cur->next;
  }
  return jumlah;
}

//menambah di depan
void AddFSL(string nama){
    newnode = new list;
    newnode->nama = nama;
    newnode->next = NULL;
    newnode->next = head;
    head = newnode;
}

//menambah di tengah
void AddMSL(string nama, int umur, int posisi){
  if( posisi < 1 || posisi > CountSL() ){
    cout << "Posisi tidak dalam jangkauan" << endl;
  }else if( posisi == 1){
    cout << "Posisi tidak di tengah" << endl;
  }else{
    newnode = new list();
    newnode->nama = nama;
    newnode->umur = umur;

    // tranversing
    cur = head;
    int nomor = 1;
    while( nomor < posisi - 1 ){
      cur = cur->next;
      nomor++;
    }
    newnode->next = cur->next;
    cur->next = newnode;
  }    
}

//menambah di akhir
void AddLSL(string nama, int umur){
  newnode = new list();
  newnode->nama = nama;
  newnode->umur = umur;
  newnode->next = NULL;
  tail->next = newnode;
  tail = newnode;
}

//mengubah di awal
void ChangeFSL(string nama, int umur){
  head->nama = nama;
  head->umur = umur;
}

//mengubah di tengah
void ChangeMSL(string nama, int umur, int posisi){
  if( posisi < 1 || posisi > CountSL() ){
    cout << "Posisi tidak dalam jangkauan" << endl;
  }else if( posisi == 1 || posisi == CountSL() ){
    cout << "Posisi tidak di tengah" << endl;
  }else{
    cur = head;
    int nomor = 1;
    while( nomor < posisi ){
      cur = cur->next;
      nomor++;
    }
    cur->nama = nama;
    cur->umur = umur;
  }
}

//mengubah di akhir
void ChangeLSL(string nama, int umur){
  tail->nama = nama;
  tail->umur = umur;
}

//menghapus di awal
void DeleteFSL(){
  del = head;
  head = head->next;
  delete del;
}

//menghapus di tengah
void DeleteMSL(int posisi){
  if( posisi < 1 || posisi > CountSL() ){
    cout << "Posisi tidak dalam jangkauan" << endl;
  }else if( posisi == 1){
    cout << "Posisi tidak di tengah" << endl;
  }else{
    int nomor = 1;
    cur = head;
    while( nomor <= posisi ){
      if( nomor == posisi-1 ){
        before = cur;
      }
      if( nomor == posisi ){
        del = cur;
      }
      cur = cur->next;
      nomor++;
    }
    before->next = cur;
    delete del;
  }
}

void check(string nama){
    cur = head;
    int i = 0;
    while(cur != NULL){
        if(cur->nama == nama){
            i++;
        }
        cur = cur->next;
    }
        if(i == 0){
            cout << "OK" << endl;
        }
        else{
            cout << nama << i << endl;
        }
}


int main(){
    int i, max;
    string nama;
    cout << "masukkan nilai max : ";
    cin >> max;
    while(i != max){
        cin >> nama;
        if(i == 0){
            initSL(nama);
            cout << "OK" << endl;
        }
        else{
            check(nama);
            AddFSL(nama);
        }
        i++;
    }
}