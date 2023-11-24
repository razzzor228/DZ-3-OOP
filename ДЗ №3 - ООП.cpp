#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Leaks {
	~Leaks() { _CrtDumpMemoryLeaks(); }
};
Leaks _l;

class House {
	string s;
public:
	House() { s = "House"; }
	virtual House* Copy() {
		House* new_obj = new House(*this);
		return new_obj;
	}
	House(const House& obj) {
		s = obj.s;
	}
	virtual ~House() = default;
	virtual void print(){}
};

class Wooden :public House {
	string s1;
public:
	Wooden() { s1 = "Wooden"; }
	virtual Wooden* Copy() {
		Wooden* new_obj = new Wooden(*this);
		return new_obj;
	}
	Wooden(const Wooden& obj) {
		s1 = obj.s1;
	}
	void print() {
		cout << s1 << endl;
	}
	~Wooden() = default;
};

class Brick : public House {
	string s2;
public:
	Brick(){ s2 = "Brick"; };
	virtual Brick* Copy() {
		Brick* new_obj = new Brick(*this);
		return new_obj;
	}
	Brick(const Brick& obj) {
		s2 = obj.s2;
	}
	void print() {
		cout << s2 << endl;
	}
	~Brick() = default;
};


int main()
{
	vector<House*> v;
	vector<House*> v1;
	for (int i = 0; i < 5; i++)
	{
		if (i % 2 == 0)
			v.push_back(new Wooden());
		else
			v.push_back(new Brick());
	}

	for (int i = 0; i < v.size(); i++)
	{
		v1.push_back(v[i]->Copy());
		v1[i]->print();
	}
	for (int i = 0; i < v.size(); i++)
	{
		delete v[i];
	}
	for (int i = 0; i < v1.size(); i++)
	{
		delete v1[i];
	}
}
