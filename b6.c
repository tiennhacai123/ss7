#include <stdio.h>
#include <stdlib.h>
#define MAX 5 

// Cấu trúc dữ liệu cho ngăn xếp
typedef struct Deque {
    int array[MAX];
    int front;
    int rear;
} Deque;

// Khởi tạo ngăn xếp rỗng
void initial(Deque* deque) {
    deque->front = -1;
    deque->rear = -1;
}

// Kiểm tra ngăn xếp có rỗng không
int isEmpty(Deque* deque) {
    return (deque->front == -1);
}

// Kiểm tra ngăn xếp đã đầy chưa
int isFull(Deque* deque) {
    return ((deque->front == 0 && deque->rear == MAX - 1) || (deque->rear == (deque->front - 1 + MAX) % MAX));
}

// Thêm phần tử vào đầu ngăn xếp
void addFront(Deque* deque, int data) {
    if (isFull(deque)) {
        printf("Deque đã đầy, không thể thêm phần tử.\n");
        return;
    }
    if (isEmpty(deque)) {
        deque->front = 0;
        deque->rear = 0;
    } else if (deque->front == 0) {
        deque->front = MAX - 1;
    } else {
        deque->front--;
    }
    deque->array[deque->front] = data;
    printf("Thêm phần tử vào đầu: %d\n", data);
}

// Thêm phần tử vào cuối ngăn xếp
void addRear(Deque* deque, int data) {
    if (isFull(deque)) {
        printf("Deque đã đầy, không thể thêm phần tử.\n");
        return;
    }
    if (isEmpty(deque)) {
        deque->front = 0;
        deque->rear = 0;
    } else if (deque->rear == MAX - 1) {
        deque->rear = 0;
    } else {
        deque->rear++;
    }
    deque->array[deque->rear] = data;
    printf("Thêm phần tử vào cuối: %d\n", data);
}

// Lấy phần tử ra từ đầu ngăn xếp
void removeFront(Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque rỗng, không thể lấy phần tử ra.\n");
        return;
    }
    printf("Lấy ra phần tử từ đầu: %d\n", deque->array[deque->front]);
    if (deque->front == deque->rear) {
        deque->front = -1;
        deque->rear = -1;
    } else if (deque->front == MAX - 1) {
        deque->front = 0;
    } else {
        deque->front++;
    }
}

// Lấy phần tử ra từ cuối ngăn xếp
void removeRear(Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque rỗng, không thể lấy phần tử ra.\n");
        return;
    }
    printf("Lấy ra phần tử từ cuối: %d\n", deque->array[deque->rear]);
    if (deque->front == deque->rear) {
        deque->front = -1;
        deque->rear = -1;
    } else if (deque->rear == 0) {
        deque->rear = MAX - 1;
    } else {
        deque->rear--;
    }
}

// In trạng thái hiện tại của ngăn xếp
void printDeque(Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque rỗng.\n");
        return;
    }
    printf("Hàng đợi hiện tại: [");
    int i = deque->front;
    while (i != deque->rear) {
        printf("%d, ", deque->array[i]);
        i = (i + 1) % MAX;
    }
    printf("%d]\n", deque->array[deque->rear]);
}

int main() {
    Deque deque;
    initial(&deque);

    // Thêm phần tử vào Deque
    addFront(&deque, 10);
    addRear(&deque, 20);
    addFront(&deque, 5);

    // In ra trạng thái hiện tại của Deque
    printDeque(&deque);

    // Thực hiện removeFront và in trạng thái
    removeFront(&deque);
    printDeque(&deque);

    // Thực hiện removeRear và in trạng thái
    removeRear(&deque);
    printDeque(&deque);

    return 0;
}
