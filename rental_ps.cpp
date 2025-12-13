#include <iostream>
#include <vector>
#include <iomanip>
#include <limits>
using namespace std;

/* =========================
   CLASS DATAKONSOL
   ========================= */
class DataKonsol {
private:
    int id;
    string namaKonsol;
    double hargaSewa;
    bool statusTersedia;

public:
    DataKonsol(int i, string n, double h, bool s)
        : id(i), namaKonsol(n), hargaSewa(h), statusTersedia(s) {}

    int getId() const { return id; }
    string getNama() const { return namaKonsol; }
    double getHarga() const { return hargaSewa; }
    bool tersedia() const { return statusTersedia; }

    void setHarga(double h) { hargaSewa = h; }
    void setStatus(bool s) { statusTersedia = s; }
};

/* =========================
   CLASS TRANSAKSISEWA
   ========================= */
class TransaksiSewa {
public:
    int idTransaksi;
    int idKonsol;
    int lamaSewa;
    double totalBiaya;

    TransaksiSewa(int idT, int idK, int lama, double harga)
        : idTransaksi(idT),
          idKonsol(idK),
          lamaSewa(lama),
          totalBiaya(lama * harga) {}
};

/* =========================
   CLASS MANAJEMENRENTAL
   ========================= */
class ManajemenRental {
private:
    vector<DataKonsol> konsol;
    vector<TransaksiSewa> transaksi;
    int nextTransaksi = 1;
    bool isAdmin = false;

