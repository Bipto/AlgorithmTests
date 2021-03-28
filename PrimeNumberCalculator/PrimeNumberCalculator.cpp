#include <iostream>
#include <string>
#include <chrono>
int maxNumber;

bool checkNumber() {
    try {
        std::string input;
        std::cin >> input;

        for (int i = 0; i < input.length(); i++) {
            if (isdigit(input[i]) == false) {
                return false;
            }
        }
        maxNumber = std::stoi(input);
        return true;
    }

    catch (std::string error) {
        std::cout << "Not a valid number" << std::endl;
    }
}

int calculatePrimeNumbers() {
    int counter = 0;
    for (float x = 1; x <= maxNumber; x++) {
        if (floor(x / 2) == x / 2) {
            counter++;
        }
    }

    return counter;
}

int main()
{
    std::cout << "Prime Number Calculator\n";
    std::cout << "Enter the maximum number:";

    if (checkNumber()) {
        int count = 0;
        auto start = std::chrono::high_resolution_clock::now();
        count = calculatePrimeNumbers();
        auto stop = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double, std::milli> totalTime  = stop - start;

        std::cout << "Found " << count << " numbers divisible by two" << std::endl;
        std::cout << "Program took " << totalTime.count() << "  milliseconds (" << totalTime.count() / 1000 << " seconds)" << std::endl;
        return 0;
    }

    else {
        std::cout << "Not a valid number";
        return -1;
    }
}