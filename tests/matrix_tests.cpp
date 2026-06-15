#include <iostream>
#include "Matrix.h"

void print_separator(const std::string& name)
{
    std::cout << "\n==================== " << name << " ====================\n";
}

void test_constructor()
{
    print_separator("Constructor Test");

    double arr[] = {
        1, 2, 3,
        4, 5, 6
    };

    Matrix<double> m(arr, 2, 3);

    std::cout << "Matrix m:\n";
    std::cout << m << std::endl << m[1][2];
}

void test_addition()
{
    print_separator("Addition Test");

    double a[] = { 1, 2, 3, 4 };
    double b[] = { 5, 6, 7, 8 };

    Matrix<double> A(a, 2, 2);
    Matrix<double> B(b, 2, 2);

    Matrix<double> C = A + B;

    std::cout << "A:\n" << A;
    std::cout << "B:\n" << B;
    std::cout << "A + B:\n" << C;
}

void test_scalar()
{
    print_separator("Scalar Multiplication Test");

    double a[] = { 1, 2, 3, 4 };

    Matrix<double> A(a, 2, 2);

    std::cout << "A:\n" << A;

    Matrix<double> B = A * 3.0;

    std::cout << "A * 3:\n" << B;

    Matrix<double> C = 3.0 * A;

    std::cout << "3 * A:\n" << C;
}

void test_matrix_multiplication()
{
    print_separator("Matrix Multiplication Test");

    double a[] = {
        1, 2,
        3, 4
    };

    double b[] = {
        2, 0,
        1, 2
    };

    Matrix<double> A(a, 2, 2);
    Matrix<double> B(b, 2, 2);

    Matrix<double> C = A * B;

    std::cout << "A:\n" << A;
    std::cout << "B:\n" << B;
    std::cout << "A * B:\n" << C;
}

void test_negation_subtraction()
{
    print_separator("Negation + Subtraction Test");

    double a[] = { 1, -2, 3, -4 };
    double b[] = { 5, 6, 7, 8 };

    Matrix<double> A(a, 2, 2);
    Matrix<double> B(b, 2, 2);

    std::cout << "A:\n" << A;
    std::cout << "-A:\n" << -A;

    std::cout << "B:\n" << B;
    std::cout << "B - A:\n" << (B - A);
}

void test_transpose()
{
    print_separator("Transpose Test");

    double a[] = {
        1, 2, 3,
        4, 5, 6
    };

    Matrix<double> A(a, 2, 3);

    std::cout << "A:\n" << A;
    std::cout << "A^T:\n" << A.transpose();
}

void test_equality()
{
    print_separator("Equality Test");

    double a[] = { 1, 2, 3, 4 };
    double b[] = { 1, 2, 3, 4 };
    double c[] = { 1, 2, 3, 5 };

    Matrix<double> A(a, 2, 2);
    Matrix<double> B(b, 2, 2);
    Matrix<double> C(c, 2, 2);

    std::cout << "A == B: " << (A == B) << "\n";
    std::cout << "A == C: " << (A == C) << "\n";
}

void run_matrix_tests()
{
    test_constructor();
    test_addition();
    test_scalar();
    test_matrix_multiplication();
    test_negation_subtraction();
    test_transpose();
    test_equality();
}