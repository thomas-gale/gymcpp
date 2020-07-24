/* register_types.cpp */

#include "register_types.h"

#include "core/class_db.h"
#include "gym/godot/summator.h"
#include "gym/godot/gdserver.h"

void register_gymcpp_types() { 
    ClassDB::register_class<Summator>(); 
    ClassDB::register_class<Server>(); 
}

void unregister_gymcpp_types() {
    // Nothing to do here in this example.
}