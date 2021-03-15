#include <cmath>
#include <iostream>
#include "IMethod.h"

int main() {
	IFunction* function = IFunction::create_function([](double x) { return x * std::sin(x) + 2 * cos(x); });
	IMethod* parabolic_method = IMethod::create_method(IMethod::METHOD::PARABOLIC, function, 0.02, { -5, -4 });

	IMethod* dichotomy_method = IMethod::create_method(IMethod::METHOD::DICHOTOMY, function, 0.02, { -5, -4 });

	std::cout << parabolic_method->calculate() << std::endl;
	std::cout << dichotomy_method->calculate() << std::endl;

	delete dichotomy_method;
	delete parabolic_method;
	delete function;
	return 0;
}