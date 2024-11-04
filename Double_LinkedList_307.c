#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

// Struktur node untuk double linked list
struct node {
    int data;
    struct node *prev;
    struct node *next;
};
typedef struct node node;

// Fungsi untuk operasi dasar linked list
void tambahAwal(node **head);
void tambahData(node **head);
void tranverse(node *head);
void tambahAkhir(node **head);
void hapusAwal(node **head);
void hapusTengah(node **head);
void hapusAkhir(node **head);
void cariData(node *head);
void hitungData(node *head);
void jumlahkanData(node *head);

// Fungsi utama
int main() {
    node *head = NULL;
    char pilih;

    do {
        system("cls");
        printf("Menu:\n");
        printf("1. Tambah data di awal\n");
        printf("2. Tambah data di tengah list\n");
        printf("3. Tambah data di akhir\n");
        printf("4. Hapus data di awal\n");
        printf("5. Hapus data di tengah\n");
        printf("6. Hapus data di akhir\n");
        printf("7. Cari data\n");
        printf("8. Hitung jumlah data\n");
        printf("9. Jumlahkan seluruh data\n");
        printf("10. Cetak isi list\n");
        printf("Pilihan (q untuk keluar): ");
        fflush(stdin);
        scanf("%c", &pilih);

        switch(pilih) {
            case '1': tambahAwal(&head); break;
            case '2': tambahData(&head); break;
            case '3': tambahAkhir(&head); break;
            case '4': hapusAwal(&head); break;
            case '5': hapusTengah(&head); break;
            case '6': hapusAkhir(&head); break;
            case '7': cariData(head); break;
            case '8': hitungData(head); break;
            case '9': jumlahkanData(head); break;
            case '10': tranverse(head); getch(); break;
            case 'q': printf("Keluar dari program.\n"); break;
            default: printf("Pilihan tidak valid!\n"); getch();
        }
    } while (pilih != 'q');
    
    return 0;
}

// Fungsi untuk menambah data di awal list
void tambahAwal(node **head) {
    int bil;
    node *pNew;

    system("cls");
    printf("Masukkan bilangan: ");
    fflush(stdin);
    scanf("%d", &bil);
    
    pNew = (node *)malloc(sizeof(node));
    if (pNew != NULL) {
        pNew->data = bil;
        pNew->prev = NULL;
        pNew->next = *head;
        if (*head != NULL) {
            (*head)->prev = pNew;
        }
        *head = pNew;
    } else {
        printf("Alokasi memori gagal.\n");
        getch();
    }
}

// Fungsi untuk menambah data di tengah list
void tambahData(node **head) {
    int pos, bil;
    node *pNew, *pCur;

    system("cls");
    tranverse(*head);
    printf("\nPosisi penyisipan setelah data bernilai: ");
    fflush(stdin);
    scanf("%d", &pos);
    printf("Bilangan: ");
    fflush(stdin);
    scanf("%d", &bil);

    if (*head == NULL) {
        printf("List kosong!\n");
        getch();
        return;
    }

    pCur = *head;
    while (pCur != NULL && pCur->data != pos) {
        pCur = pCur->next;
    }

    if (pCur == NULL) {
        printf("Node tidak ditemukan!\n");
        getch();
        return;
    }

    pNew = (node *)malloc(sizeof(node));
    if (pNew != NULL) {
        pNew->data = bil;
        pNew->next = pCur->next;
        pNew->prev = pCur;
        if (pCur->next != NULL) {
            pCur->next->prev = pNew;
        }
        pCur->next = pNew;
    } else {
        printf("Alokasi memori gagal.\n");
        getch();
    }
}

// Fungsi untuk mencetak isi list
void tranverse(node *head) {
    node *pWalker = head;

    while (pWalker != NULL) {
        printf("%d\t", pWalker->data);
        pWalker = pWalker->next;
        printf(" -> ");
    }
    printf("NULL\n");
}

