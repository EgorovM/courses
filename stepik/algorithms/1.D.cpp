#include <iostream>
#include <set>

int n, m;
int arr[100000];

int main() {
    std::set<std::pair<int, int>> maximums;

    std::cin >> n;

    for(int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    std::cin >> m;

    for(int i = 0; i < m; i++) {
        maximums.insert({-arr[i], i});
    }

    for(int i = m; i < n; i++) {
        std::cout << -maximums.begin()->first << " ";

        maximums.erase({-arr[i-m], i-m});
        maximums.insert({-arr[i], i});
    }

    std::cout << -maximums.begin()->first << std::endl;

    return 0;
}
