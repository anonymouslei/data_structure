// 耗时： 17ms

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
#define NotFound 0
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* 保存线性表中最后一个元素的位置 */
};

List ReadInput(); /* 裁判实现，细节不表。元素从下标1开始存储 */
Position BinarySearch( List L, ElementType X );

int main()
{
    List L;
    ElementType X;
    Position P;

    L = ReadInput();
    scanf("%d", &X);
    P = BinarySearch( L, X );
    printf("%d\n", P);

    return 0;
}

Position BinarySearch(List L, ElementType X)
{
    int result = -1;
    int start = 1;
    int length = L->Last + 1;
    int end = length;
    int mid;

    while(start <= end){
        mid = start + (end - start)/2;
        if (L->Data[mid] < X)
            start = mid +1;
        else if (L->Data[mid] > X)
        {
            end = mid - 1;
        }
        else
        {
            result = mid;
            return result;
        }
    }            
    return NotFound;
}