// Fungsi untuk menambah data di akhir list
void tambahAkhir(node **head) {
    int bil;
    node *pNew, *pCur;

    system("cls");
    printf("Masukkan bilangan: ");
    fflush(stdin);
    scanf("%d", &bil);
    
    pNew = (node *)malloc(sizeof(node));
    if (pNew != NULL) {
        pNew->data = bil;
        pNew->next = NULL;
        if (*head == NULL) {
            pNew->prev = NULL;
            *head = pNew;
        } else {
            pCur = *head;
            while (pCur->next != NULL) {
                pCur = pCur->next;
            }
            pCur->next = pNew;
            pNew->prev = pCur;
        }
    } else {
        printf("Alokasi memori gagal.\n");
        getch();
    }
}

// Fungsi untuk menghapus data di awal list
void hapusAwal(node **head) {
    if (*head == NULL) {
        printf("List kosong!\n");
        getch();
        return;
    }

    node *pDel = *head;

    if (pDel->next != NULL) {
        *head = pDel->next;
        (*head)->prev = NULL;
    } else {
        *head = NULL;
    }

    free(pDel);
    printf("Data di awal telah dihapus.\n");
    getch();
}

// Fungsi untuk menghapus data di tengah list
void hapusTengah(node **head) {
    if (*head == NULL) {
        printf("List kosong!\n");
        getch();
        return;
    }

    int bil;
    node *pCur = *head, *pDel = NULL;

    tranverse(*head);
    printf("\nMasukkan nilai yang ingin dihapus: ");
    fflush(stdin);
    scanf("%d", &bil);

    while (pCur != NULL && pCur->data != bil) {
        pCur = pCur->next;
    }

    if (pCur == NULL) {
        printf("Data tidak ditemukan!\n");
        getch();
        return;
    }

    if (pCur->prev != NULL) {
        pCur->prev->next = pCur->next;
    } else {
        *head = pCur->next;
    }

    if (pCur->next != NULL) {
        pCur->next->prev = pCur->prev;
    }

    free(pCur);
    printf("Data di tengah telah dihapus.\n");
    getch();
}

// Fungsi untuk menghapus data di akhir list
void hapusAkhir(node **head) {
    if (*head == NULL) {
        printf("List kosong!\n");
        getch();
        return;
    }

    node *pCur = *head;

    if (pCur->next == NULL) {
        free(pCur);
        *head = NULL;
    } else {
        while (pCur->next != NULL) {
            pCur = pCur->next;
        }
        pCur->prev->next = NULL;
        free(pCur);
    }

    printf("Data di akhir telah dihapus.\n");
    getch();
}

// Fungsi untuk mencari data
void cariData(node *head) {
    if (head == NULL) {
        printf("List kosong!\n");
        getch();
        return;
    }

    int bil;
    node *pCur = head;
    int found = 0;

    system("cls");
    printf("Masukkan data yang ingin dicari: ");
    fflush(stdin);
    scanf("%d", &bil);

    while (pCur != NULL) {
        if (pCur->data == bil) {
            printf("Data %d ditemukan di list!\n", bil);
            found = 1;
            break;
        }
        pCur = pCur->next;
    }

    if (!found) {
        printf("Data %d tidak ditemukan!\n", bil);
    }
    getch();
}

// Fungsi untuk menghitung jumlah node
void hitungData(node *head) {
    int count = 0;
    node *pCur = head;

    if (head == NULL) {
        printf("Jumlah data di list: 0\n");
        getch();
        return;
    }

    while (pCur != NULL) {
        count++;
        pCur = pCur->next;
    }

    printf("Jumlah data di list: %d\n", count);
    getch();
}

// Fungsi untuk menjumlahkan data
void jumlahkanData(node *head) {
    int total = 0;
    node *pCur = head;

    if (head == NULL) {
        printf("List kosong!\n");
        getch();
        return;
    }

    while (pCur != NULL) {
        total += pCur->data;
        pCur = pCur->next;
    }

    printf("Jumlah total data di list: %d\n", total);
    getch();
}