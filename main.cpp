#include <homie.h>

int main(int argc, char *argv[])
{
    Homie application(argc, argv);

    // main loop delay
    application.frequency = 10; //ms

    return application.run();
}
