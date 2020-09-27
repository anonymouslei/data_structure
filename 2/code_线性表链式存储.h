typedef struct LNode *List;
struct LNode{
	ElementType Data;
	List Next;
};
struct Lnode L;
List PtrL;

int Length(List PtrL){
	List p = PtrL;
	int j = 0;
	while(p){
		p = p->Next;
		j++;
	}
	return j;
}

List FindKth(int K, List PtrL)
{
	List p = PtrL;
	int i = 1;
	while(p!=NULL && i<K){
		p = p->Next;
		i++;
	}
	if(i == K) return p;
	else return NULL;
}

List Find(ElementType X, List PtrL)
{
	List p = PtrL;
	while(p!=NULL && p->Data != X)
		p = p->Next;
	return p;
}

List Insert(ElementType X, int i, List PtrL)
{
	List p,s;
	if(i == 1){
		s = (List)malloc(sizeof(struct LNode));
		s->Data = X;
		s->Next = PtrL;
		return s;
	}
	p = FindKth(i-1, PtrL); // 查找第i-1个结点
	if(p == NULL){
		printf("参数错");
		return NULL;
	}else{
		s = (List)malloc(sizeof(struct LNode));
		s->Data = X;
		s->Next = p->Next;
		p->Next = s;
		return PtrL;
	}
}

List Delet(int i, List PtrL)
{
	List p,s;
	if(i == 1){
		s = PtrL;
		if(PtrL != NULL) PtrL = PtrL->Next;
		else return NULL;
		free(s);
		return PtrL;
	}
	p = FindKth(i-1, PtrL);
	if(p == NULL){
		printf("第%d个结点不存在", i-1); 
		return NULL;
	}else if (p->Next == NULL){
		printf("第%d个结点不存在", i);
		return NULL;
	}else{
		s = p->Next;
		p->Next = s->Next;
		free(s);
		return PtrL;
	}
}

typedef struct GNode *GList;
struct GNode{
	int Tag; //标志域： 0表示结点是单元素，1表示结点时广义表
	union{ // 子表指针域Sublist 与单元素数据域Data复用，即公用存储空间
		ElementType Data;
		GList SubList;
	} URegion;
	GList Next; //
}










