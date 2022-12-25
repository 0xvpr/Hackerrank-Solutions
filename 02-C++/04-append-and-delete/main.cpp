#include <iostream>
#include <string>
#include <vector>
#include <map>

int main() {
    std::ios::sync_with_stdio(true);

    std::string a{}, b{};
    int limit = 0;
    std::cin >> a >> b >> limit;

    if (a == b) {
        std::cout << "Yes" << "\n";
        return 0;
    }

    int diff = abs(static_cast<int>(a.length() - b.length()));
    if (diff > limit) {
        std::cout << "No" << "\n";
        return 0;
    }

    limit -= diff;
    auto min = std::min(a.length(), b.length());
    for (unsigned i = 0; i < min; ++i) {
        if (a[i] != b[i]) {
            limit -= 2;
        }
    }

    std::cout << (limit >= 0 ? "No" : "Yes" ) << "\n";

    return 0;
}
