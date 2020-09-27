Stack CreateStack(int MaxSize); //生成空堆栈，其最大长度为MaxSize
int IsFull(Stack S, int MaxSize); // 判断堆栈S是否已满
void Push(Stack S, ElementType item); // 将元素Item压入堆栈；
int IsEmpty(Stack S); // 判断堆栈S是否为空；
ElementType Pop(Stack S); // 删除并返回栈顶元素

#define MaxSize <储存数据元素的最大个数>
typedef struct SNode *Stack;
struct SNode{
	ElementType Data[MaxSize];
	int Top; // Top = -1 代表堆栈空
};

void Push(Stack PtrS, ElementType item)
{
	if(PtrS->Top == MaxSize-1){
		printf("stack is full."); return;
	} else {
		PtrS -> Data[++(PtrS->Top)] = item;
		return;
	}
}

ElementType Pop (Stack PtrS)
{
	if(PtrS->Top == -1){
		printf("stack is leer. ");
		return ERROR;
	} else 
		return (PtrS->Data[(PtrS->Top)--])
}

#define MaxSize <存储数据元素的最大个数>
struct DStack{
	ElementType Data[MaxSize];
	int Top1;
	int Top2;
}S;
S.Top1 = -1;
S.Top2 = MaxSize;

void Push(struct DStack *PtrS, ElementType item, int Tag)
{ // Tag 作为区分两个堆栈的标志，取值为1和2
	if(PtrS->Top2 - PtrS->Top1 == 1){
		printf("stack is full");
		return;
	}
	if(Tag == 1) // 对第一个stack操作
		PtrS->Data[++(PtrS->Top1)] = item;
		else
			PtrS -> Data[--(PtrS->Top2)] = item;
}

ElementType Pop(struct DStack *PtrS, int Tag)
{
	if(Tag == 1){
		if(PtrS->Top1 == -1){
			printf("stack1 is leer"); return NULL;
		} else return PtrS->Data[(PtrS->Top1)--];
	} else{
		if( PtrS->Top2 == MaxSize){
			printf("stack2 is leer");
			return NULL;
		} else return PtrS->Data[(PtrS->Top2)++]
	}
}
	