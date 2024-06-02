#pragma once

#include <string>
#include <vector>


struct Person;

struct ChatRoom
{
    std::vector<Person*> people;

    void join(Person* p);

    void broadcast(const std::string& origin, const std::string& message);

    void message(const std::string& origin, const std::string& who, const std::string& message);
};

struct Person
{

    Person(const std::string& name) : name(name)
    {

    }

    void receive(const std::string& origin, const std::string message)
    {
        std::string s {origin + ": \"" + message + "\"" };
        std::cout << "[" << name << "'s chat session] " << s << "\n";
        chatLog.emplace_back(s);
    }

    void say(const std::string& message) const
    {
        room->broadcast(name, message);
    }

    void pm(const std::string who, const std::string& message) const
    {
        room->message(name, who, message);
    }

    std::vector<std::string> chatLog;

    ChatRoom* room = nullptr;

    std::string name;
};

void ChatRoom::join(Person* p)
{
    std::string joinMessage = p->name + " joins the chat";
    broadcast("room", joinMessage);
    p->room = this;
    people.emplace_back(p);
}

void ChatRoom::broadcast(const std::string& origin, const std::string& message)
{
    for (auto p : people)
    {
        if (p->name != origin)
        {
            p->receive(origin, message);
        }
    }
}

void ChatRoom::message(const std::string& origin, const std::string& who, const std::string& message)
{
    auto target = std::find_if(std::begin(people), std::end(people), [&](const Person* p)
    {
        return p->name == who;
    });

    if (target != std::end(people))
    {
        (*target)->receive(origin, message);
    }
}
