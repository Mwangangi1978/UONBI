#include <iostream>
using namespace std;
#include <cmath>

double add(double a, double b){
    return a+b;
}
double subtract(double a, double b){
    return a-b;
}
double multiply(double a, double b){
    return a*b;
}
double divide(double a, double b){
    return a/b;
}
double square(double a){
    return a*a;
}
double raiseToPower(double a, double b){
    return pow(a, b);
}
double root (double a){
    return sqrt(a);
}

int main(){
    int choice;
    do{
        cout << "Enter the operation you want to perform:"<<endl;
        cout << "0. Terminate"<<endl;
        cout << "1. Add"<<endl;
        cout << "2. Subtract"<<endl;
        cout << "3. Multiply"<<endl;
        cout << "4. Divide"<<endl;
        cout << "5. Square"<<endl;
        cout << "6. Raise to power"<<endl;
        cout << "7. Root"<<endl;
        cin >> choice;

        switch(choice){
            case 0:
                break;
            case 1:
                double a, b;
                cout << "Enter the first number: ";
                cin >> a;
                cout << "Enter the second number: ";
                cin >> b;
                cout << "The sum is: " << add(a, b) << endl;
                break;
            case 2:
                double c, d;
                cout << "Enter the first number: ";
                cin >> c;
                cout << "Enter the second number: ";
                cin >> d;
                cout << "The difference is: " << subtract(c, d) << endl;
                break;
            case 3:
                double e, f;
                cout << "Enter the first number: ";
                cin >> e;
                cout << "Enter the second number: ";
                cin>> f;
                cout << "The product is: " << multiply(e, f) << endl;
                break;
            case 4:
                double g, h;
                cout << "Enter the first number: ";
                cin >> g;
                cout << "Enter the second number: ";
                cin >> h;
                cout << "The quotient is: " << divide(g, h) << endl;
                break;
            case 5:
                double i;
                cout << "Enter the number: ";
                cin >> i;
                cout << "The square is: " << square(i) << endl;
                break;
            case 6:
                double j, k;
                cout << "Enter the base: ";
                cin >> j;
                cout << "Enter the exponent: ";
                cin >> k;
                cout << "The result is: " << raiseToPower(j, k) << endl;
                break;
            case 7:
                double l;
                cout << "Enter the number: ";
                cin >> l;
                cout << "The root is: " << root(l) << endl;
                break;
            default:
                cout << "Invalid choice"<<endl;                
        }
    }while(choice != 0);
}
