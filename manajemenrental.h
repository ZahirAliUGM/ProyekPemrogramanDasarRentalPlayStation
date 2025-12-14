#ifndef MANAJEMENRENTAL_H
#define MANAJEMENRENTAL_H

#include <vector>
#include "DataKonsol.h"
#include "TransaksiSewa.h"
using namespace std;

class ManajemenRental {
private:
    vector<DataKonsol> databaseKonsol;        // Menyimpan data konsol
    vector<TransaksiSewa> databaseTransaksi;  // Menyimpan data transaksi
    bool isAdmin;                             // Status login admin

public:
    /*
     * @param -
     */
    void loginAdmin();

    /*
     * @param -
     */
    void muatData();

    /*
     * @param -
     */
    void simpanData();

    /*
     * @param -
     */
    void tambahKonsol();

    /*
     * @param -
     */
    void tampilkanKonsol();

    /*
     * @param -
     */
    void cariKonsol();

    /*
     * @param -
     */
    void editKonsol();

    /*
     * @param -
     */
    void hapusKonsol();

    /*
     * @param -
     */
    void sewaKonsol();

    /*
     * @param -
     */
    void pengembalianKonsol();

    /*
     * @param -
     */
    void menu();
};

#endif
