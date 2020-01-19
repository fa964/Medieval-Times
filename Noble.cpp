#include "noble.h"
#include "Protector.h"
#include <stdio.h>
using namespace std;

namespace WarriorCraft {
	ostream& operator<< (ostream& os, Lord& lord) {
		if (lord.returnArmy().size() == 0) { os << lord.returnName() << " has no army"; }
		else {
			os << lord.returnName() << " has an army of " << lord.returnArmy().size();
			for (size_t armyI = 0; armyI < lord.returnArmy().size(); ++armyI) {
				os << endl << lord.returnArmy()[armyI]->returnName() << ": " << lord.returnArmy()[armyI]->returnStrength();
			}
		}
		return os;
	}

	Noble::Noble(const string& newName, float aStrength) : name(newName), strength(aStrength) {}

	string Noble::returnName() const { return name; }

	const float& Noble::returnStrength() { return strength; }

	void Noble::changeStrength(float newStrength) { strength = newStrength; }

	PersonWithStrengthToFight::PersonWithStrengthToFight(const string& aName, float aStrength) :
		Noble(aName, aStrength) {}


	Lord::Lord(const string& name) : Noble(name, -1) {}
	

	void Lord::hires(Protector& applicant) {
		if (applicant.isHired() == true) {
			cout << applicant.returnName() << " is already hired." << endl;
		}
		else if (returnStrength() == 0) {
			cout << "You're dead, " << returnName() << endl;
		}
		else {
			applicant.gotHired(this);
			Protector* warriorPtr = &applicant;
			returnArmy().push_back(warriorPtr);
			applicant.changeHired(true);
			if (returnStrength() == -1) { changeStrength(0); }
			changeStrength(returnStrength() + applicant.returnStrength());

		}
	}

	void Lord::fire(Protector& warrior) {
		string wName;
		for (size_t i = 0; i < returnArmy().size(); ++i) {
			if (returnArmy()[i]->returnName() == warrior.returnName()) {
				Protector* temp = returnArmy()[i];
				returnArmy()[i] = returnArmy()[returnArmy().size() - 1];
				returnArmy()[returnArmy().size() - 1] = temp;
				returnArmy().pop_back();
			}
		}
		warrior.changeHired(false);
		changeStrength(returnStrength() - warrior.returnStrength());
		cout << "You dont work for me anymore " << wName << "! -- " << returnName() << '.' << endl;
	}

	void Lord::lostProtector(const Protector& warrior) {
		for (size_t i = 0; i < returnArmy().size(); ++i) {
			if (returnArmy()[i]->returnName() == warrior.returnName()) {
				Protector* temp = returnArmy()[i];
				returnArmy()[i] = returnArmy()[returnArmy().size() - 1];
				returnArmy()[returnArmy().size() - 1] = temp;
				returnArmy().pop_back();
			}
		}
		changeStrength(returnStrength() - warrior.returnStrength());
	}

	void Noble::battle(Noble& op) {
		cout << returnName() << " battles " << op.returnName() << endl;
		if (returnStrength() > 0) {
			for (size_t i = 0; i < army.size(); ++i) { army[i]->battleCry(); cout << endl; }
		}
		if (returnStrength() <= 0 && op.returnStrength() <= 0) {
			cout << "Oh, NO!  They're both dead!  Yuck!" << endl;
		}
		else if (returnStrength() == op.returnStrength()) {
			for (size_t i = 0; i < army.size(); ++i) {
				if (army[i] != nullptr) {
					army[i]->changeStrength(0);
				}
			}
			changeStrength(0);
			for (size_t i = 0; i < op.army.size(); ++i) {
				if (op.army[i] != nullptr) {
					op.army[i]->changeStrength(0);
				}
			}
			op.changeStrength(0);
			cout << "Mutual Annihalation: " << returnName() << " and " << op.returnName() << " die at each other's hands" << endl;
		}
		else if (returnStrength() == 0) {
			cout << "He's dead, " << op.returnName() << endl;
		}
		else if (op.returnStrength() == 0) {
			cout << "He's dead, " << returnName() << endl;
		}
		else if (returnStrength() > op.returnStrength()) {
			float tempArmyStrength = 0;
			for (size_t i = 0; i < army.size(); ++i) {
				if (army.size() != 0) {
					army[i]->changeStrength((army[i]->returnStrength() *(op.returnStrength() / returnStrength())));
					tempArmyStrength += army[i]->returnStrength();
				}
			}
			changeStrength(returnStrength() - tempArmyStrength);
			for (size_t i = 0; i < op.army.size(); ++i) {
				if (op.army[i] != nullptr) {
					op.army[i]->changeStrength(0);
				}
			}
			op.changeStrength(0);
			cout << returnName() << " defeats " << op.returnName() << endl;
		}
		else if (returnStrength() < op.returnStrength()) {
			float tempArmyStrength = 0;
			for (size_t i = 0; i < op.army.size(); ++i) {
				if (op.army.size() != 0) {
					op.army[i]->changeStrength((op.army[i]->returnStrength() * (returnStrength() / op.returnStrength())));
					tempArmyStrength += op.army[i]->returnStrength();
				}
			}
			op.changeStrength(op.returnStrength() - tempArmyStrength);
			for (size_t i = 0; i < army.size(); ++i) {
				if (army[i] != nullptr) {
					army[i]->changeStrength(0);
				}
			}
			changeStrength(0);
			cout << op.returnName() << " defeats " << returnName() << endl;
		}
	}
	}