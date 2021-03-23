#pragma once
#include"IMethod.h"

class FibonacciMethod : public IMethod {
public:
	FibonacciMethod(IFunction* const, double, std::pair<double, double> const&);

	void set_tolerance(double) override;   // Задаёт погрешность
	void set_section(std::pair<double, double> const&) override;   // Задаёт отрезок, на котором ищём минимум

	double calculate() override;

	~FibonacciMethod();
private:
	IFunction* const function;
	std::pair<double, double> section;
	double tol;
};