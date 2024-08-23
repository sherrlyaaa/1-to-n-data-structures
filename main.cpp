#include <iostream>
#include "DataKeluarga.h"
using namespace std;

int main()
{
    List_ortu o;
    List_anak a;

    createListOrtu(o);
    createListAnak(a);

    infotype_ortu p;
    adr_ortu adr_o;
    p.namaAyah = "David"; p.namaIbu = "Rachel"; p.jumlahAnak = 3; p.alamat = "Bekasi";
    adr_o = createElemenOrtu(p);
    insertOrtu(o, adr_o);

    p.namaAyah = "Michael"; p.namaIbu = "Sarah"; p.jumlahAnak = 1; p.alamat = "Bandung";
    adr_o = createElemenOrtu(p);
    insertOrtu(o, adr_o);

    p.namaAyah = "Andrew"; p.namaIbu = "Grace"; p.jumlahAnak = 0; p.alamat = "Karawang";
    adr_o = createElemenOrtu(p);
    insertOrtu(o, adr_o);

    p.namaAyah = "Daniel"; p.namaIbu = "Hannah"; p.jumlahAnak = 2; p.alamat = "Depok";
    adr_o = createElemenOrtu(p);
    insertOrtu(o, adr_o);

    p.namaAyah = "Matthew"; p.namaIbu = "Laura"; p.jumlahAnak = 3; p.alamat = "Jogja";
    adr_o = createElemenOrtu(p);
    insertOrtu(o, adr_o);

    //==========================================================================================

    infotype_anak x;
    adr_anak adr_a;

    x.nama = "Elwy"; x.usia = 15; x.bilAnak = 1; x.status = "Pelajar";
    adr_a = createElemenAnak(x);
    adr_o = findParent(o, "David");
    insertAnak(a, adr_a, adr_o);

    x.nama = "Emily"; x.usia = 12; x.bilAnak = 2; x.status = "Pelajar";
    adr_a = createElemenAnak(x);
    adr_o = findParent(o, "David");
    insertAnak(a, adr_a, adr_o);

    x.nama = "Jessica"; x.usia = 9; x.bilAnak = 3; x.status = "Pelajar";
    adr_a = createElemenAnak(x);
    adr_o = findParent(o, "David");
    insertAnak(a, adr_a, adr_o);

    x.nama = "Grace"; x.usia = 18; x.bilAnak = 1; x.status = "Mahasiswa";
    adr_a = createElemenAnak(x);
    adr_o = findParent(o, "Michael");
    insertAnak(a, adr_a, adr_o);

    x.nama = "Olivia"; x.usia = 25; x.bilAnak = 1; x.status = "Bekerja";
    adr_a = createElemenAnak(x);
    adr_o = findParent(o, "Daniel");
    insertAnak(a, adr_a, adr_o);

    x.nama = "Peter"; x.usia = 19; x.bilAnak = 2; x.status = "Mahasiswa";
    adr_a = createElemenAnak(x);
    adr_o = findParent(o, "Daniel");
    insertAnak(a, adr_a, adr_o);

    x.nama = "Verta"; x.usia = 25; x.bilAnak = 1; x.status = "Bekerja";
    adr_a = createElemenAnak(x);
    adr_o = findParent(o, "Matthew");
    insertAnak(a, adr_a, adr_o);

    x.nama = "Paul"; x.usia = 18; x.bilAnak = 2; x.status = "Mahasiswa";
    adr_a = createElemenAnak(x);
    adr_o = findParent(o, "Matthew");
    insertAnak(a, adr_a, adr_o);

    x.nama = "Megan"; x.usia = 11; x.bilAnak = 3; x.status = "Pelajar";
    adr_a = createElemenAnak(x);
    adr_o = findParent(o, "Matthew");
    insertAnak(a, adr_a, adr_o);

    mainMenu(o, a);
    return 0;
}
