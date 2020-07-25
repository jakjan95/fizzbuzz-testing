#include <string>

std::string fizzbuzz(const int& number) {
    if (number) {
        auto divideByThree = number % 3;
        auto divideByFive = number % 5;

        if (!divideByFive && !divideByThree) {
            return "fizzbuzz";
        } else if (!divideByFive) {
            return "buzz";
        } else if (!divideByThree) {
            return "fizz";
        }
    }
    return std::to_string(number);
}
