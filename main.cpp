#include "src/genpass.hpp"

int main(){
    auto g = std::make_unique<GenPass>();
    std::cout << g->gen_pass(32) << '\n';

    return 0;
}
