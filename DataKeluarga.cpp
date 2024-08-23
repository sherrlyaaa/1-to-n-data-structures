#include "DataKeluarga.h"

void mainMenu(List_ortu &o, List_anak &a){
    int menu;
    cout << "-------------------MAIN MENU-------------------" << endl;
    cout << "1. Tambah Data" << endl;
    cout << "2. Hapus Data" << endl;
    cout << "3. Update Data" << endl;
    cout << "4. Tampil Data" << endl;
    cout << "5. Keluar" << endl;
    cout << "       " << endl;
    cout << "Pilih Menu: "; cin >> menu;

     if (menu == 1){
        menuInsert(o, a);
     }else if (menu == 2){
         menuDelete(o, a);
     }else if (menu == 3){
        menuUpdate(o, a);
     }else if (menu == 4){
         menuShow(o, a);
     }else{
         menu5();
     }
}
void menuInsert(List_ortu &o, List_anak &a){
    int menu;
    cout << "-------------------MENU INSERT-------------------" << endl;
    cout << "1. Tambah orang tua" << endl;
    cout << "2. Tambah anak" << endl;
    cout << "3. Back" << endl;
    cout << "      " << endl;
    cout << "Pilih Menu: "; cin >> menu;

    adr_ortu adr_o;
    infotype_ortu info_o;

    adr_anak adr_a;
    infotype_anak info_a;
    if (menu == 1){
        cout << "Masukan nama ayah: "; cin >> info_o.namaAyah;
        cout << "Masukan nama ibu: "; cin >> info_o.namaIbu;
        cout << "Masukan jumlah anak: "; cin >> info_o.jumlahAnak;
        cout << "Masukan alamat: "; cin >> info_o.alamat;
        adr_o = createElemenOrtu(info_o);
        insertOrtu(o, adr_o);
        cout << endl; cout << "Data berhasil diinput" << endl;
        mainMenu(o, a);
    }else if (menu == 2){
        string ayah;
        cout << "Masukan nama ayah: "; cin >> ayah;
        adr_o = findParent(o,ayah);
        if (adr_o != NULL){
            cout << "Masukan nama anak: "; cin >> info_a.nama;
            cout << "Masukan bilAnak: "; cin >> info_a.bilAnak;
            cout << "Masukan status: "; cin >> info_a.status;
            cout << "Masukan usia: "; cin >> info_a.usia;
            adr_a = createElemenAnak(info_a);
            insertAnak(a, adr_a, adr_o);
            cout << endl; cout << "Data berhasil diinput" << endl;
        }else{
            cout << "Data ayah tidak ditemukan" << endl;
        }
        mainMenu(o, a);
    }else{
        mainMenu(o, a);
    }
}
void menuDelete(List_ortu &o, List_anak &a){
    int menu;
    cout << "-------------------MENU DELETE-------------------" << endl;
    cout << "1. Hapus orang tua" << endl;
    cout << "2. Hapus anak" << endl;
    cout << "3. Back" << endl;
    cout << "    " << endl;
    cout << "Pilih Menu: "; cin >> menu;
    string ayah, child;

    if (menu == 1){
        cout << "Masukan nama ayah: "; cin >> ayah;
        adr_ortu adr_o = findParent(o, ayah);
        if (adr_o != NULL){
            deleteAllChild(adr_o, a);
            penentuDeleteOrtu(o, adr_o);
            cout << "Data berhasil dihapus" << endl;
        }else{
            cout << "Nama ayah tidak ditemukan" << endl;
        }
        menuDelete(o, a);
    }else if (menu == 2){
        string nama;
        cout << "Masukan nama ayah: "; cin >> ayah;
        adr_ortu adr_o = findParent(o, ayah);
        if (adr_o != NULL){
            cout << "Masukan nama child: "; cin >> child;
            adr_anak adr_a = findChild(adr_o, child);
            if (adr_a != NULL){
                penentuDeleteAnak(a, adr_a, adr_o);
                cout << "Data berhasil dihapus" << endl;
            }else{
                cout << "Nama anak tidak ditemukan" << endl;
            }
        }else{
            cout << "Nama ayah tidak ditemukan" << endl;
        }
        menuDelete(o, a);
    }else{
        mainMenu(o, a);
    }
}
void menuUpdate(List_ortu &o, List_anak &a){
    int menu;
    cout << "-------------------MENU UPDATE-------------------" << endl;
    cout << "1. Update data orangtua" << endl;
    cout << "2. Update data anak" << endl;
    cout << "3. Back" << endl;
    cout << "     " << endl;
    cout << "Pilih Menu: "; cin >> menu;

    string nama, child;

    if (menu == 1){
        cout << "Masukan nama ayah: "; cin >> nama;
        adr_ortu x = findParent(o, nama);
        if (x != NULL){
            cout << "Silahkan Update: " << endl;
            cout << "Masukan nama ayah: "; cin >> x->info.namaAyah;
            cout << "Masukan nama ibu: "; cin >> x->info.namaIbu;
            cout << "Masukan jumlah anak: "; cin >> x->info.jumlahAnak;
            cout << "Masukan alamat: "; cin >> x->info.alamat;

            cout << "Data berhasil diupdate " << endl;
        }else{
            cout << "Data tidak ditemukan" << endl;
        }
        menuUpdate(o, a);
    }else if (menu == 2){
        cout << "Masukan nama ayah: "; cin >> nama;
        adr_ortu x = findParent(o, nama);
        if (x != NULL){
            cout << "Masukan nama anak: "; cin >> child;
            adr_anak y = findChild(x, child);
            if (y != NULL){
                cout << "Silahkan Update: " << endl;
                cout << "Masukan nama anak: "; cin >> y->info.nama;
                cout << "Masukan bilAnak: "; cin >> y->info.usia;
                cout << "Masukan status: "; cin >> y->info.status;
                cout << "Masukan usia: "; cin >> y->info.bilAnak;
                cout << "Data berhasil diupdate " << endl;
            }else{
                cout << "Data tidak ditemukan" << endl;
            }
        }else{
            cout << "Data tidak ditemukan" << endl;
        }
        menuUpdate(o, a);
    }else{
        mainMenu(o, a);
    }
}
void menuShow(List_ortu &o, List_anak &a){
    int menu;
    cout << "-------------------MENU SHOW-------------------" << endl;
    cout << "1. Semua orang tua dan anak" << endl;
    cout << "2. Semua anak dari orang tua" << endl;
    cout << "3. Anak terbanyak dan tersedikit" << endl;
    cout << "4. Mencari orangtua" << endl;
    cout << "5. Semua orangtua" << endl;
    cout << "6. Back" << endl;
    cout << "    " << endl;
    cout << "Pilih Menu: "; cin >> menu;

    adr_anak adr_a;
    adr_ortu adr_o;
    if (menu == 1){
        adr_ortu p = o.first;
        int i = 1;
        while (p != NULL){
            cout << i << ". " << p->info.namaAyah << " " <<  p->info.namaIbu << " " << p->info.alamat << " " << p->info.jumlahAnak << endl;
            cout << "Nama anak: " << endl;
            adr_a = p->anak;
            while (adr_a != NULL){
                cout << " - " << adr_a->info.nama;
                adr_a = adr_a->next;
            }
            cout << endl;
            p = p->next;
            i++;
        }
        cout << endl;
        menuShow(o, a);
    }else if (menu == 2){
        string ayah;
        cout << "Masukan nama ayah: "; cin >> ayah;
        adr_o = findParent(o, ayah);
        if (adr_o != NULL){
            adr_a = adr_o->anak;
            while (adr_a != NULL){
                cout << " - " << adr_a->info.nama;
                adr_a = adr_a->next;
            }
        }else{
            cout << "Data tidak ditemukan" << endl;
        }
        cout << endl;
        menuShow(o, a);
    }else if (menu == 3){
        int kecil, besar, i;
        adr_ortu Obesar, Okecil;
        adr_o = o.first;
        while (adr_o != NULL){
            i = 0;
            adr_a = adr_o->anak;
            while (adr_a != NULL){
                i++;
                adr_a = adr_a->next;
            }
            if (besar < i){
                besar = i;
                Obesar = adr_o;
            }
            if (kecil > i){
                kecil = i;
                Okecil = adr_o;
            }
            adr_o = adr_o->next;
        }
        cout << "Orang tua yang memiliki anak terbanyak yang terdata adalah: " << Obesar->info.namaAyah << " dengan " << Obesar->info.namaIbu << " mempunyai " << besar << " anak" << endl;
        cout << "Orang tua yang memiliki anak terdikit yang terdata adalah: " << Okecil->info.namaAyah << " dengan " << Okecil->info.namaIbu << " mempunyai " << kecil << " anak" << endl;
        menuShow(o, a);
    }else if  (menu == 4){
        string nama;
        cout << "Masukan nama anak yang ingin dicari: "; cin >> nama;
        cout << nama << " memiliki orang tua bernama: " << endl;

        adr_o = o.first;
        while (adr_o != NULL){
            adr_a = adr_o->anak;
            while (adr_a != NULL){
                if (adr_a->info.nama == nama){
                    cout << " - " << adr_o->info.namaAyah << " dengan " << adr_o->info.namaIbu << endl;
                }
                adr_a = adr_a->next;
            }
            adr_o = adr_o->next;
        }
        menuShow(o, a);
    }else if (menu == 5){
        adr_ortu ortu = o.first;
        while (ortu != NULL){
            cout << "Nama ayah: " << ortu->info.namaAyah << " dan nama ibu: " << ortu->info.namaIbu << endl;
            ortu = ortu->next;
        }
        menuShow(o, a);
    }else{
        mainMenu(o, a);
    }
}
void menu5(){
    cout << endl << "Terimakasih :)" << endl;
}

