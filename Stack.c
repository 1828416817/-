#include <stdio.h>
#include <stdlib.h>
 typedef struct
  {
    int *data;
    int size;
  }Stack;
  Stack*CreateStack()
  {
    Stack* s=malloc(sizeof(Stack));
    s->data=NULL;
    s->size=0;
    return s;
  }
  void DestroyStack(Stack *s)
  {
    free(s->data);
    free(s);
  }
  void push(Stack *s,int x)
  {
    s->data=realloc(s->data,sizeof(int)*(s->size+1));
      s->data[s->size]=x;
      s->size++;
  }
  void pop(Stack *s)
  {
      s->size--;
  }
 int  top(const Stack * s)
{
  return s->data[s->size-1];
}
  void PrintStack(const Stack *s)
  {
    for(int i=0;i<s->size;i++)
    {
      printf("%d ",s->data[i]);
    }
    printf("\n");
     
  }
int main(void) {
  Stack *s=CreateStack();
  
  push(s,10);
  push(s,20);
  printf("%d\n",top(s));
  //PrintStack(s);
  push(s,30);
   //PrintStack(s);
    printf("%d\n",top(s));
   pop(s);
    printf("%d\n",top(s));
    DestroyStack(s);
   //PrintStack(s);
  return 0;
}
