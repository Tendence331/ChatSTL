#include "User.h"

User::User(const string &name, const string &login, const string &password) : _name(name), _login(login), _password(password) {}

void User::setName(const string name)
{
    _name = name;
}

void User::setLogin(const string login)
{
    _login = login;
}

void User::setPassword(const string password)
{
    _password = password;
}

void User::setNextUser(std::shared_ptr<User> next)
{
    _nextUser = next;
}

string User::getName() const
{
    return _name;
}

string User::getLogin() const
{
    return _login;
}

string User::getPassword() const
{
    return _password;
}

std::shared_ptr<User> User::getNextUser() const
{
    return _nextUser;
}
