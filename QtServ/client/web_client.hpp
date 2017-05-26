#ifndef WEB_CLIENT_HPP
#define WEB_CLIENT_HPP

#include "client.h"

class web_client
{
public:
    web_client();
    bool make_player_registration();
    void make_step(int card);
    int  get_opponent_step();
private:
    int player_id;
};

#endif // WEB_CLIENT_HPP
