//      The Null Object pattern raises an issue of API design : what kinds of
//  assumptions can we make about the objects we depend upon ? If we are
//  taking a pointer(raw or smart), do we then have an obligation to check this
//  pointer on every use ?
//      If you feel no such obligation, then the only way the client can
//  implement a Null Object is to contruct a no - op implementation of the
//  required interface and pass that instance in.That said, this only works well
//  with functions : if the object’s fields are also being used, for example, then
//  you are in real trouble.
//      If you want to proactively support the idea of Null Objects being passed
//  as arguments, you need to be explicit about it : either specify the parameter
//  type as std::optional, give the parameter a default value that hints at a
//  built - in Null Object(e.g., = no_logging), or just write documentation that
//  explains what kind of value is expected at this location.

#include <iostream>

#include "NullObject.hpp"


int main()
{
    
}

