#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Barang {
    int id;
    string nama;
    int jumlah;
    double harga;
};

class Gudang {
private:
    vector<Barang> barangList;

public:
    // Menambahkan data barang
    void tambahBarang(const Barang& barang) {
        barangList.push_back(barang);
        cout << "Barang berhasil ditambahkan.\n";
    }

    // Menghapus data barang
    void hapusBarang(int id) {
        auto it = remove_if(barangList.begin(), barangList.end(), [id](const Barang& b) {
            return b.id == id;
        });
        if (it != barangList.end()) {
            barangList.erase(it, barangList.end());
            cout << "Barang berhasil dihapus.\n";
        } else {
            cout << "Barang dengan ID " << id << " tidak ditemukan.\n";
        }
    }

    // Mencari barang berdasarkan ID
    void cariBarang(int id) {
        auto it = find_if(barangList.begin(), barangList.end(), [id](const Barang& b) {
            return b.id == id;
        });
        if (it != barangList.end()) {
            tampilkanBarang(*it);
        } else {
            cout << "Barang dengan ID " << id << " tidak ditemukan.\n";
        }
    }

    // Mengedit atau memperbarui data barang
    void editBarang(int id, const Barang& barangBaru) {
        auto it = find_if(barangList.begin(), barangList.end(), [id](const Barang& b) {
            return b.id == id;
        });
        if (it != barangList.end()) {
            *it = barangBaru;
            cout << "Barang berhasil diperbarui.\n";
        } else {
            cout << "Barang dengan ID " << id << " tidak ditemukan.\n";
        }
    }

    // Menampilkan data barang
    void tampilkanBarang(const Barang& barang) {
        cout << "ID: " << barang.id << "\n"
             << "Nama: " << barang.nama << "\n"
             << "Jumlah: " << barang.jumlah << "\n"
             << "Harga: " << barang.harga << "\n";
    }

    // Menampilkan semua data barang
    void tampilkanSemuaBarang() {
        for (const auto& barang : barangList) {
            tampilkanBarang(barang);
            cout << "---------------------\n";
        }
    }
};

void tampilkanMenu() {
    cout << "===== Menu Gudang =====\n";
    cout << "1. Tambah Barang\n";
    cout << "2. Hapus Barang\n";
    cout << "3. Cari Barang\n";
    cout << "4. Edit Barang\n";
    cout << "5. Tampilkan Semua Barang\n";
    cout << "6. Keluar\n";
    cout << "=======================\n";
    cout << "Pilih menu: ";
}

int main() {
    Gudang gudang;
    int pilihan;

    do {
        tampilkanMenu();
        cin >> pilihan;

        switch (pilihan) {
        case 1: {
            Barang barang;
            cout << "Masukkan ID Barang: ";
            cin >> barang.id;
            cout << "Masukkan Nama Barang: ";
            cin.ignore();
            getline(cin, barang.nama);
            cout << "Masukkan Jumlah Barang: ";
            cin >> barang.jumlah;
            cout << "Masukkan Harga Barang: ";
            cin >> barang.harga;
            gudang.tambahBarang(barang);
            break;
        }
        case 2: {
            int id;
            cout << "Masukkan ID Barang yang akan dihapus: ";
            cin >> id;
            gudang.hapusBarang(id);
            break;
        }
        case 3: {
            int id;
            cout << "Masukkan ID Barang yang akan dicari: ";
            cin >> id;
            gudang.cariBarang(id);
            break;
        }
        case 4: {
            int id;
            Barang barang;
            cout << "Masukkan ID Barang yang akan diedit: ";
            cin >> id;
            cout << "Masukkan Nama Barang baru: ";
            cin.ignore();
            getline(cin, barang.nama);
            cout << "Masukkan Jumlah Barang baru: ";
            cin >> barang.jumlah;
            cout << "Masukkan Harga Barang baru: ";
            cin >> barang.harga;
            barang.id = id;
            gudang.editBarang(id, barang);
            break;
        }
        case 5:
            cout << "\nDaftar semua barang di gudang:\n";
            gudang.tampilkanSemuaBarang();
            break;
        case 6:
            cout << "Keluar dari program.\n";
            break;
        default:
            cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }
    } while (pilihan != 6);

    return 0;
}
