#pragma once

#include <fstream>
#include <string_view>

namespace purchase {

class FileHelper {
public:
    FileHelper(FileHelper const&) = delete;
    FileHelper& operator=(FileHelper const&) = delete;

    explicit FileHelper(std::string_view path);

    FileHelper(FileHelper&& rhs) noexcept
        : m_file(std::move(rhs.m_file))
    {
    }

    ~FileHelper() noexcept
    {
        m_file.close();
    }

    auto& getFd()
    {
        return m_file;
    }

private:
    std::ifstream m_file {};
};

} // namespace purchase
