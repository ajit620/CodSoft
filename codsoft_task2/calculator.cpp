#include <iostream>

void displayMenu() {
    std::cout << "Select an operation:" << std::endl;
    std::cout << "1. Addition (+)" << std::endl;
    std::cout << "2. Subtraction (-)" << std::endl;
    std::cout << "3. Multiplication (*)" << std::endl;
    std::cout << "4. Division (/)" << std::endl;
    std::cout << "Enter your choice (1/2/3/4): ";
}

int main() {
    double num1, num2;
    int choice;

    std::cout << "Enter the first number: ";
    std::cin >> num1;
    std::cout << "Enter the second number: ";
    std::cin >> num2;

    displayMenu();
    std::cin >> choice;

    switch (choice) {
        case 1:
            std::cout << "Result: " << num1 + num2 << std::endl;
            break;
        case 2:
            std::cout << "Result: " << num1 - num2 << std::endl;
            break;
        case 3:
            std::cout << "Result: " << num1 * num2 << std::endl;
            break;
        case 4:
            if (num2 != 0) {
                std::cout << "Result: " << num1 / num2 << std::endl;
            } else {
                std::cout << "Error: Division by zero is not allowed." << std::endl;
            }
            break;
        default:
            std::cout << "Invalid choice. Please select a valid operation." << std::endl;
            break;
    }

    return 0;
}
