#pragma once
#include <functional>

// Класс функции
class IFunction {
public:
	static IFunction* create_function(std::function<double(double)> const&);   // Создаёт функцию

	virtual double at(double) = 0;   // Значение в точки
	virtual size_t get_counter() const = 0;   // Возвращает количество обращений к функции
	virtual void update_counter() = 0;   // Обнуляет счетчик вызовов функции

	virtual ~IFunction() = 0;

private:
	IFunction(IFunction const&) = delete;
	IFunction& operator=(IFunction const&) = delete;
protected:
	IFunction() = default;
};