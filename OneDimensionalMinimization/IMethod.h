#pragma once
#include "IFunction.h"

// Класс метода
class IMethod{
public:
	enum METHOD {
		DICHOTOMY,
		PARABOLIC
	};

	static IMethod* create_method(METHOD, IFunction* const, double tol = 0, std::pair<double, double> const& section = {0, 0});   // Создаёт метод

	virtual void set_tolerance(double) = 0;   // Задаёт погрешность
	virtual void set_section(std::pair<double, double> const&) = 0;   // Задаёт отрезок, на котором ищём минимум

	virtual double calculate() = 0;   // сам метод

	virtual ~IMethod() = 0;
private:
	IMethod(IMethod const&) = delete;
	IMethod& operator=(IMethod const&) = delete;
protected:
	IMethod() = default;
};