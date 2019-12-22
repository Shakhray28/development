#include "pch.h"
#include <iostream>

#include <vector>

#include "user.h"
#include "control_auth_user.h"

using namespace std;

const string login                  = "vasia";
const string password               = "111";
const int antiBruteForceCounter     = 3;

int main()
{
	ControlAuthUser o;
	User u1("vasia@bublic.com","vasia");
	User u2("petia@bublic.com","vasia");
	User u3("igor@bublic.com","vasia");
	User u4("igor@bublic.com","vasia");
	o.LoadFromFile("1.txt");
	//o.AddUser(u1);
	//o.AddUser(u1);
	//o.AddUser(u2);
	//o.AddUser(u3);
	//o.AddUser(u4);
	o.SaveFromFile("1.txt");
	o.Print();
	system("pause");
	return 0;
}
