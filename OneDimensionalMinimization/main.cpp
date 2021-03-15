#include <cmath>
#include <iostream>
#include "IMethod.h"

int main() {
	IFunction* function = IFunction::create_function([](double x) { return x * std::sin(x) + 2 * cos(x); });
	IMethod* parabolic_method = IMethod::create_method(IMethod::METHOD::PARABOLIC, function, 0.02, { -5, -4 });

	double  x_min = parabolic_method->calculate();
	std::cout << "Number of function calls: " << function->get_counter() << std::endl;
	std::cout << "Min: " << x_min << ", with value: " << function->at(x_min) << std::endl;

	delete parabolic_method;
	delete function;
	return 0;
}