#include<algorithm>
#include <string>
#include "Zoo.h"
#include "Clownfish.h"
#include "Owl.h"
#include "Shark.h"

// ==========non-members==========
/**
 @brief Converts a string to lower case.
 @param str The string to convert.
 @return The string in lower case.
 */
static std::string& toLower(std::string& str)
{
	std::transform(str.cbegin(), str.cend(),
		str.begin(), // write to the same location
		[](unsigned char c) { return std::tolower(c); });
	return str;
}
//===============================

AnimalType Zoo::strToAnimlaType(std::string type)
{
	int i;
	for (i = 0; i < knownAnimals.size(); i++)
	{
		if (knownAnimals[i] == toLower(type))
		{
			return (AnimalType)i;
		}
	}
	return (AnimalType)i;
}

std::string Zoo::stop(int animalIndex)
{
	if (0 > animalIndex || animalIndex >= animals.size())
	{
		return "index out of range";
	}
	animals[animalIndex]->stop();
	return "success";
}
std::string Zoo::move(int animalIndex)
{
	if (0 > animalIndex || animalIndex >= animals.size())
	{
		return "index out of range";
	}
	animals[animalIndex]->move();
	return "success";
}
std::string Zoo::create(AnimalType type, std::string name)
{
	switch (type)
	{
	case E_owl:
		animals.push_back(std::make_unique<Owl>(name, ballotNewLocation()));
		break;
	case E_clownfish:
		animals.push_back(std::make_unique<Clownfish>(name, ballotNewLocation()));
		break;
	case E_shark:
		animals.push_back(std::make_unique<Shark>(name, ballotNewLocation()));
		break;
	default:
		return "unsupported type";
	}
	return "success";

}
std::string Zoo::del(int animalIndex) 
{
	if (0 > animalIndex || animalIndex >= animals.size())
	{
		return "index out of range";
	}
	animals.erase(animals.begin() + animalIndex);
	return "success";
}
std::string Zoo::delAll(AnimalType type)
{
	char fLetter;
	switch (type)
	{
	case E_owl:
		fLetter = 'O';
		break;
	case E_clownfish:
		fLetter = 'C';
		break;
	case E_shark:
		fLetter = 'S';
		break;
	default:
		return "unsupported type";
	}
	animals.erase(std::remove_if(
		animals.begin(), animals.end(),
		[fLetter](const std::unique_ptr<Animal>& animal) {
			return animal->getInitial() == fLetter;
		}), animals.end());
	return "success";
}
void Zoo::help() const 
{
	std::string helpStr = R"(
menu: 
1. 'stop <animal index>' to make an animal to stop.
2. 'move <animal index>' to make an animal to move.
3. 'create <animal type> <animal name>' to create new animal.
4. 'del <animal index>' to delete an animal.
5. 'delAll <animal type>' to delete all animals of certain type.
6. 'help' to print this menu.
7. 'exit' to exit from the program.
8. '.' to advance to the next turn.)";
	std::cout << helpStr << "\n";
}
void Zoo::step() 
{
	for (auto& animal : animals)
	{
		animal->step();
	}
}
void Zoo::initZooVec()
{
	create(E_owl, "Hedwig");
	create(E_shark, "Jaws");
	create(E_clownfish, "Nemo");
}
void Zoo::printMap()
{
	std::cout << "ZOO MAP:\n";
	for (int r = 0; r < ROWS; r++)
	{
		for (int c = 0; c < COLUMNS; c++)
		{
			bool isCellFull = false;
			for (auto& animal : animals)
			{
				if (!isCellFull && animal->getLocation().row == r && animal->getLocation().column == c)
				{
					// the first animal we findwill be printed
					std::cout << animal->getInitial()<<" ";
					isCellFull = true;
				}
			}
			// if no animal in the cell - print '-'
			if (!isCellFull)
			{
				std::cout << "- ";
			}
		}
		std::cout << "\n";
	}
}
void Zoo::printList()
{
	int index = 0;
	std::cout << "ZOO LIST:\n";
	for (auto& animal : animals)
	{
		std::cout << index << ") ";
		animal->printDetails();
		index++;
	}
}
Location Zoo::ballotNewLocation()
{
	return Location{ rand() % ROWS, rand() % COLUMNS };
}

// ==========Public==========
void Zoo::run() 
{
	std::string userInput;
	int index;
	std::string type;
	std::string name;
	std::string res;
	bool isValidCmd;

	printMap();
	printList();
	
	std::cin >> userInput;
	while (toLower(userInput) != "exit")
	{
		isValidCmd = true;
		if (toLower(userInput) == "stop")
		{
			std::cin >> index;
			res = stop(index);
			std::cout << res << "\n";

		}
		else if (toLower(userInput) == "create")
		{
			std::cin >> type;
			std::cin >> name;
			res = create(strToAnimlaType(type), name);
			std::cout << res << "\n";
		}
		else if (toLower(userInput) == "move")
		{
			std::cin >> index;
			res = move(index);
			std::cout << res << "\n";
		}
		else if (toLower(userInput) == "del")
		{
			std::cin >> index;
			res = del(index);
			std::cout << res << "\n";
		}
		else if (toLower(userInput) == "delall")
		{
			std::cin >> type;
			res = delAll(strToAnimlaType(type));
			std::cout << res << "\n";
		}
		else if (toLower(userInput) == "help")
		{
			help();
		}
		// '.' means to advance turn, which happens anyway with every legal command
		// so no action needs to be taken now.
		else if (toLower(userInput) == "."){}
		else
		{
			std::cout<<"unsupported command\n";
			isValidCmd = false;
		}
		// Do not advance turn untill getting valid command
		if (isValidCmd)
		{
			step();
			printMap();
			printList();
		}
		std::cin >> userInput;
	}
}

Zoo::Zoo()
{ 
	initZooVec(); 
}

