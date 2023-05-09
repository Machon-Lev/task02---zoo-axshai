#include "Clownfish.h"
#include "Zoo.h"
#define CLOWNFISH_SPEED 1
Clownfish::Clownfish(const std::string& name, const Location& location) : Animal(name, location)
{
	steps = CLOWNFISH_SPEED;
	ballotNewDir();
}

std::string Clownfish::getType() const
{
	return "Clownfish";
}

void Clownfish::ballotNewDir()
{
	VerticalDirection verticalDir;
	HorizontalDirection horizontalDir;
	do
	{
		// verticalDir and horizontalDir can be -1, 0 ,1 (see Vertical and HorizontalDirection enums.)
		verticalDir = (VerticalDirection)(rand() % 3 - 1);
		horizontalDir = (HorizontalDirection)(rand() % 3 - 1);
	} while (verticalDir == VNone && horizontalDir == HNone); // verify that the direction isnt 0,0 (witch means no move)
	direction = { verticalDir, horizontalDir };
}