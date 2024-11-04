#include <stdio.h>
#include <stdlib.h>

//========================================================

struct node {
    int data;
    struct node *next;
};
typedef struct node node;

// Fungsi deklarasi
void tambahAwal(node **head);
void tambahData(node **head);
void tranverse(node *head);
void tambahAkhir(node **head);
void hapusAwal(node **head);
void hapusTengah(node **head, int val);
void hapusAkhir(node **head);
void cariData(node *head, int val);
int hitungJumlahNode(node *head);
int jumlahkanData(node *head);

//========================================================

int main() {
    node *head = NULL;
    char pilih;
    int val;

    do {
        system("cls");
        printf("Masukkan pilihan:\n");
        printf("0. Tambah data di awal\n");
        printf("1. Tambah data di tengah list\n");
        printf("2. Cetak isi list\n");
        printf("3. Tambah data di akhir linked list\n");
        printf("4. Hapus data di awal linked list\n");
        printf("5. Hapus data di tengah linked list\n");
        printf("6. Hapus data di akhir linked list\n");
        printf("7. Pencarian data dalam linked list\n");
        printf("8. Menampilkan informasi jumlah data di linked list\n");
        printf("9. Menampilkan hasil penjumlahan dari semua data di linked list\n"); 
        printf("MASUKKAN PILIHAN (tekan q untuk keluar): ");
        fflush(stdin);
        scanf("%c", &pilih);

        switch (pilih) {
            case '0':
                tambahAwal(&head);
                break;
            case '1':
                tambahData(&head);
                break;
            case '2':
                tranverse(head);
                printf("\nTekan tombol apa saja untuk melanjutkan...");
                fflush(stdin);
                getchar();  
                break;
            case '3':
                tambahAkhir(&head);
                break;
            case '4':
                hapusAwal(&head);
                break;
            case '5':
                printf("Masukkan nilai yang akan dihapus: ");
                scanf("%d", &val);
                hapusTengah(&head, val);
                break;
            case '6':
                hapusAkhir(&head);
                break;
            case '7':
                printf("Masukkan nilai yang ingin dicari: ");
                scanf("%d", &val);
                cariData(head, val);
                printf("\nTekan tombol apa saja untuk melanjutkan...");
                fflush(stdin);
                getchar();  
                break;
            case '8':
                hitungJumlahNode(head);
                printf("\nTekan tombol apa saja untuk melanjutkan...");
                fflush(stdin);
                getchar();  
                break;
            case '9':
                jumlahkanData(head);
                printf("\nTekan tombol apa saja untuk melanjutkan...");
                fflush(stdin);
                getchar();  
                break;
            case 'q':
                break;
            default:
                printf("Pilihan tidak valid!\n");
                printf("Tekan tombol apa saja untuk melanjutkan...");
                fflush(stdin);
                getchar();  
        }
    } while (pilih != 'q');

    return 0;
}

//========================================================

void tambahAwal(node **head) {
    int bil;
    node *pNew;

    system("cls");
    printf("Masukkan bilangan: ");
    scanf("%d", &bil);
    pNew = (node *)malloc(sizeof(node));

    if (pNew != NULL) {
        pNew->data = bil;
        pNew->next = NULL;

        if (*head == NULL) {
            *head = pNew;
            pNew->next = *head; 
        } else {
            node *pCur = *head;
            while (pCur->next != *head) {
                pCur = pCur->next;
            }
            pCur->next = pNew; 
            pNew->next = *head; 
            *head = pNew; 
        }
        printf("Node dengan data %d berhasil ditambahkan di awal.\n", bil);
    } else {
        printf("Alokasi memori gagal\n");
        getchar();
    }
}

//========================================================

void tambahData(node **head) {
    int pos, bil;
    node *pNew, *pCur;

    system("cls");
    tranverse(*head);
    printf("\nPosisi penyisipan setelah data bernilai: ");
    scanf("%d", &pos);
    printf("\nBilangan: ");
    scanf("%d", &bil);

    pCur = *head;
    while (pCur != NULL && pCur->data != pos) {
        pCur = pCur->next;
        if (pCur == *head) {
            printf("\nNode tidak ditemukan.\n");
            return;
        }
    }

    pNew = (node *)malloc(sizeof(node));

    if (pNew == NULL) {
        printf("\nAlokasi memori gagal\n");
        getchar();
        return;
    }

    pNew->data = bil;

    if (*head == NULL) {
        *head = pNew;
        pNew->next = *head; 
    } else {
        pNew->next = pCur->next; 
        pCur->next = pNew; 
    }
    printf("Node dengan data %d berhasil ditambahkan di tengah.\n", bil);
}