void createListOrtu(List_ortu &o){
    o.first = NULL;
    o.last = NULL;
}
adr_ortu createElemenOrtu(infotype_ortu p){
    adr_ortu x = new elm_ortu;
    x->info.namaAyah = p.namaAyah;
    x->info.namaIbu = p.namaIbu;
    x->info.alamat = p.alamat;
    x->info.jumlahAnak = p.jumlahAnak;
    x->anak = NULL;
    x->next = NULL;
    x->prev = NULL;
    return x;
}
void insertOrtu(List_ortu &o, adr_ortu p){
    if (o.first == NULL){
        o.first = p;
        o.last = p;
    }else{
        p->prev = o.last;
        o.last->next = p;
        o.last = p;
    }
}
void deleteFirstOrtu(List_ortu &o, adr_ortu &p){
    if (o.first == NULL){
        cout << "Tidak ada data orangtua" << endl;
        p = NULL;
    }else{
        p = o.first;
        o.first = p->next;
        if (o.first != NULL){
            o.first->prev = NULL;
        }else{
            o.last = NULL;
        }
        p->next = NULL;
    }
}
void deleteLastOrtu(List_ortu &o, adr_ortu &p){
    if (o.first == NULL){
        cout << "Tidak ada data orangtua" << endl;
        p = NULL;
    }else{
        p = o.last;
        if (p->prev != NULL){
            o.last = p->prev;
            o.last->next = NULL;
        }else{
            o.first = NULL;
            o.last = NULL;
        }
        p->prev = NULL;
    }
}
void deleteAfterOrtu(List_ortu &o, adr_ortu &p, adr_ortu x){
    if (o.first == NULL){
        cout << "Tidak ada data orangtua" << endl;
        p = NULL;
    }else if (o.first->next == NULL){
		p = o.first;
		o.first = NULL;
		o.last = NULL;
	}else{
        p = x;
        x = x->prev;
        x->next = p->next;
        p->next->prev = x;
        p->next = NULL;
        p->prev = NULL;
    }
}
void penentuDeleteOrtu(List_ortu &o, adr_ortu &p){
    adr_ortu temp = NULL;
    if (p == o.first){
        deleteFirstOrtu(o, temp);
    }else if (p == o.last){
        deleteLastOrtu(o, temp);
    }else{
        deleteAfterOrtu(o, temp, p);
    }
}
//==============================================================

