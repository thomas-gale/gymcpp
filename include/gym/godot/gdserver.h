/* gdserver.h */

#ifndef __GYM_GODOT_SERVER_H__
#define __GYM_GODOT_SERVER_H__

#include "core/reference.h"
#include "gym/server.h"

class Server : public Reference {
    GDCLASS(Server, Reference);

    int count;
    

protected:
    static void _bind_methods();

public:
    void add(int p_value);
    void reset();
    int get_total() const;

    Server();
};

#endif // __GYM_GODOT_SERVER_H__