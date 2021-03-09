#include "IMethod.h"
#include "ParabolicMethod.h"

IMethod* IMethod::create_method(METHOD method, IFunction* const function, double tol, std::pair<double, double> const& section) {
	if (section.first > section.second) {
		return nullptr;
	}
	switch (method) {
	case METHOD::PARABOLIC:
		return new ParabolicMethod(function, tol, section);
	case METHOD::DICHOTOMY:
		return nullptr;
	}
	return nullptr;
}

IMethod::~IMethod() {}