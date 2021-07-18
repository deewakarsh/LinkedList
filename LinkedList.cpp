#include <iostream>
#include <stdlib.h>

using namespace std;

void display(struct node*);  //to display the LinkedList
struct node* create(struct node*, int); // to create the linked list of any length
struct node* ins_beg(struct node*); // insert @ begining 
struct node* ins_last(struct node*); // insert @ last
struct node* ins_any(struct node*, int); // insert @ any position
struct node* del_beg(struct node*); // delete @ begining
struct node* del_last(struct node*); // delete @ last
struct node* del_any(struct node*, int); // delete @ any position
struct node* rev(struct node*);  //reverse the linkedList
struct node* sel_sort(struct node*); //sorting LL using selection sort

struct node 
{
    int info;
    struct node *link;
};

int main()
{
    int select, n, pos;
    struct node* start = NULL;
    
    while(1)
    {
        cout<<"\n1. Create\n2. ins_beg\n3. ins_last\n4. ins_any\n5. del_beg\n6. del_last\n7. del_any\n8. Reverse\n9. Sort\n10. Display"<<endl;

        cout<<"Enter your coice:"<<endl;
        cin>>select;
        switch(select)
        {
            case 1:
                cout<<"Enter the number of nodes you want in Linked List:"<<endl;
                cin>>n;
                start = create(start,n);
                break;

            case 2:
                start = ins_beg(start);
                break;

            case 3:
                start = ins_last(start);
                break;
            
            case 4:
                cout<<"Enter the position where you want to insert:"<<endl;
                cin>>pos;
                start = ins_any(start, pos);
                break;

            case 5:
                start = del_beg(start);
                break;
            
            case 6:
                start = del_last(start);
                break;
            
            case 7:
                cout<<"Enter the position where you want to delete:"<<endl;
                cin>>pos;
                start = del_any(start,pos);
                break;
            
            case 8:
                start = rev(start);
                break;

            case 9:
                start = sel_sort(start);
                break;

            case 10:
                display(start);
                break;

            default :
                cout<<"Invalid Entry!!  \n  Exiting"<<endl;
                if(start != NULL)
                    delete start;
                exit(0);


        }
    }

    return 0;
}

struct node * create(struct node* start, int n)
{
    int i;
    struct node *p, *current;
    for(int i=1;i<=n;i++)
    {
        p = new node;
        cout<<"Enter Node value"<<endl;
        cin>>p->info;
        p->link=NULL;
        
        if(start == NULL)
            start = p;
        else
            current->link = p;
        current = p;
    }
    current ->link = NULL;
    
    return start;
}

void display (struct node* start)
{
    struct node* p;
    p = start;
    while(p!=NULL)
    {
        cout<<p->info<<"->";
        p = p->link;
    }
    cout<<"NULL"<<endl;
}


struct node* ins_beg(struct node * start)
{
    struct node *p;
    p = new node;
    cout<<"enter the value:"<<endl;
    cin>>p->info;

    p->link = start;
    start = p;

    return start;
}

struct node* ins_last(struct node* start)
{
    struct node *p, *ptr;
    p = new node;
    cout<<"enter the value:"<<endl;
    cin>>p->info;

    ptr = start;
    while(ptr->link != NULL)
        ptr = ptr->link;

    ptr->link = p;
    p->link = NULL;

    return start;
}

struct node* ins_any(struct node* start, int pos)
{
    struct node *p, *ptr;
    p = new node;
    cout<<"enter the value:"<<endl;
    cin>>p->info;

    ptr = start;

    for(int i=1; i<pos-1; i++)
        ptr = ptr->link;
    
    p->link = ptr->link;
    ptr->link = p;

    return start;
}

struct node* del_beg(struct node *start)
{
    if(start == NULL)
    {
        cout<<"Empty Linked List"<<endl;
    }
    else
    {
        struct node *p = start;
        start = start->link;
        delete p;
    }

    return start;
}

struct node* del_last(struct node *start)
{
    struct node *p, *q;
    p = start;

    if(start == NULL)
    {
        cout<<"Empty Linked List"<<endl;
    }
    else if(start->link == NULL)
    {
        start = NULL;
        delete p;
    }
    else
    {
        while(p->link != NULL)
        {
            q = p;
            p = p->link;
        }

        delete p;
        q->link = NULL;
    }

    return start;
}

struct node* del_any(struct node* start, int pos)
{
    if(start == NULL)
        cout<<"Empty Linked List"<<endl;
    else
    {
        struct node *p, *q;
        p = start;
        for(int i =1; i<pos; i++)
        {
            q = p;
            p = p->link;
        }

        q->link = p->link;
        delete p;
    }

    return start;
}

struct node* rev(struct node* start)
{
    struct node *p, *next, *prev;
    p = start;
    next = prev = NULL;

    while(p != NULL)
    {
        next = p->link;
        p->link = prev;
        prev = p;
        p = next;
    }

    start = prev;

    return start;
}

struct node* sel_sort(struct node *start)
{
    struct node* p = start;
    while (p != NULL)
    {
        struct node *min = p;
        struct node *q = p->link;

        while(q != NULL)
        {
            if(min->info > q->info)
                min = q;

            q = q->link;
        }

        int temp = p->info;
        p->info = min->info;
        min->info = temp;

        p = p->link;
    }

    return start;
}