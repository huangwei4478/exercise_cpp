#include <iostream>

enum class Operation {
    Substract = 1,
    Add,
    Multiply,
    Divide
};

struct Calculator {
private:
    Operation operation;

public:
    Calculator(Operation operation): operation{operation} {}

    int calculate(int a, int b) {
        switch (operation) {
            case Operation::Add: {
                return a + b;
                break;
            }
            case Operation::Substract: {
                return a - b;
                break;
            }
            case Operation::Multiply: {
                return a * b;
                break;
            }
            case Operation::Divide: {
                return a / b;
                break;
            }
        }
    }
};


int main() {
    Calculator cal{Operation::Divide};
    std::cout << cal.calculate(8, 2) << std::endl;
    return 0;
}
