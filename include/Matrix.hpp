#include <iomanip>
#include <string>

#include "Matrix.h"

template<typename T>
Matrix<T>::Matrix(size_t rows, size_t columns) : number_of_rows(rows), number_of_columns(columns), 
	data(std::make_unique<T[]>(number_of_rows * number_of_columns)) { }

template<typename T>
Matrix<T>::Matrix(T arr[], size_t rows, size_t columns) : number_of_rows(rows), number_of_columns(columns),
	data(std::make_unique<T[]>(number_of_rows * number_of_columns))
{
	for (size_t array_index = 0; array_index < number_of_rows * number_of_columns; ++array_index)
		data[array_index] = arr[array_index];
}

template<typename T>
T* Matrix<T>::operator[](size_t row_index) const
{ return (data.get() + row_index * number_of_columns); }

template<typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& other) const
{
	// Number of columns should equal to the number of rows for matrix multiplication
	if (number_of_columns != other.number_of_rows)
		throw std::logic_error("The number of columns, " + std::to_string(number_of_columns) 
			+ ", should equal to the other number of rows, " + std::to_string(other.number_of_rows));

	Matrix<T> product(number_of_rows, other.number_of_columns);

	for (size_t row_index = 0; row_index < number_of_rows; ++row_index)
		for (size_t column_index = 0; column_index < other.number_of_columns; ++column_index)
			for (size_t sum_index = 0; sum_index < number_of_columns; ++sum_index)
				product.data[row_index * other.number_of_columns + column_index] +=
					data[row_index * number_of_columns + sum_index] *  
					other.data[sum_index * other.number_of_columns + column_index];

	return product;
}

template<typename T>
Matrix<T> Matrix<T>::operator*(double scalar) const
{
	Matrix<T> product(number_of_rows, number_of_columns);
	
	for (size_t i = 0; i < number_of_rows * number_of_columns; ++i)
		product.data[i] = data[i] * scalar;

	return product;
}

template<typename U>
Matrix<U> operator*(double scalar, const Matrix<U>& mat)
{ return mat * scalar; }

template<typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& other) const
{
	if (number_of_rows != other.number_of_rows)
		throw std::logic_error("The number of rows, " + std::to_string(number_of_rows) +
			", are not equal to the other number of rows, " + std::to_string(other.number_of_rows));
	if (number_of_columns != other.number_of_columns)
		throw std::logic_error("The number of columns, " + std::to_string(number_of_columns) 
			+ ", are not equal to the other number of columns, " + std::to_string(other.number_of_columns));

	Matrix sum(number_of_rows, number_of_columns);

	for (size_t i = 0; i < number_of_rows * number_of_columns; ++i)
		sum.data[i] = data[i] + other.data[i];

	return sum;
}

template<typename T>
Matrix<T> Matrix<T>::operator-() const
{ return (*this) * -1; }

template<typename T>
Matrix<T> Matrix<T>::operator-(const Matrix<T>& other) const
{ return (*this) + -other; }

template<typename T>
bool Matrix<T>::operator==(const Matrix<T>& other) const
{
	if (number_of_rows != other.number_of_rows || number_of_columns != other.number_of_columns)
		return false;

	for (size_t i = 0; i < number_of_rows * number_of_columns; ++i)
		if (data[i] != other.data[i])
			return false;

	return true;
}

template<typename T>
Matrix<T> Matrix<T>::transpose() const
{
	Matrix<T> transpose(number_of_columns, number_of_rows);

	for (size_t row_index = 0; row_index < number_of_rows; ++row_index)
		for (size_t column_index = 0; column_index < number_of_columns; ++column_index)
			transpose.data[column_index * number_of_rows + row_index] = data[row_index * number_of_columns + column_index];

	return transpose;
}

template<typename U>
std::ostream& operator<<(std::ostream& os, const Matrix<U>& mat)
{
	size_t number_of_rows = mat.get_number_of_rows(); 
	size_t number_of_columns = mat.get_number_of_columns();

	for (size_t row_index = 0; row_index < number_of_rows; ++row_index)
	{	
		os << std::fixed << std::setprecision(4);
		os << "| ";
		for (size_t column_index = 0; column_index < number_of_columns; ++column_index)
			os << std::setw(7) << mat[row_index][column_index] << " ";
		os << "|\n";
	}

	return os;
}