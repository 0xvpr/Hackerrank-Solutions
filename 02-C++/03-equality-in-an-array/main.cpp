#include <iostream>
#include <vector>
#include <map>

static unsigned n;

unsigned min_deletions(const std::vector<unsigned>& v) {
    unsigned total = 0;

    std::map<unsigned, unsigned> m;
    for (const auto i : v) {
        m[i]++;
    }

    unsigned max = 0;
    for (auto& it : m) {
        if (m[max] < it.second) {
            max = it.first;
        }
    }

    for (const auto& [key, val] : m) {
        total += (key != max ? val : 0);
    }

    return total;
}

int main() {
    std::ios::sync_with_stdio(true);
    std::cin >> n;

    std::vector<unsigned> v(n);
    for (auto& i : v) {
        std::cin >> i;
    }

    std::cout << min_deletions(v);

    return 0;
}
