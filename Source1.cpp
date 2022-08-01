#include <iostream>
#include <cmath>
using namespace std;

double Max(double Array[], int n)
{
	double max;
	max = Array[0];
	for (int i = 1; i < n; i++)
	{
		if (Array[i] > max) max = Array[i];
	}
	return max;
}
double Min(double Array[], int n)
{
	double min;
	min = Array[0];
	for (int i = 1; i < n; i++)
	{
		if (Array[i] < min) min = Array[i];
	}
	return min;
}
double Tot(double Array[], int n)
{
	double tot(0);
	tot += Array[0];
	for (int i = 0; i < n; i++)
	{
		tot += Array[i];
	}
	return tot;
}
void Print(double Array[], int n)
{
	cout << "\n\n Array : [ ";
	for (int h = 0; h < n - 1; h++)
	{
		cout << Array[h] << " , ";
	}
	cout << Array[n - 1] << " ] ." << endl;
}