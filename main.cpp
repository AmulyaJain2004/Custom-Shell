#include <iostream>
#include <string>

int main() {
    std::cout << std::unitbuf;
    std::cerr << std::unitbuf;

    while (true) {
        std::cout << "$ ";
        std::string input;
        std::getline(std::cin, input);
        if (input == "exit") {
            break;
        }
        if (input.substr(0, 5) == "echo ") {
            std::cout << input.substr(5) << std::endl;
        }
        else if (input.substr(0, 5) == "type ") {
            if (input.substr(5) == "echo") {
                std::cout << "echo is a shell builtin" << std::endl;
            }
            else if (input.substr(5) == "type") {
                std::cout << "type is a shell builtin" << std::endl;
            }
            else if (input.substr(5) == "exit") {
                std::cout << "exit is a shell builtin" << std::endl;
            }
            else {
                std::cout << input.substr(5) << ": not found" << std::endl;
            }
        }
        else {
            std::cout << input << ": command not found" << std::endl;
        }
    }

    return 0;
}