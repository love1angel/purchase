#include <purchase/InfoMap.hpp>

#include "FileHelper.hpp"
#include <iostream>

namespace purchase {

InfoMap::InfoMap()
{
    FileHelper info_fd = FileHelper("/Users/helianthusxie/project/purchase/resource/product_info.txt");
    std::string line;
    while (std::getline(info_fd.getFd(), line)) {
        std::cout << line << std::endl;
    }

    FileHelper product_fd = FileHelper("/Users/helianthusxie/project/purchase/resource/product_item.txt");
    while (std::getline(product_fd.getFd(), line)) {
        std::cout << line << std::endl;
    }
}

InfoMap::~InfoMap()
{
}

void InfoMap::purchase(const purchase::ProductItem& item)
{
    // find earliest

    // find maybe expired
}

void InfoMap::shipment(purchase::pid id, int amount)
{
}

} // namespace purchase
