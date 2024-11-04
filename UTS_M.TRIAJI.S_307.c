#include <stdio.h>
#include <string.h>

#define MAX_LINGKARAN 20

struct Peserta {
    char nama[50];
    char jenis_kelamin;
};

void tampilkanKegiatanSemua(struct Peserta peserta[], int jumlah) {
    printf("\nKegiatan di acara api unggun:\n");
    
    for (int i = 0; i < jumlah; i++) {
        printf("Peserta: %s (Jenis kelamin: %c)\n", peserta[i].nama, peserta[i].jenis_kelamin);
        if (peserta[i].jenis_kelamin == 'L') {
            printf("Kegiatan: Mendirikan tenda.\n");
        } else if (peserta[i].jenis_kelamin == 'P') {
            printf("Kegiatan: Memasak di dapur umum.\n");
        } else {
            printf("Kegiatan: Tidak diketahui.\n");
        }
    }
}

int tambahPeserta(struct Peserta lingkaran[], int *jumlah, struct Peserta peserta) {
    if (*jumlah >= MAX_LINGKARAN) {
        printf("Lingkaran sudah penuh!\n");
        return 0;
    }

    lingkaran[*jumlah] = peserta;
    (*jumlah)++;
    return 1;
}

void hapusPeserta(struct Peserta lingkaran[], int *jumlah, char nama[]) {
    for (int i = 0; i < *jumlah; i++) {
        if (strcmp(lingkaran[i].nama, nama) == 0) {
            printf("%s keluar dari lingkaran.\n", lingkaran[i].nama);
            for (int j = i; j < *jumlah - 1; j++) {
                lingkaran[j] = lingkaran[j + 1];
            }
            (*jumlah)--;
            return;
        }
    }
    printf("Peserta dengan nama %s tidak ditemukan.\n", nama);
}

void pisahkanLingkaran(struct Peserta lingkaran[], int jumlah, struct Peserta lingkaranMahasiswa[], int *jumlahMahasiswa, struct Peserta lingkaranMahasiswi[], int *jumlahMahasiswi) {
    for (int i = 0; i < jumlah; i++) {
        if (lingkaran[i].jenis_kelamin == 'L') {
            tambahPeserta(lingkaranMahasiswa, jumlahMahasiswa, lingkaran[i]);
        } else if (lingkaran[i].jenis_kelamin == 'P') {
            tambahPeserta(lingkaranMahasiswi, jumlahMahasiswi, lingkaran[i]);
        }
    }
}

int main() {
    struct Peserta lingkaran[MAX_LINGKARAN];
    int jumlahPeserta = 0;
    struct Peserta lingkaranMahasiswa[MAX_LINGKARAN];
    int jumlahMahasiswa = 0;
    struct Peserta lingkaranMahasiswi[MAX_LINGKARAN];
    int jumlahMahasiswi = 0;

    int pilihan;
    struct Peserta peserta;
    char nama[50];
    
    while (1) {
        printf("\nMenu:\n");
        printf("1. Tambah peserta ke lingkaran\n");
        printf("2. Hapus peserta dari lingkaran\n");
        printf("3. Pisahkan lingkaran menjadi mahasiswa dan mahasiswi\n");
        printf("4. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);

        if (pilihan == 1) {
            if (jumlahPeserta < MAX_LINGKARAN) {
                
                printf("\nMasukkan nama peserta: ");
                scanf("%s", peserta.nama);
                printf("Masukkan jenis kelamin (L/P): ");
                scanf(" %c", &peserta.jenis_kelamin);

                if (tambahPeserta(lingkaran, &jumlahPeserta, peserta)) {
                    printf("Peserta %s ditambahkan ke lingkaran.\n", peserta.nama);
                }
            } else {
                printf("Lingkaran sudah mencapai kapasitas maksimum (20 orang).\n");
            }
        } else if (pilihan == 2) {
            printf("\nMasukkan nama peserta yang ingin keluar: ");
            scanf("%s", nama);
            hapusPeserta(lingkaran, &jumlahPeserta, nama);
        } else if (pilihan == 3) {
            pisahkanLingkaran(lingkaran, jumlahPeserta, lingkaranMahasiswa, &jumlahMahasiswa, lingkaranMahasiswi, &jumlahMahasiswi);
        } else if (pilihan == 4) {
            break;
        } else {
            printf("Pilihan tidak valid. Coba lagi.\n");
        }
    }

    return 0;
}