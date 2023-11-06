#include <purchase/InfoMap.hpp>

int main()
{
    purchase::InfoMap map;
    return 0;
}

// #include <iostream>
// #include <fstream>
// #include <chrono>
// #include <iomanip>
// #include <ctime>
// #include <sstream>

// int main() {
//     // 获取当前时间点
//     //    const auto now = std::chrono::system_clock::now();
// //    std::cout << std::chrono::year_month_day{std::chrono::time_point_cast<std::chrono::days>(now)}.year().operator int();

//    std::chrono::year_month_day ymd1 = std::chrono::floor<std::chrono::days>(std::chrono::system_clock::now());
//    std::cout << ymd1.year().operator int() << std::endl;
//    std::cout << ymd1.month().operator unsigned int() << std::endl;
//    std::cout << ymd1.day().operator unsigned int() << std::endl;

//    std::string tfmt = std::format("{}", std::chrono::system_clock::now());
//    std::cout << tfmt << std::endl;

//    {
//         std::tm parsedTime = {};
//     std::istringstream timeStream(tfmt);
//     timeStream >> std::get_time(&parsedTime, "%Y-%m-%d %H:%M:%S");
//     std::time_t parsedTime_t = std::mktime(&parsedTime);
//     auto parsedTimePoint = std::chrono::system_clock::from_time_t(parsedTime_t);
//        std::chrono::year_month_day ymd2 = std::chrono::floor<std::chrono::days>(parsedTimePoint);
//    std::cout << "xp" <<  ymd2.year() << std::endl;
//    std::cout << ymd2.month() << std::endl;
//    std::cout << ymd2.day() << std::endl;
//    }

//     auto currentTime = std::chrono::system_clock::now();

//     // 将时间点转换为字符串
//     std::time_t currentTime_t = std::chrono::system_clock::to_time_t(currentTime);
//     std::stringstream ss;
//     ss << std::put_time(std::localtime(&currentTime_t), "%Y-%m-%d %H:%M:%S");

//     std::string timeString = ss.str();

//     // 将时间字符串写入文件
//     std::ofstream file("time_data.txt");
//     if (!file.is_open()) {
//         std::cerr << "Failed to open the file." << std::endl;
//         return 1;
//     }

//     file << timeString;
//     file.close();

//     // 从文件中读取时间字符串并转换为 time_point
//     std::ifstream inFile("time_data.txt");
//     if (!inFile.is_open()) {
//         std::cerr << "Failed to open the file for reading." << std::endl;
//         return 1;
//     }

//     std::string readTimeString;
//     inFile >> readTimeString;
//     std::cout << readTimeString << std::endl;
//     inFile.close();

//     // 将读取的时间字符串转换为 time_point
//     std::tm readTm = {};
//     std::istringstream readSS(readTimeString);
//     readSS >> std::get_time(&readTm, "%Y-%m-%d %H:%M:%S");

//     std::time_t readTime_t = std::mktime(&readTm);
//     auto readTimePoint = std::chrono::system_clock::from_time_t(readTime_t);

//        std::chrono::year_month_day ymd = std::chrono::floor<std::chrono::days>(readTimePoint);
//    std::cout << ymd.year() << std::endl;
//    std::cout << ymd.month()<< std::endl;
//    std::cout << ymd.day() << std::endl;

//     // 输出读取的 time_point
//     std::time_t t = std::chrono::system_clock::to_time_t(readTimePoint);
//     std::cout << "Time point read from file: " << std::ctime(&t);

//     return 0;
// }




// // #include <chrono>
// // #include <iostream>

// // int main()
// // {
// //    using namespace std::chrono;
// //    const auto today = sys_days{std::chrono::floor<days>(system_clock::now())};
// //    for (const year_month_day ymd : {{November/15/2020}, {November/15/2120}, today})
// //    {
// //        std::cout << ymd;
// //        const auto delta = (sys_days{ymd} - today).count();
// //        (delta < 0) ? std::cout << " was " << -delta << " day(s) ago\n" :
// //            (delta > 0) ? std::cout << " is " << delta << " day(s) from now\n"
// //                        : std::cout << " is today!\n";
// //    }
// // }


// //#include <iostream>
// //#include <purchase/InfoMap.hpp>
// //#include <chrono>
// //#include <format>
// //
// //int main()
// //{
// ////    const auto now = std::chrono::system_clock::now();
// ////    std::cout << std::chrono::year_month_day{std::chrono::time_point_cast<std::chrono::days>(now)}.year().operator int();
// //
// //    std::chrono::year_month_day ymd = std::chrono::floor<std::chrono::days>(std::chrono::system_clock::now());
// //    std::cout << ymd.year().operator int() << std::endl;
// //    std::cout << ymd.month().operator unsigned int() << std::endl;
// //    std::cout << ymd.day().operator unsigned int() << std::endl;
// ////    std::chrono::sys_days
// ////    std::cout <<
// //    return 0;
// //}
