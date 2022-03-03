#include "PowerFist.hpp"
#include "PlasmaRifle.hpp"
#include "Boomerang.hpp"
#include "SuperMutant.hpp"
#include "RadScorpion.hpp"
#include "ShieldKnight.hpp"
#include "Character.hpp"
#include <iostream>

int		main(void)
{
	Character *me = new Character("me");
	Character *john = new Character("John");

	std::cout << *me;

	Enemy *b = new RadScorpion();

	AWeapon *pr = new PlasmaRifle();
	AWeapon *pf = new PowerFist();

	me->equip(pr);
	std::cout << *me;
	me->equip(pf);

	me->attack(b);
	std::cout << *me;
	me->equip(pr);
	std::cout << *me;
	me->attack(b);
	std::cout << *me;
	me->attack(b);
	std::cout << *me;

	// Since you have to delete the enemy in the Character's attack function,
	// the enemy will now be dead, but there's no way to tell from the main.
	// So if you run this line you will segfault.
	// me->attack(b);

	std::cout << std::endl;

	// We're reusing the Enemy pointer for a different Enemy type.
	b = new SuperMutant();
	me->equip(pf);
	john->equip(pr);
	std::cout << *john;
	me->attack(b);
	me->attack(b);
	std::cout << *me;
	me->attack(b);
	std::cout << *me;
	me->recoverAP();
	std::cout << *me;
	me->attack(b);
	std::cout << *me;
	me->attack(b);
	std::cout << *me;
	me->recoverAP();
	me->recoverAP();
	std::cout << *me;

	std::cout << std::endl;

	// Again reusing the Enemy pointer for my own custom Enemy.
	b = new ShieldKnight();
	std::cout << "Knight hp: " << b->getHP() << std::endl;
	std::cout << "Me weapon damage: " << me->getWeapon()->getDamage() << std::endl;
	me->attack(b);
	std::cout << "Knight hp: " << b->getHP() << std::endl;
	std::cout << *me;
	john->attack(b);
	std::cout << "John weapon damage: " << john->getWeapon()->getDamage() << std::endl;
	std::cout << "Knight hp: " << b->getHP() << std::endl;
	std::cout << *john;

	std::cout << std::endl;

	// Creating my own custom weapon.
	AWeapon	*boom = new Boomerang();
	john->equip(boom);
	std::cout << *john;
	john->attack(b);
	std::cout << *john;
	std::cout << "Knight hp: " << b->getHP() << std::endl;

	std::cout << std::endl;
	std::cout << ">>> End of the program, deleting all pointers now." << std::endl;
	std::cout << std::endl;

	delete pr;
	delete pf;
	delete boom;
	delete b;
	delete me;
	delete john;

	// Uncomment the next line to check for leaks.
	// while (1);
	
	return 0;
}
