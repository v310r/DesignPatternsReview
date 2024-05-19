//    This chapter has presented a number of proxies.Unlike the Decorator
//    pattern, the Proxy doesn’t try to expand the functionality of an object
//    by adding new members(unless it can’t be helped).All it tries to do is
//    enhance the underlying behavior of existing members.
//    Plenty of different proxies exist :
//    • Property proxies are stand - in objects that can replace
//    fields and perform additional operations during
//    assignment and /or access.
//    • Virtual proxies provide virtual access to the underlying
//    object, and can implement behaviors such as lazy
//    object loading.You may feel like you’re working with a
//    real object, but the underlying implementation may not
//    have been created yet, and can, for example, be loaded
//    on demand.
//    • Communication proxies allow us to change the
//    physical location of the object(e.g., move it to the
//    cloud) but allow us to use pretty much the same API.Of
//    course, in this case the API is just a shim for a remote
//    service such as a REST API.
//    • Logging proxies allow you to perform logging in
//    addition to calling the underlying functions.
//    There are lots of other proxies out there, and chances are that the ones
//    you build yourself will not fall into a preexisting category, but will instead
//    perform some action specific to your domain.

// There could be a lot of other proxies like caching proxy, or even smart pointers can be considered a proxy


#include <iostream>

#include "PropertyProxy.hpp"
#include "VirtualProxy.hpp"


 void draw_image(Image& img)
 {
    std::cout << "About to draw the image" << std::endl;
    img.draw();
    std::cout << "Done drawing the image" << std::endl;
}

int main()
{
    std::cout << "Hello World!\n";

    LazyBitmap lazybitmap("/Game/Images/lol.jpg");
    draw_image(lazybitmap); // image loaded here

    Creature creature;
    creature.agility = 20;
    auto x = creature.strength;
}

