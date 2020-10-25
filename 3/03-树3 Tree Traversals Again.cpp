// 根据观察可知，输入格式中push的过程就是二叉树前序遍历的结果，而pop的过程为二叉树的中序遍历的结果。
// 题目就变成已知二叉树的前序和中序遍历求二叉树的后序遍历。

// 因此，前序遍历中第一个元素为后序遍历的最后一个元素，在中序遍历中根节点左边的为左子树的节点，
// 右边为右子树的节点。所以需要递归的求解这个问题。
// 中序的作用就是提供左右子树的个数的

#include <iostream>
#include <vector>
#include <stack>
#include <cassert>
#include <string>

using std::vector;
using std::cout;
using std::cin;
using std::string;

class RootOfAvlTree {
public:
    void ReadInput();
    void PostOrder(int startPos, int num, int inL, int postL);
    void PrintPostOrder();
    void Test();

private:
    void NumOfLeftAndRightTree(int startPos, int num, const int root, int & numOfRight, int & numOfLeft);

    int size_;
    std::vector<int> preOrder_;
    std::vector<int> inOrder_;
    std::vector<int> postOrder_;
};

void RootOfAvlTree::NumOfLeftAndRightTree(int startPos, int num, const int root, int &numOfRight, int &numOfLeft) {
    int tmp = 0;
    for (int i = startPos; i < startPos + num; ++i) {
        if (inOrder_[i] == root)
        {
            tmp = i;
            break;
        }
    }
    numOfLeft = tmp - startPos;
    numOfRight = num - 1 - numOfLeft;
}

void RootOfAvlTree::ReadInput() {
    cin >> size_;
    std::stack<int> binaryTree;
    for (int i = 0; i < 2*size_; ++i) {
        string text;
        int tmp;
        cin >> text;
        if (text == "Push") {
            cin >> tmp;
            preOrder_.push_back(tmp);
            binaryTree.push(tmp);
        } else {
            tmp = binaryTree.top();
            binaryTree.pop();
            inOrder_.push_back(tmp);
        }
    }
}

void RootOfAvlTree::PostOrder(int startPos, int num, int inL, int postL) {

    if(num == 0)    return;
    if (num == 1) {
        postOrder_[postL+num-1] = preOrder_[startPos];
        return;
    }
    int root = preOrder_[startPos];
    postOrder_[postL+num-1] = root;
    int numOfRight, numOfLeft;
    NumOfLeftAndRightTree(inL, num, root, numOfRight, numOfLeft);

    PostOrder(startPos+1, numOfLeft, inL, postL);
    PostOrder(startPos+1+numOfLeft, numOfRight, inL+numOfLeft+1, postL+numOfLeft);
}

void RootOfAvlTree::PrintPostOrder() {
    postOrder_ = vector<int>(size_, 0);
    PostOrder(0, size_, 0, 0);
    for (int i = 0; i < size_; ++i) {
        cout << postOrder_[i];
        if (i < size_-1)
            cout << " ";
    }
}

void RootOfAvlTree::Test() {
    assert(preOrder_.size() == 6);
    assert(inOrder_.size() == 6);

    postOrder_ = vector<int>(size_, 0);
//    assert(postOrder_.size() == 6);
//    for (int i = 0; i < size_; ++i) {
//        assert(postOrder_[i] == 0);
//    }
}

int main()
{
    RootOfAvlTree test;
    test.ReadInput();
    test.PrintPostOrder();
    return 0;
}