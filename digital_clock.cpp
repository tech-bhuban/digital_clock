

#include <iostream>
#include <ctime>
#include <unistd.h>
#include <string>

class DigitalClock {
private:
    bool is24Hour;
    bool showDate;
    
    std::string getCurrentTime() {
        time_t now = time(0);
        tm *ltm = localtime(&now);
        
        char buffer[80];
        if(is24Hour) {
            strftime(buffer, sizeof(buffer), "%H:%M:%S", ltm);
        } else {
            strftime(buffer, sizeof(buffer), "%I:%M:%S %p", ltm);
        }
        return std::string(buffer);
    }
    
    std::string getCurrentDate() {
        time_t now = time(0);
        tm *ltm = localtime(&now);
        char buffer[80];
        strftime(buffer, sizeof(buffer), "%A, %B %d, %Y", ltm);
        return std::string(buffer);
    }
    
public:
    DigitalClock(bool format24 = true, bool date = true) 
        : is24Hour(format24), showDate(date) {}
    
    void run() {
        while(true) {
            system("clear");
            std::cout << "╔════════════════════════╗\n";
            std::cout << "║                        ║\n";
            std::cout << "║     " << getCurrentTime() << "      ║\n";
            std::cout << "║                        ║\n";
            if(showDate) {
                std::cout << "║  " << getCurrentDate() << "  ║\n";
                std::cout << "║                        ║\n";
            }
            std::cout << "╚════════════════════════╝\n";
            std::cout << "\nPress Ctrl+C to exit\n";
            sleep(1);
        }
    }
};

int main() {
    DigitalClock clock(true, true);
    clock.run();
    return 0;
}