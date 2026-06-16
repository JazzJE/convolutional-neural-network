#pragma once
#include <memory>
#include <cstdint>
#include <iostream>

template<typename T>
class Tensor
{
private:
	// A matrix should be immutable in dimensions once initialized
	// A new matrix should be made when needing to mutate dimensions
	const size_t number_of_rows;
	const size_t number_of_columns;
	std::unique_ptr<T[]> data;

public:

	Tensor<T>(size_t rows, size_t columns);
	Tensor<T>(T arr[], size_t row, size_t columns);

	// Basic operations
	T* operator[](size_t row_index) const;
	Tensor<T> operator*(const Tensor<T>& other) const;
	Tensor<T> operator*(double scalar) const;
	template<typename U>
	friend Tensor<U> operator*(double scalar, const Tensor<U>& mat);
	Tensor<T> operator+(const Tensor<T>& other) const;
	Tensor<T> operator-() const;
	Tensor<T> operator-(const Tensor<T>& other) const;
	bool operator==(const Tensor<T>& other) const;
	Tensor<T> transpose() const;

	template<typename U>
	friend std::ostream& operator<<(std::ostream& os, const Tensor<U>& mat);

	// Setters and getters
	size_t get_number_of_rows() const { return number_of_rows; }
	size_t get_number_of_columns() const { return number_of_columns; }
};

#include "Tensor.hpp"