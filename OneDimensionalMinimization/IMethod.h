#pragma once
#include "IFunction.h"

// ����� ������
class IMethod{
public:
	enum METHOD {
		DICHOTOMY,
		PARABOLIC
	};

	static IMethod* create_method(METHOD, IFunction* const, double tol = 0, std::pair<double, double> const& section = {0, 0});   // ������ �����

	virtual void set_tolerance(double) = 0;   // ����� �����������
	virtual void set_section(std::pair<double, double> const&) = 0;   // ����� �������, �� ������� ���� �������

	virtual double calculate() = 0;   // ��� �����

	virtual ~IMethod() = 0;
private:
	IMethod(IMethod const&) = delete;
	IMethod& operator=(IMethod const&) = delete;
protected:
	IMethod() = default;
};