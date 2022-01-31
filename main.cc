//Theo Andonyadis
/*This program uses various functions to make calculations based on the center point and a point on the outside of a circle entered by the user. It differs from
CPP-Circle-Calculations in that it uses objects and classes as well as public, private, and protected members. It differs from the first modified version in that it employs templating*/
#include <iostream>
#include <cmath>
#include <limits>
using namespace std;
template<typename TheType>
class circle {   //declares circle class
	public:		//declares public member functions radius, circumference, area, and populate_classobj
		double radius() {
			double r = distance();
			return r;
		}
		double circumference() {
			double c = M_PI*2*radius();
			return c;
		}
		double area() {
			double a = M_PI*radius()*radius();
			return a;
		}
		void populate_classobj(TheType a, TheType b, TheType c, TheType d) {
			x1 = a;
			y1 = b;
			x2 = c;
			y2 = d;
		}
		circle(TheType a=0,TheType b=0,TheType c=0,TheType d=0); //sets data members to zero
	private:	//declares private data members x1,y1,x2,y2
		TheType x1;
		TheType y1;
		TheType x2;
		TheType y2;
	protected:
		double distance() //Distance function used to find the distance from (x1,y1) to (x2,y2)
		{
			TheType run = x2-x1;
			TheType rise = y2-y1;
			TheType sum = run*run + rise*rise;
			double d = sqrt(sum);
			return d;
		}
};
template<typename TheType> 
circle<TheType>::circle(TheType a, TheType b, TheType c, TheType d)		//defines circle function to initialize x1,y1,x2,y2
{
	x1=a;
	y1=b;
	x2=c;
	y2=d;
}
int main()
{
	double e,f,g,h;
	circle<int> my_obj1(1,3);
	circle<double> my_obj2(-1.5,-6.65,-0.5,10.0);
	double r1 = my_obj1.radius ();		//the next 6 lines call public member functions and insert their values into r1, r2, a1, a2, c1, c2
	double r2 = my_obj2.radius ();
	double c1 = my_obj1.circumference ();
	double c2 = my_obj2.circumference ();
	double a1 = my_obj1.area ();
	double a2 = my_obj2.area ();
	char choice;
	while(choice != 6) //While loop to run the menu repeatedly
	{
	cout << "Do you wish to compute (1) Radius of both circles, (2) Circumference of both, (3) Area of both," << endl << "or (4) Enter new values for the points of circle 1, (5) Enter new values for the points of circle 2, or do you wish to Exit (6)?" << endl;
	cout << "Please select a number from the previous options." << endl;
	cin >> choice;
	switch(choice) { 	//switch menu with 6 cases
		case '1' :r1 = my_obj1.radius ();	//calls functions again in case inputs have been modified	
				  r2 = my_obj2.radius ();
				  cout << "Radius 1: " << r1 << ", " << "Radius 2: " << r2 << endl; 
		break;
		case '2' :c1 = my_obj1.circumference ();
				  c2 = my_obj2.circumference ();
			      cout << "Circumference 1: " << c1 << ", " << "Circumference 2: " << c2 << endl;
		break;
		case '3' :a1 = my_obj1.area ();
				  a2 = my_obj2.area (); 
				  cout << "Area 1: " << a1 << ", " << "Area 2: " << a2 << endl;
		break;
		case '4' :cout << "Enter value for circle center x1" << endl; //Prompts user for values for x1,y1,x2,y2 for circle 1
				  cin >> e;
				  cout << "Enter value for circle center y1" << endl;
				  cin >> f;
				  cout << "Enter value for point on circle x2" << endl;
				  cin >> g;					
				  cout << "Enter value for point on circle y2" << endl;
				  cin >> h;
			   	  my_obj1.populate_classobj (e,f,g,h);
		break;
		case '5' :cout << "Enter value for circle center x1" << endl; //Prompts user for values for x1,y1,x2,y2 for circle 2
				  cin >> e;
				  cout << "Enter value for circle center y1" << endl;
				  cin >> f;
				  cout << "Enter value for point on circle x2" << endl;
				  cin >> g;					
				  cout << "Enter value for point on circle y2" << endl;
				  cin >> h;
				  my_obj2.populate_classobj (e,f,g,h);
		break;
		case '6' : cout << "Exit. Have a nice day!" << endl;
		return 0;
		default : cout << "Invalid input." << endl; 	//default case to prevent crashing
		break;
	}
	}
	return 0;
}

