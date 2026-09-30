#include <iostream>
#include "GameCharacter.h"

int main()
{
    std::cout << "=== Creating characters ===" << std::endl;

    GameCharacter character1;

    CharacterStats PyromancerStats = {10, 12, 11, 12, 9, 12, 10, 8};

    GameCharacter character2(
        "Astolfo",
        1,
        200,
        50.0,
        PyromancerStats
    );

    GameCharacter character3(character2);

    std::cout << "\nNumber of existing objects: " << GameCharacter::getObjectCount() << std::endl;



    std::cout << "\n=== Initial state ===" << std::endl;

    std::cout << "\nCharacter 1:" << std::endl;
    character1.printInfo();

    std::cout << "\nCharacter 2:" << std::endl;
    character2.printInfo();

    std::cout << "\nCharacter 3:" << std::endl;
    character3.printInfo();


    
    std::cout << "\n=== Correct operations ===" << std::endl;

    character1.takeDamage(30);
    character1.heal(10);
    character1.gainExperience(50);
    character1.increaseStrength(5);

    character2.takeDamage(70);
    character2.gainExperience(260);

    std::cout << "\nCharacter 1 after operations:" << std::endl;
    character1.printInfo();

    std::cout << "\nCharacter 2 after operations:" << std::endl;
    character2.printInfo();



    std::cout << "\n=== Incorrect operations ===" << std::endl;

    try
    {
        character1.takeDamage(-50);
    }
    catch (const std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    try
    {
        character1.heal(-20);
    }
    catch (const std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    try
    {
        character1.gainExperience(-10);
    }
    catch (const std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    try
    {
        character1.increaseStrength(-5);
    }
    catch (const std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }



    std::cout << "\n=== State after incorrect operations ===" << std::endl;

    character1.printInfo();



    std::cout << "\n=== Independence test ===" << std::endl;

    std::cout << "Before changing Character 1:" << std::endl;

    std::cout << "\nCharacter 1:" << std::endl;
    character1.printInfo();

    std::cout << "\nCharacter 2:" << std::endl;
    character2.printInfo();

    character1.takeDamage(20);
    character1.increaseStrength(100);

    std::cout << "\nAfter changing Character 1:" << std::endl;

    std::cout << "\nCharacter 1:" << std::endl;
    character1.printInfo();

    std::cout << "\nCharacter 2:" << std::endl;
    character2.printInfo();



    std::cout << "\n=== Object counter ===" << std::endl;

    std::cout << "Existing objects: "
              << GameCharacter::getObjectCount()
              << std::endl;

    return 0;
}