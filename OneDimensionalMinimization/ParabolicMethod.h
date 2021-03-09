#pragma once
#include "IMethod.h"

class ParabolicMethod : public IMethod {
public:
	ParabolicMethod(IFunction* const, double, std::pair<double, double> const&);

	void set_tolerance(double) override;
	void set_section(std::pair<double, double> const&) override;

	double calculate() override;

	~ParabolicMethod();
private:
	IFunction* const function;   // функция
	std::pair<double, double> section;   // отрезок
	double tol;   // погрешность
};