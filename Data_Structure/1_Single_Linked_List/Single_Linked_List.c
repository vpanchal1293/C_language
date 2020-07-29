#include <stdio.h>

typedef struct node
{
  int info;
  struct node *link;
} Node;

Node *addnodeatbeg (Node * start, int addinfo);
void printlist (Node * start);
Node *addnodeatend (Node * start, int addinfo);
void addafter (Node * start, int searchinfo, int addinfo);
Node * addbefore(Node * start, int searchinfo, int addinfo);
Node * addatposition(Node * start, int position, int addinfo);
Node * deletenode(Node *start, int deleteinfo);

main ()
{
    Node *start = NULL;
    start = addnodeatend (start, 10);
    start = addnodeatend (start, 20);
    start = addnodeatend (start, 30);
    start = addnodeatend (start, 40);
    start = addnodeatend (start, 50);
    start = addnodeatend (start, 60);
    printlist(start);
    start = deletenode(start, 40);
    printlist(start);
    start = deletenode(start, 10);
    printlist(start);
    start = deletenode(start, 60);
    printlist(start);
    start = deletenode(start, 80);
    printlist(start);
    
    return 0;
}


Node *addnodeatbeg (Node * start, int addinfo)
{
  Node *temp = (Node *) malloc (sizeof (Node));
  temp->info = addinfo;

  temp->link = start;
  start = temp;

  return start;
}

Node *addnodeatend (Node * start, int addinfo)
{
  Node *p = start;
  Node *temp = (Node *) malloc (sizeof (Node));

  temp->info = addinfo;

  if (start)
    {
      while (p->link != NULL)
	p = p->link;

      temp->link = p->link;
      p->link = temp;
    }
  else
    {
      temp->link = start;
      start = temp;
    }
  return start;
}


void addafter (Node * start, int searchinfo, int addinfo)
{
  Node *p = start;
  while (p != NULL)
    {
      if (p->info == searchinfo)
	{
	  Node *temp = (Node *) malloc (sizeof (Node));
	  temp->info = addinfo;
	  
	  temp->link = p->link;
	  p->link = temp;
	  return;
	}
      p = p->link;
    }
  printf ("Info not found");
}

Node * addatposition(Node * start, int position, int addinfo)
{
    if(position == 1)
    {
        Node *temp = (Node *) malloc (sizeof (Node));
        temp->info = addinfo;
        
        temp->link = start;
        start = temp;
        return start;
    }
    
    Node *p = start;
    int i = 0;
    for(i = 1; (i < position-1) && (p!=NULL);i++)
    {
        p= p->link;
    }
    
    if(p == NULL)
    {
        printf("position is greter than the link list length\n");
    }
    else
    {
        Node *temp = (Node *) malloc (sizeof (Node));
        temp->info = addinfo;
        
        temp->link = p->link;
        p->link = temp;
    }
    return start;
}

Node * addbefore(Node * start, int searchinfo, int addinfo)
{
    if(start == NULL)
    {
        printf("Empty list");
        return start;
    }
    if(start->info == searchinfo)
    {
        Node *temp = (Node *) malloc (sizeof (Node));
    	temp->info = addinfo;
        
        temp->link = start;
        start = temp;
        return start;
    }
    Node *p = start;
    while(p->link != NULL)
    {
        if (p->link->info == searchinfo)
        {
            Node *temp = (Node *) malloc (sizeof (Node));
            temp->info = addinfo;
            
            temp->link = p->link;
            p->link = temp;
            
            return start;
        }
        p = p->link;
    }
    
    printf("Not Found");
}

Node * deletenode(Node *start, int deleteinfo)
{
    if(start == NULL)
    {
        printf("Empty list\n");
        return start;
    }
    
    Node *temp;
    if(start->info == deleteinfo)
    {
        temp = start;
        start = start->link;
        free(temp);
        return start;
    }
    
    Node *p = start;
    while(p->link != NULL)
    {
        if(p->link->info == deleteinfo)
        {
            temp = p->link;
            p->link = temp->link;
            free(temp);
            return start;
        }
        p = p->link;
    }
    
    printf("Delete node with info not found\n");
    return start;
}

void printlist (Node * start)
{
  Node *p = start;
  while (p != NULL)
    {
      printf ("%d ", p->info);
      p = p->link;
    }
    printf ("\n");
}
