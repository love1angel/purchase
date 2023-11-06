#include <purchase/InfoMap.hpp>

#include <iostream>

#define INFO_PATH "/Users/helianthusxie/project/purchase/resource/product_info.txt"
#define ITEM_PATH "/Users/helianthusxie/project/purchase/resource/product_item.txt"

#include <iostream>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>

namespace purchase {

InfoMap::InfoMap()
{
    std::ifstream product_info_fd(INFO_PATH);
    if (!product_info_fd.is_open()) {
        std::cerr << "Failed to open file: ";
    }

    pid id;
    ProductInfo info;
    while (product_info_fd >> id >> info) {
        if (0 == m_product_map.count(id)) {
            m_product_map[id] = info;
        } else {
            std::cerr << "info pid not only occurs once, some error happens" << std::endl;
        }
    }
    //    for (auto item : m_product_map) {
    //        std::cout << std::get<0>(item) << std::get<1>(item) << std::endl;
    //    }

    std::ifstream product_item_fd(ITEM_PATH);
    if (!product_item_fd.is_open()) {
        std::cerr << "Failed to open file: ";
    }

    std::string line;
    while (std::getline(product_item_fd, line)) {
        std::stringstream ss{line};
        ProductItem item;
        ss >> item;
        m_total.push_back(item);
    }

    // for (auto each : m_total) {
    //     std::cout << each << std::endl;
    // }
}

InfoMap::~InfoMap() noexcept
{
       std::ofstream info_file(INFO_PATH);
    
       for (const auto& item : m_product_map) {
           info_file << std::get<0>(item) << " "
                     << std::get<1>(item).getName() << " "
                     << std::get<1>(item).getProducer() << std::endl;
       }
       info_file.close();
    
       std::ofstream item_file(ITEM_PATH);
    
       for (const auto& item : m_total) {
           item_file << item.getPid() << " "
                     << item.getPrice() << " "
                     << item.getAmount() << " "
                     << std::format("{}", item.getPurchaseTime()) << " "
                     << std::format("{}", item.getExpireTime()) << " "
                     << std::endl;
       }
       item_file.close();
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
