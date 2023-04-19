#pragma once
#include "Animal.h"
/**
 * @class Clownfish
 * @brief Represents a clownfish in the simulation.
 */
class Clownfish : public Animal {
    /**
     * @brief Randomly selects a new direction for the clownfish to move.
     */
    void ballotNewDir() override;

    /**
     * @brief Returns the type of the animal as a string.
     * @return The string "Clownfish".
     */
    std::string getType() const override;
public:
    /**
     * @brief Constructor for the Clownfish class.
     * @param name The name of the clownfish.
     * @param location The initial location of the clownfish.
     */
    Clownfish(const std::string& name, const Location& location);


};