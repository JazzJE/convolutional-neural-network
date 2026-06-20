#pragma once

namespace ConfigTypes
{
	enum LayerTypes
	{
		FORWARDLAYER,
		MAXPOOLLAYER,
		SOFTMAXLAYER,
		CONVLAYER,
	};

	// Note that the dimensions of each kernel should be an odd number
	// The number will produce an n x n kernel
	enum KernelSizes
	{
		SMALL = 3,
		LARGE = 5,
	};
}