#include <stdio.h>

typedef struct node
{
    struct node *prev;
    int info;
    struct node *next;
} Node;

Node *addnodeatbeg (Node * start, int addinfo);
void printlist (Node * start);
Node *addnodeatend (Node * start, int addinfo);
void addafter (Node * start, int searchinfo, int addinfo);
Node * addbefore(Node * start, int searchinfo, int addinfo);
Node * addatposition(Node * start, int position, int addinfo);
Node * deletenode(Node *start, int deleteinfo);

int main ()
{
    Node *start = NULL;
    //start = addnodeatbeg(start, 10);
    //start = addnodeatbeg(start, 20);
    //start = addnodeatbeg(start, 30);
    start = addnodeatend(start, 50);
    start = addnodeatend(start, 60);
    start = addnodeatend(start, 70);
    start = addnodeatbeg(start, 40);
    start = addnodeatbeg(start, 30);
    start = addnodeatbeg(start, 20);
    start = addnodeatbeg(start, 10);
    printlist(start);
    start = deletenode(start, 80);
    printlist(start);
    start = deletenode(start, 60);
    printlist(start);
    return 0;
}


Node *addnodeatbeg (Node * start, int addinfo)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->info = addinfo;
    //Empty List
    if(start == NULL)
    {
        temp->next = NULL;
        temp->prev = NULL;
        start = temp;
        return start;
    }
    
    //List is not Empty
    temp->next = start;
    temp->prev = NULL;
    start->prev = temp;
    start = temp;
    return start;
}

Node *addnodeatend(Node * start, int addinfo)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->info = addinfo;
    
    //if List is empty
    if(start == NULL)
    {
        temp->next = NULL;
        temp->prev = NULL;
        start = temp;
        return start;
    }
    
    Node *p = start;
    
    //if list is not empty
    while(p->next != NULL)
    {
        p = p->next;
    }
    temp->next = NULL;
    temp->prev = p;
    p->next = temp;
    return start;
}


void addafter (Node * start, int searchinfo, int addinfo)
{
    Node *p = start;
    while( p != NULL )
    {
        if( p->info == searchinfo)
        {
            Node *temp = (Node *)malloc(sizeof(Node));
            temp->info = addinfo;
            temp->prev = p;
            temp->next = p->next;
            if(p->next != NULL)
                p->next->prev = temp;
            p->next = temp;
            return;
        }
        p = p->next;
    }
    printf("Data not found\n");
}

Node * addatposition(Node * start, int position, int addinfo)
{
    if(position == 1)
    {
        if(start == NULL)
        {
            Node *temp = (Node *)malloc(sizeof(Node));
            temp->info = addinfo;
            
            temp->next = NULL;
            temp->prev = NULL;
            start = temp;
        }
        else
        {
            Node *temp = (Node *)malloc(sizeof(Node));
            temp->info = addinfo;
            
            temp->next = start;
            temp->prev = NULL;
            start->prev = temp;
            start = temp;
        }
    return start;   
    }
    
    int i = 0;
    Node *p = start;
    for(i = 1; (p!= NULL) && i<position-1; i++)
        p = p->next;
    if(p == NULL)
    {
        printf("position is grater than length\n");
    }
    else
    {
        Node *temp = (Node *)malloc(sizeof(Node));
        temp->info = addinfo;
        temp->prev = p;
        temp->next = p->next;
        if( p->next != NULL)
            p->next->prev = temp;
        p->next = temp;
    }
    return start;
}

Node * addbefore(Node * start, int searchinfo, int addinfo)
{
    //list Empty
    
    if(start == NULL)
    {
        printf("Empty List\n");
        return start;
    }
    
    //first node
    if(start->info == searchinfo)
    {
        Node *temp = (Node *)malloc(sizeof(Node));
        temp->info = addinfo;
        
        temp->prev = NULL; 
        temp->next = start;
        start->prev = temp;
        start = temp;
        
        return start;
    }
    
    //other node
    Node *p = start;
    while( p->next != NULL)
    {
        if( p->next->info == searchinfo)
        {
            Node *temp = (Node *)malloc(sizeof(Node));
            temp->info = addinfo;
            
            temp->prev = p;
            temp->next = p->next;
            p->next->prev = temp;
            p->next = temp;
            
            return start;
        }
        p = p->next;
    }
    
    printf("Node not found\n");
    return start;
}

Node * deletenode(Node *start, int deleteinfo)
{
    //empty List
    if(start == NULL)
    {
        printf("List is empty\n");
        return start;
    }
    
    //first node
    Node *temp;
    if(start->info == deleteinfo)
    {
        temp = start;
        
        if(temp->next != NULL)
            temp->next->prev = NULL;
        start = temp->next;
        free(temp);
        return start;
    }
    
    //other node
    Node *p = start;
    while(p->next != NULL)
    {
        if(p->next->info == deleteinfo)
        {
            temp = p->next;
            if(temp->next != NULL)    
                temp->next->prev = p;
            p->next = temp->next;
            free(temp);
            return start;
        }
        p = p->next;
    }
    
    printf("Info not found\n");
    return start;
}

void printlist (Node * start)
{
    Node *p = start,*q;
    if(start == NULL)
    {
        printf("Empty list\n");
        return;
    }
    while(p != NULL)
    {
        printf("%d ",p->info);
        if(p->next == NULL)
        {
            q = p;
        }
        p = p->next;
    }
    printf("\t\t");
    
    printf("Printing reverse\t");
    while(q != NULL)
    {
        printf("%d ",q->info);
        q = q->prev;
    }
    printf("\n");
}
