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
    queue->rear = - 1;
    queue->array = new int[queue->capacity];
}

bool isEmpty(Queue *queue)
{
    return queue->size == 0 ? true : false;
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

void printQueue(Queue *queue)
{
    if (isEmpty(queue))
    {
        cout << "Queue is empty!" << endl;
        return;
    }
    for (int i = 0; i < queue->size; i++)
    {
        cout << queue->array[i] << " ";
    }
}

int displayFront(Queue *queue)
{
    if (isEmpty(queue))
    {
        cout << "Queue is empty" << endl;
        return 0;
    }
    return queue->array[queue->front];
}

void nhapMang(int n, int a[255][255])
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cout << "a[" << i << "][" << j << "]= ";
            cin >> a[i][j];
        }
}

void xuatMang(int n, int a[255][255])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
}

int checkVisited(int n, int arr[255])
{
    for (int i = 0; i < n; i++)
        if (arr[i] == 0)
            return 0;
    return 1;
}

void bfs(int n, int a[255][255], int start)
{
    Queue *q = new Queue;
    initQueue(q, n);
    // khoi tao queue voi capacity = n
    int visited[n] = {}; // mang visited luu cac dinh da visit

    enQueue(q, start);  // them dinh khoi dau vao hang cho
    visited[start] = 1; // gan dinh khoi dau da visit
    cout << start << " ";
    while (!isEmpty(q))
    {
        int k = displayFront(q); // lay dinh tu queue de kiem tra
        for (int i = 0; i < n; i++)
        {
            if (a[k][i] != 0 && visited[i] == 0)
            {
                enQueue(q, i);
                visited[i] = 1;
                cout << i << " ";
            }
        }
        deQueue(q);
    }
}

int main()
{
    int n, start;

    int a[255][255] = {};
    cout << "Nhap so dinh cua do thi: ";
    cin >> n;
    nhapMang(n, a);
    xuatMang(n, a);
    cout << "Nhap dinh khoi dau: ";
    cin >> start;
    bfs(n, a, start);
}