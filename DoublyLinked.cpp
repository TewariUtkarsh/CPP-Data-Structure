#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node* next;
    struct node* prev;
};
typedef struct node NODE;

void traverse(NODE* head)
{
    /* This Function is used to Traverse the List by taking the struct pointer, pointing at the first element, as a parameter*/

    NODE* p;
    p=head;
    cout<<"Elements: \n";
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
}
NODE* insertbet(NODE*head,int i,int n)
{
    

    NODE* ptr;
    ptr=(NODE*)malloc(sizeof(NODE));
    ptr->data=n;
    int j=0;
    while(j<i-1)
    {
        head=head->next;
        ++j;
    }
    ptr->next=head->next;
    ptr->prev=head;
    head->next=ptr;
    return head;
}
NODE* delbet(NODE* head,int i)
{
    NODE*ptr=(NODE*)malloc(sizeof(NODE));
    int j=0;
    while(j<i-1)
    {
        head=head->next;
        ++j;
    }
    ptr=head->next;
    head->next=ptr->next;
    ptr->next->prev=head;
    free(ptr);
    return head;
}
int main()
{
    NODE *head,*first,*temp;
    first=NULL;
    head=NULL;
    cout<<"Enter the elements: \n";
    for(int i=0;i<5;++i)
    {
        temp=(NODE*)malloc(sizeof(NODE));
        cin>>temp->data;
        temp->next=NULL;
        temp->prev=head;
        if(head!=NULL)
        {
            head->next=temp;
            head=temp;
        }
        else
        {
            head=first=temp;
        }
    }
    head=first;
    head=insertbet(head,3,55);
    head=first;
    head=delbet(head,3);
    head=first;
    traverse(head);
    return 0;
}
