#include <stdio.h>
#include <malloc.h>
#define MaxSize 50
typedef int ElemType;
typedef struct
{
    ElemType data[MaxSize];
    int length;
} SqList;
void InitList(SqList*& L)   //��ʼ�����Ա�
{
    L = (SqList*)malloc(sizeof(SqList)); //���������Ա�Ŀռ�
    L->length = 0;                        //�ÿ����Ա���Ϊ0
}
void DestroyList(SqList* L)     //�������Ա�
{
    free(L);
}
bool ListEmpty(SqList* L)   //�����Ա��Ƿ�Ϊ�ձ�
{
    return(L->length == 0);
}
int ListLength(SqList* L)   //�����Ա�ĳ���
{
    return(L->length);
}
void DispList(SqList* L)    //������Ա�
{
    int i;
    if (ListEmpty(L)) return;
    for (i = 0; i < L->length; i++)
        printf("%d\n ", L->data[i]);
    printf("\n");
}
bool GetElem(SqList* L, int i, ElemType& e)   //�����Ա���ĳ������Ԫ��ֵ
{
    if (i<1 || i>L->length)
        return false;           //��������ʱ����false
    e = L->data[i - 1];             //ȡԪ��ֵ
    return true;                //�ɹ��ҵ�Ԫ��ʱ����true
}
int LocateElem(SqList* L, ElemType e)   //��Ԫ��ֵ����
{
    int i = 0;
    while (i < L->length&& L->data[i] != e)
        i++;                    //����Ԫ��e
    if (i >= L->length)           //δ�ҵ�ʱ����0
        return 0;
    else
        return i + 1;             //�ҵ��󷵻����߼����
}

bool ListInsert(SqList*& L, int i, ElemType e)    //��������Ԫ��
{
    int j;
    if (i<1 || i>L->length + 1)
        return false;           //��������ʱ����false
                           //��˳����߼����ת��Ϊ�������
    for (j = L->length; j >= i; j--)   //��data[i]������Ԫ�غ���һ��λ��
        L->data[j] = L->data[j - 1];
    L->data[i-1] = e;               //����Ԫ��e
    L->length++;                //˳�������1
    return true;                //�ɹ����뷵��true
}
bool ListDelete(SqList*& L, int i, ElemType& e)   //ɾ������Ԫ��
{
    int j;
    if (i<1 || i>L->length)     //��������ʱ����false
        return false;
    i--;                        //��˳����߼����ת��Ϊ�������
    e = L->data[i];
    for (j = i; j < L->length - 1; j++) //��data[i]֮���Ԫ��ǰ��һ��λ��
        L->data[j] = L->data[j + 1];
    L->length--;                //˳����ȼ�1
    return true;                //�ɹ�ɾ������true
}

extern void InitList(SqList*& L);
extern void DestroyList(SqList* L);
extern bool ListEmpty(SqList* L);
extern int ListLength(SqList* L);
extern void DispList(SqList* L);
extern bool GetElem(SqList* L, int i, ElemType& e);
extern int LocateElem(SqList* L, ElemType e);
extern bool ListInsert(SqList*& L, int i, ElemType e);
extern bool ListDelete(SqList*& L, int i, ElemType& e);
int main()
{
    SqList* L;
   // ElemType e;
    
    InitList(L);
    
    ListInsert(L, 1, 12);
    ListInsert(L, 2, 13);
    ListInsert(L, 3, 14);
    ListInsert(L, 4, 15);
    ListInsert(L, 5, 16);
    printf("  (3)���˳���L:");
    DispList(L);
   printf("  (4)˳���L����=%d\n", ListLength(L));
    printf("  (5)˳���LΪ%s\n", (ListEmpty(L) ? "��" : "�ǿ�"));
    GetElem(L, 3, e);
    printf("  (6)˳���L�ĵ�3��Ԫ��=%c\n", e);
    printf("  (7)Ԫ��a��λ��=%d\n", LocateElem(L, 'a'));
    printf("  (8)�ڵ�4��Ԫ��λ���ϲ���fԪ��\n");
    ListInsert(L, 4, 'f');
    printf("  (9)���˳���L:");
    DispList(L);
    printf("  (10)ɾ��L�ĵ�3��Ԫ��\n");
    ListDelete(L, 3, e);
    printf("  (11)���˳���L:");
    DispList(L);
    printf("  (12)�ͷ�˳���L\n");
    DestroyList(L);
}



