#include <iostream>
#include <string>
#include <chrono>
#include <list>
#include <vector>

float maxNumber;
int count = 0;

bool validateNumber() {
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

bool isPrime(int n) {

    if (n == 0 || n == 1)
        return false;
    else {
        for (int i = 2; i <= n / 2; i++) {
            if (n % i == 0) {
                return false;
            }
        }
    }

    return true;
}

void calculatePrimeNumbers() {
    float i, n;

    for (i = 0; i <= maxNumber; i++) {
        if (isPrime(i)) {
            std::cout << i << " is a prime number" << std::endl;
            count++;
        }
    }

}

int primeNumberMachine() {
    std::cout << "Enter the maximum number:";

    if (validateNumber()) {
        auto start = std::chrono::high_resolution_clock::now();
        calculatePrimeNumbers();
        auto stop = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double, std::milli> totalTime = stop - start;

        if (count == 0) {
            std::cout << "Found no prime numbers" << std::endl;
        }

        else if (count == 1) {
            std::cout << "Found one prime number" << std::endl;
        }

        else {
            std::cout << "Found " << count << " prime numbers" << std::endl;
        }

        std::cout << "Program took " << totalTime.count() << "  milliseconds (" << totalTime.count() / 1000 << " seconds)" << std::endl;
        return 0;
    }

    else {
        std::cout << "Not a valid number";
        return -1;
    }
}

void calculateFibonacciNumbers() {
    std::vector<unsigned long long int> numbers;
    unsigned long long int i;

    for (i = 0; i <= maxNumber; i++) {
        if (i == 0) {
            numbers.push_back(0);
        }
        else if (i == 1) {
            numbers.push_back(1);
        }
        else {
            numbers.push_back(numbers[i-1] + numbers[i-2]);            
        }
        std::cout << numbers[i] << std::endl;
    }
}

int fibonacciMachine() {
    std::cout << "Enter the maximum number:";

    if (validateNumber()) {
        auto start = std::chrono::high_resolution_clock::now();
        calculateFibonacciNumbers();
        auto stop = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double, std::milli> totalTime = stop - start;
        std::cout << "Program took " << totalTime.count() << "  milliseconds (" << totalTime.count() / 1000 << " seconds)" << std::endl;
        return 0;
    }

    else {
        std::cout << "Not a valid number";
        return -1;
    }    
}

int main()
{
    int choice;
    std::cout << "Algorithms in C++!\n";
    std::cout << "Press 1 to calculate prime numbers or 2 to calculate fibonacci numbers:";

    std::cin >> choice;

    if (choice == 1) {
        return primeNumberMachine();
    }

    else if (choice == 2) {
        return fibonacciMachine();
    }

    else {
        std::cout << "Not a valid choice!" << std::endl;
        return 0;
    }

}