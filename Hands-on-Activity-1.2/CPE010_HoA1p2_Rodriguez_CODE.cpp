#include <iostream>
#include <cmath>
using namespace std;

//ILO A
//Create a function that will take the sum of 2 numbers
int sum(int num1,int num2) {
  return (num1 + num2);
};

//ILO A
//Create a function that will output the greater number
int more(int num1,int num2) {
    if (num1 > num2) {
    return num1;
    }
    else {
  return num2;
}};

//ILO A
//Create a function that takes 2 Boolean values and display the result of logical operations
bool logic(bool num1,bool num2) {
	cout << num1 << " and " << num2 << ": " << (num1 && num2) << endl;
	cout << num1 << " or " << num2 << ": " << (num1  || num2) << endl;
    cout << "Not " << num1 << ": " << (!num1) << endl;
    cout << "Not " << num2 << ": " << (!num2) << endl;
    return true;
};

//Supplementary activity
//Create a code that swap 2 numbers
void swap(int& num1, int& num2) {
    int temp = num1;
    num1 = num2;
    num2 = temp;
};

//Supplementary activity
//Create a C++ program that has a function to convert temperature in Kelvin to Fahrenheit
double Kfahrenheit(double K) {
	return ((K - 273.15) * 9 / 5) + 32;
};

//Supplementary activity
//Calculate the distance of two points
double dist(double x1, double y1, double x2, double y2) {
	double distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    return distance;
};

//Supplementary activity
//Calculate the area, perimeter, and type of a triangle
void triangle(double a, double b, double c) {
	double perimeter = a + b + c;
	cout << "Perimeter: " << perimeter << endl;
	double semi = perimeter / 2;
	double area = sqrt(semi*(semi - a)*(semi-b)*(semi-c));
	cout << "Area " << area << endl;
	//type
	double longest = max(max(a, b), c);
	if (pow(longest, 2) > pow(a, 2) + pow(b, 2) + pow(c, 2) - 2 * longest * max(min(a, b), min(b, c))) {
        cout << "It is an obtuse triangle" << endl;
    } 
	else if (pow(longest, 2) < pow(a, 2) + pow(b, 2) + pow(c, 2) - 2 * longest * max(min(a, b), min(b, c))) {
        cout << "It is an acute triangle" << endl;
    } 
	else {
		cout <<"This triangle is classified as 'others'" << endl;
	};
};

int main() {
	//ILO A
	cout << "-----------------------" << endl;
	cout << "ILO A" << endl << endl;
	
	//Calling sum function
	cout << "1) Sum function:" << endl;
	int n1=4, n2=6;
	int sums = sum(4,6);
	cout << n1 << " + " << n2 << " = " << sums << endl <<endl;
	
	//Calling the "Print the greatest number function"
	cout << "2) Printing the greatest number:" << endl;
	cout << "Between " << n1 << " and " << n2 <<", ";
	cout << "the bigger number is ";
	cout << more(n1,n2) << endl << endl;
	
	//Calling Boolean function
	cout << "3) Logical operation of 2 boolean values:" << endl;
	bool True = true, False = false;
    logic(True, False);
    
    //----------------------------------------------------------
    //Supplementary activity
    cout << "-----------------------" << endl;
	cout << "Supplementary Activity" << endl << endl;
	
	//Swapping numbers
	cout << "1) Swapping values of 2 variables:" << endl;
	int n3 = 7, n4 = 3;
	cout << "Before swap: " << endl;
	cout << "n1: " << n3 << ", n2: " << n4 << endl;
	swap(n3,n4);
	cout << "After swap: " << endl;
	cout << "n1: " << n3 << ", n2: " << n4 << endl;
	cout << endl;
	
	//Temperature: Kelvin to Fahrenheit
	cout << "2) Convert Kelvin to Fahrenheit:" << endl;
	double K = 400;
	cout << "Kelvin: " << K << endl;
	cout << "Fahrenheit: " << Kfahrenheit(K);
	cout << endl << endl;
	
	//Distance of two points
	cout << "3) Distance of two points:" << endl;
	double x1=3, y1=4, x2=30, y2=40;
	cout << "First point: " << "(" << x1 <<", " << y1 << ")" << endl;
	cout << "Second point: " << "(" << x2 <<", " << y2 << ")" << endl;
	cout << "Distance: " << dist(x1,y1,x2,y2) << endl << endl;
	
	//Triangle area, perimeter, and type
	cout << "4) Triangle:" << endl;
	double s1 = 6, s2 = 3, s3 = 4;
	triangle(s1,s2,s3);
    return 0;
}
