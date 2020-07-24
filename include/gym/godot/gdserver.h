/* gdserver.h */

#ifndef __GYM_GODOT_SERVER_H__
#define __GYM_GODOT_SERVER_H__

#include <memory>

#include "core/reference.h"
#include "gym/server.h"

class Server : public Reference {
    GDCLASS(Server, Reference);
private:
    int count;
    std::unique_ptr<gym::Server> server_;

protected:
    static void _bind_methods();

public:
    Server();
    void init(const String& host, int port);
    void run();
};

#endif // __GYM_GODOT_SERVER_H__