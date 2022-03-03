#include <iostream>
#include "AMateria.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int		main(void)
{
	AMateria	*ice = new Ice();
	std::cout << ice->getType() << std::endl;
	AMateria	*ice2 = new Ice();
	AMateria	*ice3 = new Ice();
	AMateria	*cure = new Cure();
	Character	*character = new Character("Bert");
	Character	*character2 = new Character("Sjaak");

	std::cout << character->getName() << std::endl << std::endl;

	character->equip(NULL);
	character->equip(ice);
	character->equip(ice);
	character->unequip(2);
	character->unequip(1);
	character->unequip(0);

	std::cout << std::endl;

	character->use(4, *character2);

	character->equip(ice);
	character->equip(ice2);
	character->equip(ice3);
	character->unequip(1);
	character->equip(ice2);
	character->equip(cure);

	std::cout << std::endl;

	for (int i = 0; i < 4; i++)
		character->use(i, *character2);
	delete character;
	delete character2;

	std::cout << std::endl;

	character = new Character("Harry");
	character->equip(new Ice());
	character->equip(new Cure());
	character->equip(new Cure());
	character->equip(new Ice());
	character2 = new Character("Menno");
	character2->equip(new Cure());

	std::cout << std::endl;
	*character2 = *character;
	std::cout << std::endl;

	std::cout << ">>> Deleting char2" << std::endl;
	delete character2;
	std::cout << std::endl;
	std::cout << ">>> Deleting char" << std::endl;
	delete character;

	IMateriaSource *src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter *me = new Character("me");

	AMateria *tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter *bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	std::cout << "ik hier" << std::endl;
	delete src;

	// Uncomment the next line to check for leaks!
	// while(1);
}
