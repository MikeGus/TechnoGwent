#include "server.h"

int main(int argc, char** argv)
{
    try {
        QApplication app(argc, argv);
        Server server;
        return app.exec();
    }
    catch (std::runtime_error& err) {
        std::cerr << err.what() << std::endl;
    }
}
