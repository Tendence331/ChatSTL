#pragma once
#include <list>
#include <memory>
#include <iostream>
#include "User.h"
#include "Message.h"
using namespace std;

class User;
class Message;

class Chat
{
private:
    list<User> _user;                   // пользователи
    list<Message> _message;             // сообщения
    User* _currentUsers = {nullptr};    // текущий пользователь
public:
    Chat() = default;
    ~Chat() = default;

    void registerUser(string& name, string& login, string& password);           // регистрация пользователя
    bool loginUser(string& login, string& password);                            // авторизация пользователя
    void sendToUser(string& from, string& to, string& text);                    // отправка сообщения пользователю
    void sendToAll(string& text);                                               // отправка сообщения всем
    void viewMessages();                                                        // просмотр всего чата

    void displayUsers();                                                        // проверка всех пользователей в списке
};

