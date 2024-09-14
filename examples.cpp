#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// 1. Basic Input/Output and Arithmetic Operations
int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;
    cout << "You entered: " << num << endl;

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

    // 2. Control Structures: If-Else, Loops, and Switch Case
    int x;
    cout << "Enter a number: ";
    cin >> x;

    if (x > 0)
        cout << x << " is positive" << endl;
    else if (x < 0)
        cout << x << " is negative" << endl;
    else
        cout << x << " is zero" << endl;

    for (int i = 0; i < 5; i++) {
        cout << "i = " << i << endl;
    }

    int count = 5;
    while (count > 0) {
        cout << "Countdown: " << count << endl;
        count--;
    }

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

    // 3. Functions and Function Overloading
    cout << "Sum using function: " << add(a, b) << endl;
    cout << "Sum of doubles: " << add(5.5, 10.5) << endl;

    // 4. Arrays and Pointers
    int arr[5] = {10, 20, 30, 40, 50};
    cout << "Array elements:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int var = 10;
    int* ptr = &var;
    cout << "Pointer value (address): " << ptr << endl;
    cout << "Pointer dereference (value at address): " << *ptr << endl;

    int* dyn_ptr = new int;
    *dyn_ptr = 25;
    cout << "Value at allocated memory: " << *dyn_ptr << endl;
    delete dyn_ptr;
    dyn_ptr = nullptr;

    // 5. Strings and String Manipulation
    string name;
    cout << "Enter your name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Hello, " << name << "!" << endl;

    string reversed_name = string(name.rbegin(), name.rend());
    cout << "Reversed name: " << reversed_name << endl;

    // 6. Classes, Objects, Constructors, Inheritance, and Friend Functions
    Person p1;
    p1.name = "Bipin";
    p1.age = 25;
    p1.introduce();

    Rectangle rect(10, 5);
    cout << "Area of rectangle: " << rect.area() << endl;

    Dog dog;
    dog.eat();
    dog.bark();

    Sample s1;
    s1.setValue(30);
    showValue(s1);

    // 7. Inline Functions and Function Templates
    cout << "Maximum of 10 and 20 is: " << max(10, 20) << endl;

    cout << "Sum of floats (template): " << sum(5.5, 6.3) << endl;

    // 8. Recursion (Factorial Calculation)
    int factorial_input = 5;
    cout << "Factorial of " << factorial_input << " is: " << factorial(factorial_input) << endl;

    // 9. Vectors and Algorithms (Sorting)
    vector<int> vec = {5, 1, 4, 2, 3};
    cout << "Unsorted vector: ";
    for (int v : vec) cout << v << " ";
    cout << endl;

    sort(vec.begin(), vec.end());
    cout << "Sorted vector: ";
    for (int v : vec) cout << v << " ";
    cout << endl;

    return 0;
}

// Function Definitions
int add(int a, int b) {
    return a + b;
}

double add(double a, double b) {
    return a + b;
}

inline int max(int a, int b) {
    return (a > b) ? a : b;
}

// Templates for Generic Functions
template <typename T>
T sum(T a, T b) {
    return a + b;
}

// Recursion Example
int factorial(int n) {
    if (n == 0) return 1;
    return n * factorial(n - 1);
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

// Friend Functions
class Sample {
    friend void showValue(Sample s);

private:
    int value;

public:
    void setValue(int val) {
        value = val;
    }
};

void showValue(Sample s) {
    cout << "The value is: " << s.value << endl;
}

// Additional Advanced Examples

// 10. Lambda Expressions
void lambdaExample() {
    auto square = [](int x) { return x * x; };
    cout << "Square of 5 using lambda: " << square(5) << endl;
}

// 11. Exception Handling
void exceptionHandlingExample() {
    try {
        int divisor;
        cout << "Enter divisor: ";
        cin >> divisor;
        if (divisor == 0) throw runtime_error("Division by zero");
        cout << "10 / " << divisor << " = " << 10 / divisor << endl;
    } catch (exception& e) {
        cout << "Error: " << e.what() << endl;
    }
}

// 12. Operator Overloading
class Complex {
public:
    int real, imag;

    Complex(int r = 0, int i = 0) : real(r), imag(i) {}

    Complex operator + (Complex const& obj) {
        return Complex(real + obj.real, imag + obj.imag);
    }

    void display() {
        cout << real << " + " << imag << "i" << endl;
    }
};

void operatorOverloadingExample() {
    Complex c1(10, 5), c2(2, 4);
    Complex c3 = c1 + c2;
    cout << "Sum of complex numbers: ";
    c3.display();
}

// 13. File Handling
#include <fstream>
void fileHandlingExample() {
    ofstream file("example.txt");
    file << "This is a test file." << endl;
    file.close();

    string line;
    ifstream readFile("example.txt");
    while (getline(readFile, line)) {
        cout << line << endl;
    }
    readFile.close();
}
