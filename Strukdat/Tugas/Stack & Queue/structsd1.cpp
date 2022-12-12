#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

struct namaHP
{
    int no;
    string nama;
    float harga[4];
    char jenis;
};

int main()
{

    namaHP hp[20] = {
        {1001,  "Samsung Galaxy A03",       {1Jt, 2JT, 3Jt, 4Jt}, 'A Series'},
        {1002,  "Samsung Galaxy A12",       {1Jt, 2JT, 3Jt, 4Jt}, 'A Series'},
        {1003,  "Samsung Galaxy A13",       {1Jt, 2JT, 3Jt, 4Jt}, 'A Series'},
        {1004,  "Samsung Galaxy A22",       {1Jt, 2JT, 3Jt, 4Jt}, 'A Series'},
        {1005,  "Samsung Galaxy A23",       {1Jt, 2JT, 3Jt, 4Jt}, 'A Series'},
        {1006,  "Samsung Galaxy A32",       {1Jt, 2JT, 3Jt, 4Jt}, 'A Series'},
        {1007,  "Samsung Galaxy A33",       {1Jt, 2JT, 3Jt, 4Jt}, 'A Series'},
        {1008,  "Samsung Galaxy A52",       {1Jt, 2JT, 3Jt, 4Jt}, 'A Series'},
        {1009,  "Samsung Galaxy A53",       {1Jt, 2JT, 3Jt, 4Jt}, 'A Series'},
        {1010,  "Samsung Galaxy A72",       {1Jt, 2JT, 3Jt, 4Jt}, 'A Series'},
        {1011,  "Samsung Galaxy A73",       {1Jt, 2JT, 3Jt, 4Jt}, 'A Series'},
        {1012,  "Samsung Galaxy M23",       {1Jt, 2JT, 3Jt, 4Jt}, 'M Series'},
        {1013,  "Samsung Galaxy M33",       {1Jt, 2JT, 3Jt, 4Jt}, 'M Series'},
        {1014,  "Samsung Galaxy M53",       {1Jt, 2JT, 3Jt, 4Jt}, 'M Series'},
        {1015,  "Samsung Galaxy M62",       {1Jt, 2JT, 3Jt, 4Jt}, 'M Series'},
        {1016,  "Samsung Galaxy S21",       {1Jt, 2JT, 3Jt, 4Jt}, 'S Series'},
        {1017,  "Samsung Galaxy S21+",      {1Jt, 2JT, 3Jt, 4Jt}, 'S Series'},
        {1018,  "Samsung Galaxy S22",       {1Jt, 2JT, 3Jt, 4Jt}, 'S Series'},
        {1019,  "Samsung Galaxy S22+",      {1Jt, 2JT, 3Jt, 4Jt}, 'S Series'},
        {1020,  "Samsung Galaxy S22 Ultra", {1Jt, 2JT, 3Jt, 4Jt}, 'S Series'},

    };

    for (int i = 0; i < 20; i++)
    {
        cout << "NO : " << hp[i].no << endl;
        cout << "Nama : " << hp[i].nama << endl;

        for (int j = 0; j < 4; j++)
        {
            cout << "Harga :" << hp[i].harga[j] << endl;
        }
        cout << "Jenis : " << hp[i].jenis << endl;
    }
  
}