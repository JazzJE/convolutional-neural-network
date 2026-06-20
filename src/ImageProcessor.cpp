#include "ImageProcessor.h"

ImageProcessor::ImageProcessor(size_t PAD_AMT, size_t image_height, size_t image_width) : PADDING_AMOUNT(PAD_AMT), 
height(image_height), width(image_width), 

// The number of rows will be the height of the image + 2 * the padding amount for either top or bottom of the image
// The number of columns will be the width of the image + 2 * the padding amount for either right or left of the image
image_buffer(2 * PAD_AMT + image_height, 2 * PAD_AMT + image_width)
{ }

void ImageProcessor::grayscale_and_store_image(const char* data)
{
	// Skip the first (PADDING_AMOUNT) rows and start loading data from there
	for (size_t row_index = PADDING_AMOUNT; row_index < PADDING_AMOUNT + height; ++row_index)
		for (size_t column_index = PADDING_AMOUNT; column_index < PADDING_AMOUNT + width; ++column_index)
			image_buffer[row_index][column_index] = data[(row_index - PADDING_AMOUNT) * width + (column_index - PADDING_AMOUNT)];
}