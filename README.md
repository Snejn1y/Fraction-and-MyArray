# Fraction and MyArray

This code provides implementations for the `Fraction` and `MyArray` classes. The `Fraction` class represents a mathematical fraction, and the `MyArray` class is a templated array implementation that supports sorting.

## Fraction Class

The `Fraction` class provides the following functionality:

- `Fraction()`: Default constructor that sets the numerator to 0 and the denominator to 1.
- `Fraction(int num, int denom)`: Constructor that sets the numerator and denominator to the given values and simplifies the fraction.
- `operator+`, `operator-`, `operator*`, `operator/`: Overloaded arithmetic operators for performing addition, subtraction, multiplication, and division on fractions.
- `operator==`, `operator!=`, `operator<`, `operator>`, `operator<=`, `operator>=`: Overloaded comparison operators for comparing fractions.
- `operator+` (with integer): Overloaded addition operator for adding an integer to a fraction.
- `operator-` (with integer): Overloaded subtraction operator for subtracting an integer from a fraction.
- `operator*` (with integer): Overloaded multiplication operator for multiplying a fraction by an integer.
- `operator/` (with integer): Overloaded division operator for dividing a fraction by an integer.
- `simplify()`: Function that simplifies the fraction by dividing both the numerator and denominator by their greatest common divisor (GCD).
- `gcd(int a, int b)`: Function that calculates the GCD of two integers.
- `operator<<`: Overloaded stream insertion operator for printing a fraction.

## MyArray Class

The `MyArray` class is a templated array implementation that supports sorting using the merge sort algorithm. It provides the following functionality:

- `MyArray(T* arr, int size)`: Constructor that initializes the array with the given values and size.
- `~MyArray()`: Destructor that frees the dynamically allocated memory for the array.
- `sort()`: Sorts the array in ascending order using the merge sort algorithm.
- `print() const`: Prints the elements of the array.
- `merge(int left, int mid, int right)`: Helper function for merging two sorted subarrays during the merge sort.
- `mergeSort(int left, int right)`: Recursive function for performing the merge sort algorithm.
- Specialization for `char*` arrays.

## Example Usage

The code also provides an example usage of the `Fraction` and `MyArray` classes in the `main` function. It demonstrates sorting arrays of different types, such as `int`, `Fraction`, `std::string`, `char*`, and `double`. It also includes options to work with fractions and strings separately, allowing the user to input values and sort the arrays.

### Menu Options

The `main` function presents a menu with the following options:

1. Display information about the developer.
2. Run an example of work for all possible types.
3. Work with fractions.
4. Work with dates.
5. End the program.

Depending on the selected option, the program executes the corresponding functionality.

---

This is the overview of the provided code and its functionalities. Feel free to explore and modify it as needed.
