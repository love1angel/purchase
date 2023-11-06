#include "FileHelper.hpp"

namespace purchase {

FileHelper::FileHelper(std::string_view path)
    : m_file(path.data(), std::ios::in | std::ios::out)
{
    if (!m_file.is_open()) {
        // Handle error opening file
        throw std::runtime_error("Failed to open file");
    }
}

} // namespace purchase
