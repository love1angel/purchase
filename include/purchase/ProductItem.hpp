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

    [[nodiscard]] pid getPid() const { return m_pid; }
    [[nodiscard]] double getPrice() const { return m_price; }
    [[nodiscard]] int getAmount() const { return m_amount; }
    [[nodiscard]] const auto& getPurchaseTime() const { return m_purchase_time; }
    [[nodiscard]] const auto& getExpireTime() const { return m_expire_time; }

    bool isOutdated() const
    {
        using namespace std::chrono;
        const auto today = sys_days { std::chrono::floor<days>(system_clock::now()) };
        return m_expire_time <= today;
    }

    bool isWarn(int amount) const
    {
        using namespace std::chrono;
        const auto today = sys_days { std::chrono::floor<days>(system_clock::now()) };

        const auto delta = (today - m_expire_time).count();
        return delta > 0 && delta <= amount;
    }

private:
    pid m_pid {};

    double m_price {};
    int m_amount {};

    std::chrono::system_clock::time_point m_purchase_time;
    std::chrono::system_clock::time_point m_expire_time;
};

} // namespace purchase
