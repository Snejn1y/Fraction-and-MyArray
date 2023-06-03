#include "6.h"

int Fraction::gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

void Fraction::simplify() {
    int g = gcd(abs(numerator), abs(denominator));
    numerator /= g;
    denominator /= g;
}

Fraction::Fraction() : numerator(0), denominator(1) {}

Fraction::Fraction(int num, int denom) : numerator(num), denominator(denom) {
    simplify();
}

Fraction Fraction::operator+(const Fraction& other) const {
    int new_num = numerator * other.denominator + other.numerator * denominator;
    int new_denom = denominator * other.denominator;
    return Fraction(new_num, new_denom);
}

Fraction Fraction::operator+(int value) const {
    return Fraction(numerator + value * denominator, denominator);
}

Fraction operator+(int value, const Fraction& f) {
    return f + value;
}

Fraction Fraction::operator-(const Fraction& other) const {
    int new_num = numerator * other.denominator - other.numerator * denominator;
    int new_denom = denominator * other.denominator;
    return Fraction(new_num, new_denom);
}

Fraction Fraction::operator-(int value) const {
    return Fraction(numerator - value * denominator, denominator);
}

Fraction operator-(int value, const Fraction& f) {
    return Fraction(value * f.denominator - f.numerator, f.denominator);
}

Fraction Fraction::operator*(const Fraction& other) const {
    int new_num = numerator * other.numerator;
    int new_denom = denominator * other.denominator;
    return Fraction(new_num, new_denom);
}

Fraction Fraction::operator*(int value) const {
    return Fraction(numerator * value, denominator);
}

Fraction operator*(int value, const Fraction& f) {
    return f * value;
}

Fraction Fraction::operator/(const Fraction& other) const {
    int new_num = numerator * other.denominator;
    int new_denom = denominator * other.numerator;
    return Fraction(new_num, new_denom);
}

Fraction Fraction::operator/(int value) const {
    return Fraction(numerator, denominator * value);
}

Fraction operator/(int value, const Fraction& f) {
    return Fraction(value * f.denominator, f.numerator);
}

std::ostream& operator<<(std::ostream& out, const Fraction& f) {
    out << f.numerator << "/" << f.denominator;
    return out;
}

bool Fraction::operator==(const Fraction& other) const {
    return numerator == other.numerator && denominator == other.denominator;
}

bool Fraction::operator!=(const Fraction& other) const {
    return !(*this == other);
}

bool Fraction::operator<(const Fraction& other) const {
    return numerator * other.denominator < other.numerator* denominator;
}

bool Fraction::operator>(const Fraction& other) const {
    return other < *this;
}

bool Fraction::operator<=(const Fraction& other) const {
    return !(other < *this);
}

bool Fraction::operator>=(const Fraction& other) const {
    return !(*this < other);
}

template<typename T>
MyArray<T>::MyArray(T* arr, int size) : arr(arr), size(size) {}

template<typename T>
MyArray<T>::~MyArray() {
    delete[] arr;
}

template<typename T>
void MyArray<T>::sort() {
    mergeSort(0, size - 1);
}

