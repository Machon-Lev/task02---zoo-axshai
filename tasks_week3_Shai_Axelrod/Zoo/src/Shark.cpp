#include "Shark.h"
#include "Zoo.h"
#define SHARK_SPEED 5
Shark::Shark(const std::string& name, const Location& location): Animal(name, location)
{
	steps = SHARK_SPEED;
	ballotNewDir();
}


std::string Shark::getType() const
{
	return "Shark";
}

void Shark::ballotNewDir()
{
	VerticalDirection verticalDir;
	HorizontalDirection horizontalDir;
	do
	{
		// verticalDir and horizontalDir can be -1, 0 ,1 (see Vertical and HorizontalDirection enums.)
		verticalDir = (VerticalDirection)(rand() % 3 - 1);
		horizontalDir = (HorizontalDirection)(rand() % 3 - 1);
	} while (verticalDir == VNone && horizontalDir == HNone);  // verify that the direction isnt 0,0 (witch means no move)
	direction = { verticalDir, horizontalDir };
}