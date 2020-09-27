#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print( List L ); /* 细节在此不表；空链表将输出NULL */

List Merge( List L1, List L2 );

int main()
{
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    L = Merge(L1, L2);
    Print(L);
    Print(L1);
    Print(L2);
    return 0;
}

List Merge(List L1, List L2 )
{
    List L;
    List tmp = (List)malloc(sizeof(struct Node)); // L的地址一直在变，否则就找不到L的首地址在哪里了。需要tmp来存储首地址
    List tmp1 = L1->Next;
    List tmp2 = L2->Next;

    L = tmp;
    tmp->Next = NULL;

    while(tmp1!=NULL && tmp2!=NULL)
    {
        if (tmp1->Data < tmp2->Data)
        {
            L->Next = tmp1;
            tmp1  = tmp1->Next;
        } else {
            L->Next = tmp2;
            tmp2  = tmp2->Next;
        }
        L = L->Next;
    }

    if (tmp1 == NULL)    L ->Next = tmp2;
    if (tmp2 == NULL)    L ->Next = tmp1;
    L1->Next = NULL;
    L2->Next = NULL;

    return tmp;
}

List Read1()
{
    List L0;
    L0 = (List)malloc(sizeof(struct Node));
    List L;
    L = (List)malloc(sizeof(struct Node));
//    L0->Next = NULL;
    L0->Next = L;
    L ->Data = 1;
    List tmp1 = (List)malloc(sizeof(struct Node));
    tmp1 ->Data = 3;
    L -> Next = tmp1;
    List tmp2 = (List)malloc(sizeof(struct Node));
    tmp2 ->Data = 5;
    tmp1 ->Next = tmp2;
    tmp2 ->Next = NULL;
    return L0;
}

List Read2()
{
    List L0;
    L0 = (List)malloc(sizeof(struct Node));
//    L0->Next = NULL;
    List L;
    L = (List)malloc(sizeof(struct Node));
    L0->Next = L;
    L ->Data = 2;
    List tmp1 = (List)malloc(sizeof(struct Node));
    tmp1 ->Data = 4;
    L -> Next = tmp1;
    List tmp2 = (List)malloc(sizeof(struct Node));
    tmp2 ->Data = 6;
    tmp1 ->Next = tmp2;
    List tmp3 = (List)malloc(sizeof(struct Node));
    tmp3 ->Data = 8;
    tmp2 -> Next = tmp3;
    List tmp4 = (List)malloc(sizeof(struct Node));
    tmp4 ->Data = 10;
    tmp3 ->Next = tmp4;
    tmp4 ->Next = NULL;
    return L0;
}