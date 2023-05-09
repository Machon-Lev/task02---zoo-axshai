#include "Animal.h"
#include <Zoo.h>

Animal::Animal(const std::string& name, const Location& location): name(name), location(location), inMoveMode(true)
{}

void Animal::printDetails() const
{
	std::cout << "Name: " << name << " Type: " << getType() << " Location: " << location << std::endl;
}

char Animal::getInitial() const
{
	return getType()[0];
}

Location Animal::getLocation() const
{
	return location;
}

void Animal::step()
{
	if (!(this->inMoveMode))
		return;
	Location move = { direction.vertical * steps, direction.horizontal * steps };
	// When the animal reaches the end of the table, it has to change direction accordingly. 
	if ((location + move).row >= ROWS || (location + move).row < 0)
	{
		turnVertically();
		move.row = direction.vertical * steps;
	}
	if ((location + move).column >= COLUMNS || (location + move).column < 0)
	{
		turnHorizontally();
		move.column = direction.horizontal * steps;
	}

	location += move;

}

void Animal::stop()
{
	inMoveMode = false;
}

void Animal::move()
{ 
	// When switching from stop to moveMode - need to ballot 
	// need to ballot a new direction.
	if (!inMoveMode)
	{
		ballotNewDir();
		inMoveMode = true;
	}
}

void Animal::turnVertically()
{
	direction.vertical = (VerticalDirection)(direction.vertical * -1);

}

void Animal::turnHorizontally()
{
	direction.horizontal = (HorizontalDirection)(direction.horizontal * -1);
}
