


#ifndef Object_H_
#define Object_H_

#include<string>
#include<iostream>
using namespace std;

class Object
{
private:
	string name;
	int	   key;



public:
	Object(string newName, int newWait){name = newName;
										 key = newWait;}

	Object() {name = "";
			  key = 0;}

	int GetKey() const {return key;}

	string GetName() const {return name;}
};



#endif /* Object_H_ */
