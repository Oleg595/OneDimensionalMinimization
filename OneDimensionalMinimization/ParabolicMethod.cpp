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
	return 0;
}