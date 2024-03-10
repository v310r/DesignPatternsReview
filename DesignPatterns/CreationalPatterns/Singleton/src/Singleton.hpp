#pragma once

/*
        The Singleton is the most hated design pattern in the (rather limited)
    history of design patterns. Just stating that, however, doesn’t mean you
    shouldn’t use the singleton: a toilet brush is not the most pleasant device
    either, but sometimes it’s simply necessary.
        The Singleton design pattern grew out of a very simple idea that
    you should only have one instance of a particular component in your
    application. For example, a component that loads a database into memory
    and offers a read-only interface is a prime candidate for a Singleton, since
    it really doesn’t make sense to waste memory storing several identical
    datasets. In fact, your application might have constraints such that two or
    more instances of the database simply won’t fit into memory, or will result
    in such a lack of memory as to cause the program to malfunction.
*/

struct Database
{
protected:

    Database()
    {

    }

public:

    static Database& get()
    {
        // better to use heap rather than global memory in case object depends on other global data
        static Database* database = new Database();
        return *database;
    }

    Database(Database const&) = delete;
    Database(Database&&) = delete;
    Database& operator=(Database const&) = delete;
    Database& operator=(Database&&) = delete;
};
