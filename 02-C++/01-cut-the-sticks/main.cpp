#include <iostream>
#include <numeric>
#include <vector>

static unsigned n;

void cut_the_sticks(std::vector<unsigned>& vec) {
    auto count = [&vec]() -> unsigned {
        unsigned result = 0;
        for (const auto i : vec) {
            result += i > 0 ? 1 : 0;
        }
        return result;
    };
    
    while (count() > 0) {
        unsigned sticks_cut = 0;
        unsigned min = INT32_MAX;
        for (size_t i = 0; i < vec.size(); ++i) {
            if (vec[i] < min && vec[i] != 0) {
                min = vec[i];
            }
        }
        
        for (size_t i = 0; i < vec.size(); ++i) {
            if (vec[i] > 0) {
                vec[i] -= min;
                ++sticks_cut;
            }
        }
        
        std::cout << sticks_cut << "\n";
    }
}

int main() {
    std::ios::sync_with_stdio(true);
    std::cin >> n;
    
    std::vector<unsigned> sticks(n);
    for (auto& i : sticks) {
        std::cin >> i;
    }
    
    cut_the_sticks(sticks);
    
    return 0;
}
