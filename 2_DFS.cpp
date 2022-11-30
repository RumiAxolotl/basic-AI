#include <bits/stdc++.h>
using namespace std;

FILE *f;

struct Stack
{
    int top;
    unsigned capacity;
    int *array;
};

void initStack(Stack *stack, unsigned capacity)
{
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = new int[stack->capacity];
}

bool isEmpty(Stack *stack)
{
    return stack->top < 0;
}

void push(Stack *stack, int item)
{
    if (stack->top == stack->capacity - 1)
    {
        cout << "Stack if full, can't push" << endl;
        return;
    }
    stack->top++;
    stack->array[stack->top] = item;
}

int pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        cout << "Stack is empty, can't pop" << endl;
        return 0;
    }
    int item = stack->array[stack->top];
    stack->array[stack->top] = 0;
    stack->top--;
    return item;
}

void dfs(int n, int a[255][255], int start)
{
    Stack *stack = new Stack;
    initStack(stack, n);
    // khoi tao queue voi capacity = n
    int visited[n] = {}; // mang visited luu co hieu cac dinh da visit

    push(stack, start); // them dinh khoi dau vao stack
    visited[start] = 1; // gan dinh khoi dau da visit
    cout << start << " ";
    while (!isEmpty(stack))
    {

        int k = pop(stack); // lay dau stack de kiem tra
        for (int i = 0; i < n; i++)
        {
            if (a[k][i] != 0 && visited[i] == 0) // neu chua visit va trong so khac 0 thi them vao stack va gan co visited
            {
                push(stack, i);
                visited[i] = 1;
                cout << i << " ";
            }
        }
    }
}

int main()
{
    int n =6, start; // n la so dinh, start la dinh khoi dau

    int a[255][255] = {
        {0, 20, 42, 31, 6, 24},
        {10, 0, 17, 6, 35, 18},
        {25, 5, 0, 27, 14, 9},
        {12, 9, 24, 0, 30, 12},
        {14, 7, 21, 15, 0, 38},
        {40, 15, 16, 5, 20, 0}};
    do
    {
        cout << "Nhap dinh khoi dau (nhap -1 de ket thuc chuong trinh): ";
        cin >> start;
        if (start == -1)
            break;
        else
        {
            if (start >= n)
            {
                cout << "Dinh khong thuoc do thi!";
                break;
            }
        }

        dfs(n, a, start);
        cout << endl;
    } while (start != -1);
}