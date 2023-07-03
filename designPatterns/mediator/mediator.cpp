#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

#include "Person.hpp"
#include "ChatRoom.hpp"

// mediator
// Motivation
// Components may go out of the system at any time
/// chat room
// it makes no sense for them to have a direct references between them
// solution
// all of them refer to some central component that facilitates communication

// chat room

int main()

{
    ChatRoom room;

    Person john{"John"};
    Person jane{"Jane"};
    room.join(&john);
    room.join(&jane);
    john.say("hi room");
    jane.say("oh, hey john");

    Person simon{"Simon"};
    room.join(&simon);
    simon.say("hi everyone!");

    jane.pm("Simon", "glad you found us, simon!");

    return 0;
}
