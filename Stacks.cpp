#include<iostream>
using namespace std;

struct stack    // Implementing Stacks using structure
{
    int size;
    int top;
    int *arr;
};
typedef struct stack Stack;

int isEmpty(Stack *s)
{
    /* This Function checks if the struct stack pointer is empty or not */

    if(s->top==-1)
    {
        return 1;
    }
    return 0;
}
int isFull(Stack *s)
{
    /* This Function checks if the struct stack pointer is full or not */

    if(s->top == (s->size) - 1)
    {
        return 1;
    }
    return 0;
}
void push(Stack*s)
{
    /* This Function is used to Push an Element to the Stack */

    if(isFull(s))
    {
        cout<<"\nStack Overflow.\n";
    }
    else
    {
        cout<<"\nEnter the Element to be pushed: ";
        ++(s->top);
        cin>>s->arr[s->top];
        cout<<"\n"<<s->arr[s->top]<<" Pushed to the Stack Successfully!!!\n";
    }
}
void pop(Stack*s)
{
    /* This Element is used to remove/delete/pop an Element from the Stack (LIFO) */

    if(isEmpty(s))
    {
        cout<<"\nStack Underflow.\n";
    }
    else
    {
        int val=s->arr[s->top];
        --(s->top);
        cout<<"\n"<<val<<" Popped from the Stack Successfully\n";
    }
}
void peek(Stack*s)
{
    /* This Function is used to Display the Element at a desired index */

    int val,ans;
    cout<<"\nEnter the Position for Peeking: ";
    cin>>val;
    ans=s->top-val+1;
    if(ans<0)
        cout<<"\nInvalid Position.\n";

    else
    {
        cout<<"\nElement at Position "<<val<<" is "<<s->arr[ans];
    }
}
int StackTop(Stack*s)
{
    /* This Function returns the top element of the Stack */

    return s->arr[s->top];
    
}
int StackBottom(Stack*s)
{
    /* This Function returns the Bottom Element of the Stack */

    return s->arr[0];
    
}
void display(Stack*s)
{
    /* This Function is used display the Stack */

    cout<<"\nElements in the Stack are: ";
    for(int j=s->top;j>=0;--j)
    {
        cout<<s->arr[j]<<" ";
    }
}
int main()
{
    Stack *s=new Stack;
    s->top = -1;
    cout << "Enter the size of the Stack: ";
    cin >> s->size;
    s->arr = new int(s->size);
    int c,i=1;

    // Menu Driven: 
    while(i){
    cout<<"\nSelect from the following: \n1. Push Element\n2. Pop Element\n3. Peek through the Stack\n4. Display Stack Top Element\n5. Display Stack Bottom Element\n6. Display the Stack\n7. Exit the program\n\nEnter your Choice: ";
    cin>>c;
    switch(c)
    {
        case 1:
        push(s);
        break;

        case 2:
        pop(s);
        break;

        case 3:
        peek(s);
        break;

        case 4:
        cout<<"Stack Top Element: "<<StackTop(s);
        break;

        case 5:
        cout<<"Stack Bottom Element: "<<StackBottom(s);
        break;

        case 6:
        display(s);
        break;

        case 7:
        cout<<"\nThank You for using the Program.\n";
        exit(0);
        break;

        default:
        cout<<"\nInvalid Choice.\n";
        break;
    }
    }
    return 0;
}