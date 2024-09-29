#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

std::string getBatteryStatus() {
    std::ifstream file("/sys/class/power_supply/BAT1/status");
    std::string status;

    if (file.is_open()) {
        std::getline(file, status);
        file.close();
    }
    return status;
}

int main() {
    std::string status = getBatteryStatus();

    std::transform(status.begin(), status.end(), status.begin(), ::tolower);   

    std::cout << status << std::endl;
    // Basically if it can't find the word(s) in the string it will fail, npos just means null position (I think??)
    std::cout << status;
    if (status.find("discharging") != std::string::npos) {
        system("konsole > /dev/null&");
    } else {
        system("warp-terminal > /dev/null&");
    }
    return 0;
}