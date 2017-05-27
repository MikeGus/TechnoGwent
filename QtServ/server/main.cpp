#include "server.h"

int main(int argc, char** argv)
{
    try {
        QApplication app(argc, argv);
        Server server;
        return app.exec();
    }
    catch (std::exception& err) {
        std::cerr << "Server works failed " << err.what() << std::endl;
    }
}
