#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class Car {
public:
	Car(const string& _company, const string& _model): company(_company), model(_model) {}

	virtual ~Car() {
		cout << "Company: " << company << "    " << "Model: " << model << endl;
	}

private:
	const string company;
	const string model;
};

class Mercedes :public Car {
public:
	Mercedes(const string& model) :Car("Mercedes", model) {}
	~Mercedes() = default;
};

class BMW : public Car {
public:
	BMW(const string& model) :Car("BMW", model) {}
	~BMW() = default;
};

class Audi : public Car {
public:
	Audi(const string& model) : Car("Audi", model) {}
	~Audi() = default;
};

class Toyota : public Car {
public:
	Toyota(const string& model) :Car("Toyota", model) {}
	~Toyota() = default;
};

class Lada : public Car {
public:
	Lada(const string& model) :Car("Lada", model) {}
	~Lada() = default;
};

int main() {
	ifstream file("cars.txt");

	vector<Car*> Cars;
	string company, model;

	while (file >> company >> model) {
		if (company == "Mercedes") {
			Cars.push_back(new Mercedes(model));
		}
		else if (company == "BMW") {
			Cars.push_back(new BMW(model));
		}
		else if (company == "Audi") {
			Cars.push_back(new Audi(model));
		}
		else if (company == "Toyota") {
			Cars.push_back(new Toyota(model));
		}
		else if (company == "Lada") {
			Cars.push_back(new Lada(model));
		}
	}

	for (const Car* car : Cars) {
		delete car;
	}
}
