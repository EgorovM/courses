#include <iostream>
#include <queue>

int size, n;
int start, duration;
int max_end = -1;

void print_answer(int a) {
    std::cout << a << std::endl;
}

int main() {
    std::queue<int> mq;
    std::cin >> size >> n;

    for(int q = 0; q < n; q++) {
        std::cin >> start >> duration;

        while(!mq.empty() && mq.front() <= start) {
            mq.pop();
        }

        if(mq.empty()) {
            print_answer(start);
            mq.push(start + duration);
            max_end = start + duration;

            continue;
        }

        if(mq.size() >= size) {
            print_answer(-1);
            continue;
        }

        int actual_start;

        actual_start = max_end > start ? max_end : start;

        print_answer(actual_start);
        mq.push(actual_start + duration);

        max_end = std::max(max_end, actual_start + duration);
    }

    return 0;
}
