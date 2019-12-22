#pragma once

#include <string>
using namespace std;

class User
{
public:
    User(const string& userLogin,
         const string& userPass);

    bool          IsValid() const;
    string        Dump()  const;
    const string& GetLogin()  const  { return userLogin; }
    const string& GetPass()   const  { return userPass; }
    
	bool          ChangePass(const string& newPass);

protected:
	bool		  IsValidLogin() const;

    const string	userLogin;
    string			userPass;
};
