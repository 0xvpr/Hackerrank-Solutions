#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int n{};
    int d{};
    int count{};
    
    std::cin >> n >> d;
    
    std::vector<int> v(n);
    for (auto& i : v) {
        std::cin >> i;
    }
    
    auto size = v.size();
    for (size_t i = 0; i < size; ++i) {
        std::vector<int>::iterator it;
        if ((it = std::find(v.begin()+i, v.end(), v[i] + d)) != v.end()) {
            if (std::find(it, v.end(), *it + d) != v.end()) {
                ++count;
            }
        }
    }
    
    std::cout << count;
    
    return 0;
}
