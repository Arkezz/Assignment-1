#include <iostream>
#include <iomanip>
#include <fstream>
#include <queue>
#include <regex>
using namespace std;

class Car {
private:
	string Car_Brand;
	string Car_Type; //Validate to only Bus Private Motorcycle, Truck in constructor and setter
	string Car_Plate; //Validate to be only 6 characters(3 letters and 3 numbers) long in constructor and setter
	int Speed;
	int Year_Model;
public:
	// create default class constructor
	Car() {
		Car_Brand = " ";
		Car_Type = " ";
		Car_Plate = " ";
		Speed = 0;
		Year_Model = 0;
	}
	// create class constructor with parameters
	Car(string Brand, string Type, string Plate, int S, int Model) {
		Car_Brand = Brand;

		//Validate Car_Type to only Bus Private Motorcycle, Truck. Ignore upper or lowercase
		if (Type == "Bus" || Type == "bus") {
			Car_Type = "Bus";
		}
		else if (Type == "Private" || Type == "private") {
			Car_Type = "Private";
		}
		else if (Type == "Motorcycle" || Type == "motorcycle") {
			Car_Type = "Motorcycle";
		}
		else if (Type == "Truck" || Type == "truck" || Type == "TRUCK") {
			Car_Type = "Truck";
		}
		else {
			cout << Type << " is invalid. Car Type can only be Bus Private Motorcycle, and Truck." << endl;
		}
		//validate that the plate string is made up of 3 letters and 3 numbers and cannot exceed the length of 6
		if (Plate.length() == 6) {
			regex r("[a-zA-Z]{3}[0-9]{3}");
			if (regex_match(Plate, r)) {
				Car_Plate = Plate;
			}
			else {
				cout << Plate << " is invalid" << endl;
			}
		}
		else {
			cout << Plate << " is invalid" << endl;
		}
		Speed = S;
		Year_Model = Model;
	}
	// create setter for each variable
	void setCar_Brand(string Brand) {
		Car_Brand = Brand;
	}
	void setCar_Type(string Type) {
		//Validate Car_Type to only Bus Private Motorcycle, Truck. Ignore upper or lowercase
		if (Type == "Bus" || Type == "bus") {
			Car_Type = "Bus";
		}
		else if (Type == "Private" || Type == "private") {
			Car_Type = "Private";
		}
		else if (Type == "Motorcycle" || Type == "motorcycle") {
			Car_Type = "Motorcycle";
		}
		else if (Type == "Truck" || Type == "truck" || Type == "TRUCK") {
			Car_Type = "Truck";
		}
		else {
			cout << Type << " is invalid. Car Type can only be Bus Private Motorcycle, and Truck." << endl;
		}
	}
	void setCar_Plate(string Plate) {
		//validate that the plate string is made up of 3 letters and 3 numbers and cannot exceed the length of 6
		if (Plate.length() == 6) {
			regex r("[a-zA-Z]{3}[0-9]{3}");
			if (regex_match(Plate, r)) {
				Car_Plate = Plate;
			}
			else {
				cout << Plate << " is invalid should consist of 3 letters and 3 numbers" << endl;
			}
		}
		else {
			cout << Plate << " is too long should only have a length of 6 characters long" << endl;
		}
	}
	void setSpeed(int S) {
		Speed = S;
	}
	void setYear_Model(int Model) {
		Year_Model = Model;
	}
	// create getter for each variable
	string getCar_Brand() const {
		return Car_Brand;
	}
	string getCar_Type() const {
		return Car_Type;
	}
	string getCar_Plate() const {
		return Car_Plate;
	}
	int getSpeed() const {
		return Speed;
	}
	int getYear_Model() const {
		return Year_Model;
	}
};

class Road {
private:
	char Road_Type; //Validate the characters to only be A,B, or C
	int Speed_Limit;
	static float countA, countB, countC;
public:
	// create default class constructor
	Road() {
		Road_Type = ' ';
		Speed_Limit = 0;
	}
	// create class contructor with parameters
	Road(char Type, int Limit) {
		//Validate the Type to only allow A,B, or C
		if (Type == 'A' || Type == 'a') {
			Road_Type = 'A';
		}
		else if (Type == 'B' || Type == 'b') {
			Road_Type = 'B';
		}
		else if (Type == 'C' || Type == 'c') {
			Road_Type = 'C';
		}
		else {
			cout << Type << " is invalid" << endl;
		}
		Speed_Limit = Limit;
	}
	// bool function returns true if car speed is more than than road speed limit
	bool Radar(int car_speed) {
		if (Road_Type == 'A' || Road_Type == 'a') {
			if (car_speed > 120) {
				return true;
			}
			else {
				return false;
			}
		}
		else if (Road_Type == 'B' || Road_Type == 'b') {
			if (car_speed > 80) {
				return true;
			}
			else {
				return false;
			}
		}
		else if (Road_Type == 'C' || Road_Type == 'c') {
			if (car_speed > 60) {
				return true;
			}
			else {
				return false;
			}
		}
		else {
			cout << Road_Type << " is invalid" << endl;
		}
	}
	// allow function  Road A: Allow only Private and motorcycle vehicles. Road B : Allow all vehicles Road C : Allow only trucks
	void Allow(string Car_Type) const {
		if (Road_Type == 'A') {
			if (Car_Type == "Private" || Car_Type == "Motorcycle") {
				cout << Car_Type << " is allowed on road A" << endl;
				++countA;
			}
			else {
				cout << Car_Type << " is not allowed only Private and Motorcycle vechiles can be on road A" << endl;
			}
		}
		else if (Road_Type == 'B') {
			cout << Car_Type << " is allowed on road B" << endl;
			++countB;
		}
		else if (Road_Type == 'C') {
			if (Car_Type == "Truck") {
				cout << Car_Type << " is allowed on road C" << endl;
				++countC;
			}
			else {
				cout << Car_Type << " is not allowed only Truck vechiles can be on road C" << endl;
			}
		}
	}
	// age function calculates the age of the car
	int age(int Year_Model) const {
		{
			int current_year = 2022;
			int age = current_year - Year_Model;
			return age;
		}
	}
	//Setters and Getters
	void setRoad_Type(char Type) {
		//Validate the Type to only allow A,B, or C
		if (Type == 'A' || Type == 'a') {
			Road_Type = 'A';
		}
		else if (Type == 'B' || Type == 'b') {
			Road_Type = 'B';
		}
		else if (Type == 'C' || Type == 'c') {
			Road_Type = 'C';
		}
		else {
			cout << Type << " is invalid" << endl;
		}
	}
	void setSpeed_Limit(int Limit) {
		Speed_Limit = Limit;
	}
	int getSpeed_Limit() const {
		return Speed_Limit;
	}
	char getRoad_Type() const {
		return Road_Type;
	}

