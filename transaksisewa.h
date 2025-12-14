#ifndef TRANSAKSISEWA_H
#define TRANSAKSISEWA_H

class TransaksiSewa {
public:
    int idTransaksi;    // ID transaksi sewa
    int idKonsol;       // ID konsol yang disewa
    int lamaSewa;       // Lama sewa (hari)
    double totalBiaya;  // Total biaya sewa

    /*
     * @param idTransaksi ID unik transaksi
     * @param idKonsol ID konsol yang disewa
     * @param lama Lama sewa konsol
     * @param harga Harga sewa per hari
     */
    TransaksiSewa(int idTransaksi, int idKonsol, int lama, double harga);
};

#endif
