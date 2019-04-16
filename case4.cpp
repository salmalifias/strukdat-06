/*
Author		: Salma Alifia Shafira
NPM			: 140810180058
Kelas		: B
Tanggal		: 27 Maret 2019
Exercise	: 04
*/

#include<iostream>
#include<string.h>

using namespace std;

struct Kontak{
     char nama[10];
     char phone[12];
     Kontak* nextKontak;
};

struct Index{
     char index[1];
     Kontak* FirstKontak;
     Index* next;
};

typedef Index* pointerInd;
typedef Kontak* pointerCon;
typedef pointerInd listInd;

void createListInd(listInd& First){
    First = NULL;
}

void createElmtInd(pointerInd& pBaru){
    pBaru = new Index;
    cout << "Input Index :"; cin >> pBaru->index;
    pBaru->next = NULL;
    pBaru->FirstKontak = NULL;
}

void createElmtKontak(pointerCon& pBaru){
    pBaru = new Kontak;
    cout << "Input Nama   :"; cin >> pBaru->nama;
    cout << "Input Nomor  :"; cin >> pBaru->phone;
    pBaru->nextKontak = NULL;
}

void traversalInd(listInd First){
    pointerInd pBantu;
    pBantu = First;
    cout << "Index :" << endl;
    while(pBantu!=NULL){
        cout << "|- " << pBantu->index << endl;
        pBantu = pBantu->next;
    }
}

void linearSearch(listInd First,char key[20],int& status,pointerInd& pCari){
    status = 0;
    pCari = First;
    while(status==0 && pCari!=NULL){
        if(strcmp(pCari->index,key)==0){
            status = 1;
        }
        else{
            pCari = pCari->next;
        }
    }
}

void insertFirstInd(listInd& First,pointerInd pBaru){
     if(First==NULL){
        First = pBaru;
     }
     else{
        pBaru->next = First;
        First = pBaru;
     }
}

void deleteFirstInd(listInd& First,pointerInd pHapus){
     if(First==NULL){
        cout << "tidak ada yang dihapus " << endl;
     }
     else if(First->next==NULL){
        pHapus = First;
        First = NULL;
     }
     else{
        pHapus = First;
        First = pHapus->next;
        First->next = NULL;
    }
}

void insertFirstKontak(listInd& First,char key[20],pointerCon pBaru){
     pointerInd pInd;
     int ketemu;
     cout << "Insert Index yang di cari: "; cin >> key;
     linearSearch(First,key,ketemu,pInd);
     if(ketemu){
          cout << "Ditemukan dengan Index :" << pInd->index << endl;
          if(pInd->FirstKontak==NULL){
            pInd->FirstKontak = pBaru;
          }
          else{
            pBaru->nextKontak = pInd->FirstKontak;
            pInd->FirstKontak = pBaru;
          }
     }
     else{
      cout << "Nama Divisi tidak di temukan" << endl;
     }
}

void deleteFirstKontak(listInd& First,char key[20],pointerCon& pHapus ){
    int ketemu;
    pointerInd pInd;
    cout << "Insert Index yang di cari: "; cin >> key;
    linearSearch(First,key,ketemu,pInd);

    if(ketemu){
        cout << "Ditemukan dengan nama :" << pInd->index;
        if(pInd->FirstKontak==NULL){
            cout << "Tidak ada yang di hapus"<<endl;
        }
        else if(pInd->FirstKontak->nextKontak==NULL){
            pHapus = pInd->FirstKontak;
            pInd->FirstKontak = NULL;
        }
        else{
            pHapus = pInd->FirstKontak;
            pInd->FirstKontak = pInd->FirstKontak->nextKontak;
            pHapus->nextKontak = NULL;
        }
    }
     else{
        cout << "Nama Index tidak di temukan" << endl;
     }

}

void traversalIndKontak(listInd First){
    pointerInd pBantuInd;
    pointerCon pBantuCon;
    cout << "Traversal Index" << endl;
    pBantuInd=First;
    while (pBantuInd!=NULL){
        cout << "|- " << pBantuInd->index << endl;
        pBantuCon = pBantuInd->FirstKontak;
        while (pBantuCon!=NULL) {
            cout << "\t|- " << pBantuCon->nama << " / " << pBantuCon->phone << endl;
            pBantuCon = pBantuCon->nextKontak;
        }
        pBantuInd = pBantuInd->next;
    }
}

int main()
{
    listInd q;
    int nd,nk,menu;
    char key [20];
    pointerInd pd,pc,phd;
    pointerCon pk,phk;
    createListInd(q);

    do{
        system("cls");
        cout<<"===Tampilan Menu==="<<endl;
        cout<<"1. Insert First"<<endl;
        cout<<"2. Insert Last"<<endl;
        cout<<"3. Delete First"<<endl;
        cout<<"4. Delete Last"<<endl;
        cout<<"5. Traversal"<<endl;
        cout<<"6. Exit"<<endl;
        cout<<"====================="<<endl;
        cout << "Choose Menu: "; cin >> menu;
        switch(menu){
        case 1 :
            cout << "Masukan banyak Index : "; cin >> nd;
            for(int i=0;i<nd;i++){
                createElmtInd(pd);
                insertFirstInd(q,pd);
            }
        break;

        case 2 :cout << "Masukan banyak Nama :"; cin >> nk;
            traversalInd(q);
            for(int i=0;i<nk;i++){
                createElmtKontak(pk);
                insertFirstKontak(q,key,pk);
            }
        break;

        case 3 :
            deleteFirstInd(q,phd);
            traversalInd(q);
        break;

        case 4:
            deleteFirstKontak(q,key,phk);
            traversalIndKontak(q);
        break;

        case 5 :
            traversalIndKontak(q);
        break;

        default :
            exit(0);
        }
        system("pause");
    }while(menu!=6);
}
