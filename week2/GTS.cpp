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

int displayFront(Queue *queue)
{
    if (isEmpty(queue))
    {
        cout << "Queue is empty" << endl;
        return 0;
    }
    return queue->array[queue->front];
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

// int checkVisited(int n, int arr[255])
// {
//     for (int i = 0; i < n; i++)
//         if (arr[i] == 0)
//             return 0;
//     return 1;
// }

int GTS1(int n, int a[255][255], int start)
{
    Queue *q = new Queue;
    initQueue(q, n);
    int sum = 0;
    int visited[n] = {};    // khoi tao mang visited danh dau cac dinh da di qua
    int KQ[2][n + 1] = {0}; // khoi tao mang ket qua
    int temp = 0;           // bien luu vi tri thu tu
    visited[start] = 1;     // danh dau dinh khoi dau da visit
    KQ[0][0] = KQ[n][0] = start;
    enQueue(q, start); // them dinh khoi dau vao hang cho
    while (!isEmpty(q))
    {
        int k = deQueue(q); // lay dinh tu queue de kiem tra
        for (int i = 0; i < n; i++)
        {
            int min = a[k][0];
            int pos = 0;
            if (a[k][i] != 0 && visited[i] == 0)
            {
                if (a[k][i] < min)
                {
                    min = a[k][i];
                    pos = i; //luu thu tu cua dinh
                }
            }
            enQueue(q,min);
            KQ[0][temp + 1] = pos;
        }
        KQ[1][temp] == displayFront(q);
        temp++;
    }
    for(int i = 0; i <= n; i++){
        sum += KQ[1][i];
        cout << KQ[0][i] << " ";
    }
    return sum;
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
        else
        {
            if (start > n)
            {
                cout << "Dinh khoi dau khong thuoc do thi!";
                break;
            }
        }
        cout<<GTS1(n, a, start);
        cout << endl;
    } while (start != -1);
}