    void clearInput() {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

public:
    /* ===== LOGIN ADMIN ===== */
    void loginAdmin() {
        string user, pass;
        cout << "\n=== LOGIN ADMIN ===\n";
        cout << "Username: ";
        cin >> user;
        cout << "Password: ";
        cin >> pass;

        if (user == "admin" && pass == "123") {
            isAdmin = true;
            cout << "Login admin berhasil.\n";
        } else {
            cout << "Login gagal. Masuk sebagai pelanggan.\n";
        }
    }

    /* ===== FITUR ===== */
    void muatData() {
        cout << "Fitur muat data belum diaktifkan.\n";
    }

    void simpanData() {
        cout << "Fitur simpan data belum diaktifkan.\n";
    }

    void tambahKonsol() {
        int id;
        double harga;
        string nama;

        cout << "ID Konsol   : ";
        while (!(cin >> id)) {
            clearInput();
            cout << "Masukkan angka! ID Konsol: ";
        }
        clearInput();

        cout << "Nama Konsol : ";
        getline(cin, nama);

        cout << "Harga Sewa  : ";
        while (!(cin >> harga)) {
            clearInput();
            cout << "Masukkan angka! Harga Sewa: ";
        }

        konsol.emplace_back(id, nama, harga, true);
        cout << "Konsol berhasil ditambahkan.\n";
    }

    void tampilkanKonsol() {
        if (konsol.empty()) {
            cout << "Belum ada data konsol.\n";
            return;
        }

        cout << left << setw(5) << "ID"
             << setw(20) << "Nama"
             << setw(12) << "Harga"
             << "Status\n";

        for (auto &k : konsol) {
            cout << left << setw(5) << k.getId()
                 << setw(20) << k.getNama()
                 << setw(12) << k.getHarga()
                 << (k.tersedia() ? "Tersedia" : "Disewa") << endl;
        }
    }

    void cariKonsol() {
        string cari;
        clearInput();
        cout << "Cari nama konsol: ";
        getline(cin, cari);

        for (auto &k : konsol) {
            if (k.getNama() == cari) {
                cout << "Ditemukan -> "
                     << k.getNama()
                     << " | Harga: " << k.getHarga() << endl;
                return;
            }
        }
        cout << "Konsol tidak ditemukan.\n";
    }

    void editKonsol() {
        int id;
        double harga;
        cout << "ID Konsol: ";
        cin >> id;

        for (auto &k : konsol) {
            if (k.getId() == id) {
                cout << "Harga baru: ";
                cin >> harga;
                k.setHarga(harga);
                cout << "Data konsol diperbarui.\n";
                return;
            }
        }
        cout << "ID konsol tidak ditemukan.\n";
    }

    void hapusKonsol() {
        int id;
        cout << "ID Konsol: ";
        cin >> id;

        for (int i = 0; i < (int)konsol.size(); i++) {
            if (konsol[i].getId() == id) {
                konsol.erase(konsol.begin() + i);
                cout << "Konsol berhasil dihapus.\n";
                return;
            }
        }
        cout << "ID konsol tidak ditemukan.\n";
    }

    void sewaKonsol() {
        int id, lama;
        cout << "ID Konsol       : ";
        cin >> id;
        cout << "Lama sewa (hari): ";
        cin >> lama;

        for (auto &k : konsol) {
            if (k.getId() == id && k.tersedia()) {
                k.setStatus(false);
                transaksi.emplace_back(
                    nextTransaksi++, id, lama, k.getHarga());
                cout << "Sewa berhasil.\n";
                return;
            }
        }
        cout << "Konsol tidak tersedia.\n";
    }

    void pengembalianKonsol() {
        int id;
        cout << "ID Transaksi: ";
        cin >> id;

        for (auto &t : transaksi) {
            if (t.idTransaksi == id) {
                for (auto &k : konsol) {
                    if (k.getId() == t.idKonsol) {
                        k.setStatus(true);
                        cout << "Total biaya: " << t.totalBiaya << endl;
                        cout << "Pengembalian berhasil.\n";
                        return;
                    }
                }
            }
        }
        cout << "Transaksi tidak ditemukan.\n";
    }

    /* ===== MENU UTAMA ===== */
    void menu() {
        int pilih;
        char jawab;

        cout << "Login sebagai admin? (y/n): ";
        cin >> jawab;
        if (jawab == 'y' || jawab == 'Y') {
            loginAdmin();
        }

        while (true) {
            cout << "\n===================================\n";
            cout << "APLIKASI RENTAL PLAYSTATION\n";
            cout << "===================================\n";

            if (isAdmin) {
                cout << "1. Muat Data\n";
                cout << "2. Simpan Data\n";
                cout << "3. Tambah Konsol\n";
                cout << "6. Edit Konsol\n";
                cout << "7. Hapus Konsol\n";
                cout << "9. Pengembalian Konsol\n";
            }

            cout << "4. Tampilkan Konsol\n";
            cout << "5. Cari Konsol\n";
            cout << "8. Sewa Konsol\n";
            cout << "0. Keluar\n";
            cout << "Pilih menu: ";

            cin >> pilih;
            if (cin.fail()) {
                clearInput();
                cout << "Input tidak valid.\n";
                continue;
            }

            switch (pilih) {
                case 1:
                    if (isAdmin) muatData();
                    else cout << "Akses ditolak.\n";
                    break;
                case 2:
                    if (isAdmin) simpanData();
                    else cout << "Akses ditolak.\n";
                    break;
                case 3:
                    if (isAdmin) tambahKonsol();
                    else cout << "Akses ditolak.\n";
                    break;
                case 4:
                    tampilkanKonsol();
                    break;
                case 5:
                    cariKonsol();
                    break;
                case 6:
                    if (isAdmin) editKonsol();
                    else cout << "Akses ditolak.\n";
                    break;
                case 7:
                    if (isAdmin) hapusKonsol();
                    else cout << "Akses ditolak.\n";
                    break;
                case 8:
                    sewaKonsol();
                    break;
                case 9:
                    if (isAdmin) pengembalianKonsol();
                    else cout << "Akses ditolak.\n";
                    break;
                case 0:
                    cout << "Program selesai.\n";
                    return;
                default:
                    cout << "Menu tidak tersedia.\n";
            }
        }
    }
};

/* =========================
   MAIN PROGRAM
   ========================= */
int main() {
    ManajemenRental app;
    app.menu();
    return 0;
}



