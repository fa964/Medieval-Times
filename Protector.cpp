#include "noble.h"
#include "protector.h"
#include <stdio.h>
using namespace std;

namespace WarriorCraft {
	Protector::Protector(const string& aName, float aStrength) : name(aName), strength(aStrength), hired(false) {}
	
	string Protector::returnName() const { return name; }

	float Protector::returnStrength() const { return strength; }

	Noble* Protector::empName() const { return employer; }

	void Protector::changeStrength(float newStrength) { strength = newStrength; }

	bool Protector::isHired() const { return hired; }

	void Protector::changeHired(bool newStatus) { hired = newStatus; }

	void Protector::gotHired(Lord* noble) { employer = noble; }

	void Protector::runaway() {
		if (hired == false) { cout << name << " is not even hired!"; }
		else {
			cout << name << " flees in terror, abandoning his lord, " << employer->returnName() << endl;
			hired = false;
			employer->lostProtector(*this);
		}
	}

	Warrior::Warrior(const string& newName, float newStrength) :
		Protector(newName, newStrength) {}

	Archer::Archer(const std::string&newName, float newStrength) :
		Warrior(newName, newStrength) {}

	void Archer::battleCry() {
		if (returnStrength() > 0) {
			cout << "TWANG! " << returnName() << " says: Take that in the name of my lord, " << empName()->returnName();
		}
	}

	Swordsman::Swordsman(const std::string& newName, float newStrength) :
		Warrior(newName, newStrength) {}

	void Swordsman::battleCry() {
		if (returnStrength() > 0) {
			cout << "CLANG! " << returnName() << " says: Take that in the name of my lord, " << empName()->returnName();
		}
	}

	Wizard::Wizard(const string& newName, float newStrength) :
		Protector(newName, newStrength) {}

	void Wizard::battleCry() {
		if (returnStrength() > 0) {
			cout << "POOF! ";
		}
	}
}


