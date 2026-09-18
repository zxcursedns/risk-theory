#include <iostream>
#include <string>
#include <windows.h>

double getScore(std::string text) {
    if(text == "дуже добре") return 10;
    if(text == "добре") return 8;
    if(text == "посередньо") return 6;
    if(text == "погано") return 3;
    if(text == "дуже погано") return 1;
    return 0;
}

void recommend(std::string home_rain, std::string home_sun, std::string forest_rain, std::string forest_sun, double p_rain) {
    double p_sun = 1 - p_rain;
    double w_home = p_rain * getScore(home_rain) + p_sun * getScore(home_sun);
    double w_forest = p_rain * getScore(forest_rain) + p_sun * getScore(forest_sun);
    std::cout << "W(вдома) = " << w_home << "\n";
    std::cout << "W(ліс) = " << w_forest << "\n";

    if (w_forest > w_home) std::cout << "рекомендація: їхати в ліс\n";
    else std::cout << "рекомендація: залишитись вдома\n";
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    recommend("добре", "погано", "дуже погано", "дуже добре", 0.47);
    recommend("добре", "погано", "дуже погано", "дуже добре", 0.75);
    return 0;
}