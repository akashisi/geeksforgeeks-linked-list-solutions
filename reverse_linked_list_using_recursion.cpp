#include<iostream>
#include<stdlib.h>
using namespace std;

void display();
struct node *addONE(struct node);

struct node
{
    int data;
    struct node *next;
};
struct node *head=NULL;
struct node *create()
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    return(temp);
};

void reverse_list(struct node *p)
{
    if(p->next==NULL)
    {
        head=p;
        return;
    }
    reverse_list(p->next);
    struct node *q=p->next;
    q->next=p;
    p->next=NULL;
}
void add_one_to_list(struct node *p)
{
    struct node *temp;
    temp=p;
    reverse_list(temp);
    addONE(temp);
    reverse_list(temp);

}
//struct node *addONE(struct node *p)
void addONE(struct  node *p)
{
    struct node *res,*prev,*temp,*newnode;
    res=p;
    prev=NULL;
    int sum=0,carry=1;
    while(res)
    {
        sum=carry+(head?head->data:0);
        carry=(sum>=10)?1:0;
        sum=sum%10;
        res->data=sum;
        temp=res;
        temp=temp->next;
    }
    if(carry>0)
    {
        newnode=(struct node *)malloc(sizeof(struct node));\
        temp->next=newnode;
        temp->next->data=carry;
    }
    //return(p);
}

void append()
{
    int x;
    struct node *temp,*p;
    temp=create();
    cout<<endl<<"Enter the data to append in the list :: ";
    cin>>x;
    temp->data=x;
    temp->next=NULL;
    p=head;
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        while(p->next!=NULL)
        {
            p=p->next;
        }
        p->next=temp;
    }

}
void display()
{
    struct node *temp;
    temp=head;
    cout<<endl<<"CONTENT OF LINKED LSIT ::\n";
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

int main()
{
    int ch;
    while(1)
    {
        cout<<endl<<"1. Add element in th linked list\n2. DISPLAY content of linked list\n";
        cout<<"3. REVERSE LINKED LSIT\n4. ADD 1 TO LINKED LSIT\n5. EXIT\n";
        cout<<endl<<"Enter your choice ::";
        cin>>ch;
        switch(ch)
        {
            case 1:append();
                   break;
            case 2:display();
                   break;
            case 3: reverse_list(head);
                    break;
            case 4: add_one_to_list(head);
                    break;
            case 5: exit(1);
                    break;
            default:exit;
        }
    }
    return(0);
}