void createListAnak(List_anak &a){
    a.first = NULL;
    a.last = NULL;
}
adr_anak createElemenAnak(infotype_anak p){
    adr_anak x = new elm_anak;
    x->info.nama = p.nama;
    x->info.usia = p.usia;
    x->info.bilAnak = p.bilAnak;
    x->info.status = p.status;
    x->next = NULL;
    x->prev =NULL;
    return x;
}
void insertAnak(List_anak &a, adr_anak p, adr_ortu &o){
    if (o->anak == NULL){
        a.first = p;
        a.last = p;
    }else{
        p->next = a.first;
        a.first->prev = p;
        a.first = p;
    }

    o->anak = p;
}
void deleteFirstAnak(List_anak &a, adr_anak &p, adr_ortu &o){
    if (o->anak == NULL){
        cout << "Tidak ada anak" << endl;
        p = NULL;
    }else{
        p = o->anak;
        if (p->next != NULL){
            a.first = p->next;
            a.first->prev = NULL;
            o->anak = a.first;
        }else{
            a.first = NULL;
            a.last = NULL;
        }
        p->prev = NULL;
        p->next = NULL;
    }
}
void deleteLastAnak(List_anak &a, adr_anak &p, adr_ortu &o){
    if (o->anak == NULL){
        cout << "Tidak ada anak" << endl;
        p = NULL;
    }else{
        p = a.last;

        if (p->prev != NULL){
            a.last = p->prev;
            a.last->next = NULL;
        }else{
            a.first = NULL;
            a.last = NULL;
        }
        p->prev = NULL;
        p->next = NULL;
    }
    o->anak = a.first;
}
void deleteAfterAnak(List_anak &a, adr_anak &p, adr_anak x, adr_ortu &o){
    if (o->anak == NULL || x == NULL){
        cout << "Tidak dapat menghapus elemen yang diberikan" << endl;
        p = NULL;
    }else{
        p = x;

        if (p->prev != NULL){
            p->prev->next = p->next;
        }else{
            a.first = p->next;
        }

        if (p->next != NULL){
            p->next->prev = p->prev;
        }else{
            a.last = p->prev;
        }
        p->prev = NULL;
        p->next = NULL;
    }
}
void penentuDeleteAnak(List_anak &a, adr_anak &p, adr_ortu &o){
    adr_anak temp = NULL;

    if (p == o->anak){
        deleteFirstAnak(a, temp, o);
    }else if (p == a.last){
        deleteLastAnak(a, temp, o);
    }else{
        deleteAfterAnak(a, temp, p, o);
    }
}

adr_anak findChild(adr_ortu o, string nama){
    adr_anak p = o->anak;
    while (p != NULL){
        if (p->info.nama == nama){
            return p;
        }
        p = p->next;
    }
    return NULL;
}

void deleteAllChild(adr_ortu &o, List_anak &a){
    adr_anak p = o->anak;
    adr_anak temp;
    while (p != NULL){
        deleteFirstAnak(a, temp, o);
        p = p->next;
    }
}

adr_ortu findParent(List_ortu o, string ayah){
    adr_ortu p = o.first;
    while (p != NULL){
        if (p->info.namaAyah == ayah){
            return p;
        }
        p = p->next;
    }
    return NULL;
}

bool isAvailable(adr_ortu o, string nama){
    adr_anak temp = o->anak;
    int i = 0;
    while (temp != NULL){
        i++;
        temp = temp->next;
    }
    if (i != o->info.jumlahAnak){
        return true;
    }
    return false;
}
