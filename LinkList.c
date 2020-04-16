#include "stdio.h"
#include "stdlib.h"
typedef int DataType;
typedef struct node
{
    DataType data;
    struct node* next;
}Node;
Node* CreateList()
{
    Node* headNode = (Node*)malloc(sizeof(Node));

    headNode->next = NULL;
    return headNode;
}
int ListIsEmpty(Node* headNode)
{
    if (headNode->next == NULL)
    {
        return 1;
    }
    return 0;
}
Node* CreateNewNode(DataType data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void PrintLinklist(Node* headNode)
{
    if (headNode == NULL)
    {
        return;
    }
    Node* cur = headNode->next;
    while (cur != NULL)
    {
        printf("%d\t", cur->data);
        cur = cur->next;
    }
    printf("\n");
}
void HeadInsert(Node* headNode, DataType data)
{
    Node* newNode = CreateNewNode(data);
    newNode->next = headNode->next;
    headNode->next = newNode;

}
Node* TailInsert(Node* headNode, DataType data)
{
  Node* newNode = CreateNewNode(data);
  if(headNode==NULL)
  {
    headNode=newNode;
    return headNode;
  }
  else{
    Node* cur = headNode;
    
    while (cur->next != NULL)
    {
        cur = cur->next;
    }
    cur->next = newNode;
    return headNode;
    
  }
  
}
void PointInsert(Node* headNode, DataType olddata, DataType newdata)
{
    Node* newNode = CreateNewNode(newdata);
    if (headNode == NULL)
    {
        return;
    }
    else
    {
        Node* pcur = headNode;
        Node* cur = headNode->next;
        while (cur != NULL)
        {
            if (cur->data == olddata)
            {
                break;
            }
            else
            {
                pcur = cur;
                cur = cur->next;
            }

        }
        newNode->next = cur;
        pcur->next = newNode;
    }


}
void DeleteList(Node*headNode,DataType x)
{        
    if(headNode==NULL)
    {
        return;
    }
    else
    {
        Node*pcur=headNode;
        Node*cur=headNode->next;
        while(cur!=NULL)
        {
            if(cur->data==x)
            {
                break;
            }
            pcur=cur;
            cur=cur->next;
        }
        if(cur==NULL)
        {
            return;
        }
        pcur->next=cur->next;
        free(cur);
        cur=NULL;

    }
 
        
}
void ClearList(Node*headNode)
{
  if(headNode==NULL)
  {
    return;
  }
  else{
    Node*cur=headNode->next;
    while(cur!=NULL)
    {
      Node*pcur=cur->next;
      free(cur);
      cur=pcur;
    }
  }
  headNode->next=NULL;
}
void DestroyList(Node*headNode)
{
  if(headNode==NULL)
  {
    return;
  }
  ClearList(headNode);
  free(headNode);
  headNode=NULL;
}

int main()
{
    Node* L = CreateList();
   /* HeadInsert(L, 1);
    HeadInsert(L, 2);
    HeadInsert(L, 3);
    HeadInsert(L, 4);
    PrintLinklist(L);*/
    TailInsert(L,1);
    TailInsert(L,2);
    TailInsert(L,3);
    TailInsert(L,4);
     PrintLinklist(L);
     DeleteList(L,3);

   // PointInsert(L, 0, 10);
   PrintLinklist(L);
   ClearList(L);
  TailInsert(L,4);
   PrintLinklist(L);

}

