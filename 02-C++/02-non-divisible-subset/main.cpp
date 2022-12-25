#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

static unsigned n;
static unsigned k;

unsigned get_non_divisible_subset(std::vector<unsigned>& v) {
    size_t size = v.size();

    std::vector<unsigned> result(0);
    for (unsigned i = 0; i < size-1; ++i) {
        for (unsigned j = i + 1; j < size; ++j) {
            if (v[i] + v[j] % k == 0) {
                continue;
            }
        }

        result.push_back(v[i]);
    }

    return result.size();
}

int main() {
    std::ios::sync_with_stdio(true);
    std::cin >> n >> k;

    std::vector<unsigned> v(n);
    for (auto& i : v) {
        std::cin >> i;
    }

    std::cout << get_non_divisible_subset(v);

    return 0;
}
