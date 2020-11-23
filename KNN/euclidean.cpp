#include <iostream>
#include <math.h>

using namespace std;

double distanceCalculate(double x1, double y1, double x2, double y2)
{
	double x = x1 - x2; //calculating number to square in next step
	double y = y1 - y2;
	double dist;

	dist = pow(x, 2) + pow(y, 2);       //calculating Euclidean distance
	dist = sqrt(dist);                  

	return dist;
}

int main()
{
	double x1, y1, x2, y2;
	double dist;
	cout << "Enter x1:" << endl;    //user inputs the points
	cin >> x1;
	cout << "Enter y1:" << endl;
	cin >> y1;
	cout << "Enter x2:" << endl;
	cin >> x2;
	cout << "Enter y2:" << endl;
	cin >> y2;

	dist = distanceCalculate(x1, y1, x2, y2);    //initiate equation
	cout << "Distance Between (" << x1 << " , " << y1 << ") and (" << x2 << " , " << y2 << ") = " << dist << endl;
}
