#include "roblox/classes/classes.hpp"
#include "utils/configs/configs.hpp"

#include <filesystem>
#include <iostream>
#include <thread>

#include "keyauth/auth.hpp"
#include <string>
#include "keyauth/utils.hpp"
#include "keyauth/skStr.h"

std::string tm_to_readable_time(tm ctx);
static std::time_t string_to_timet(std::string timestamp);
static std::tm timet_to_tm(time_t timestamp);
const std::string compilation_date = (std::string)skCrypt(__DATE__);
const std::string compilation_time = (std::string)skCrypt(__TIME__);

using namespace KeyAuth;

std::string name = skCrypt("").decrypt(); // Application Name
std::string ownerid88 = skCrypt("").decrypt(); // Owner ID
std::string secret = skCrypt("").decrypt(); // Application Secret
std::string version = skCrypt("").decrypt(); // Application Version
std::string url = skCrypt("https://keyauth.win/api/1.2/").decrypt(); // change if you're self-hosting
std::string path = skCrypt("").decrypt(); // (OPTIONAL) see tutorial here https://www.youtube.com/watch?v=I9rxt821gMk&t=1s


api KeyAuthApp(name, ownerid, secret, version, url, path);

int main()
{
    // Freeing memory to prevent memory leak or memory scraping
    name.clear(); ownerid.clear(); secret.clear(); version.clear(); url.clear();
    std::string consoleTitle = skCrypt("Loader - Built at:  ").decrypt() + compilation_date;
    SetConsoleTitleA(consoleTitle.c_str());
    KeyAuthApp.init();
    if (!KeyAuthApp.response.success)
    {
        std::cout << skCrypt("\n Status: ") << KeyAuthApp.response.message;
        Sleep(1500);
        exit(1);
    }

    {

        std::string key;
        std::cout << skCrypt("YourCheatName v69");
            std::cout << skCrypt("\nEnter Key: ");
            std::cin >> key;
            KeyAuthApp.license(key);
     

        if (!KeyAuthApp.response.success)
        {
            std::cout << skCrypt("\n Status: ") << KeyAuthApp.response.message;
            Sleep(1500);
            exit(1);
        }
    

    }

    system("cls");
    silence::roblox::init();

    return 0;
}

std::string tm_to_readable_time(tm ctx) {
    char buffer[80];

    strftime(buffer, sizeof(buffer), "%a %m/%d/%y %H:%M:%S %Z", &ctx);

    return std::string(buffer);
}

static std::time_t string_to_timet(std::string timestamp) {
    auto cv = strtol(timestamp.c_str(), NULL, 10); // long

    return (time_t)cv;
}

static std::tm timet_to_tm(time_t timestamp) {
    std::tm context;

    localtime_s(&context, &timestamp);

    return context;
}