//========================================================

void tambahAkhir(node **head) {
    int bil;
    node *pNew, *pCur;

    system("cls");
    printf("Masukkan bilangan: ");
    scanf("%d", &bil);

    pNew = (node *)malloc(sizeof(node));
    if (pNew != NULL) {
        pNew->data = bil;
        pNew->next = NULL;

        if (*head == NULL) {
            *head = pNew;
            pNew->next = *head; 
        } else {
            pCur = *head;
            while (pCur->next != *head) {
                pCur = pCur->next;
            }
            pCur->next = pNew; 
            pNew->next = *head; 
        }
        printf("Node dengan data %d berhasil ditambahkan di akhir.\n", bil);
    } else {
        printf("Alokasi memori gagal\n");
        getchar();
    }
}

//========================================================

void hapusAwal(node **head) {
    node *pTemp;
    if (*head == NULL) {
        printf("List kosong, tidak ada yang bisa dihapus.\n");
    } else {
        pTemp = *head;
        if (pTemp->next == *head) { 
            free(pTemp);
            *head = NULL;
        } else {
            node *pCur = *head;
            while (pCur->next != *head) {
                pCur = pCur->next; 
            }
            *head = (*head)->next; 
            pCur->next = *head; 
            free(pTemp);
        }
        printf("Data di awal berhasil dihapus.\n");
        getchar();
    }
}

//========================================================

void hapusTengah(node **head, int val) {
    node *pCur, *pPrev;
    pCur = *head;
    pPrev = NULL;

    if (*head == NULL) {
        printf("List kosong, tidak ada yang bisa dihapus.\n");
        return;
    }

    do {
        if (pCur->data == val) {
            if (pPrev == NULL) { 
                hapusAwal(head);
            } else {
                pPrev->next = pCur->next;
                free(pCur);
                printf("Node dengan nilai %d berhasil dihapus.\n", val);
            }
            return;
        }
        pPrev = pCur;
        pCur = pCur->next;
    } while (pCur != *head);

    printf("Node dengan nilai %d tidak ditemukan.\n", val);
    getchar();
}

//========================================================

void hapusAkhir(node **head) {
    node *pCur, *pPrev;
    pCur = *head;
    pPrev = NULL;

    if (*head == NULL) {
        printf("List kosong, tidak ada yang bisa dihapus.\n");
        return;
    }

    if (pCur->next == *head) { 
        free(pCur);
        *head = NULL;
        printf("Data di akhir berhasil dihapus.\n");
        return;
    }

    while (pCur->next != *head) {
        pPrev = pCur;
        pCur = pCur->next;
    }

    pPrev->next = *head; 
    free(pCur);
    printf("Data di akhir berhasil dihapus.\n");
    getchar();
}

//========================================================

void cariData(node *head, int val) {
    node *pCur = head;

    if (head == NULL) {
        printf("List kosong, tidak ada yang bisa dicari.\n");
        return;
    }

    do {
        if (pCur->data == val) {
            printf("Data %d ditemukan dalam linked list.\n", val);
            return;
        }
        pCur = pCur->next;
    } while (pCur != head);

    printf("Data %d tidak ditemukan.\n", val);
    getchar();
}

//========================================================

int hitungJumlahNode(node *head) {
    int count = 0;
    node *pCur = head;

    if (head == NULL) {
        printf("Jumlah node di linked list: %d\n", count);
        return count;
    }

    do {
        count++;
        pCur = pCur->next;
    } while (pCur != head);
    
    printf("Jumlah node di linked list: %d\n", count);
    return count;
}

//========================================================

int jumlahkanData(node *head) {
    int sum = 0;
    node *pCur = head;

    if (head == NULL) {
        printf("Jumlah seluruh data di linked list: %d\n", sum);
        return sum;
    }

    do {
        sum += pCur->data;
        pCur = pCur->next;
    } while (pCur != head);
    
    printf("Jumlah seluruh data di linked list: %d\n", sum);
    return sum;
}

//========================================================

void tranverse(node *head) {
    node *pWalker;

    system("cls");
    if (head == NULL) {
        printf("Linked list kosong.\n");
    } else {
        pWalker = head;
        do {
            printf("%d -> ", pWalker->data);
            pWalker = pWalker->next;
        } while (pWalker != head);
        printf("HEAD (kembali ke awal)\n");
    }
}
