#pragma once
#include "Tensor.h"

class Layer
{
private:
	Tensor<double> input_vector;
	Tensor<double>& output_vector;
	Tensor<double> weights;

public:
	Layer(size_t input_size, size_t number_of_neurons, Tensor<double>& out_vector) : 
		input_vector(input_size, 1), output_vector(out_vector), weights(number_of_neurons, input_size) { }
	virtual void apply_transformation() = 0;
	
};