#include "pch.h"
#include "control_auth_user.h"
#include <iostream>
#include <fstream>



ControlAuthUser::ControlAuthUser()
{
	users.reserve(50);
}

ControlAuthUser::~ControlAuthUser()
{
	users.clear();
}

bool ControlAuthUser::AddUser(const User& _user)
{
	if(!_user.IsValid() || HasSameUser(_user))
		return false;
	users.push_back(_user);
	return true;
}

void ControlAuthUser::Print() const
{
	for(const User& user : users)
	{
		cout<<user.Dump()<<endl;
	}
}

bool ControlAuthUser::SaveFromFile(const string& filename) const
{
	ofstream outputFile(filename);
	for(const User& user : users)
	{
		outputFile << user.GetLogin()<<" "<<user.GetPass()<<endl;
	}
	outputFile.close();
	return true;
}

bool ControlAuthUser::LoadFromFile(const string& filename)
{
	ifstream inputFile(filename);
	
	if(!inputFile.is_open() || !inputFile.good())
	{
		inputFile.close();
		return false;
	}
	string userName, userPass;
	while(!inputFile.eof())
	{
		inputFile>>userName>>userPass;
		User user(userName, userPass);
		AddUser(user);
	}
	inputFile.close();
	return true;
}

bool ControlAuthUser::HasSameUser(const User& _user) const
{
	for(const User& user : users)
	{
		if(user.GetLogin() == _user.GetLogin())
			return true;
	}
	return false;
}

