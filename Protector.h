#ifndef PROTECTOR_H
#define PROTECTOR_H

#include <iostream>
#include <string>
#include <vector>
namespace WarriorCraft {
	class Noble;
	class Protector{
	public:
		Protector(const std::string& aName, float aStrength);

		std::string returnName() const;

		float returnStrength() const;

		Noble* empName() const;

		void changeStrength(float newStrength);

		bool isHired() const;

		void changeHired(bool newStatus);

		void gotHired(Lord* noble);

		void runaway();

		virtual void battleCry() = 0;

	private:
		std::string name;
		float strength;
		bool hired;
		Lord* employer;
	};

	class Warrior : public Protector {
	public:
		Warrior(const std::string& newName, float newStrength);


	private:
	};

	class Archer : public Warrior {
	public:
		Archer(const std::string&newName, float newStrength);
		void battleCry();
	};

	class Swordsman : public Warrior {
	public:
		Swordsman(const std::string& newName, float newStrength);
		void battleCry();
	};

	class Wizard : public Protector {
	public:
		Wizard(const std::string& newName, float newStrength);
		void battleCry();
	};
}
#endif

