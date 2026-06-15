#pragma once
#include <memory>
#include <cstdint>
#include <iostream>

template<typename T>
class Matrix
{
private:
	// A matrix should be immutable in dimensions once initialized
	// A new matrix should be made when needing to mutate dimensions
	const size_t number_of_rows;
	const size_t number_of_columns;
	std::unique_ptr<T[]> data;

public:

	Matrix<T>(size_t rows, size_t columns);
	Matrix<T>(T arr[], size_t row, size_t columns);

	// Basic operations
	T* operator[](size_t row_index) const;
	Matrix<T> operator*(const Matrix<T>& other) const;
	Matrix<T> operator*(double scalar) const;
	template<typename U>
	friend Matrix<U> operator*(double scalar, const Matrix<U>& mat);
	Matrix<T> operator+(const Matrix<T>& other) const;
	Matrix<T> operator-() const;
	Matrix<T> operator-(const Matrix<T>& other) const;
	bool operator==(const Matrix<T>& other) const;
	Matrix<T> transpose() const;

	template<typename U>
	friend std::ostream& operator<<(std::ostream& os, const Matrix<U>& mat);

	// Setters and getters
	size_t get_number_of_rows() const { return number_of_rows; }
	size_t get_number_of_columns() const { return number_of_columns; }
};

#include "Matrix.hpp"