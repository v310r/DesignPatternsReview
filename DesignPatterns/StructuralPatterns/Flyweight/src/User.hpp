#pragma once

#include <map>
#include <unordered_map>
#include <xstring>


typedef uint32_t key;

struct User
{

    User() = default;
        
    User(const std::string & first_name, const std::string & last_name)
    : first_name{ add(first_name) }, last_name{ add(last_name) }
    {
        
    }
    
    protected:

    key first_name, last_name;


    // here bimap was used instead
    static std::unordered_map<key, std::string> names;

    static key seed;

    static key add(const std::string & s)
    {
        
        auto it = std::find_if(std::begin(names), std::end(names), [&s](auto&& p)
        {
            return p.second == s;
        });

        if (it != names.end())
        {
            names.emplace(std::make_pair(++seed, s));
            return seed;
        }

        return it->first;
    }

    //const std::string& GetFirstName() const
    //{
    //    //return names
    //}

    //const string & get_last_name() const
    //{
    //    return names.left.find(last_name)->second;
    //}
};

//friend ostream & operator<<(ostream & os, const User & obj 
//{
//    //return os << "first_name: " << obj.get_first_name() << " last_name: " << obj.get_last_name();
//}
