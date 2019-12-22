#include "pch.h"
#include "user.h"

const static string CORRECT_LOGIN_ALPHABET = "@._qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM1234567890";

User::User(const string& _userLogin, const string& _userPass)
: userLogin(_userLogin)
, userPass(_userPass)
{}

bool User::IsValid() const
{
    return !userLogin.empty() 
		&& !userPass.empty() 
		&& IsValidLogin();
}

string User::Dump() const
{
    string dump = "Login: " + userLogin + "/Pass: " + userPass;
    return dump;
}
bool User::ChangePass(const string& newPass)
{
    if(newPass.empty()) return false;
    userPass = newPass;
    return true;
}

bool User::IsValidLogin() const
{
	for (size_t i = 0; i < userLogin.size(); ++i)
	{
		if (CORRECT_LOGIN_ALPHABET.find(userLogin[i]) == string::npos)
		{
			return false;
		}
	}
	size_t find1 = userLogin.find("@");
	size_t find2 = userLogin.rfind(".");
	if (find1 != string::npos
		&& find2 != string::npos
		&& find1 < find2)
	{
		return true;

	}
	return false;
}
