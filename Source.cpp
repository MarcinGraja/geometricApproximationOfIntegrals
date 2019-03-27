#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
struct function
{
	vector <double> coefficients;
};
double calculateValue(function f, double x)
{
	double sum = 0;
	for (int i = 0; i < f.coefficients.size(); i++)
	{
		sum += f.coefficients[i] * pow(x, i);
	}
	return sum;
}
double rectangleMethod(function f, double a, double b, int n)
{
	if (a >= b) 
	{
		cout << "początek zakresu większy bądź równy końcowi\n";
	}
	double delta = (b - a) / n;
	double currentXValue = a + delta;
	double sum = 0;
	while (currentXValue <= b)
	{
		cout << "calc\t" << calculateValue(f, currentXValue) << endl;
		sum += calculateValue(f, currentXValue);
		currentXValue += delta;
	}
	return sum * delta;
}
double trapezeMethod(function f, double a, double b, int n)
{
	double delta = (b - a) / n;
	double currentXValue = a;
	double sum = 0;
	double firstYValue = calculateValue(f, currentXValue);
	while (currentXValue < b)
	{
		currentXValue += delta;
		double secondYValue = calculateValue(f, currentXValue);
		sum += firstYValue + secondYValue;
		firstYValue = secondYValue;
	}
	return delta * sum / 2;
}

int main()
{
	cout << "wtf";
	function f;
	f.coefficients.push_back(2);
	f.coefficients.push_back(0);
	f.coefficients.push_back(0);
	f.coefficients.push_back(1); // 2+0*x+0*x^2+x^3
	cout << rectangleMethod(f, 1, 4, 3) << endl;
	cout << trapezeMethod(f, 1, 4, 3) << endl;
	cin.ignore();
}