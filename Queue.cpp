#include<iostream>
using namespace std;

// int count = 0;
struct Node 
{
    /* This Struct contains the Queue(*arr), Size of the Queue(size) and two index variables (front and rear) for pointing the First and Last Element of the Queue */
    int size,front,rear,*arr, count;   
};
typedef struct Node NODE;

void Enqueue(NODE *q)
{
    /* This Funciton is Used to Add an Element to the Queue */

    if((q->size)-1 == q->rear)
    {
        cout<<"\nQueue Overflow\n";
    }
    else
    {
        ++(q->count);
        ++(q->rear);
        cout<<"\nEnter the Element: ";
        cin>>q->arr[q->rear];
        cout<<"\n"<<q->arr[q->rear]<<" Inserted to the Queue Successfully!!\n";
    }
}
void Dequeue(NODE *q)
{
    /* This Function is used to Remove an Element from the Queue */

    if(q->rear == -1)
    {
        cout<<"\nQueue Underflow\n";
    }
    else
    {
        int val = q->arr[(q->front)+1];
        ++(q->front);
        cout<<"\n"<<val<<" Removed from the Queue Successfully\n";
    }
}
void Display(NODE *q)
{
    /* This Function is Used to Display the Complete Queue */

    if(q->rear == q->front)
    {
        cout<<"\nQueue Empty!!\n";
    }
    else
    {
        cout<<"\nQueue: ";
        for(int i = (q->front)+1;i<=(q->rear);++i)
        {
            cout<<q->arr[i]<<" ";
        }
    }
}
int main()
{
    NODE *q = new NODE; 
    q->front = q->rear = -1;
    cout<<"\nEnter the size of the Queue: ";
    cin>>q->size;
    q->arr = new int(q->size);
    while(1)
    {
        int c;
        cout<<"\nSelect from the following:\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter your choice: ";
        cin>>c;
        switch(c)
        {
            case 1:
            Enqueue(q);
            break;

            case 2:
            Dequeue(q);
            break;

            case 3:
            Display(q);
            break;

            case 4:
            cout<<"\nThank You for using the program!!\n";
            exit(0);

            default:
            cout<<"\nInvalid Choice!!\n";
            break;
        }
    }   
}