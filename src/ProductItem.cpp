#include <purchase/ProductItem.hpp>

#include <iomanip>
#include <sstream>

namespace purchase {

std::istream& operator>>(std::istream& in, ProductItem& p)
{
    std::string purchase_time;
    std::string expire_time;

    // read time and other thing
    {
        std::string purchase_time_1;
        std::string expire_time_1;
        in >> p.m_pid >> p.m_price >> p.m_amount >> purchase_time >> purchase_time_1 >> expire_time >> expire_time_1;
        purchase_time += " ";
        purchase_time += purchase_time_1;
        expire_time += " ";
        expire_time += expire_time_1;
    }

    auto str2time = [](const std::string& time) {
        std::tm buffer {};
        std::istringstream iss(time);
        iss >> std::get_time(&buffer, "%Y-%m-%d %H:%M:%S");
        return std::chrono::system_clock::from_time_t(std::mktime(&buffer));
    };

    if (in) {
        p.m_purchase_time = str2time(purchase_time);
        p.m_expire_time = str2time(expire_time);
    } else {
        p = ProductItem();
    }
    return in;
}

std::ostream& operator<<(std::ostream& o, const ProductItem& p)
{
    std::time_t purchase_time = std::chrono::system_clock::to_time_t(p.m_purchase_time);
    std::time_t expire_time = std::chrono::system_clock::to_time_t(p.m_expire_time);
    return o << "ProductItem: { id: " << p.m_pid
             << ", price: " << p.m_price
             << ", amount: " << p.m_amount
             << ", purchase time: " << std::ctime(&purchase_time)
             << ", expire time: " << std::ctime(&expire_time)
             << " }." << std::endl;
}

} // namespace purchase
