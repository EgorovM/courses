#include <iostream>

template <typename T>
struct BinaryHeap {
public:
    BinaryHeap() = default;

    BinaryHeap(size_t n, const T& el): last(n) {
        nodes = new T[n]();
        for(int i = 0; i < n; i++) {
            nodes[i] = el;
        }
    }

    BinaryHeap(T* elements, int n) {
        nodes = new T[n]();

        for(int i = 0; i < elements; i++) {
        }
    }

    ~BinaryHeap() {
        delete[] nodes;
    }

    bool Empty() const {
        return last == 0;
    }

    void Insert(const T &el) {
        nodes[last] = el;
        ShiftUp(last);
        last++;
    }

    void Remove(const int pos) {
        nodes[pos] = INT32_MAX;
        ShiftUp(pos);
        ExtractMax();
    }

    void ChangePriority(int pos, int inc) {
        nodes[pos] += inc;
        ShiftUp(nodes[pos]);
        ShiftDown(nodes[pos]);
    }

    T& GetMax() {
      return nodes[0];
    }

    T ExtractMax() {
        T max_el = nodes[0];
        nodes[0] = nodes[--last];
        ShiftDown(0);

        return max_el;
    }

private:
    void ShiftUp(int pos) {
        int parent = pos / 2;

        while(parent != pos && nodes[parent] < nodes[pos]) {
            std::swap(nodes[parent], nodes[pos]);
            pos = parent;
            parent = pos / 2;
        }
    }

    void ShiftDown(int pos) {
        auto getChilds = [](int pos) -> std::pair<int, int>{
            return {pos * 2, pos * 2 + 1};
        };

        std::pair<int, int> children = getChilds(pos);

        while(children.first < last || children.second < last) {
            if(children.first > last) {
                children.first = children.second;
            }else if(children.second > last){
                children.second = children.first;
            }

            int toSwapChild = nodes[children.first] > nodes[children.second]
                                      ? children.first
                                      : children.second;

            std::swap(nodes[toSwapChild], nodes[pos]);
            pos = toSwapChild;
            children = getChilds(pos);
        }
    }

    T* nodes{nullptr};
    int last{0};
};


template <typename T>
void HeapSort(T *elements, size_t n) {
    BinaryHeap<T> binaryHeap(n);

    for(int i = 0; i < n; i++) {
        binaryHeap.Insert(elements[i]);
    }

    for(int i = 0; i < n; i++) {
        elements[i] = binaryHeap.ExtractMax();
    }
}