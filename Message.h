#pragma once
#include "Chat.h"

class Message
{
private:
    std::string _from;          // отправитель
    std::string _to;            // получатель
    std::string _text;          // сообщение
public:
    Message(const std::string& from, const std::string& to, const std::string& text);
    ~Message() = default;

    // сеттеры
    void setSender(const std::string& from);
    void setRecipient(const std::string& to);
    void setText(const std::string& text);
    // геттеры
    std::string getSender() const;
    std::string getRecipient() const;
    std::string getText() const;
};

