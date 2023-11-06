#include <purchase/ProductItem.hpp>

#include <iomanip>
#include <sstream>

namespace purchase {

std::istream& operator>>(std::istream& in, ProductItem& p)
{
    std::string purchase_time;
    std::string expire_time;

    {
        std::string t1, t2, t3, t4;
        
        if (not (in >> p.m_pid >> p.m_price >> p.m_amount >> t1 >> t2 >> t3 >> t4)) {
            return in;
        }
        purchase_time += t1 += " ";
        purchase_time += t2;
        expire_time += t3 += " ";
        expire_time += t4;
    }

    {
        std::tm parsedTime = {};
        std::istringstream timeStream(purchase_time);
        timeStream >> std::get_time(&parsedTime, "%Y-%m-%d %H:%M:%S");
        std::time_t parsedTime_t = std::mktime(&parsedTime);
        auto parsedTimePoint = std::chrono::system_clock::from_time_t(parsedTime_t);
        p.m_purchase_time = parsedTimePoint;
        // std::chrono::year_month_day ymd2 = std::chrono::floor<std::chrono::days>(parsedTimePoint);
        // std::cout << "xp" << ymd2.year() << std::endl;
        // std::cout << ymd2.month() << std::endl;
        // std::cout << ymd2.day() << std::endl;
    }

    {
        std::tm parsedTime = {};
        std::istringstream timeStream(expire_time);
        timeStream >> std::get_time(&parsedTime, "%Y-%m-%d %H:%M:%S");
        std::time_t parsedTime_t = std::mktime(&parsedTime);
        auto parsedTimePoint = std::chrono::system_clock::from_time_t(parsedTime_t);
        p.m_expire_time = parsedTimePoint;
        // std::chrono::year_month_day ymd2 = std::chrono::floor<std::chrono::days>(parsedTimePoint);
        // std::cout << "xp" << ymd2.year() << std::endl;
        // std::cout << ymd2.month() << std::endl;
        // std::cout << ymd2.day() << std::endl;
    }
    return in;
}

std::ostream& operator<<(std::ostream& o, const ProductItem& p)
{
    return o << "ProductItem: { id: " << p.m_pid
             << ", price: " << p.m_price
             << ", amount: " << p.m_amount
             << ", purchase time: " << p.m_purchase_time
             << ", expire time: " << p.m_expire_time
             << " }." << std::endl;
}

} // namespace purchase