	//Count getters
	static float getcountA() {
		return countA;
	}
	static float getcountB() {
		return countB;
	}
	static float getcountC() {
		return countC;
	}
};

// static float initialization
float Road::countA = 0;
float Road::countB = 0;
float Road::countC = 0;

// function that uses a loop to generate Car objects and set their values randomly out of set arrays
void generateCars(Car cars[], int size) {
	// create arrays for random values // break these values if you wanna make sure validation works
	string brands[5] = { "Toyota", "Honda", "Ford", "Chevrolet", "Nissan" };
	string types[4] = { "Bus", "Private", "Motorcycle", "Truck" };
	string plates[6] = { "ABC123", "DEF456", "GHI789", "JKL012", "MNO345", "PQR678" };
	int speeds[10] = { 40, 50, 60, 70, 80, 90, 100, 110, 120, 130 };
	int models[5] = { 2015, 2016, 2017, 2018, 2019 };
	for (int i = 0; i < size; i++) {
		cars[i].setCar_Brand(brands[rand() % 5]);
		cars[i].setCar_Type(types[rand() % 4]);
		cars[i].setCar_Plate(plates[rand() % 6]);
		cars[i].setSpeed(speeds[rand() % 10]);
		cars[i].setYear_Model(models[rand() % 5]);
	}
}

//function that prints the car information and that its getting fined
void printCar(Car car, Road road) {
	cout << "------------------------------------------------------------" << endl;
	cout << "Road " << road.getRoad_Type() << endl;
	cout << "Car Brand: " << car.getCar_Brand() << endl;
	cout << "Car Type: " << car.getCar_Type() << endl;
	cout << "Car Plate: " << car.getCar_Plate() << endl;
	cout << "Car Speed: " << car.getSpeed() << endl;
	cout << "Car Year Model: " << car.getYear_Model() << endl;
	cout << "Car Age: " << road.age(car.getYear_Model()) << endl;
	cout << "Car is getting fined for going past the speed limit: " << road.getSpeed_Limit() << endl;
}

int main() {
	//Seed so that rand values are different each time
	srand((unsigned int)time(NULL));

	//Create 3 roads
	Road road1('A', 120);
	Road road2('B', 80);
	Road road3('C', 60);
	//Create a queue for cars
	queue<Car> car_queue;
	Car carArray[10];
	//Generate 10 cars and add them to the queue
	generateCars(carArray, 10);
	for (int i = 0; i < 10; i++) {
		car_queue.push(carArray[i]);
	}

	//Loop the queue
	for (int i = 0; i < car_queue.size(); i++) {
		{
			road1.Allow(car_queue.front().getCar_Type());
			road2.Allow(car_queue.front().getCar_Type());
			road3.Allow(car_queue.front().getCar_Type());
			if (road1.Radar(car_queue.front().getSpeed())) {
				// print that these cars are getting fined for going past road speed limit
				printCar(car_queue.front(), road1);
			}
			road1.age(car_queue.front().getYear_Model());
			if (road2.Radar(car_queue.front().getSpeed())) {
				printCar(car_queue.front(), road2);
			}
			road2.age(car_queue.front().getYear_Model());
			if (road3.Radar(car_queue.front().getSpeed())) {
				printCar(car_queue.front(), road3);
			}
			road3.age(car_queue.front().getYear_Model());
			car_queue.pop();
		}
	}

	//find the highest count out of countA, countB, and countC
	float max = road1.getcountA();
	if (road1.getcountB() > max) {
		max = road1.getcountB();
	}
	if (road1.getcountC() > max) {
		max = road1.getcountC();
	}

	cout << "------------------------------------------------------------" << endl;
	cout << "Road A: " << road1.getcountA() << " cars allowed" << endl;
	cout << "Road B: " << road2.getcountB() << " cars allowed" << endl;
	cout << "Road C: " << road3.getcountC() << " cars allowed" << endl;
	cout << "------------------------------------------------------------" << endl;
	cout << "The effeciency of Road A is: " << (road1.getcountA() / max) * 100 << "%" << endl;
	cout << "The effeciency of Road B is: " << (road2.getcountB() / max) * 100 << "%" << endl;
	cout << "The effeciency of Road C is: " << (road3.getcountC() / max) * 100 << "%" << endl;
	return 0;
}