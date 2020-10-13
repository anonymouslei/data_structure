#include <iostream>
#include <vector>

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

TreeP insert(TreeP T,int v);

TreeP newNode(int v) { // not sure whether the reference here is right
    TreeP T = new TreeNode;
    T->v = v;
    T->Left = T->Right = NULL;
    T->flag = 0;

    return T;
}

TreeP MakeTree(int N) {
    int v;
    cin >> v;

    TreeP T = newNode(v);
    for (int i = 1; i < N; ++i)
    {
        cin >> v;
        T = insert(T, v);
    }
    return T;
}

TreeP insert(TreeP T,int v) {
    if (!T)
    {
        T = newNode(v);
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

int check(TreeP T, int v) {
    if (T->flag)
    {
        if (v < T->v)
        {
            return check(T->Left, v);
        } else if (v > T->v)
        {
            return check(T->Right, v);
        } else
            return 0;
    }
    else {
        if (v == T->v)
        {
            T->flag = 1;
            return 1;
        }
        else
            return 0;
    }

}

int judge(TreeP T, int n) {
    std::vector<int> v;
//    int flag = 0; // flag: 0 represents same, 1 represents different

    for (int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
//    cin >> v;
    if (v[0]!=T->v)
    {
        return 0;
    } else {
        T->flag = 1;
    }
    for (int i = 1; i < n; ++i)
    {
//        cin >> v;
        if (!check(T, v[i]))
        {
            return 0;
        }
    }
    return 1;
}

void ResetT(TreeP T) // 清除T中各结点的flag标记
{
    if (T->Left)    ResetT(T->Left);
    if (T->Right)   ResetT(T->Right);
    T->flag = 0;
}

void FreeTree(TreeP T)
{
    if (T->Left) FreeTree(T->Left);
    if (T->Right) FreeTree(T->Right);
    delete T;
}

int main() {
    // read N and L
    // build tree according the first line
    // discriminate whether a sequence forms the same
    // search tree as T
    int N, L;
    TreeP T;

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
        cin >> N;
    }

    return 0;
}



