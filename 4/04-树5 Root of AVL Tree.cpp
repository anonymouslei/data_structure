#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

using std::vector;
using std::cin;

typedef struct AVLNode *Position;
typedef Position AVLTree;
struct AVLNode {
    int data;
    AVLTree left;
    AVLTree right;
//    int height;

    AVLNode() : data(0), left(nullptr), right(nullptr) {}
};

class AVLTreeRoot {
public:
    vector<int> ReadNodes();
    AVLTree CreateAVLTree(vector<int> & input);
    void PrintRootOfAVL() const;
    void test() const;

private:
    int GetHeight(AVLTree T) const;
    AVLTree Insert(AVLTree T, int data);
    AVLTree SingleRightRotation(AVLTree A);
    AVLTree SingleLeftRotation(AVLTree A);
    AVLTree DoubleRightLeftRotation(AVLTree A);
    AVLTree DoubleLeftRightRotation(AVLTree A);

    int size_;
    AVLTree T_ = nullptr;

};

vector<int> AVLTreeRoot::ReadNodes() {
    cin >> size_;
    vector<int> input;
    for (int i = 0; i < size_; ++i) {
        int tmp;
        cin >> tmp;
        input.push_back(tmp);
    }
    return input;
}

AVLTree AVLTreeRoot::CreateAVLTree(vector<int> & input) {
    for (auto i : input) {
        T_ = Insert(T_, i);
    }
    return T_;
}

void AVLTreeRoot::PrintRootOfAVL() const {
    std::cout << T_->data;
}

int AVLTreeRoot::GetHeight(AVLTree T) const {
    if (T == nullptr)
        return 0;

    return std::max(GetHeight(T->right), GetHeight(T->left)) + 1;
}

AVLTree AVLTreeRoot::Insert(AVLTree T, int data) {
    // 1. 新的节点递归式插入
    // 2. 调整使平衡
    if (T == nullptr) {
        T = new AVLNode;
        T->data = data;
    } else if (data > T->data) {
        T->right = Insert(T->right, data); // 想一下返回值应该是什么
        // 调整使平衡
        if (GetHeight(T->right) - GetHeight(T->left) == 2) {
            if (data > T->right->data) {
                T = SingleRightRotation(T);
            } else {
                T = DoubleRightLeftRotation(T);
            }
        }
    } else if (data < T->data) {
        T->left = Insert(T->left, data);
        if (GetHeight(T->left) - GetHeight(T->right) == 2) {
            if (data > T->left->data) {
                T = DoubleLeftRightRotation(T);
            } else {
                T = SingleLeftRotation(T);
            }
        }
    }
    return T;
}

void AVLTreeRoot::test() const {
    assert(T_->data == 88);
    assert(T_->left->data == 70);
    assert(T_->left->left->data == 61);
    assert(T_->right->data == 96);

}

AVLTree AVLTreeRoot::SingleLeftRotation(AVLTree A) {
    AVLTree B = A->left;
    A->left = B->right;
    B->right = A;
    return B;
}

AVLTree AVLTreeRoot::SingleRightRotation(AVLTree A) {
    AVLTree B = A->right;
    A->right = B->left;
    B->left = A;
    return B;
}

AVLTree AVLTreeRoot::DoubleRightLeftRotation(AVLTree A) {
    AVLTree B = A->right;
//    AVLTree C = B->left;
    B = SingleLeftRotation(B);
    A->right = B; // 求出新的B之后要更新A的右节点
    return SingleRightRotation(A);
}

AVLTree AVLTreeRoot::DoubleLeftRightRotation(AVLTree A) {
    AVLTree B = A->left;
    B = SingleRightRotation(B);
    A->left = B;
    return SingleLeftRotation(A);
}

int main() {
    AVLTreeRoot test;
    vector<int> inputs = test.ReadNodes();
    test.CreateAVLTree(inputs);
    test.PrintRootOfAVL();
//    test.test();
}
