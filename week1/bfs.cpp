#include <bits/stdc++.h>
using namespace std;

FILE *f;

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
    queue->rear = -1;
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
    int item = queue->array[queue->front];
    for (int i = 0; i < queue->size; i++)
    {
        queue->array[i] = queue->array[i + 1];
    }
    queue->size--;
    queue->rear--;
    return item;
}

void readFile(int &n, int a[255][255])
{
    f = fopen("graph.txt", "r");
    fscanf(f, "%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            fscanf(f, "%d", &a[i][j]);
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
    int visited[n] = {}; // mang visited luu co hieu cac dinh da visit

    enQueue(q, start);  // them dinh khoi dau vao hang cho
    visited[start] = 1; // gan dinh khoi dau da visit
    cout << start << " ";
    while (!isEmpty(q)) // kiem tra toan bo cac dinh visited hay chua
    {
        int k = deQueue(q); // lay dinh tu queue de kiem tra
        for (int i = 0; i < n; i++)
        {
            if ((a[k][i] != 0 || a[i][k] != 0) && visited[i] == 0) // neu chua visit va trong so khac 0 thi them vao hang cho va gan co visited
            {
                enQueue(q, i);
                visited[i] = 1;
                cout << i << " ";
            }
        }
    }
}

int main()
{
    int n, start; // n la so dinh, start la dinh khoi dau

    int a[255][255] = {};
    readFile(n, a);
    do
    {
        cout << "Nhap dinh khoi dau (nhap -1 de ket thuc chuong trinh): ";
        cin >> start;
        if (start == -1)
            break;
        else if (start > n)
        {
            cout << "Dinh khoi dau khong thuoc do thi!";
            break;
        }

        bfs(n, a, start);
        cout << endl;
    } while (start != -1);
}