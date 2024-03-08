#define WIDTH 640
#define HEIGHT 480

#include "Application.h"
#include "./playground.h"


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
