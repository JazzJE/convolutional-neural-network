#pragma once
#include "Tensor.h"

class Layer
{
protected:
	Tensor<double>& input_matrix;
	Tensor<double> output_matrix;
	Tensor<double> weights;

public:
	Layer(size_t input_size, size_t number_of_neurons, Tensor<double>& in_matrix) : 
		input_matrix(in_matrix), weights(number_of_neurons, input_size) { }
	virtual void apply_transformation() = 0;

	// setters/getters
	Tensor<double>& get_ref_to_input_vector() { return input_vector; }
	
};