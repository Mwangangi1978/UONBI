#include <iostream>
using namespace std;

double celciusToFahrenheit(double celcius){
    return (celcius * 9/5) + 32;
}
double fahrenheitToCelcius(double fahrenheit){
    return(fahrenheit - 32) / 1.8;
}

int main(){
    int choice;
    do{
        cout << "Enter the operation you want to perform:"<<endl;
        cout << "0. Terminate"<<endl;
        cout << "1. Convert Celcius to Fahrenheit"<<endl;
        cout << "2. Convert Fahrenheit to Celcius"<<endl;
        cin >> choice;

        switch(choice){
            case 0:
                break;
            case 1:
                double celcius;
                cout << "Enter the temperature in Celcius: ";
                cin >> celcius;
                cout << "The temperature in Fahrenheit is: " << celciusToFahrenheit(celcius) << endl;
                break;
            case 2:
                double fahrenheit;
                cout << "Enter the temperature in Fahrenheit: ";
                cin >> fahrenheit;
                cout << "The temperature in Celcius is: " << fahrenheitToCelcius(fahrenheit) << endl;
                break;
        }
    }while(choice != 0);

    return 0;
}