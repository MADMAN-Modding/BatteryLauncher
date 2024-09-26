#include <fstream>
#include <iostream>
#include <string>

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
    std::cout << getBatteryStatus();
    return 0;
}