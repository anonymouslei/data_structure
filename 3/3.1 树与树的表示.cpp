typedef struct LNode *List;
struct LNode{
	ElementType Element[MAXSIZE];
	int Length;
};

int SequentialSearch (List Tb1, ElementType K)
{
	int i;
	Tb1->Element[0] = K; // 建立哨兵
	for(i = Tb1->Length; Tb1->Element[i]!=K;i--);
	return i; // 查找成功返回所在单元下标；不成功返回0
}

int BinarySearch (List Tbl, ElementType K)
{
	int left, right, mid, NotFound = -1;
	
	left = 1;
	right = Tbl->Length;
	while(left <= right)
	{
		mid = (left+right)/2;
		if(K<Tbl->Element[mid])	right = mid-1;
		else if(K>Tbl->Element[mid])	left=mid+1;
		else return mid;
	}
	return NotFound;
}