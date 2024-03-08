#include "../include/Application.h"
#include "./playground.h"

#define WIDTH 640
#define HEIGHT 480

int main()
{
    //create our application
    Application app(WIDTH, HEIGHT, "PixGround Demo");

    //YOUR PIXEL PLAYGROUND
    playground(&app);
    //=====================

    //run it
    app.run();
    return 0;
}
