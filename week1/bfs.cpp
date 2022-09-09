#include <bits/stdc++.h>
using namespace std;

struct Queue
{
    int front, rear, size;
    unsigned capacity;
    int *array;
};

void initQueue(Queue *queue, unsigned capacity)
{
    queue->capacity = capacity;
    queue->front = 0;
    queue->size = 0;
    queue->rear = queue->size - 1;
    queue->array = new int[queue->capacity];
}

bool isEmpty(Queue *queue)
{
    return queue->size == 0;
}

void enQueue(Queue *queue, int item)
{
    if (queue->size == queue->capacity)
    {
        cout << "Queue is full, can't add more items!" << endl;
        return;
    }
    queue->rear++;
    queue->array[queue->rear] = item;
    queue->size++;
}

int deQueue(Queue *queue)
{
    if (isEmpty(queue))
    {
        cout << "Queue is empty, can't dequeue" << endl;
        return 0;
    }
    int item = queue->front;
    for (int i = 0; i < queue->size; i++)
    {
        queue->array[i] = queue->array[i + 1];
    }
    queue->size--;
    queue->rear--;
    return item;
}

void nhapMang(int n, int a[255][255])
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 255; j++)
        {
            cout << "a[" << i << "][" << j << "]= ";
            cin >> a[i][j];
        }
}

void xuatMang(int n, int a[255][255])
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 255; j++)
            cout << a[i][j] << " ";
}

void bfs(int n, int a[255][255]) {
    
}

int main()
{
    int n, a[255][255];
    cout << "Nhap so dinh cua do thi: ";
    cin >> n;
    nhapMang(n, a);
    bfs(n, a);
}