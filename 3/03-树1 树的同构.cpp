#include <iostream>

#define MaxTree 10
#define ElementType char
#define Tree int
#define Null -1

using namespace std;

struct TreeNode {
    ElementType data;
    Tree Left;
    Tree Right;
};

class ListLeaves {
public:
    void inputData() {
        root1_ = buildTree(T1_);
        root2_ = buildTree(T2_);
    }
    Tree buildTree(TreeNode* T);
    int isomorphic (Tree R1, Tree R2);
    void isomorphic ();

private:
    TreeNode T1_[MaxTree];
    TreeNode T2_[MaxTree];
    Tree root1_;
    Tree root2_;
};

Tree ListLeaves::buildTree(TreeNode* T) {
    int n;
    cin >> n;
    if (n == 0)    return Null;
    int check[MaxTree];
    for (int i = 0; i < n; ++i)    check[i] = 0;
    for (int i = 0; i < n; ++i) {
        char data, j, k;
        cin >> data >> j >> k;
        T[i].data = data;
        if (j != '-') {
            T[i].Left = j - '0';
            check[T[i].Left] = 1;
        } else
            T[i].Left = Null;

        if (k != '-') {
            T[i].Right = k - '0';
            check[T[i].Right] = 1;
        } else
            T[i].Right = Null;
    }
    int i;
    for (i = 0; i < n; ++i) {
        if (!check[i]) {
            break;
        }
    }
    return i;
}

int ListLeaves::isomorphic(Tree R1, Tree R2) {
    // both empty
    if ((R1 == Null) && (R2 == Null))
        return 1;
    // one of them is empty
    if (((R1 == Null) && (R2 != Null)) || ((R1 != Null) && (R2 == Null)))
        return 0;
    // roots are different
    if (T1_[R1].data != T2_[R2].data)
        return 0;
    // both have no left subtree
    if ((T1_[R1].Left == Null) && (T2_[R2].Left == Null))
        return isomorphic(T1_[R1].Right, T2_[R2].Right);
    // both have no right subtree
    if ((T1_[R1].Right == Null) && (T2_[R2].Right == Null))
        return isomorphic(T1_[R1].Left, T2_[R2].Left);

    if (((T1_[R1].Left!=Null) && (T2_[R2].Left!=Null) &&
         (T1_[T1_[R1].Left].data) == (T2_[T2_[R2].Left].data)))
        // no need to swap the left and the right
        return (isomorphic(T1_[R1].Left, T2_[R2].Left) &&
                isomorphic(T1_[R1].Right, T2_[R2].Right));
    else // need to swap the left and the right
        return (isomorphic(T1_[R1].Left, T2_[R2].Right) &&
                isomorphic(T1_[R1].Right, T2_[R2].Left));
}

void ListLeaves::isomorphic() {
    if (isomorphic(root1_, root2_))
        cout << "Yes";
    else
        cout << "No";
}
int main() {
    ListLeaves test;
    test.inputData();
    test.isomorphic();
    return 0;
}