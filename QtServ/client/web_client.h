#ifndef WEB_CLIENT_HPP
#define WEB_CLIENT_HPP

#include "client.h"

class web_client
{
public:
    web_client();
    bool make_player_registration();
    void make_step(int card, int line);
    int  get_opponent_step();
    void make_game_end();
    //bool close_game();
private:
    int player_id;
};

#endif // WEB_CLIENT_HPP
