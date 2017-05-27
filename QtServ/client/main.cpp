#include "client.h"

using namespace std;

int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    std::cout << "Hello!\n";

    Client client(-1, -1, -1);
    client.start();

    app.exec();

    return 0;
}
