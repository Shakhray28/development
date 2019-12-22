#pragma once

#include "user.h"
#include <vector>

class ControlAuthUser
{
public:
	ControlAuthUser();
	~ControlAuthUser();

	bool AddUser(const User&);
	void Print() const;
	bool SaveFromFile(const string& filename) const;
	bool LoadFromFile(const string& filename);

protected:
	bool HasSameUser(const User&) const;

	vector<User> users;
};