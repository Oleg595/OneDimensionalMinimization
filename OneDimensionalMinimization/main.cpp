#include <cmath>
#include <iostream>
#include <vector>
#include "IMethod.h"

#define __CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW

template <typename pT>
void clear(pT* ptr) {
	delete ptr;
}

template <typename pHead, typename... pArgs>
void clear(pHead* ptr, pArgs*... pargs) {
	delete ptr;
	clear(pargs...);
}

int main() {
	auto function = IFunction::create_function([](double x) { return x * std::sin(x) + 2 * cos(x); });
	auto func= IFunction::create_function([](double x) { return x + 1.0 / (x * x); });
	auto parabolic_method = IMethod::create_method(IMethod::METHOD::PARABOLIC, function, 0.02, { -5, -4 });

	/*double x_min = parabolic_method->calculate();
	std::cout << "Number of function calls: " << function->get_counter() << std::endl;
	std::cout << "Min: " << x_min << ", with value: " << function->at(x_min) << std::endl;*/

	auto dichotomy_method = IMethod::create_method(IMethod::METHOD::DICHOTOMY, function, 0.1, { -5, -4 });
	auto fibonaccy_method = IMethod::create_method(IMethod::METHOD::FIBONACCY, function, 0.1, { -5, -4 });
	std::cout << fibonaccy_method->calculate() << std::endl;
	std::vector<double> tols = { 0.1, 0.02, 0.01, 0.001 };
	for (auto tol : tols) {
		function->update_counter();
		parabolic_method->set_tolerance(tol);
		double x_min = parabolic_method->calculate();

		std::cout << "Tolerance: " << tol << "; Number of function calls: " << function->get_counter() << std::endl;
		std::cout << "Min: " << x_min << ", with value: " << function->at(x_min) << std::endl;
	}

	clear(parabolic_method, dichotomy_method, function, func);

	_CrtDumpMemoryLeaks();
	return 0;
}