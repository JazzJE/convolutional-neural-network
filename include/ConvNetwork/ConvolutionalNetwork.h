#pragma once
#include "Tensor.h"
#include "Configs.h"

class ConvolutionalNetwork
{
private:

	const ConfigTypes::LayerTypes layer_array[];

public:
	
	ConvolutionalNetwork();

	// Inference methods
	void forward_propagate();
	double return_prediction();

	// Training methods
	void forward_propagate_with_dropout();
	void backpropagate_gradient();

};