

#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime> // for time()
#include <string>
#include <random>
#include <stack>
using namespace std;


class electricalEngineeringStudent {
private:
    string name;
    string gender;
    double feesBalance;
    double scores[11];
    double average;

public:
    // Default constructor
    electricalEngineeringStudent() : name(""), gender(""), feesBalance(0.0), average(0.0) {
         for (int i = 0; i < 11; ++i) {
            scores[i] = 0.0; // Initialize scores array with zeros
        }
    }

    //Parametized Constructor
    electricalEngineeringStudent(string studentName, string studentGender, double balance, double studentScores[]) {
        name = studentName;
        gender = studentGender;
        feesBalance = balance;
        for (int i = 0; i < 11; i++) {
            scores[i] = studentScores[i];
        }
        calculateAverage() ;
    }
    // Getters for accessing private members
    string getName() const { return name; }
    string getGender() const { return gender; }
    double getFeesBalance() const { return feesBalance; }
    double* getScores() { return scores; }
    double getAverage() const { return average; }

    // Calculate the average of the scores
    void calculateAverage() {
        double sum = 0.0;
        for (int i = 0; i < 11; i++) {
            sum += scores[i];
        }
        average = sum / 11;
    }
};




class Node {
public:
    int key;
    electricalEngineeringStudent data;
    Node* next;
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
    Node* top;
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
    Node* peek() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return nullptr;
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
        string unitNames[] = {"Computer Science", "AppliedMaths1A", "PureMaths1A", "Physics1A", "Electrical Workshop", "Data Structures and Algorithms", "AppliedMaths1B", "Physics1B", "PureMaths1B", "Mechanical Workshop", "ECT"};

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
               
                double* scores = temp->data.getScores(); 
                for (int i = 0; i < 11; i++) {
                    cout << unitNames[i] << ": " << scores[i] << endl;
                }
                cout << endl << endl;
                temp = temp->next;
            }   
        }
    };
};


void displayStudentsByGender(Stack& stack, string gender) {
    Node* temp = stack.top;
    bool found = false;

    if (stack.isEmpty()) {
        cout << "Stack is empty." << endl;
        return;
    } else {
        while (temp != nullptr) {
            if (temp->data.getGender() == gender) {
                found = true;
                cout << "Student Name: " << temp->data.getName() << ": Admission Number: FEE3/" << temp->key << "/2023:" << endl;
            }
            temp = temp->next;
        }
    }
    if (!found) {
        cout << "No students of gender " << gender << " found." << endl;
    }
}

void sortStudentsByAdmissionNumber(Stack& stack) {
    int size = stack.count();
    Node** pointerArray = new Node*[size];

    Node* temp = stack.top;
    for (int i = 0; i < size; ++i) {
        pointerArray[i] = temp;
        temp = temp->next;
    }

    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (pointerArray[j]->key > pointerArray[j + 1]->key) {
                Node* tempNode = pointerArray[j];
                pointerArray[j] = pointerArray[j + 1];
                pointerArray[j + 1] = tempNode;
            }
        }
    }

    for (int i = 0; i < size; ++i) {
        cout << "Student Name: " << pointerArray[i]->data.getName() << ":  Admission Number: FEE3/" << pointerArray[i]->key << "/2023:" << endl;
    }

    delete[] pointerArray;
}

void sortStudentsByAverage(Stack& stack) {
    int size = stack.count();
    Node** pointerArray = new Node*[size];

    Node* temp = stack.top;
    for (int i = 0; i < size; ++i) {
        pointerArray[i] = temp;
        temp = temp->next;
    }

    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (pointerArray[j]->data.getAverage() < pointerArray[j + 1]->data.getAverage()) {
                Node* tempNode = pointerArray[j];
                pointerArray[j] = pointerArray[j + 1];
                pointerArray[j + 1] = tempNode;
            }
        }
    }

    // showing sorted student 
    for (int i = 0; i < size; ++i) {
        cout << "Student Name: " << pointerArray[i]->data.getName() << ": Admission Number: FEE3/" << pointerArray[i]->key << "/2023:  " << "Average Score: " << pointerArray[i]->data.getAverage() << endl;
    }

    delete[] pointerArray;
}







