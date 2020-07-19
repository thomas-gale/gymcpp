/* register_types.cpp */

#include "register_types.h"

#include "core/class_db.h"
#include "src/summator.h"

void register_gymcpp_types() { ClassDB::register_class<Summator>(); }

void unregister_gymcpp_types() {
    // Nothing to do here in this example.
}