#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Car {
public:
	string car_name;
	int x, y;

	Car() {
		car_name = "Audi Q7";
		x = y = 0;
	}
	Car(string name, int x, int y) {
		car_name = name;
		this->x = x;
		this->y = y;
	}

	int dist() {
		return x * x + y * y;
	}
};

bool compare(Car c1, Car c2) {
	int da =  c1.x * c1.x + c1.y * c1.y;
	int db =  c2.x * c2.x + c2.y * c2.y;

	if (da == db) {
		return c1.car_name < c2.car_name;
	}

	return da < db;

}


int main() {
	vector<Car> v;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string name;
		int x, y;
		cin >> name >> x >> y;
		Car newCar(name, x, y);
		v.push_back(newCar);
	}

	sort(v.begin(), v.end(), compare);

	for (auto c : v) {
		cout << "Car " << c.car_name << " distance " << c.dist() << " location " << c.x << " " << c.y << endl;
	}
}