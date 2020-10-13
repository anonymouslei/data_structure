#include <iostream>

using std::endl;
using std::cout;
using std::cin;

typedef struct TreeNode *TreeP;
struct TreeNode 
{
	int v;
	TreeP Left, Right;
	int flag;	
};

TreeP MakeTree(N) {
	int i, v;
	cin >> v;

	THead_ = newNode(v);
	for (int i = 0; i < N; ++i)
	{
		cin >> v;
		T = insert(T, v);
	}
	return T;
}

TreeP NewNode(int v) { // not sure whether the reference here is right
	TreeP T = new TreeNode;
	T->v = v;
	T->Left = T->Right = NULL;
	T->flag = 0;

	return T;
}

TreeP insert(TreeP T,int v) {
	if (!T)
	{
		T = NewNode(v);
	} else {
		if (v > T->v)
		{
			T->Right = insert(T->Right, v);
		} else {
			T->Left = insert(T->Left, v);
		}
	}
	return T;
}

int check() {

}

int judge(TreeP T, int n) {
	
}
int main() {
	// read N and L
	// build tree according the first line
	// discriminate whether a sequence forms the same
	// search tree as T
	int N, L, i;
	Tree T;

	std::cin >> N;
	while (N) {
		cin >> L;
		T = MakeTree(N);
		for (int i = 0; i < L; ++i)
		{
			if (judge(T, N))
			{
				cout << "Yes" << endl;
			} else {
				cout << "No" << endl;
			}
			ResetT(T);
		}
		FreeTree(T);
		cin << "N";
	}

	return 0;
}