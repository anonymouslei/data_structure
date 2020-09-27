struct PolyNode{
	int coef;
	int expon;
	struct PolyNode *link;
};
typedef struct PolyNode *Polynomial;
Polynomial P1,P2;