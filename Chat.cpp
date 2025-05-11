#include "Chat.h"

void Chat::registerUser(string &name, string &login, string &password)
{    
    for (list<User>::iterator it = _user.begin(); it != _user.end(); ++it)
    {
        if (it->getLogin() == login)
        {
            std::cout << "Пользователь с логином " << login << " уже существует!" << std::endl;
            std::cout << "Пройдите регистрацию снова!" << std::endl;
            return;
        }
    }
    User newUser (name, login, password);
    _user.push_back(newUser);
    std::cout << "Пользователь " << "[" << name << "]" << " зарегистрирован!" << std::endl;
}

bool Chat::loginUser(string &login, string &password)
{    
    for (list<User>::iterator it = _user.begin(); it != _user.end(); ++it)
    {
        if (it->getLogin() == login && it->getPassword() == password)
        {
            _currentUsers = &(*it);
            std::cout << "Пользователь " << "[" << it->getName() << "]" << " успешно вошел" << std::endl;   
            return true;
        }
        
    }
    std::cout << "Ошибка неправильный логин и пароль" << std::endl;
    return false;
}

void Chat::sendToUser(string& from, string &to, string &text)
{
    if(!_currentUsers)
    {
        std::cout << "Вы не авторизированы!" << std::endl;
        return;
    }
    Message newMessage (from, to, text);
    _message.push_back(newMessage);
    cout << "Сообщение отправлено пользователю: " << to << endl;
}

void Chat::sendToAll(string &text)
{
    if(!_currentUsers)
    {
        std::cout << "Вы не авторизированы!" << std::endl;
        return;
    }
    Message newMessage (_currentUsers->getLogin(), "all", text);
    _message.push_back(newMessage);
}

void Chat::viewMessages()
{
    for (auto msg : _message)
    {
        if (msg.getRecipient() == "all" || msg.getRecipient() == _currentUsers->getLogin())
        {
            cout << "[" << msg.getSender() << "] >> " << msg.getText() << std::endl;
        }
    }
    
}

void Chat::displayUsers()
{
    for (auto it : _user)
    {
        std::cout << "Пользователь: [ " << it.getName() << " ] Логин: [ " << it.getLogin() << " ]" << std::endl;
    }
}
