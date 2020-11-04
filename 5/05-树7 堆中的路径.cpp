#include <vector>
#include <iostream>
#include <cassert>
#include <chrono>


int MaxSize = 10000;
typedef struct HeapStruct *MaxHeap;
typedef int ElementType;
struct HeapStruct {
    ElementType * elements; // 存储堆元素的地址
    int size; // 堆的当前元素个数
    int capacity; //堆的最大容量

    HeapStruct(): elements(new ElementType[MaxSize]), size(0), capacity(MaxSize) {}
};

class PathInHeap {
public:
    void createHeap();
    void printPath();
    bool isFull(MaxHeap h);
    void test();

private:
    MaxHeap h_;
    std::vector<int> heapLists();
    void insert(ElementType item);
    
    int printIndexNum_;
    std::vector<int> printIndexs_;
};

std::vector<int> PathInHeap::heapLists() {
    int size;
    std::cin >> size;
    std::cin >> printIndexNum_;
    std::vector<int> heapList;
    for (int i = 0; i < size; ++i) {
        int tmp;
        std::cin >> tmp;
        heapList.push_back(tmp);
    }
    for (int i = 0; i < printIndexNum_; ++i) {
        int tmp;
        std::cin >> tmp;
        printIndexs_.push_back(tmp);
    }
    return heapList;
}

void PathInHeap::printPath() {
//    auto t1 = std::chrono::high_resolution_clock::now();
    for (auto index: printIndexs_) {
        for (int j = index; j>0; j/=2) {
            std::cout << h_->elements[j];
            (j == 1) ? (std::cout << std::endl) : std::cout << " ";
        }
    }
//    auto t2 = std::chrono::high_resolution_clock::now();
//    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2-t1).count();

}

void PathInHeap::createHeap() {
    h_ = new HeapStruct;
    std::vector<int> heapList;
    heapList = heapLists();
    h_->elements[0] = -MaxSize-1;
    for (int item : heapList) {
        insert(item);
    }
}

void PathInHeap::insert(ElementType item) {
    if (isFull(h_)) {
        std::cout << "the max Heap is full!" << std::endl;
        return;
    }

    int i = ++h_->size; // i points to the last element in the heap after insert
    for (; h_->elements[i/2] > item; i/=2) {
        h_->elements[i] = h_->elements[i/2];
    }
    h_->elements[i] = item;
}

bool PathInHeap::isFull(MaxHeap h) {
    return h->size == h->capacity;
}

void PathInHeap::test() {
    assert(h_->size == 5);
    assert(h_->elements[5] == 24);
    assert(h_->elements[4] == 46);

}

int main() {

    PathInHeap test;
    test.createHeap();
//    test.test();
    test.printPath();
    return 0;
}
