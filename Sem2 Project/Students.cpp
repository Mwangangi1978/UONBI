#include <iostream>
#include <map>
#include <cstdlib> // for rand() and srand()
#include <ctime> // for time()
#include <string>
#include <random>
using namespace std;

class electricalEngineeringStudent {
private:
    string name;
    string gender;
    double feesBalance;
    map<string, string> units;

public:
    // Default constructor
    electricalEngineeringStudent() : name(""), gender(""), feesBalance(0.0), units({}) {}

    //Parametized Constructor
    electricalEngineeringStudent(string studentName, string studentGender, double balance, map<string, string> studentUnits) {
        name = studentName;
        gender = studentGender;
        feesBalance = balance;
        units = studentUnits;
    }
     // Getters for accessing private members
    string getName() const { return name; }
    string getGender() const { return gender; }
    double getFeesBalance() const { return feesBalance; }
    map<string, string> getUnits() const { return units; }
};

// Function to generate a random student
electricalEngineeringStudent generateRandomStudent() {
    // Generate random values for student properties
    string studentName = "Student" + to_string(rand() % 1000);
    string studentGender = (rand() % 2 == 0) ? "M" : "F";
    double feesBalance = (rand() % 10000) / 100;
    map<string, string> studentUnits;
    double studentScores[11];      

    string unitNames[] = {"Computer Science", "AppliedMaths1A", "PureMaths1A", "Physics1A", "Electrical Workshop", "Data Structures and Algorithms", "AppliedMaths1B", "Physics1B", "PureMaths1B", "Mechanical Workshop", "ECT"};
    
    for (int i = 0; i < 11; i++) {
        studentUnits[unitNames[i]] = to_string(rand() % 99); 
    }
    
    
    electricalEngineeringStudent student(studentName, studentGender, feesBalance, studentUnits);
    return student;
}    
                

class Node {
public:
    int key;
    electricalEngineeringStudent data; // Change data type here
    Node * next;
    Node() {
        key = 0;
        next = NULL;
    }
    Node(int k, electricalEngineeringStudent d) { // Change constructor parameter type here
        key = k;
        data = d; // Assign data here
        next = NULL;
    }
};

class Stack {
public:
    Node * top;
    Stack() {
        top = NULL;
    }
    bool isEmpty() {
        if (top == NULL) {
            return true;
        } else {
            return false;
        }
    }
    bool checkIfNodeExist(Node * n) {
        Node * temp = top;
        bool exist = false;
        while (temp != NULL) {
            if (temp -> key == n -> key) {
                exist = true;
                break;
            }
            temp = temp -> next;
        }
        return exist;
    }
    void push(Node * n) {
        if (top == NULL) {
            top = n;
        } else if (checkIfNodeExist(n)) {
            cout << "Node already exist with key value: " << n -> key << ". Can't add the node." << endl;
        } else {
            Node * temp = top;
            top = n;
            n -> next = temp;
            cout << "Node pushed." << endl;
        }
    }
    Node * pop() {
        Node * temp = NULL;
        if (isEmpty()) {
            cout << "Stack underflow." << endl;
            return temp;
        } else {
            temp = top;
            top = top -> next;
            return temp;
        }
    }
    Node * peek() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return NULL;
        } else {
            return top;
        }
    }
    int count() {
        int count = 0;
        Node * temp = top;
        while (temp != NULL) {
            count++;
            temp = temp -> next;
        }
        return count;
    }
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
        } else {
            Node * temp = top;
        
            while (temp != NULL) {
                cout << "Student with admission number FEE3/" << temp->key << "/2023:" << endl;
                cout << "Student name: " << temp->data.getName() << endl;
                cout << "Gender: " << temp->data.getGender() << endl;
                cout << "Fees Balance: " << temp->data.getFeesBalance() << "shillings" << endl;
                cout << "Units: " << endl;
                for (const auto& unit : temp->data.getUnits()) {
                    cout << unit.first << ": " << unit.second << endl;
                }
                cout << endl << endl;
                temp = temp->next;
            }   
        }
    }
};

void displayStudentsByGender(Stack& stack, string gender) {
    Node* temp = stack.top;
    bool found = false;

    if (stack.isEmpty()) {
        cout << "Stack is empty." << endl;
        return;
    }
    else{
        while (temp != nullptr) {
            if (temp->data.getGender() == gender) {
                found = true;
                cout << "Student Name: " << temp->data.getName() << ": Admission Number: FEE3/" << temp->key << "/2023:" << endl;
            }
            temp = temp->next;
        }
    }
}

void sortStudentsByAdmissionNumber(Stack& stack) {
    int size = stack.count();
    Node** pointerArray = new Node*[size];

    // Populate the pointer array with pointers to nodes in the stack
    Node* temp = stack.top;
    for (int i = 0; i < size; ++i) {
        pointerArray[i] = temp;
        temp = temp->next;
    }

    // Sort the pointer array based on admission numbers using bubble sort
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (pointerArray[j]->key > pointerArray[j + 1]->key) {
                Node* tempNode = pointerArray[j];
                pointerArray[j] = pointerArray[j + 1];
                pointerArray[j + 1] = tempNode;
            }
        }
    }

    // Display students' properties using the sorted pointer array
    for (int i = 0; i < size; ++i) {
        cout << "Student Name: " << pointerArray[i]->data.getName() << ":  Admission Number: FEE3/" << pointerArray[i]->key << "/2023:" <<endl;
        // Display other properties as needed
    }

    delete[] pointerArray;
}




