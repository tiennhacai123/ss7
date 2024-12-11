#include <stdio.h>
#include <stdlib.h>
#define MAX 5

// Cấu trúc dữ liệu cho queue
typedef struct Queue {
    int array[MAX];
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

// Thêm phần tử vào cuối hàng đợi
void enqueue(Queue* queue, int value) {
    if (isFull(queue)) {
        printf("Hàng đợi đã đầy, không thể thêm phần tử.\n");
        return;
    }
    if (isEmpty(queue)) {
        queue->front = 0;
    }
    queue->rear++;
    queue->array[queue->rear] = value;
    printf("Đã thêm phần tử %d vào hàng đợi.\n", value);
}

// Lấy ra phần tử đầu và xóa nó
void dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Hàng đợi rỗng.\n");
        return;
    }
    printf("Phần tử đầu tiên sau khi xóa là: %d\n", queue->array[queue->front]);
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
    printf("Phần tử đầu tiên của hàng đợi là: %d\n", queue->array[queue->front]);
}

void printQueue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Hàng đợi rỗng.\n");
        return;
    }
    printf("Danh sách hàng đợi:\n");
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d  ", queue->array[i]);
    }
    printf("\n");
}

int main() {
    int value;
    Queue queue;
    initial(&queue);
    do {
        printf("\n========================MENU============================");
        printf("\n1. Thêm 1 phần tử vào cuối hàng đợi");
        printf("\n2. In ra danh sách hàng đợi");
        printf("\n3. Lấy ra phần tử đầu tiên của hàng đợi và xóa nó");
        printf("\n4. Lấy ra phần tử đầu tiên của hàng đợi");
        printf("\n0. Thoát");
        int choice;
        printf("\nMời nhập lựa chọn của bạn: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Nhập vào giá trị của bạn: ");
                scanf("%d", &value);
                enqueue(&queue, value);
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
