/* JOSHUA BARA
    IT - 03 */

/*Program to implement insert, delete, display, search in linked list*/


#include <stdio.h>

struct node
{
    int info;
    struct node *next;
};
int p;

struct node *list = 0;

struct node *getnode(void)
{
    return ((struct node *)malloc(sizeof(struct node)));
}

void freenode(struct node *p)
{
    free(p);
}

void main()
{
    int x;
    int n;
    while (1)
    {

        printf("-----------linked list operation------------");
        printf("\nenter\n");
        printf("1. insert at begining\n");
        printf("2. insert at end of the list\n");
        printf("3. insert at any position in the list\n");
        printf("4. delete at begining\n");
        printf("5. delete at end of the list\n");
        printf("6. delete at any position in the list\n");
        printf("7. traverse\n");
        printf("8:exit");
        scanf(" %d", &n);
        switch (n)
        {
        case 1:

            printf("enter the number:");
            scanf("%d", &x);
            insert_at_beg(x);
            break;

        case 2:
            printf("enter the number:");
            scanf("%d", &x);
            insert_at_end(x);
            break;

        case 3:
            int pi;
            printf("enter the position and value respectively at which list to be added:");
            scanf("%d,%d", &pi, &x);
            insert_at_location(pi, x);
            break;

        case 4:
            delete_at_Beg();
            break;

        case 5:
            delete_at_end();
            break;                

        case 6:
            int m;
            printf("enter the position at which to be deleted in linked list: ");
            scanf("%d", &m);
            delete_at_loctaion(m);
            break;

        case 7:
            display();
            break;

        case 8:
            exit(1);

        default:
            printf("wrong option selected:");
            break;
        }
    }
}

void insert_at_beg(int x)
{
    struct node *newnode;
    newnode = getnode();
    newnode->info = x;
    newnode->next = list;
    list = newnode;
}

void insert_at_end(int x)
{
    if (list == 0)
    {
        insert_at_beg(x);
    }

    else
    {
        struct node *newnode, *temp;
        newnode = getnode();
        newnode->info = x;
        newnode->next = 0;

        temp = list;

        while (temp->next != 0)
        {
            temp = temp->next;
        }

        temp->next = newnode;
    }
}

void insert_at_location(int pi, int x)
{
    struct node *newnode, *temp;

    if (list == 0 || pi == 1)
    {
        insert_at_beg(x);
    }
    else
    {
        temp = list;
        for (int i = 1; i < pi - 1; i++)
        {
            temp = temp->next;
        }

        newnode = getnode();
        newnode->info = x;
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

void delete_at_Beg()
{
    if (list == 0)
    {
        printf("Empty list:");
    }
    else
    {
    struct node *temp;
    temp = list;
    list = list->next;
    freenode(temp);
    }
}

void delete_at_loctaion(int m)
{
    if(list==0)
    {
        printf("Empty linked lsit");
        
    }
    if(m==1)
    {
        delete_at_Beg();
    }
    struct node *temp, *t2;
    temp =list;
    for(int i=1; i<m; i++)
    {
        t2 = temp;
        temp= temp->next;
    }
    t2->next=t2->next->next;
    freenode(temp);
}

void delete_at_end()
{
    if(list==0)
    {
        printf("Empty LL");
    }
    if(list->next==0)
    {
        delete_at_Beg();      
    }
    struct node *temp, *t2;
    temp=list;
    while(temp->next->next!=0)
    {
        t2=temp;
        temp =temp->next;
    }
    freenode(temp->next);
    temp->next=0;
}

void display()
{
    if(list==0)
    {
        printf("Empty linke list");
    }
    struct node *temp;
    temp=list;
    while(temp->next!=0)
    {
        printf("%d\n", temp->info);
        temp=temp->next;
    }
    printf("%d", temp->info);
}