int main() {
    Stack stack;
    string unitNames[] = {"Computer Science", "AppliedMaths1A", "PureMaths1A", "Physics1A", "Electrical Workshop", "Data Structures and Algorithms", "AppliedMaths1B", "Physics1B", "PureMaths1B", "Mechanical Workshop", "ECT"};
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
        cout << "8. Sort students based on average marks" << endl;
        cout << "9. Find students of a particular gender" << endl;
        cout << "10. Sort students by admission number" << endl;
        cin >> option;

        switch (option) {
            case 1: {
                int nodeKey;
                string studentName;
                string studentGender;
                double feesBalance;
                double studentScores[11];

                cout << "Enter the admission number of the student you want to remove (integer between 2000 and 3000): ";
                cin >> nodeKey;
                cout << "Enter the student's name: ";
                cin.ignore(); // Ignore any remaining newline characters
                getline(cin, studentName);
                cout << "Enter the student's gender (M or F): ";
                getline(cin, studentGender);
                cout << "Enter the student's fees balance: ";
                cin >> feesBalance;
                cout << "Enter the student's scores for each unit: " << endl;
                for (int i = 0; i < 11; i++) {
                    cout << "Score for " <<unitNames[i]<< ": ";
                    cin >> studentScores[i];
                }

                electricalEngineeringStudent student(studentName, studentGender, feesBalance, studentScores);
                Node* newNode = new Node(nodeKey, student);
                stack.push(newNode);
                break;
            }


            case 2: {
                int nodeKey;
                string unitNames[] = {"Computer Science", "AppliedMaths1A", "PureMaths1A", "Physics1A", "Electrical Workshop", "Data Structures and Algorithms", "AppliedMaths1B", "Physics1B", "PureMaths1B", "Mechanical Workshop", "ECT"};
                cout << "Enter the admission number of the student you want to find (integer between 2000 and 3000): ";
                cin >> nodeKey;
                // Find a student using their admission number (nodeKey)
                Node* temp = stack.top;
                bool found = false;

                while (temp != nullptr) {
                    if (temp->key == nodeKey) {
                        found = true;
                        break;
                    }
                    temp = temp->next;
                }

                if (found) {
                    cout << "Students with admission number FEE3/" << nodeKey << "/2023 has been found" << endl;
                    cout << "Student name: " << temp->data.getName() << endl;
                    cout << "Gender: " << temp->data.getGender() << endl;
                    cout << "Fees Balance: " << temp->data.getFeesBalance() << " shillings" << endl;
                    cout << "Units and Scores: " << endl;
                    double* scores = temp->data.getScores(); // Get the scores array
                    for (int i = 0; i < 11; i++) {
                        cout << unitNames[i] << ": " << scores[i] << endl;
                    }
                    cout << "Average: " << temp->data.getAverage() << endl;
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
                Node* prev = nullptr;
                bool found = false;

                while (temp != nullptr) {
                    if (temp->key == nodeKey) {
                        found = true;
                        break;
                    }
                    prev = temp;
                    temp = temp->next;
                }

                if (found) {
                    if (prev == nullptr) {
                        stack.top = temp->next;
                    } else {
                        prev->next = temp->next;
                    }
                    delete temp;
                    cout << "Students with admission number FEE3/" << nodeKey << "/2023 has been removed" << endl;
                } else {
                    cout << "Student with admission number FEE3/" << nodeKey << "/2023 not found" << endl;
                }
                break;
            }
            case 5: {
                // Count the number of students
                cout << "Total number of students: " << stack.count() << endl;
                break;
            }
            case 6: {
                cout << "Display Function Called - " << endl;
                if (stack.isEmpty()) {
                    cout << "Stack is Empty" << endl;
                } else {
                    stack.display();
                }
                break;
            }
            case 7: {
                // Clear the screen
                system("clear");
                break;
            }
            case 8:{
                sortStudentsByAverage(stack);
            }
            case 9: {
                string gender;
                cout << "Enter the gender of students you want to find (M or F): ";
                cin >> gender;
                displayStudentsByGender(stack, gender);
                break;
            }
            case 10: {
                sortStudentsByAdmissionNumber(stack);
                break;
            }
            default:
                cout << "Enter Proper Option number " << endl;
                break;
        }

    } while (option != 0);

    return 0;
}

