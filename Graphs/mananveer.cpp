#include <iostream>
#include <vector>

std::vector<std::vector<int>> map;
bool found = false;

void dfs(int current, int parent, int key) {
    if (found) {
        return;
    }

    if (current == key) {
        found = true;
        return;
    }

    for (auto &child : map[parent]) {
        if (child == parent) {
            continue;
        }
        dfs(child, current, key);
    }
}

int main() {
    int size = 0;
    std::cin >> size;
    
    for (int i = 0; i < size; i++) {
        int child1 = 0, child2 = 0;
        std::cin >> child1 >> child2;
        map.push_back(std::vector<int>({child1, child2, i}));
    }

    int key = 0;
    std::cin >> key;

    dfs(0, 0, key);
}