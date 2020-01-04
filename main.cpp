#include "type_pack.hpp"
#include <iostream>

int main() {
    auto pack = type_pack<int, char, int, bool>{};
    auto int_count{0};
    foreach(pack, [&](auto i, auto v){
        using v_type = typename decltype(v)::type;
        int_count += std::is_same_v<v_type, int>;
    });
    std::cout << int_count << std::endl;
}