#include <iostream>
#include "Tensor.h"

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

    Tensor<double> m(arr, 2, 3);

    std::cout << "Matrix m:\n";
    std::cout << m << std::endl << m[1][2];
}

void test_addition()
{
    print_separator("Addition Test");

    double a[] = { 1, 2, 3, 4 };
    double b[] = { 5, 6, 7, 8 };

    Tensor<double> A(a, 2, 2);
    Tensor<double> B(b, 2, 2);

    Tensor<double> C = A + B;

    std::cout << "A:\n" << A;
    std::cout << "B:\n" << B;
    std::cout << "A + B:\n" << C;
}

void test_scalar()
{
    print_separator("Scalar Multiplication Test");

    double a[] = { 1, 2, 3, 4 };

    Tensor<double> A(a, 2, 2);

    std::cout << "A:\n" << A;

    Tensor<double> B = A * 3.0;

    std::cout << "A * 3:\n" << B;

    Tensor<double> C = 3.0 * A;

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

    Tensor<double> A(a, 2, 2);
    Tensor<double> B(b, 2, 2);

    Tensor<double> C = A * B;

    std::cout << "A:\n" << A;
    std::cout << "B:\n" << B;
    std::cout << "A * B:\n" << C;
}

void test_negation_subtraction()
{
    print_separator("Negation + Subtraction Test");

    double a[] = { 1, -2, 3, -4 };
    double b[] = { 5, 6, 7, 8 };

    Tensor<double> A(a, 2, 2);
    Tensor<double> B(b, 2, 2);

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

    Tensor<double> A(a, 2, 3);

    std::cout << "A:\n" << A;
    std::cout << "A^T:\n" << A.transpose();
}

void test_equality()
{
    print_separator("Equality Test");

    double a[] = { 1, 2, 3, 4 };
    double b[] = { 1, 2, 3, 4 };
    double c[] = { 1, 2, 3, 5 };

    Tensor<double> A(a, 2, 2);
    Tensor<double> B(b, 2, 2);
    Tensor<double> C(c, 2, 2);

    std::cout << "A == B: " << (A == B) << "\n";
    std::cout << "A == C: " << (A == C) << "\n";
}

void test_copy_constructor()
{
    print_separator("Copy Constructor Test");

    double entries[] = { 1, 2, 3, 4 };

    Tensor<double> A(entries, 2, 2);
    Tensor<double> B(A);

    std::cout << "Original:\n" << A;
    std::cout << "Copy:\n" << B;

    B[0][0] = 100;

    std::cout << "After modifying copy:\n";
    std::cout << "Original[0][0]: " << A[0][0] << "\n";
    std::cout << "Copy[0][0]: " << B[0][0] << "\n";
}

void test_copy_assignment()
{
    print_separator("Copy Assignment Test");

    double a[] = { 1, 2, 3, 4 };
    double b[] = { 5, 6, 7, 8 };

    Tensor<double> A(a, 2, 2);
    Tensor<double> B(b, 2, 2);

    std::cout << "Before assignment:\n";
    std::cout << "A:\n" << A;
    std::cout << "B:\n" << B;

    B = A;

    std::cout << "\nAfter B = A:\n";
    std::cout << "A:\n" << A;
    std::cout << "B:\n" << B;

    B[0][0] = 999;

    std::cout << "\nAfter modifying B:\n";
    std::cout << "A[0][0]: " << A[0][0] << "\n";
    std::cout << "B[0][0]: " << B[0][0] << "\n";
}

void test_self_copy_assignment()
{
    print_separator("Self Copy Assignment Test");

    double entries[] = { 1, 2, 3, 4 };

    Tensor<double> A(entries, 2, 2);

    std::cout << "Before A = A:\n" << A;

    A = A;

    std::cout << "After A = A:\n" << A;
}

void test_move_constructor()
{
    print_separator("Move Constructor Test");

    double entries[] = { 1, 2, 3, 4 };

    Tensor<double> A(entries, 2, 2);

    std::cout << "Before move:\n";
    std::cout << "A:\n" << A;

    Tensor<double> B(std::move(A));

    std::cout << "\nMoved tensor B:\n";
    std::cout << B;
}

void test_move_assignment()
{
    print_separator("Move Assignment Test");

    double a[] = { 1, 2, 3, 4 };
    double b[] = { 9, 9, 9, 9 };

    Tensor<double> A(a, 2, 2);
    Tensor<double> B(b, 2, 2);

    std::cout << "Before move assignment:\n";
    std::cout << "A:\n" << A;
    std::cout << "B:\n" << B;

    B = std::move(A);

    std::cout << "\nAfter B = std::move(A):\n";
    std::cout << "B:\n" << B;
}

void test_self_move_assignment()
{
    print_separator("Self Move Assignment Test");

    double entries[] = { 1, 2, 3, 4 };

    Tensor<double> A(entries, 2, 2);

    std::cout << "Before self move:\n";
    std::cout << A;

    A = std::move(A);

    std::cout << "\nAfter A = std::move(A):\n";
    std::cout << A;
}

void test_chained_assignment()
{
    print_separator("Chained Assignment Test");

    double a[] = { 1, 1, 1, 1 };
    double b[] = { 2, 2, 2, 2 };
    double c[] = { 3, 3, 3, 3 };

    Tensor<double> A(a, 2, 2);
    Tensor<double> B(b, 2, 2);
    Tensor<double> C(c, 2, 2);

    std::cout << "Before assignment:\n";
    std::cout << "A:\n" << A;
    std::cout << "B:\n" << B;
    std::cout << "C:\n" << C;

    A = B = C;

    std::cout << "\nAfter A = B = C:\n";
    std::cout << "A:\n" << A;
    std::cout << "B:\n" << B;
    std::cout << "C:\n" << C;
}

void test_flatten()
{
    print_separator("Flatten Test");

    double entries[] =
    {
         1,  2,  3,  4,  5,
         6,  7,  8,  9, 10,
        11, 12, 13, 14, 15,
        16, 17, 18, 19, 20
    };

    Tensor<double> A(entries, 4, 5);

    std::cout << "Original:\n" << A << "\n";

    Tensor<double> B = A.flatten();

    std::cout << "Flattened:\n" << B << "\n";

    std::cout << "Rows: " << B.get_number_of_rows() << "\n";
    std::cout << "Columns: " << B.get_number_of_columns() << "\n";
}

void run_matrix_tests()
{
    test_constructor();
    test_addition();
    test_scalar();
    test_matrix_multiplication();
    test_negation_subtraction();
    test_transpose();
    test_flatten();
    test_equality();

    test_copy_constructor();
    test_copy_assignment();
    test_self_copy_assignment();
    test_move_constructor();
    test_move_assignment();
    test_self_move_assignment();
    test_chained_assignment();
}