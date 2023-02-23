#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Function to evaluate a given expression
float evaluateExpression(string expression) {
    // Stack to hold operators and operands
    stack<float> numbers;
    stack<char> operators;

    for (int i = 0; i < expression.length(); i++) {
        if (expression[i] == ' ') {
            continue;
        }
        else if (isdigit(expression[i])) {
            float num = 0;
            while (i < expression.length() && isdigit(expression[i])) {
                num = num * 10 + (expression[i] - '0');
                i++;
            }
            i--;
            numbers.push(num);
        }
        else if (expression[i] == '(') {
            operators.push(expression[i]);
        }
        else if (expression[i] == ')') {
            while (!operators.empty() && operators.top() != '(') {
                float num2 = numbers.top();
                numbers.pop();
                float num1 = numbers.top();
                numbers.pop();
                char op = operators.top();
                operators.pop();
                if (op == '+') {
                    numbers.push(num1 + num2);
                }
                else if (op == '-') {
                    numbers.push(num1 - num2);
                }
                else if (op == '*') {
                    numbers.push(num1 * num2);
                }
                else if (op == '/') {
                    numbers.push(num1 / num2);
                }
            }
            if (!operators.empty()) {
                operators.pop();
            }
        }
        else {
            while (!operators.empty() && (operators.top() == '*' || operators.top() == '/') && operators.top() != '(') {
                float num2 = numbers.top();
                numbers.pop();
                float num1 = numbers.top();
                numbers.pop();
                char op = operators.top();
                operators.pop();
                if (op == '+') {
                    numbers.push(num1 + num2);
                }
                else if (op == '-') {
                    numbers.push(num1 - num2);
                }
                else if (op == '*') {
                    numbers.push(num1 * num2);
                }
                else if (op == '/') {
                    numbers.push(num1 / num2);
                }
            }
            operators.push(expression[i]);
        }
    }

    while (!operators.empty()) {
        float num2 = numbers.top();
        numbers.pop();
        float num1 = numbers.top();
        numbers.pop();
        char op = operators.top();
        operators.pop();
        if (op == '+') {
            numbers.push(num1 + num2);
        }
        else if (op == '-') {
            numbers.push(num1 - num2);
        }
        else if (op == '*') {
            numbers.push(num1 * num2);
        }
        else if (op == '/') {
            numbers.push(num1 / num2);
        }
    }

    return numbers.top();
}

int main() {
    string expression;
    cout << "Enter expression: ";
    getline(cin, expression);

    float result = evaluateExpression(expression);

    cout << "Result: " << result << endl;

    return 0;
}
