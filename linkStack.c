
#include "stdio.h"
#include "stdlib.h"
typedef struct Node
{
    int data;
    struct Node*next;
}stack;
stack*CreateStack()
{
    stack*s=(stack*)malloc(sizeof(stack));
    s->next=NULL;
    return s;
}

void push(stack*s,int x)
{
    stack*newNode=(stack*)malloc(sizeof(stack));
    newNode->data=x;
    newNode->next=s->next;
    s->next=newNode;
}
void pop(stack*s)
{
    if(s==NULL)
    {
      return;
    }
    stack*cur=s->next;
    s->next=cur->next;
    free(cur);
}
int top(stack*s)
{
 if(s==NULL)
    {
      return -1;
    }
    stack*cur=s->next;
    return cur->data;
    
}
void Println(stack*s)
{
    stack*cur=s->next;
    while(cur!=NULL)
    {
        printf("%d\t",cur->data);
        cur=cur->next;
    }
    printf("\n");
}
void clearStack(stack*s)
{
    if(s==NULL)
    {
        return;
    }
    stack*cur=s->next;
    while(cur!=NULL)
    {
        stack*pcur=cur->next;
        free(cur);
        cur=pcur;
    }
    s->next=NULL;
}
void destroyStack(stack*s)
{
    if(s==NULL)
    {
        return;
    }
    else
    {
        clearStack(s);
        free(s);

    }
    s=NULL;
}
int main()
{
    stack*s=CreateStack();
    push(s,1);
    push(s,2);
    push(s,3);
    push(s,4);
    Println(s);
    pop(s);
    Println(s);
    int e=top(s);
    printf("%d",e);
}

