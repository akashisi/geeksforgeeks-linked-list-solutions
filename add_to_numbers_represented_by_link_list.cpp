#include<iostream>
using namespace std;

void display(struct node *);
struct node
{
    int data;
    struct node *next;
};

struct node *create()
{
    struct node *temp;
    temp=new node;
    return(temp);
};

struct node *append(struct node *head,int x)
{
    struct node *temp,*p,*q;
    int r;
    while(x)
    {
        r=x%10;
        p=create();
        p->data=r;
        p->next=NULL;
        if(head==NULL)
        {
            head=q=p;
        }
        else
        {
            q->next=p;
            q=p;
        }
        x=x/10;
    }
    return(head);
}

struct node *add(struct node *h1,struct node *h2)
{
    struct node *p,*q,*temp,*result=NULL,*nxt=NULL;
    int sum=0,carry=0;

    p=h1,q=h2;
    while(p!=NULL || q!=NULL)
    {
        sum=carry+(p?(p->data):0)+(q?(q->data):0);
        carry=(sum>=10)?1:0;
        sum=sum%10;
        temp=create();
        temp->data=sum;
        temp->next=NULL;
        if(result==NULL)
        {
            result=nxt=temp;
        }
        else
        {
            nxt->next=temp;
            nxt=temp;
        }
         if(p)
            p=p->next;
         if(q)
            q=q->next;


    }
    if(carry>0)
    {
        temp=create();
        temp->data=carry;
        temp->next=NULL;
        nxt->next=temp;
    }
    return(result);
}
struct node *reverse_list(struct node *head)
{
    struct node *prev=NULL;
    struct node *current=head;
    struct node *next;
    while(current!=NULL)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    return(prev);
};

void display(struct node *head)
{
    struct node *temp;
    temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data;
        temp=temp->next;
    }
}

int main()
{

    struct node *head1=NULL,*head2=NULL,*head3=NULL;
    int r=0,sum=0,i=0,x,y;
    cout<<"\nEnter the 1st number :: ";
    cin>>x;
    head1=append(head1,x);

    cout<<"\nEnter the 2nd number :: ";
    cin>>y;
    head2=append(head2,y);

    head3=add(head1,head2);
    head3=reverse_list(head3);
    cout<<"\nSUM OF TWO NUMBERS REPRESENTED BY LINKED LIST :: ";
    display(head3);

    return(0);
}
