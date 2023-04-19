#pragma once
#include "Animal.h"
/**
 * @class Owl
 * @brief Represents an owl in the simulation.
 */
class Owl : public Animal {

    /**
     * @brief Returns the type of the animal as a string.
     * @return The string "Owl".
     */
    std::string getType() const override;

    /**
     * @brief Randomly selects a new direction for the owl to move.
     * Owls can only move only diagonally.
     */
    void ballotNewDir() override;
public:
    /**
     * @brief Constructor for the Owl class.
     * @param name The name of the owl.
     * @param location The initial location of the owl.
     */
    Owl(const std::string& name, const Location& location);


};