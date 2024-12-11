#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 5

// Cấu trúc dữ liệu cho hàng đợi ưu tiên
typedef struct Queue {
    int priority[MAX];
    char data[MAX][100];
    int front;
    int rear;
} Queue;

// Khởi tạo hàng đợi
void initial(Queue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

// Kiểm tra hàng đợi đã đầy chưa
int isFull(Queue* queue) {
    return (queue->rear >= MAX - 1);
}

// Kiểm tra hàng đợi có rỗng không
int isEmpty(Queue* queue) {
    return (queue->front == -1);
}

// Thêm phần tử vào hàng đợi theo thứ tự ưu tiên
void enqueue(Queue* queue, int priority, char data[]) {
    if (isFull(queue)) {
        printf("Hàng đợi đã đầy, không thể thêm phần tử.\n");
        return;
    }
    if (isEmpty(queue)) {
        queue->front = 0;
        queue->rear = 0;
        queue->priority[0] = priority;
        strcpy(queue->data[0], data);
    } else {
        int i = queue->rear;
        while (i >= queue->front && priority < queue->priority[i]) {
            queue->priority[i + 1] = queue->priority[i];
            strcpy(queue->data[i + 1], queue->data[i]);
            i--;
        }
        queue->priority[i + 1] = priority;
        strcpy(queue->data[i + 1], data);
        queue->rear++;
    }
    printf("Đã thêm phần tử (%d, \"%s\") vào hàng đợi.\n", priority, data);
}

// Lấy ra phần tử có ưu tiên cao nhất và xóa nó
void dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Hàng đợi rỗng.\n");
        return;
    }
    printf("Phần tử ưu tiên cao nhất: \"%s\" (ưu tiên %d)\n", queue->data[queue->front], queue->priority[queue->front]);
    queue->front++;
    if (queue->front > queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    }
}

// Lấy ra phần tử đầu mà không xóa
void peek(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Hàng đợi rỗng.\n");
        return;
    }
    printf("Phần tử đầu tiên của hàng đợi là: \"%s\" (ưu tiên %d)\n", queue->data[queue->front], queue->priority[queue->front]);
}

void printQueue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Hàng đợi rỗng.\n");
        return;
    }
    printf("Danh sách hàng đợi:\n");
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("(%d, \"%s\")  ", queue->priority[i], queue->data[i]);
    }
    printf("\n");
}

int main() {
    char data[100];
    int priority;
    Queue queue;
    initial(&queue);

    do {
        printf("\n========================MENU============================");
        printf("\n1. Thêm 1 phần tử vào hàng đợi theo ưu tiên");
        printf("\n2. In ra danh sách hàng đợi");
        printf("\n3. Lấy ra phần tử ưu tiên cao nhất và xóa nó");
        printf("\n4. Lấy ra phần tử ưu tiên cao nhất mà không xóa");
        printf("\n0. Thoát");
        int choice;
        printf("\nMời nhập lựa chọn của bạn: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Nhập mức độ ưu tiên (số nguyên): ");
                scanf("%d", &priority);
                printf("Nhập dữ liệu: ");
                scanf("%s", data);
                enqueue(&queue, priority, data);
                break;
            case 2:
                printQueue(&queue);
                break;
            case 3:
                dequeue(&queue);
                break;
            case 4:
                peek(&queue);
                break;
            case 0:
                exit(0);
            default:
                printf("\nVui lòng chọn lại.\n");
        }
    } while (1);

    return 0;
}
