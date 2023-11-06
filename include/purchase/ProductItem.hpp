#pragma once

#include <purchase/common.hpp>

#include <chrono>
#include <iostream>

namespace purchase {

class ProductItem;

std::istream& operator>>(std::istream&, ProductItem&);
std::ostream& operator<<(std::ostream&, const ProductItem&);

class ProductItem {
    friend std::istream& operator>>(std::istream&, ProductItem&);
    friend std::ostream& operator<<(std::ostream&, const ProductItem&);

public:
    ProductItem() = default;

    ProductItem(pid pid, double price, int amount)
        : m_pid(pid)
        , m_price(price)
        , m_amount(amount)
    {
    }

private:
    pid m_pid {};

    double m_price {};
    int m_amount {};

    std::chrono::system_clock::time_point m_purchase_time;
    std::chrono::system_clock::time_point m_expire_time;
};

} // namespace purchase
