#pragma once

enum  VerticalDirection
{
	Up = -1,
	VNone = 0,
	Down = 1,
};

enum  HorizontalDirection
{
	Left = -1,
	HNone = 0,
	Right = 1,
};

/**
 * @struct Direction
 * @brief Represents a direction in the zoo simulation.
 */
struct Direction {
	VerticalDirection vertical;
	HorizontalDirection horizontal;
};