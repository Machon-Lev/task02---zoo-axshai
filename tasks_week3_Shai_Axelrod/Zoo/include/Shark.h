#pragma once
#include "Animal.h"
/**
 * @class Shark
 * @brief Represents a Shark in the simulation.
 */
class Shark : public Animal {
    /**
      * @brief Returns the type of the animal as a string.
      * @return The string "Shark".
    */
	std::string getType() const override;
    /**
     * @brief Randomly selects a new direction for the Shark to move.
     */
	void ballotNewDir() override;
public:
    /**
     * @brief Constructor for the Shark class.
     * @param name The name of the Shark.
     * @param location The initial location of the Shark.
    */
	Shark(const std::string& name, const Location& location);
};
