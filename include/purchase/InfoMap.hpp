#pragma once

#include <purchase/common.hpp>

#include <fstream>
#include <unordered_map>
#include <vector>

#include <purchase/ProductInfo.hpp>
#include <purchase/ProductItem.hpp>

namespace purchase {

class InfoMap {
public:
    InfoMap();

    ~InfoMap();

    void purchase(const ProductItem& item);

    void shipment(pid id, int amount);

private:
    std::vector<ProductItem> m_total {};
    std::unordered_map<pid, ProductInfo> m_product_map {};
};

} // namespace purchase
