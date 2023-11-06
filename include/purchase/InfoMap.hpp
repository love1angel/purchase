#pragma once

#include <purchase/common.hpp>

#include <unordered_map>
#include <vector>

#include <purchase/ProductItem.hpp>

namespace purchase {

class InfoMap {
public:
    InfoMap();

    ~InfoMap();

    void purchase(const ProductItem& item);

    void shipment(pid id, int amount);

private:
    std::unordered_map<pid, std::vector<ProductItem>> m_map {};
};

} // namespace purchase
