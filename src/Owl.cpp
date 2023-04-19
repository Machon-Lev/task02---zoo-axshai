#include "Owl.h"
#include "Zoo.h"
#define OWL_SPEED 3

Owl::Owl(const std::string& name, const Location& location): Animal(name, location)
{
	steps = OWL_SPEED;
	ballotNewDir();
}


std::string Owl::getType() const
{
	return "Owl";
}

void Owl::ballotNewDir()
{
	// Owls can only move only diagonally - so the direction must be +/-1 , +/-1
	VerticalDirection verticalDir = (VerticalDirection)(-1 + (rand() % 2) *2 );
	HorizontalDirection horizontalDir = (HorizontalDirection)(-1 + (rand() % 2) * 2);
	direction = { verticalDir, horizontalDir };
}