#include "Application.h"

int main(int argc, char *argv[])
{
    Application application(argc, argv);

    // main loop delay
    application.frequency = 10; //ms

    return application.run();
}
