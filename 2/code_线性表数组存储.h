typedef struct PolyNode *Polynomial;
struct PolyNode{
	int coef;
	int expon;
	Polynomial link;
}

List MakeEmpty(): 初始化一个空线性表L
ElementTpye FineKti(int K, List L): 根据位序K，返回相应元素
int Find(ElementTpye X, List L): 在线性表L中查找X的第一次出现位置
void Insert(ElementTpye X, int i, List L): 在位序i前面插入一个新元素X
void Delete(int i, LIst L):删除指定位序i的元素
int Length(List L): 返回线性表L的长度n

typedef struct LNode*;
struct LNode{
	ElementTpye Data[MAXSIZE];
	int Last;
};
struct LNode L;
List PtrL;
访问下标为i的元素： L.Data[i] 或 PtrL->Data[i]
线性表的长度： L.Last+1 或 PtrL->Last+1

List MakeEmpty()
{
	List PtrL;
	PtrL = (List) malloc(sizeof (struct LNode)); //申请一个结构
	PtrL->Last = -1;
	return PtrL;
}

int Find(ElementTpye X, List PtrL)
{
	int i = 0;
	while (i <= PtrL->Last && PtrL->Data[i]!=X)
		i++;
	if(i > PtrL->Last) return -1; //如果没找到， 返回-1
	else return i; // 找到后返回的是存储位置
}

void Insert(ElementTpye X, int i, List PtrL)
{
	int j;
	if(PtrL->Last == MAXSIZE-1){
		printf("the table is full");
		return;
	}
	if(i < 1|| i>PtrL->Last+2){
		printf("位置不合法");
		return;
	}
	for(j = PtrL->Last;j>=i-1;j--)
		PtrL->Data[j+1] = PtrL->Data[j];
	PtrL->Data[i-1] = X;
	PtrL->Last++;
	return;
}

void Delete(int i, List PtrL){
	int j;
	if(i < 1 || i>PtrL->Last+1){ // 检查空表及删除位置的合法性
		printf("不存在第%d个元素"); //不要忘记这一步，
		return;
	}
	for (j = i;j<=PtrL->Last;j++)
		PtrL->Data[j-1] = PtrL->Data[j];
		PtrL->Last--;
		return;
}
	


