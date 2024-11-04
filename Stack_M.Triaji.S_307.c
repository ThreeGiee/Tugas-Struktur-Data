#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int data;
    struct node *next;
};
typedef struct node Node;

// Stack structure
typedef struct {
    Node *top;
    int count;
} Stack;

// Function prototypes
void createStack(Stack *stack);
int isEmpty(Stack *stack);
void push(Stack *stack, int data);
int pop(Stack *stack);
int top(Stack *stack);
void destroyStack(Stack *stack);
int stackCount(Stack *stack);

int main() {
    Stack stack;
    char choice;
    int value;

    createStack(&stack);

    do {
        system("cls");
        printf("Pilih opsi:\n");
        printf("1. Push (Tambah data pada stack)\n");
        printf("2. Pop (Hapus data pada stack)\n");
        printf("3. Top (Tampilkan data teratas)\n");
        printf("4. Cek apakah stack kosong\n");
        printf("5. Cek Jumlah data dalam stack\n");
        printf("6. Hancurkan stack\n");
        printf("q. Keluar\n");
        printf("Masukkan pilihan: ");
        fflush(stdin);
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                printf("Masukkan data: ");
                scanf("%d", &value);
                push(&stack, value);
                break;
            case '2':
                if (!isEmpty(&stack)) {
                    printf("Data yang di-pop: %d\n", pop(&stack));
                } else {
                    printf("Stack kosong!\n");
                }
                getch();
                break;
            case '3':
                if (!isEmpty(&stack)) {
                    printf("Data teratas: %d\n", top(&stack));
                } else {
                    printf("Stack kosong!\n");
                }
                getch();
                break;
            case '4':
                printf(isEmpty(&stack) ? "Stack kosong\n" : "Stack tidak kosong\n");
                getch();
                break;
            case '5':
                printf("Jumlah data dalam stack: %d\n", stackCount(&stack));
                getch();
                break;
            case '6':
                destroyStack(&stack);
                printf("Stack telah dihancurkan\n");
                getch();
                break;
            case 'q':
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Pilihan tidak valid!\n");
                getch();
        }
    } while (choice != 'q');

    return 0;
}

// Function definitions
void createStack(Stack *stack) {
    stack->top = NULL;
    stack->count = 0;
}

int isEmpty(Stack *stack) {
    return stack->top == NULL;
}

void push(Stack *stack, int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode != NULL) {
        newNode->data = data;
        newNode->next = stack->top;
        stack->top = newNode;
        stack->count++;
    } else {
        printf("Alokasi memori gagal\n");
    }
}

int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack kosong, tidak bisa pop!\n");
        return -1; 
    }
    Node *temp = stack->top;
    int dataOut = temp->data;
    stack->top = stack->top->next;
    free(temp);
    stack->count--;
    return dataOut;
}

int top(Stack *stack) {
    if (!isEmpty(stack)) {
        return stack->top->data;
    }
    printf("Stack kosong, tidak ada data teratas!\n");
    return -1; 
}

int stackCount(Stack *stack) {
    return stack->count;
}

void destroyStack(Stack *stack) {
    while (!isEmpty(stack)) {
        pop(stack);
    }
}