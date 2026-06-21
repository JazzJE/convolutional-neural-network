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

namespace GameConfigs
{
	// Game dimensions and init positions
	constexpr size_t GAME_WIDTH = 300;
	constexpr size_t GAME_HEIGHT = 300;

	// Playable sprite dimensions and variables
	constexpr size_t PADDLE_WIDTH = 5;
	constexpr size_t PADDLE_HEIGHT = 50;
	constexpr size_t PADDLE_SPEED = 0;
	constexpr size_t SPAWN_OFFSET = 10;

	// Ball attributes
	constexpr size_t BALL_WIDTH = 8;
	constexpr size_t BALL_HEIGHT = 8;
	constexpr size_t INIT_BALL_DX = 10;
	constexpr size_t MAX_BALL_DY = 10;
	constexpr int MIN_BALL_DY = -1 * MAX_BALL_DY;
};