#include <iostream>

double promptForDouble()
{
	std::cout << "Please enter a number: ";
	double num{};
	std::cin >> num;
	return num;
}

char promptForOperation()
{
	std::cout << "Please enter a math operation symbol, +, -, *, or /: ";
	char operation{};
	std::cin >> operation;
	return operation;
}

int main()
{
	double x = promptForDouble();
	double y = promptForDouble();
	char operation = promptForOperation();

	double answer{};
	if (operation == '+')
	{
		answer = x + y;
	}
	else if (operation == '-')
	{
		answer = x - y;
	}
	else if (operation == '*')
	{
		answer = x * y;
	}
	else if (operation == '/')
	{
		answer = x / y;
	}
	else
	{
		return 1;
	}
	std::cout << x << " " << operation << " " << y << " = " << answer << '\n';

	return 0;
}