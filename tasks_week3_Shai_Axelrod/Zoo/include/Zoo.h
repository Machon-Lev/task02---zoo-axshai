#pragma once
#include "Animal.h"
#include <vector>

#define ROWS 20
#define COLUMNS 40
enum AnimalType {
#define ANIMAL(a) E_##a
#include "AnimalTypes.h"
	E_unsupported,
	E_supported_animals_num = E_unsupported,
#undef ANIMAL(a)
};

/**
 * @class Zoo
 * @brief manages the whole zoo.
 */
class Zoo {
private:
	const std::vector<std::string> knownAnimals = {
#define ANIMAL(a) #a
#include "AnimalTypes.h" 
#undef ANIMAL(a)
	};
    /**
     * @brief Converts a string to an AnimalType.
     * @param type The string to convert.
     * @return The corresponding AnimalType.
     */
    AnimalType strToAnimlaType(std::string type);

    std::vector<std::unique_ptr<Animal>> animals; /**< A vector of unique pointers to Animal objects. */

    /**
     * @brief Stops the animal at the specified index.
     * @param animalIndex The index of the animal to stop.
     * @return A message indicating whether the stop operation was successful.
     */
    std::string stop(int animalIndex);

    /**
     * @brief Moves the animal at the specified to move mode.
     * @param animalIndex The index of the animal to move.
     * @return A message indicating whether the move operation was successful.
     */
    std::string move(int animalIndex);

    /**
     * @brief Creates a new animal of the specified type and name.
     * @param type The type of the animal to create.
     * @param name The name of the new animal.
     * @return A message indicating whether the creation operation was successful.
     */
    std::string create(AnimalType type, std::string name);

    /**
     * @brief Deletes the animal at the specified index.
     * @param animalIndex The index of the animal to delete.
     * @return A message indicating whether the deletion operation was successful.
     */
    std::string del(int animalIndex);

    /**
     * @brief Deletes all animals of the specified type.
     * @param type The type of animals to delete.
     * @return A message indicating whether the deletion operation was successful.
     */
    std::string delAll(AnimalType type);

    /**
     * @brief Prints a list of available commands and their descriptions.
     */
    void help() const;

    /**
     * @brief Moves all animals one step.
     */
    void step();

    /**
     * @brief Initializes the zoo vector with default animals.
     */
    void initZooVec();

    /**
     * @brief Prints a map of the zoo, showing the locations of all animals.
     */
    void printMap();

    /**
     * @brief Prints a list of all animals in the zoo.
     */
    void printList();

    /**
     * @brief Randomly generates a new location for an animal.
     * @return A new, randomly generated location.
     */
    Location ballotNewLocation();

public:
    /**
     * @brief Runs the main loop of the zoo simulation.
     */
    void run();
    /**
     * @brief Zoo ctor.
     */
    Zoo();
};




