#include<iostream>
#include<stdlib.h>
using namespace std;

struct node
{
    /* This Stucture contains integer varaible data (to store the data of the Node) and *next(struct pointer which points to the Next Node in the Linked List) */
    int data;
    struct node *next;
};
typedef struct node NODE;


void traverse(NODE *ptr)
{
    /* This Function is used to Traverse the List by taking the struct pointer, pointing at the first element, as a parameter*/

    cout<<"\nElements: \n";
    while(ptr!=NULL)
    {
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
}
NODE* insertbeg(NODE* head,int data)
{
    /* This function is used to Insert a node in the beginning of the List */

    NODE *ptr=(NODE*)malloc(sizeof(NODE *));
    ptr->next=head;
    ptr->data=data;
    return ptr;
}
NODE* insertbet(NODE* head,int data,int i)
{
    /* This Function is used to Insert a Node in between the List, at a desired location*/

    NODE*ptr;
    ptr=(NODE*)malloc(sizeof(NODE));
    int j=0;
    while(j<i-1)
    {
        head=head->next;
        ++j;
    }
    ptr->next=head->next;
    head->next=ptr;
    ptr->data=data;
    return ptr; 
}
NODE* insertend(NODE* end,int n)
{
    /* This Function is used to Insert a Node at the end of the List*/
    
    NODE* ptr;
    ptr=(NODE*)malloc(sizeof(NODE));
    end->next=ptr;
    ptr->next=NULL;
    ptr->data=n;
    return ptr;
}
NODE* delbeg(NODE*head)
{
    /* This Function is used to Delete a Node from the Beginning of the List*/

    NODE *ptr;
    ptr=(NODE*)malloc(sizeof(NODE));
    ptr->next=head;
    head=head->next;
    free(ptr);
    return head;
}
NODE* delbet(NODE* head,int n)
{
    /* This Function is used to Delete a Node from in between the List*/
    
    NODE* ptr;
    ptr=(NODE*)malloc(sizeof(NODE));
    int i=0;
    while(i<n-2)
    {
        head=head->next;
        ++i;
    }
    ptr=head->next;
    head->next=ptr->next;
    free(ptr);
    return head;
}
NODE* delend(NODE* head)
{
    /* This Function is used to Delete the Last Node from the List*/
 
    NODE*p,*q;
    p=(NODE*)malloc(sizeof(NODE));
    q=(NODE*)malloc(sizeof(NODE));
    q=head;
    p=head->next;
    while(p->next!=NULL)
    {
        p=p->next;
        q=q->next;
    }
    q->next=NULL;
    free(p);
    return q;
}
int main()
{
    NODE *head,*temp,*first;    // Creted a NULL Linked List
    first=NULL;
    head=NULL;

    cout<<"Enter the elements:\n";
    for(int i=0;i<5;++i)
    {
        temp=(NODE*)malloc(sizeof(NODE));
        cin>>temp->data;
        if(head!=NULL)
        {
            head->next=temp;
            head=temp;
            temp->next=NULL;
        }
        else
        {
            head=first=temp;
        }
    }

    head=first;
    head=insertbeg(head,0);
    
    first=head;
    
    temp=insertend(temp,6);
    
    head=insertbet(head,55,4);
    
    head=first;
    head=delbeg(head);
    
    first=head;
    temp=delend(head);
    
    head=delbet(head,4);
    
    head=first;
    traverse(head);
    
    return 0;
}
