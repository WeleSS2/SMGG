#pragma once

#include <iostream>
#include <filesystem>

#ifdef _WIN32
#define APPDATA_DIR() (std::getenv("APPDATA") ? std::getenv("APPDATA") : "")
#else
#define APPDATA_DIR() ""
#endif

#define LOG(format, ...) Logs::SaveLog(std::filesystem::path(__FILE__), __func__, __LINE__, format, ##__VA_ARGS__)

class Logs
{
public:
    /* 
     * Save log in a default path
     * It's consuming some resources beacouse i'm settings path for every call
     * Use unit tests for testing, use logs rerely when it's neccasary
     * Do not use them in loops!
     *
     *
     */
    static int SaveLog(const std::filesystem::path& file,
                        const char* function,
                         int line,
                          std::string log...);
    Logs();

private:
    /*
     * Clear logs in file
     * ERROR Return -1 and proced forward
     */
    static int ClearLogs(const std::filesystem::path& file);
};
