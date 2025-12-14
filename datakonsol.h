#ifndef DATAKONSOL_H
#define DATAKONSOL_H

#include <string>
using namespace std;

class DataKonsol {
private:
    int id;                 // ID konsol
    string namaKonsol;      // Nama konsol
    double hargaSewa;       // Harga sewa per hari
    bool statusTersedia;    // Status ketersediaan konsol

public:
    /*
     * @param id ID unik konsol
     * @param nama Nama konsol
     * @param harga Harga sewa konsol
     * @param status Status ketersediaan konsol
     */
    DataKonsol(int id, string nama, double harga, bool status);

    /*
     * @param - 
     */
    string getNamaKonsol() const;

    /*
     * @param -
     */
    double getHargaSewa() const;

    /*
     * @param -
     */
    bool isTersedia() const;

    /*
     * @param nama Nama konsol baru
     */
    void setNamaKonsol(const string &nama);

    /*
     * @param harga Harga sewa baru
     */
    void setHargaSewa(double harga);

    /*
     * @param status Status ketersediaan konsol
     */
    void setStatusTersedia(bool status);
};

#endif
