#include <bits/stdc++.h>
#define MAX 10
using namespace std;

struct antri{
    int antri_depan;
    int antri_belakang;
    string data[MAX];
}antri_teller1, antri_teller2, antri_teller3;

void inisialisasi_antiran(antri *queue) {
    queue->antri_depan = -1;
    queue->antri_belakang = -1;
}

bool isEmpty(antri *queue) {
    return (queue->antri_depan == -1 && queue->antri_belakang == -1);
}

bool isFull(antri *queue) {
    return (queue->antri_belakang == MAX-1);
}

void masuk_antri(antri *queue, string data) {
    if (isFull(queue)) {
        cout << "antri sudah penuh!" << endl;
    } else {
        if (isEmpty(queue)) {
            queue->antri_depan = 0;
        }
        queue->antri_belakang++;
        queue->data[queue->antri_belakang] = data;
    }
}

void keluar_antri(antri *queue) {
    if (isEmpty(queue)) {
        cout << "antri kosong" << endl;
    } else {
        if (queue->antri_depan == queue->antri_belakang) {
            inisialisasi_antiran(queue);
        } else {
            queue->antri_depan++;
        }
    }
}

void cetak(antri *queue) {
    if (isEmpty(queue)) {
        cout << "antri kosong" << endl;
    } else {
        for (int i = queue->antri_depan; i <= queue->antri_belakang; i++) {
            cout << queue->data[i] << " " << "Urutan Nasabah" << " " << i+1 << endl;
        }
        cout << endl;
    }
}

int main(){

	int n;
    string perintah;
    string data;

    inisialisasi_antiran(&antri_teller1);
    inisialisasi_antiran(&antri_teller2);
    inisialisasi_antiran(&antri_teller3);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> perintah;
        if (perintah == "Nasabah Masuk") {
            cin >> data;
            if((&antri_teller1)->antri_belakang <= (&antri_teller2)->antri_belakang && (&antri_teller1)->antri_belakang <= (&antri_teller3)->antri_belakang){
                masuk_antri(&antri_teller1, data);
            }else if((&antri_teller2)->antri_belakang <= (&antri_teller1)->antri_belakang && (&antri_teller2)->antri_belakang <= (&antri_teller3)->antri_belakang){
                masuk_antri(&antri_teller2, data);
            }else if((&antri_teller3)->antri_belakang <= (&antri_teller1)->antri_belakang && (&antri_teller3)->antri_belakang <= (&antri_teller2)->antri_belakang){
                masuk_antri(&antri_teller3, data);
            }
        } else if (perintah == "Layani Nasabah") {
            keluar_antri(&antri_teller1);
            keluar_antri(&antri_teller2);
            keluar_antri(&antri_teller3);
        }
    }
 
 cout << "antri Teller Pertama: ";
    cetak(&antri_teller1);
    cout << "antri Teller Kedua: ";
    cetak(&antri_teller2);
    cout << "antri Teller Ketiga: ";
    cetak(&antri_teller3);

}
