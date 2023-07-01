#include "logs.h"

#include <fstream>
#include <cstdarg>
#include <stdio.h>
#include <cstdlib>

#ifdef _WIN32
#define APPDATA_DIR() (std::getenv("APPDATA") ? std::getenv("APPDATA") : "")
#else
#define APPDATA_DIR() ""
#endif

Logs::Logs()
{

}

int Logs::SaveLog(const std::filesystem::path& file, 
                   const char* function, 
                    int line,
                     std::string log...)
{
    namespace sf = std::filesystem;

    va_list args;
    va_start(args, log);

    char buffer[1024];
    vsnprintf(buffer, sizeof(buffer), log.c_str(), args);

    va_end(args);

    #ifdef _WIN32
        if(APPDATA_DIR() == "")
        {
            return 0;
        }

        std::string defPath = std::string(APPDATA_DIR()) + "/CapibaraStudio/SMGG/Logs";
    #elif __unix__
        std::string defPath = "/var/log/CapibaraStudio/Logs";
    #endif

    if(!sf::exists(sf::path(defPath)))
    {
        sf::create_directories(defPath);
    }

    defPath += "/" + file.filename().generic_string();
    defPath.replace(defPath.length() - 3, 3, "log");

    std::fstream out(defPath, std::ios_base::out | std::ios_base::app);

    if(out.is_open())
    {
        out << "File: "
            << file
            << std::endl
            << "Function: "
            << function
            << " | Line: "
            << line
            << " | Log: "
            << buffer
            << std::endl
            << "-------------------------------------------------------"
            << std::endl;
    }

    out.close();

    return 0;
}

