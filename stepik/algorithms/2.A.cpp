#include <iostream>
#include <vector>


std::pair<int, int> shiftUp(int *items, int pos) {
    int start_pos = pos;
    int end_pos = pos;

    while(pos != pos / 2) {
        int parent = pos / 2;

        if(items[parent] > items[pos]) {
            std::cout << parent << " " << pos << std::endl;
            std::cout << items[parent] << " " << items[pos] << std::endl;

            std::swap(items[parent], items[pos]);
            end_pos /= 2;
        }else {
            break;
        }

        pos /= 2;
    }

    return {start_pos, end_pos};
}


int n, items[100000];

int main() {
    std::cin >> n;

    for(int i = 1; i <= n; i++) {
        std::cin >> items[i];
    }

    std::vector<std::pair<int, int>> answer;

    for(int i = 0; i < 4 * n; i++) {
        std::pair<int, int> coords = shiftUp(items, n - i % n);

        if(coords.first != coords.second) {
            answer.push_back(coords);
        }
    }

    for(int i = 1; i <= n; i++) {
        std::cout << items[i] << " ";
    }

    std::cout << std::endl;

    std::cout << answer.size() << std::endl;

    for(int i = 0; i < answer.size(); i++) {
        std::cout << answer[i].first - 1 << " " << answer[i].second - 1 << std::endl;
    }
}

