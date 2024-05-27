#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int choice;
    double a, b, c;
    do{
        cout << "Enter the operation you want to perform:"<<endl;
        cout << "0. Terminate"<<endl;
        cout << "1. Calculate the hypotenuse of a right triangle"<<endl;
        cout << "2.Find one side using hypotenuse and one side"<<endl;
        cin >> choice;

        switch(choice){
            case 1:
                
                cout << "Enter the length of the first side: ";
                cin >> a;
                cout << "Enter the length of the second side: ";
                cin >> b;

                c = sqrt(pow(a, 2) + pow(b, 2));
                cout << "The length of the hypotenuse is: " << c << endl;
                break;
            case 2:
                
                cout << "Enter the length of the hypotenuse"<<endl;
                cin >> c;
                cout << "Enter the length of one side"<<endl;
                cin >> a;

                b = sqrt(pow(c, 2) - pow(a, 2));
                cout << "The length of the other side is: " << b << endl;
                break;
        }
    }while(choice != 0);
}