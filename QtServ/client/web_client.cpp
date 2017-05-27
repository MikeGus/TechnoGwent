#include "web_client.h"
#define STEP_TIME (40)
#define SLEEP_TIME (5)
int argc = 1;
char* argv[1] = {"web_client"};

void delay(int sec) {
    QTime dieTime= QTime::currentTime().addSecs(sec);
    while (QTime::currentTime() < dieTime){
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }
}

web_client::web_client() :
    player_id(-1)
{
}


bool web_client::make_player_registration(){ //return is your turn
    QApplication app(argc, argv);
    std::cout << "Making player registration!\n";
    Client client(-1, -1, -1);
    client.start();
    app.exec();
    player_id = client.get_player_id();
    return player_id % 2;
}


void web_client::make_step(int card, int line){
    QApplication app(argc, argv);
    std::cout << "Making step!\n";
    Client client(player_id, card, line);
    client.start();
    app.exec();
}


int web_client::get_opponent_step(){
    QApplication app(argc, argv);
    int time = 0;
    int card = -1;
    while (card == -1 && time < STEP_TIME) {
        std::cout << "Get opponent step!\n";
        Client client(player_id, -1, -1);
        client.start();
        card = client.get_card();
        time += SLEEP_TIME;
        delay(SLEEP_TIME);
    }
    app.exec();
    if (time > STEP_TIME + SLEEP_TIME) {
        throw std::runtime_error("response time too big");
    }
    return card;
}


void web_client::make_game_end(){
    QApplication app(argc, argv);
    int time;
    while (player_id != -1 && time < 40){
        Client client(player_id, -2, -2);
        client.start();
        player_id = client.get_player_id();
        time += SLEEP_TIME;
        delay(SLEEP_TIME);
    }
    if (time > STEP_TIME + SLEEP_TIME) {
        throw std::runtime_error("response time too big");
    }
    app.exec();
}
