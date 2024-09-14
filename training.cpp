#include <iostream>
#include <string>
using namespace std;

// Basic Input/Output
int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;
    cout << "You entered: " << num << endl;

    // Basic Arithmetic
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;

    cout << "Sum: " << a + b << endl;
    cout << "Difference: " << a - b << endl;
    cout << "Product: " << a * b << endl;
    if (b != 0)
        cout << "Division: " << a / b << endl;
    else
        cout << "Division by zero is not allowed" << endl;

    // Control Structures (if-else, for loop, while loop)
    int x;
    cout << "Enter a number: ";
    cin >> x;

    if (x > 0)
        cout << x << " is positive" << endl;
    else if (x < 0)
        cout << x << " is negative" << endl;
    else
        cout << x << " is zero" << endl;

    cout << "For loop example:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "i = " << i << endl;
    }

    cout << "While loop example:" << endl;
    int count = 5;
    while (count > 0) {
        cout << "Countdown: " << count << endl;
        count--;
    }

    // Functions in C++
    int result = add(a, b);
    cout << "Sum using function: " << result << endl;

    // Arrays
    int arr[5] = {10, 20, 30, 40, 50};

    cout << "Array elements:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Strings in C++
    string name;
    cout << "Enter your name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Hello, " << name << "!" << endl;

    // Class and Objects in C++
    Person p1;
    p1.name = "Bipin";
    p1.age = 25;
    p1.introduce();

    // Constructor in a Class
    Rectangle rect(10, 5);
    cout << "Area of rectangle: " << rect.area() << endl;

    // Inheritance
    Dog dog;
    dog.eat();  // Inherited method
    dog.bark(); // Specific method

    // Pointers
    int var = 10;
    int* ptr = &var;
    cout << "Value of var: " << var << endl;
    cout << "Address of var: " << &var << endl;
    cout << "Pointer value (address): " << ptr << endl;
    cout << "Pointer dereference (value at address): " << *ptr << endl;

    // Dynamic Memory Allocation
    int* dyn_ptr = new int;
    *dyn_ptr = 25;
    cout << "Value at allocated memory: " << *dyn_ptr << endl;
    delete dyn_ptr;
    dyn_ptr = nullptr;

    // Function Overloading
    cout << "Sum of integers: " << add(5, 10) << endl;
    cout << "Sum of doubles: " << add(5.5, 10.5) << endl;

    // New Examples Below:

    // Switch Case Example
    char grade;
    cout << "Enter your grade (A, B, C, D, F): ";
    cin >> grade;

    switch (grade) {
        case 'A':
            cout << "Excellent!" << endl;
            break;
        case 'B':
            cout << "Good!" << endl;
            break;
        case 'C':
            cout << "Fair!" << endl;
            break;
        case 'D':
            cout << "Poor!" << endl;
            break;
        case 'F':
            cout << "Fail!" << endl;
            break;
        default:
            cout << "Invalid grade!" << endl;
    }

    // Do-While Loop Example
    int do_while_counter = 0;
    do {
        cout << "Do-While Loop Counter: " << do_while_counter << endl;
        do_while_counter++;
    } while (do_while_counter < 5);

    // Inline Functions Example
    cout << "Maximum of 10 and 20 is: " << max(10, 20) << endl;

    // Friend Function Example
    Sample s1;
    cout << "Enter the value for Sample: ";
    cin >> s1.value;
    showValue(s1);

    return 0;
}

// Function Definitions
int add(int a, int b) {
    return a + b;
}

double add(double a, double b) {
    return a + b;
}

// Inline Function Definition
inline int max(int a, int b) {
    return (a > b) ? a : b;
}

// Class Definitions
class Person {
public:
    string name;
    int age;

    void introduce() {
        cout << "Hi, I am " << name << " and I am " << age << " years old." << endl;
    }
};

class Rectangle {
public:
    int length, width;

    Rectangle(int l, int w) : length(l), width(w) {}

    int area() {
        return length * width;
    }
};

class Animal {
public:
    void eat() {
        cout << "This animal is eating." << endl;
    }
};

class Dog : public Animal {
public:
    void bark() {
        cout << "The dog is barking." << endl;
    }
};

class Sample {
    friend void showValue(Sample s);

private:
    int value;
};

void showValue(Sample s) {
    cout << "The value is: " << s.value << endl;
}
