#include <iostream>
#include "Chat.h"
using namespace std;

int main()
{
    
    Chat chat;

    while (true)
    {
        cout << "-----------------------------" << endl;
        cout << "Войдите или авторизируйтесь" << endl;
        cout << "1. Регистрация" << endl;
        cout << "2. Авторизация" << endl;
        cout << "3. Отправить сообщение пользователю" << endl;
        cout << "4. Отправить сообщение всем" << endl;
        cout << "5. Просмотр чата" << endl;
        cout << "Для выхода введите '0' " << endl;
        cout << endl;
        cout << "Выберите действие: ";
        int choise;
        cin >> choise;
        cout << endl;


        std::string login;
        std::string password;
        std::string name;
        std::string text;
        if (choise == 0)
        {
            cout << "Выход из программы" << endl;
            break;
        }
        else if (choise > 6)
        {
            cout << "Неверно! Выберите Вход или Регистрацию!" << endl;
        }
        
        switch (choise)
        {
        case 1:
            cout << "-----------------------------" << endl;
            cout << "-------- Регистрация --------" << endl;
            cout << "Введите имя: ";
            cin >> name;
            cout << "Введите логин: ";
            cin >> login;
            cout << "Введите пароль: ";
            cin >> password;
            chat.registerUser(name, login, password);           // метод регистрации пользователя
            cout << "-----------------------------" << endl;
            cout << endl;
            break;
        case 2:
            cout << "-----------------------------" << endl;
            cout << "-------- Авторизация --------" << endl;
            cout << "Введите логин: ";
            cin >> login;
            cout << "Введите пароль: ";
            cin >> password;
            chat.loginUser(login, password);                    // метод авторизации пользователя
            cout << "-----------------------------" << endl;
            cout << endl;
            break;
        case 3:
            cout << "-----------------------------" << endl;
            cout << "----- Отправка сообщения ----" << endl;
            cout << "Введите получателя: ";
            cin >> login;
            cout << "Введите имя отправителя: ";
            cin >> name;
            cout << "Введите текст сообщения: ";
            cin >> text;
            chat.sendToUser(login, name, text);                 // метод ввода сообщения и отправки пользоавтелю
            cout << "-----------------------------" << endl;
            cout << endl;
            break;
        case 4:
            cout << "-----------------------------" << endl;
            cout << "------- Всем сообщения ------" << endl;
            cout << endl;
            cout << "Введите текст сообщения: ";
            cin.ignore();
            getline(cin, text);
            chat.sendToAll(text);                                    // метод отправки всем сообщений
            cout << "-----------------------------" << endl;
            cout << endl;
            break;
        case 5:
            cout << "-----------------------------" << endl;
            cout << "------- Просмотр чата -------" << endl;
            chat.viewMessages();
            cout << "-----------------------------" << endl;
        case 6:
            // проверка всех пользователей
            chat.displayUsers();
            break;
        default:
            break;
        }
    }
    
    return 0;
}