template<typename T>
void MyArray<T>::print() const {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

template<typename T>
void MyArray<T>::merge(int left, int mid, int right) {
    int left_size = mid - left + 1;
    int right_size = right - mid;

    T* left_arr = new T[left_size];
    T* right_arr = new T[right_size];

    for (int i = 0; i < left_size; i++) {
        left_arr[i] = arr[left + i];
    }
    for (int j = 0; j < right_size; j++) {
        right_arr[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0;
    int k = left;
    while (i < left_size && j < right_size) {
        if (left_arr[i] <= right_arr[j]) {
            arr[k] = left_arr[i];
            i++;
        }
        else {
            arr[k] = right_arr[j];
            j++;
        }
        k++;
    }

    while (i < left_size) {
        arr[k] = left_arr[i];
        i++;
        k++;
    }

    while (j < right_size) {
        arr[k] = right_arr[j];
        j++;
        k++;
    }

    delete[] left_arr;
    delete[] right_arr;
}

template<typename T>
void MyArray<T>::mergeSort(int left, int right) {
    if (left >= right) {
        return;
    }
    int mid = left + (right - left) / 2;
    mergeSort(left, mid);
    mergeSort(mid + 1, right);
    merge(left, mid, right);
}

// Specialization for char*
template<>
MyArray<char*>::MyArray(char** arr, int size) : arr(arr), size(size) {}

template<>
MyArray<char*>::~MyArray() {
    delete[] arr;
}

template<>
void MyArray<char*>::sort() {
    mergeSort(0, size - 1);
}

template<>
void MyArray<char*>::print() const {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

template<>
void MyArray<char*>::merge(int left, int mid, int right) {
    int left_size = mid - left + 1;
    int right_size = right - mid;

    char** left_arr = new char* [left_size];
    char** right_arr = new char* [right_size];

    for (int i = 0; i < left_size; i++) {
        left_arr[i] = arr[left + i];
    }
    for (int j = 0; j < right_size; j++) {
        right_arr[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0;
    int k = left;
    while (i < left_size && j < right_size) {
        if (std::strcmp(left_arr[i], right_arr[j]) <= 0) {
            arr[k] = left_arr[i];
            i++;
        }
        else {
            arr[k] = right_arr[j];
            j++;
        }
        k++;
    }

    while (i < left_size) {
        arr[k] = left_arr[i];
        i++;
        k++;
    }

    while (j < right_size) {
        arr[k] = right_arr[j];
        j++;
        k++;
    }

    delete[] left_arr;
    delete[] right_arr;
}

void Show()
{
    // для int
    int size_int = 4;
    int* arr_int = new int[size_int] {5, 10, 9, 101};
    MyArray<int> myArray_int(arr_int, size_int);

    std::cout << "Before sorting int: \n";
    myArray_int.print();

    myArray_int.sort();

    std::cout << "After sorting int: \n";
    myArray_int.print();

    // для Fraction
    int size_frac = 3;
    Fraction* arr_frac = new Fraction[size_frac]{ Fraction(1, 2), Fraction(3, 4), Fraction(1, 3) };
    MyArray<Fraction> myArray_frac(arr_frac, size_frac);

    std::cout << "Before sorting Fraction: \n";
    myArray_frac.print();

    myArray_frac.sort();

    std::cout << "After sorting Fraction: \n";
    myArray_frac.print();

    // для string
    int size_str = 4;
    std::string* arr_str = new std::string[size_str]{ "5", "10", "9", "101" };
    MyArray<std::string> myArray_str(arr_str, size_str);

    std::cout << "Before sorting string: \n";
    myArray_str.print();

    myArray_str.sort();

    std::cout << "After sorting string: \n";
    myArray_str.print();

    // для char*
    int size_char = 4;
    char** arr_char = new char* [size_char];
    arr_char[0] = (char*)"5";
    arr_char[1] = (char*)"10";
    arr_char[2] = (char*)"9";
    arr_char[3] = (char*)"101";
    MyArray<char*> myArray_char(arr_char, size_char);

    std::cout << "Before sorting char*: \n";
    myArray_char.print();

    myArray_char.sort();

    std::cout << "After sorting char*: \n";
    myArray_char.print();

    // для double
    int size_double = 4;
    double* arr_double = new double[size_double] {5.2, 10.3, 9.5, 101.7};
    MyArray<double> myArray_double(arr_double, size_double);

    std::cout << "Before sorting double: \n";
    myArray_double.print();

    myArray_double.sort();

    std::cout << "After sorting double: \n";
    myArray_double.print();
}

void inputFractionArray(Fraction*& arr, int& size) {
    for (int i = 0; i < size; ++i) {
        int a = 0, b = 0;
        std::cout << "Enter numerator for fraction " << i + 1 << ": ";
        std::cin >> a;

        std::cout << "Enter denominator for fraction " << i + 1 << ": ";
        std::cin >> b;

        arr[i] = Fraction(a, b);
    }
}

void inputStringArray(std::string* arr, int& size) {
    for (int i = 0; i < size; ++i) {
        std::cout << "Enter string " << i + 1 << ": ";
        std::cin >> arr[i];
    }
}

int main() {
    int f = 0;
    while (true)
    {
        std::cout << "\tMenu\n"
            "1. Display information about the developer;\n"
            "2. An example of work for all possible types;\n"
            "3. Work with fractions;\n"
            "4. Work with dates;\n"
            "5. End the program\n"
            "Choose: ";
        std::cin >> f;
        switch (f)
        {
        case 1:
        {
            std::cout << "NAME: Lutsak Denis Vladimirovich\n"
                "Variant: 13\n"
                "Difficulty: B\n";
            break;
        }
        case 2:
        {
            Show();
            break;
        }
        case 3:
        {
            int size_frac = 0;
            std::cout << "Enter the number of fractions: ";
            std::cin >> size_frac;
            Fraction* arr_frac = new Fraction[size_frac];

            inputFractionArray(arr_frac, size_frac);

            MyArray<Fraction> myArray_frac(arr_frac, size_frac);

            std::cout << "Before sorting Fraction: \n";
            myArray_frac.print();

            myArray_frac.sort();

            std::cout << "After sorting Fraction: \n";
            myArray_frac.print();
            
            break;
        }
        case 4:
        {
            int size_str = 0;
            std::cout << "Enter the number of strings: ";
            std::cin >> size_str;
            std::string* arr_str = new std::string[size_str];

            inputStringArray(arr_str, size_str);

            MyArray<std::string> myArray_str(arr_str, size_str);

            std::cout << "Before sorting string: \n";
            myArray_str.print();

            myArray_str.sort();

            std::cout << "After sorting string: \n";
            myArray_str.print();

            break;
        }
        default:
            return 0;
        }
    }
}
