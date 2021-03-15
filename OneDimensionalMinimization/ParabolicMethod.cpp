#include "ParabolicMethod.h"

ParabolicMethod::ParabolicMethod(IFunction* const function, double tol, std::pair<double, double> const& section)
	: function{ function }, tol{ tol }, section{ section } {}

ParabolicMethod::~ParabolicMethod() {}

void ParabolicMethod::set_tolerance(double tol_) {
	tol = tol_;
}

void ParabolicMethod::set_section(std::pair<double, double> const& section_) {
	section = section_;
}

double ParabolicMethod::calculate() {
	double x1 = section.first;
	double x3 = section.second;

	if (x3 - x1 >= tol) {
		double f1 = function->at(x1);
		double f2 = function->at(x3);
		double x2 = (x1 + x3) / 2;
		double f3 = function->at(x2);

		while (x3 - x1 >= tol) {
			double a1 = (f2 - f1) / (x2 - x1);
			double a2 = 1.f / (x3 - x2) * ((f3 - f1) * (f2 - f1)) / ((x3 - x1) * (x2 - x1));

			double x = 1.f / 2 * (x1 + x2 - a1 / a2);
			double f = function->at(x);

			if (x2 < x) {
				if (f2 <= f) {
					x3 = x;
					f3 = f;
				}
				else {
					x1 = x2;
					f1 = f2;
					x2 = x;
					f2 = f;
				}
			}
			else {
				if (f <= f2) {
					x3 = x2;
					f3 = f2;
					x2 = x;
					f2 = f;
				}
				else {
					x1 = x;
					f1 = f;
				}
			}
		}
	}

	return (x1 + x3) / 2;
}