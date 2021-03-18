#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
};
typedef struct Node NODE;
int count=-1;
bool isEmpty(NODE*top)
{
    if(top==NULL)
        return true;

    return false;
}
NODE* Push(NODE*top)
{
    NODE *ptr= new NODE;
    if(ptr==NULL)
        cout<<"\nStack Overflow.\n";
    
    else
    {
        cout<<"\nEnter the Element: ";
        cin>>ptr->data;
        ptr->next=top;
        top=ptr;
        cout<<"\n"<<ptr->data<<" Pushed to the Stack Successfully.\n";
        ++count;
        return top;
    }
    return 0;
}
NODE* Pop(NODE*top)
{
    if(isEmpty(top)==true)
        cout<<"\nStack Underflow.\n";

    else
    {
        NODE*ptr=top;
        top=top->next;
        cout<<"\n"<<ptr->data<<" Popped out from the Stack Successfully.\n";
        free(ptr);
        --count;
        return top;
    }
    return 0;
}
void Peek(NODE*top)
{
    int pos;
    cout<<"\nEnter the Position to be Peeked: ";
    cin>>pos;
    int val=count-pos+1;
    if(val>=0){
    NODE*ptr=top;
    int i=count;
    while(i>val){
        ptr=ptr->next;
        --i;
    }
    cout<<"\nElement at "<<pos<<" is "<<ptr->data<<endl;
    }
    else
    {
        cout<<"\nInvalid Positionn\n";
    }
    
}
int main()
{
    NODE*head=NULL;  //top=head
    int i=1;
    while(i)
    {
        cout<<"\nWelcome to the Program of Implementation of Stacks using Linked List\nSelect from the following:\n1. Push \n2. Pop \n3. Peek\n4. Exit\nEnter your choice: ";
        int ch;
        cin>>ch;
        switch(ch)
        {
            case 1:
            head=Push(head);
            break;

            case 2:
            head=Pop(head);
            break;

            case 3:
            Peek(head);
            break;

            case 4:
            cout<<"\nThank You for using the Program.";
            exit(0);
            break;

            default:
            cout<<"\nInvalid Input\n";
            break;
        }
    }
    return 0;
}