#pragma once
#include "Tensor.h"

// The image processor will grayscale every pixel and add a predefined amount of padding to its image buffer
struct ImageProcessor
{
	const size_t PADDING_AMOUNT;
	size_t height;
	size_t width;
	Tensor<double> image_buffer;

	ImageProcessor(size_t PAD_AMT, size_t img_height, size_t image_width);

	void grayscale_and_store_image(const char* data);
	Tensor<double>& get_image_buffer() { return image_buffer; }
};