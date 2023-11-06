#include <iostream>
#include <purchase/ProductItem.hpp>
#include <purchase/ProductInfo.hpp>

int main() {
    purchase::ProductItem productItem;
    std::cin >> productItem;
    std::cout << productItem << std::endl;

    purchase::ProductInfo productInfo;
    std::cin >> productInfo;
    std::cout << productInfo << std::endl;
    return 0;
}
