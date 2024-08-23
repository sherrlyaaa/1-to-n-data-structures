#ifndef DATAKELUARGA_H_INCLUDED
#define DATAKELUARGA_H_INCLUDED

#include<iostream>
#include<string>

using namespace std;

struct orangTua{
    string namaAyah;
    string namaIbu;
    string alamat;
    int jumlahAnak;
};
struct anak{
    string nama;
    int bilAnak;
    int usia;
    string status;
};
typedef struct orangTua infotype_ortu;
typedef struct anak infotype_anak;
typedef struct elm_ortu *adr_ortu;
typedef struct elm_anak *adr_anak;
struct List_ortu{
    adr_ortu first;
    adr_ortu last;
};
struct List_anak{
    adr_anak first;
    adr_anak last;
};
struct elm_ortu{
    infotype_ortu info;
    adr_ortu next;
    adr_ortu prev;
    adr_anak anak;
};
struct elm_anak{
    infotype_anak info;
    adr_anak next;
    adr_anak prev;
};
void mainMenu(List_ortu &o, List_anak &a);
void menuInsert(List_ortu &o, List_anak &a);
void menuDelete(List_ortu &o, List_anak &a);
void menuUpdate(List_ortu &o, List_anak &a);
void menuShow(List_ortu &o, List_anak &a);
void menu5();

//procedure Ortu
void createListOrtu(List_ortu &o);
adr_ortu createElemenOrtu(infotype_ortu p);
void insertOrtu(List_ortu &o, adr_ortu p);
void deleteFirstOrtu(List_ortu &o, adr_ortu &p);
void deleteLastOrtu(List_ortu &o, adr_ortu &p);
void deleteAfterOrtu(List_ortu &o, adr_ortu &p, adr_ortu x);
void penentuDeleteOrtu(List_ortu &o, adr_ortu &p);

//procedure anak
void createListAnak(List_anak &a);
adr_anak createElemenAnak(infotype_anak p);
void insertAnak(List_anak &a, adr_anak p, adr_ortu &o);
void deleteFirstAnak(List_anak &a, adr_anak &p, adr_ortu &o);
void deleteLastAnak(List_anak &a, adr_anak &p, adr_ortu &o);
void deleteAfterAnak(List_anak &a, adr_anak &p, adr_anak x, adr_ortu &o);
void penentuDeleteAnak(List_anak &a, adr_anak &p, adr_ortu &o);

adr_anak findChild(adr_ortu o, string nama);
void deleteAllChild(adr_ortu &o, List_anak &a);
adr_ortu findParent(List_ortu o, string ayah);
bool isAvailable(adr_ortu o, string nama);


#endif // DATAKELUARGA_H_INCLUDED
