#pragma once

#include <purchase/common.hpp>

#include <iostream>
#include <string>

namespace purchase {

class ProductInfo;

std::istream& operator>>(std::istream&, ProductInfo&);
std::ostream& operator<<(std::ostream&, const ProductInfo&);

class ProductInfo {
    friend std::istream& operator>>(std::istream&, ProductInfo&);
    friend std::ostream& operator<<(std::ostream&, const ProductInfo&);

private:
    pid m_pid {};
    std::string m_name;
    std::string m_producer;
};

std::istream& operator>>(std::istream& in, ProductInfo& p)
{
    return in >> p.m_pid >> p.m_name >> p.m_producer;
}

std::ostream&
operator<<(std::ostream& o, const ProductInfo& p)
{
    return o << "ProductInfo: { id: " << p.m_pid
             << ", name: " << p.m_name
             << ", producer: " << p.m_producer
             << " }." << std::endl;
}

} // namespace purchase
