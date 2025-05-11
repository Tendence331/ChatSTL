#pragma once
#include "Chat.h"
#include <string>

class User
{
private:
    std::string _login;          // логин
    std::string _name;           // имя пользователя
    std::string _password;       // пароль
    std::shared_ptr<User> _nextUser;
public:
    User() = default;
    User(const std::string& name, const std::string& login, const std::string& password);
    // сеттеры
    void setName(const std::string name);
    void setLogin(const std::string login);
    void setPassword(const std::string password);
    void setNextUser(std::shared_ptr<User> next);
    // геттеры
    std::string getName() const;
    std::string getLogin() const;
    std::string getPassword() const;
    std::shared_ptr<User> getNextUser() const;
    
    ~User() = default;
};
