#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <sstream>
#include <limits>

const int ADD = 1;
const int REMOVE = 2;
const int PRINT_MAX = 3;
const int PRINT_MIN = 4;

std::vector <std::string> readInput() {
    int commandsCount = 0;
    std::cin >> commandsCount;
    std::cin.ignore();
    std::vector<std::string>commands(commandsCount);
    for (std::string& command : commands) {
        getline(std::cin, command);
    }

    return commands;
}

void addElement(std::stack<int>& stackNumbers, int numberToAdd) {
    stackNumbers.push(numberToAdd);
}

void removeElement(std::stack<int>& stackNumbers) {

    stackNumbers.pop();
}

void maxElement(const std::stack<int>& stackNumbers) {
    if (stackNumbers.empty()) {
        return;
    }
    std::stack<int> stackNumbersCopy = stackNumbers;
    int maxElement = std::numeric_limits<int>::min();
    while (!stackNumbersCopy.empty()) {
        const int currNumber = stackNumbersCopy.top();
        stackNumbersCopy.pop();
        if (currNumber > maxElement)
        {
            maxElement = currNumber;
        }
    }
    std::cout << maxElement << std::endl;
}

void minElement(const std::stack<int>& stackNumbers) {
    if (stackNumbers.empty()) {
        return;
    }
    std::stack<int> stackNumbersCopy = stackNumbers;
    int minElement = std::numeric_limits<int>::max();
    while (!stackNumbersCopy.empty()) {
        const int currNumber = stackNumbersCopy.top();
        stackNumbersCopy.pop();
        if (currNumber < minElement)
        {
            minElement = currNumber;
        }
    }
    std::cout << minElement << std::endl;
}

void proccesInput(const std::vector<std::string>& commands, std::stack<int>& stackNumbers) {
    int currCommandId = 0;
    for (const std::string& command : commands) {
        std::istringstream istr(command);
        istr >> currCommandId;


        switch (currCommandId)
        {
        case ADD: {
            int numberToAdd = 0;
            istr >> numberToAdd;
            addElement(stackNumbers, numberToAdd);
        }

                break;
        case REMOVE:
            removeElement(stackNumbers);
            break;
        case PRINT_MAX:
            maxElement(stackNumbers);
            break;
        case PRINT_MIN:
            minElement(stackNumbers);
            break;
        default:
            std::cerr << "Error" << std::endl;
            break;

        }

    }
}

void printStack(std::stack<int>& stackNumbers) {
    std::string answer;
    while (!stackNumbers.empty())
    {
        answer.append(std::to_string(stackNumbers.top())).append(", ");
        stackNumbers.pop();
    }
    answer.pop_back();
    answer.pop_back();
    std::cout << answer << std::endl;

}


int main()
{
    const std::vector<std::string> commands = readInput();
    std::stack<int> stackNumbers;
    proccesInput(commands, stackNumbers);
    printStack(stackNumbers);


    return 0;
}