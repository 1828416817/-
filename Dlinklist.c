#include "stdio.h"
#include "stdlib.h"
typedef struct doubleList
{
    int data;
    struct doubleList *front;
    struct  doubleList *tail;
}DLinknode,*Dlinklist;
DLinknode*CreateList()
{
    DLinknode*headNode=(DLinknode*)malloc(sizeof(DLinknode));
    headNode->front=headNode->tail=headNode;
    return headNode;
}
DLinknode*CreateNode(int data)
{
    DLinknode*newNode=(DLinknode*)malloc(sizeof(DLinknode));
    newNode->data=data;
    newNode->front=newNode->tail=NULL;
    return newNode;
}
void insertNodeByHead(DLinknode*headNode,int data)
{
    DLinknode*newNode=CreateNode(data);
   
    newNode->front=headNode;
    newNode->tail=headNode->tail;
    headNode->tail->front=newNode;
    headNode->tail=newNode;
   
}
void append(DLinknode*headNode,int data)
{
     DLinknode*newNode=CreateNode(data);
     DLinknode*lastNode=headNode;
     while(lastNode->tail!=headNode)
     {
         lastNode=lastNode->tail;
     }
     headNode->front=newNode;
     lastNode->tail=newNode;
     newNode->front=lastNode;
}
void DeleteNodeByAppoint(DLinknode*headNode,int posData)
{
  DLinknode*cur=headNode->tail;
  DLinknode*pcur=headNode;
  while(cur->data!=posData)
  {
      pcur=cur;
      cur=cur->tail;
      if(cur->tail==headNode)
      {
        return;
      }

  }
  pcur->tail=cur->tail;
  cur->tail->front=pcur;
  free(cur);

}

void PrintListQ(DLinknode*headaNode)
{
    DLinknode*pMove=headaNode->front;
    while(pMove!=headaNode)
    {
        printf("%d\t",pMove->data);
        pMove=pMove->front;
    }
    printf("\n");

}
void PrintListS(DLinknode*headaNode)
{
    DLinknode*pMove=headaNode->tail;
    while(pMove!=headaNode)
    {
        printf("%d\t",pMove->data);
        pMove=pMove->tail;
    }
    printf("\n");

}
int main()
{
    DLinknode*L=CreateList();
    insertNodeByHead(L,1);
    insertNodeByHead(L,2);
    insertNodeByHead(L,3);
    PrintListQ(L);
   // PrintListS(L);
     append(L,0);
     PrintListQ(L);
     DeleteNodeByAppoint(L,2);
     PrintListQ(L);


}