int main() {
    Stack stack;
    
    int option;
    do {
        cout << "What operation do you want to perform?" << endl;
        cout << "Select Option number. Enter 0 to exit." << endl;
        cout << "1. Add new student" << endl;
        cout << "2. Find a student using their admission number." << endl;
        cout << "3. Check if there are no students" << endl;
        cout << "4. Remove a student using admission number" << endl;
        cout << "5. Count the number of students" << endl;
        cout << "6. Show all students and their properties" << endl;
        cout << "7. Clear Screen" << endl;
        cout << "8. Generate 5 students and add them to the stack" << endl;
        cout << "9. Find students of a particular gender" << endl;
        cout << "10. Sort students by admission number" << endl;
        cin >> option;
        
        switch (option) {
            case 1: {
                int nodeKey;
                string studentName;
                string studentGender;
                double feesBalance;
                map<string, string> studentUnits;

                cout << "Enter the node key (between 2000 and 3000): ";
                cin >> nodeKey;

                cout << "Enter the student's name: ";
                std::cin.ignore(); 
                getline(cin, studentName);

                cout << "Enter the student's gender (M or F): ";
                getline(cin, studentGender);

                cout << "Enter the student's fees balance: ";
                cin >> feesBalance;

                cout << "Enter the student's units and respective score (in the format 'unit name:unit score'): " << endl;
                string unitCode, unitName;
                for (int i = 0; i < 11; i++) {
                    cout << "Unit " << i + 1 << ": ";
                    cin >> unitCode >> unitName;
                    studentUnits[unitCode] = unitName;
                }

                electricalEngineeringStudent student(studentName, studentGender, feesBalance, studentUnits);
                Node* newNode = new Node(nodeKey, student);
                stack.push(newNode);

                break;
            }

            case 2: {
                
                int nodeKey;
                cout << "Enter the admission number of the student you want to find (integer between 2000 and 3000): ";
                cin >> nodeKey;
                // Find a student using their admission number (nodeKey)
                Node* temp = stack.top;
                Node* prev = NULL;
                bool found = false;

                while (temp != NULL) {
                    if (temp->key == nodeKey) {
                        found = true;
                        break;
                    }
                    prev = temp;
                    temp = temp->next;
                }

                if (found) {
                    cout << "Students with admission number FEE3/" << nodeKey << "/2023 has been found" << endl;
                    cout << "Student name: " << temp->data.getName() << endl;
                    cout << "Gender: " << temp->data.getGender() << endl;
                    cout << "Fees Balance: " << temp->data.getFeesBalance() << "shillings" <<endl;
                    cout << "Units: " << endl;
                    map<string, string> units = temp->data.getUnits();
                    for (const auto& unit : units) {
                        cout << unit.first << ": " << unit.second << endl;
                    }
                } else {
                    cout << "Student with admission number FEE3/" << nodeKey << "/2023 not found" << endl;
                }
                break;
            }
            case 3: {
                // Check if the stack is empty
                if (stack.isEmpty())
                    cout << "Stack is Empty" << endl;
                else
                    cout << "Stack is not Empty" << endl;
                break;
            }
            case 4: {
                int nodeKey;
                cout << "Enter the admission number of the student you want to remove (integer between 2000 and 3000): ";
                cin >> nodeKey;
                // Find a student using their admission number (nodeKey)
                Node* temp = stack.top;
                Node* prev = NULL;
                bool found = false;

                while (temp != NULL) {
                    if (temp->key == nodeKey) {
                        found = true;
                        break;
                    }
                    prev = temp;
                    temp = temp->next;
                }

                if (found) {
                    delete temp;
                    cout << "Students with admission number FEE3/" << nodeKey << "/2023 has been removed" << endl;
                } else {
                    cout << "Student with admission number FEE3/" << nodeKey << "/2023 not found" << endl;
                }
                break;
            }
            case 5: {
                // Count the number of students
                cout <<"Total number of students: " << stack.count() << endl;
                break;
            }
            case 6: {
                cout << "Display Function Called - " << endl;
                if (stack.isEmpty()){
                    cout << "Stack is Empty" << endl;
                }else{
                    stack.display();
                    cout << endl;
                } 
                break;
            }
            case 7: {
                // Clear the screen
                system("clear");
                break;
            }
            case 8: {   
                // Generate 5 random students and add them to the stack
                for (int i = 0; i < 5; i++) {
                    electricalEngineeringStudent student = generateRandomStudent();
                    Node* newNode = new Node(i + 2000, student);
                    stack.push(newNode);
                }

                // Display all the students and their properties
                stack.display();
            }
            case 9: {
                string gender;
                cout << "Enter the gender of students you want to find (M or F): ";
                cin >> gender;
                displayStudentsByGender(stack, gender);
            }    
            case 10: {
                sortStudentsByAdmissionNumber(stack);
            }
            default:
                cout << "Enter Proper Option number " << endl;
                break;
        }
        
    } while (option != 0);
    
    return 0;
};

