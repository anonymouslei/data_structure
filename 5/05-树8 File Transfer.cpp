// 2020.11.04
// Author: Lei Ge

// 1. 建立连通集数据
// while loop
// 2. 根据c和i分别进行判断和连通
// 2.1 判断
// 2.2 按秩归并，比规模，并且进行路径压缩
// 2.2.1 路径压缩： 把父节点更新为根节点
// quit while loop and output

#include <iostream>
#include <vector>
#include <cassert>

using std::vector;

class FileTransfer {
public:
    void checking();
    void inputConnection();
    int findFather(int x);
    void printResult();
    void run();

    void test();

private:
    int size_;
    vector<int> networkLists_;
};

void FileTransfer::checking() {
    // 观察两个子集的父节点是否相同
    // 在checking 的时候进行路径压缩
    int x, y;
    std::cin >> x >> y;
    if (findFather(x) == findFather(y))
    {
        std::cout << "yes" << std::endl;
    } else  {
        std::cout << "no" << std::endl;
    }

}

void FileTransfer::inputConnection() {
    int x, y;
    std::cin >> x >> y;
    int fatherX = findFather(x);
    int fatherY = findFather(y);
    if (networkLists_[fatherX] < networkLists_[fatherY])  {
        networkLists_[fatherX] += networkLists_[fatherY];
        networkLists_[fatherY] = fatherX;
    } else {
        networkLists_[fatherY] += networkLists_[fatherX];
        networkLists_[fatherX] = fatherY;
    }
}

int FileTransfer::findFather(int x) {
    // 按秩合并
    if (networkLists_[x] < 0)
        return x;
    else
        return networkLists_[x] = findFather(networkLists_[x]); // 记住这个方法。
}

void FileTransfer::run() {

    std::cin >> size_;

    networkLists_ = vector<int>(size_+1, -1);
    char opera;
    std::cin >> opera;
    while (opera != 'S') {
        switch (opera) {
            case 'C' :
                checking();
                break;
            case 'I' :
                inputConnection();
                break;
        }
        std::cin >> opera;
    }
    printResult();
}

void FileTransfer::printResult() {
    int numOfComponent = -1;
    for (auto item: networkLists_) {
        if (item < 0)    numOfComponent++;
    }
    if (numOfComponent == 1)
        std::cout << "The network is connected.";
    else
        std::cout << "There are " << numOfComponent << " components.";
}
void FileTransfer::test() {
    networkLists_ = vector<int>{-1, -1, 1, 2, 2, 4};
    int x = findFather(5);
    std::cout << x << std::endl;
}

int main() {
    FileTransfer test;
    test.run();
//    test.test();

    return 0;
}