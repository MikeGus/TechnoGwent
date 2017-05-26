#include "web_client.hpp"

web_client::web_client() :
    player_id(-1)
{
}

bool web_client::make_player_registration(){ //return is your turn
    char* k[1];
    k[0] = "name";
    int a = 1;
    QApplication app(a, k);
    std::cout << "Making player registration!\n";
    Client client(-1, -1);
    client.start();
    app.exec();

    player_id = client.get_player_id();
    return player_id % 2;
}

void web_client::make_step(int card){
    char* k[1];
    k[0] = "name";
    int a = 1;
    QApplication app(a, k);
    std::cout << "Making step!\n";
    Client client(player_id, card);
    client.start();
    app.exec();
}


int web_client::get_opponent_step(){
    char* k[1];
    k[0] = "name";
    int a = 1;
    QApplication app(a, k);
    std::cout << "Get opponent step!\n";

    Client client(player_id, -1);
    client.start();

    app.exec();
    return client.get_card();
}
