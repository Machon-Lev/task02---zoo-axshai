#pragma once
#include "Location.h"
#include "Direction.h"
/**
 * @class Animal
 * @brief Represents an animal in the simulation.
 */
class Animal {
protected:
    int steps; /**< The number of steps the takes in each move. */
    std::string name; /**< The name of the animal. */
    Location location; /**< The current location of the animal. */
    bool inMoveMode; /**< Whether the animal is currently in move mode. */
    Direction direction; /**< The direction the animal is facing. */

    /**
     * @brief Returns the type of the animal.
     * @return The type of the animal as a string.
     */
    virtual std::string getType() const = 0;

    /**
     * @brief Randomly selects a new direction for the animal to move.
     */
    virtual void ballotNewDir() = 0;

public:
    /**
     * @brief Constructor for the Animal class.
     * @param name The name of the animal.
     * @param location The initial location of the animal.
     */
    Animal(const std::string& name, const Location& location);

    /**
     * @brief Prints the details of the animal.
     */
    void printDetails() const;

    /**
     * @brief Returns the initial of the animal's name.
     * @return The initial of the animal's name as a character.
     */
    char getInitial() const;

    /**
     * @brief Returns the current location of the animal.
     * @return The current location of the animal.
     */
    Location getLocation() const;

    /**
     * @brief Moves the animal one step in its current direction.
     */
    void step();

    /**
     * @brief Stops the animal's movement.
     */
    void stop();

    /**
     * @brief Puts the animal into move mode.
     */
    void move();

    /**
     * @brief Turns the animal vertically (up or down).
     */
    void turnVertically();

    /**
     * @brief Turns the animal horizontally (left or right).
     */
    void turnHorizontally();
};
