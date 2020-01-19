#ifndef NOBLE_H
#define NOBLE_H

#include <iostream>
#include <string>
#include <vector>

namespace WarriorCraft {
	class Protector;

	class Noble {

	public:
		Noble(const std::string& newName, float strength);

		std::string returnName() const;

		std::vector<Protector*>& returnArmy() { return army; }

		const float& returnStrength();

		void changeStrength(float newStrength);

		void battle(Noble& op);


	private:
		std::string name;

		float strength;

		std::vector<Protector*> army;
	};

	class PersonWithStrengthToFight : public Noble {
	public:
		PersonWithStrengthToFight(const std::string& aName, float aStrength);
	private:
	};

	class Lord : public Noble {
		friend std::ostream& operator<< (std::ostream& os, Lord& lord);
	public:
		Lord(const std::string& name);

		void hires(Protector& applicant);

		void fire(Protector& warrior);

		void lostProtector(const Protector& warrior);

	private:
	};
}
#endif
