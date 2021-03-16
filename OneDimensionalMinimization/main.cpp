#include <cmath>
#include <iostream>
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
	IFunction* function = IFunction::create_function([](double x) { return x * std::sin(x) + 2 * cos(x); });
	IFunction* func= IFunction::create_function([](double x) { return x + 1.0 / (x * x); });
	IMethod* parabolic_method = IMethod::create_method(IMethod::METHOD::PARABOLIC, function, 0.02, { -5, -4 });

	double x_min = parabolic_method->calculate();
	std::cout << "Number of function calls: " << function->get_counter() << std::endl;
	std::cout << "Min: " << x_min << ", with value: " << function->at(x_min) << std::endl;

	std::cout << "/******************************************************/" << std::endl;

	IMethod* dichotomy_function = IMethod::create_method(IMethod::METHOD::DICHOTOMY, function, 0.02, { -5, -4 });
	function->update_counter();
	x_min = dichotomy_function->calculate();
	std::cout << "Number of function calls: " << function->get_counter() << std::endl;
	std::cout << "Min: " << x_min << ", with value: " << function->at(x_min) << std::endl;

	clear(parabolic_method, dichotomy_function, function, func);

	_CrtDumpMemoryLeaks();
	return 0;
}