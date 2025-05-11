#include "Message.h"

Message::Message(const string &from, const string &to, const string &text) : _from(from), _to(to), _text(text) {}

void Message::setSender(const string &from)
{
    _from = from;
}

void Message::setRecipient(const string &to)
{
    _to = to;
}

void Message::setText(const string &text)
{
    _text = text;
}

string Message::getSender() const
{
    return _from;
}

string Message::getRecipient() const
{
    return _to;
}

string Message::getText() const
{
    return _text;
}
