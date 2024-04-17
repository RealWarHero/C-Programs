#include <iostream>
#include <cmath>
#include <stdexcept>
using namespace std;

class Triangle{
private:
    double side1 , side2 , side3;
public:
    Triangle(double s1 , double s2 , double s3): side1(s1) , side2(s2) , side3(s3) {
        if (side1 <= 0 || side2 <= 0 || side3 <= 0)
        {
            throw invalid_argument("All sides must be greater than 0.");
        }
        if (side1+side2 <= side3 || side1+side3 <= side2 || side2+side3 <= side1)
        {
            throw invalid_argument("Sum of any two sides must be greater than the third side.");
        }
    }
    double calculateArea()  {
        double s = (side1+side2+side3)/2;
        return sqrt(s*(s-side1)*(s-side2)*(s-side3));
    }
    double calculateArea(double base , double height)  {
        if (base<=0 || height<=0)
        {
            throw invalid_argument("Base and height must be greater than 0.");
        }
        return 0.5*base*height;
    }
};

int main(){
    try
    {
        double s1,s2,s3,b,h;
        cout<<"Enter the length of the sides of the triangle : ";
        cin>>s1>>s2>>s3;
        Triangle triangle(s1,s2,s3);
        cout<<"Area of Triangle using Heron's Formula : "<<triangle.calculateArea()<<endl;
        cout<<"Enter the base and height of the right angled triangle : ";
        cin>>b>>h;
        cout<<"Area of the right angled triangle : "<<triangle.calculateArea(b,h)<<endl;
    }
    catch(const exception& e)
    {
        cerr <<"Exception Found."<< e.what() << '\n';
    }  
    return 0;
}