#include <iostream>
#include <string>
#include <vector>

class Animal {
private:
	std::string m_name;
	static int m_id;
	static int m_numberOfAnimal;
public:
	Animal(std::string name) : m_name(name) {
		m_numberOfAnimal++;
		m_id++;
	}

	int getNumberOfAnimal() const {
		return (m_numberOfAnimal);
	}

	int getIdOfAnimal() const {
		return (m_id);
	}

	std::string getName() const {
		return (m_name);
	}

	virtual void voice() = 0;
};

int Animal::m_numberOfAnimal{ 0 };
int Animal::m_id{ 0 };

// Class Mammal and Subclasses of Mammal
class Mammal : public Animal {
public:
	Mammal(std::string name) : Animal(name){}
};

class Cat : public Mammal {
public:
	Cat(std::string name) : Mammal(name) {}

	void voice() override {
		std::cout << "Meow-meow" << std::endl;
	}
};

class Dog : public Mammal {
public:
	Dog(std::string name) : Mammal(name) {}

	void voice() override {
		std::cout << "Woof-woof" << std::endl;
	}
};


// Class Bird and Subclasses of Bird
class Bird : public Animal {
public:
	Bird(std::string name) : Animal(name) {}
};

class Sparrow : public Bird {
public:
	Sparrow (std::string name) : Bird(name){}

	void voice() override {
		std::cout << "Chirick-Chirick" << std::endl;
	}
};

class Chiken : public Bird {
public:
	Chiken(std::string name) : Bird(name) {}

	void voice() override { std::cout << "Ko-ko"; }
};

class Owl : public Bird {
public:
	Owl(std::string name) : Bird(name) {}

	void voice() override { std::cout << "YYYYkr-yyyykr"; } // Не знаю как можно записать такой звук в виде текста XDDD https://www.youtube.com/watch?v=AntAR1oR0TM&ab_channel=%D0%97%D0%B2%D1%83%D0%BA%D0%B8%D0%B8%D0%B3%D0%BE%D0%BB%D0%BE%D1%81%D0%B0
};




class Zoopark {
private:
	std::vector <Animal*> m_animal;
public:
	void popBack() {
		m_animal.pop_back();
	}

	void pushBack(Animal* animal) {
		m_animal.push_back(animal);
	}

	void voice() {
		for (Animal* el : m_animal) {
			el->voice();
		}
	}

	int numberofBirds() {
		int count{ 0 };

		for (Animal* el : m_animal) {
			if (dynamic_cast<Bird*>(el)) count++;
		}
		return count;
	}
};

int main() {
	Zoopark zoopark = Zoopark();

	Sparrow bird_first = Sparrow("bird_first");
	Bird* bird_second = new Chiken("bird_second");
	Bird* bird_third = new Owl("bird_third");

	std::cout << "The ID of " << bird_third->getName() << " is " << bird_third->getIdOfAnimal() << std::endl;

	zoopark.pushBack(&bird_first);
	zoopark.pushBack(bird_second);
	zoopark.pushBack(bird_third);

	zoopark.popBack();


	std::cout << "The number of birds is " << zoopark.numberofBirds() << std::endl;

	delete bird_second;
	delete bird_third;

	Dog dog("Sharik");
	std::cout << "The ID of " << dog.getName() << " is " << dog.getIdOfAnimal() << std::endl;

	return 0;
}
