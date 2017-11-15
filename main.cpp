#include "defines.h"
#include "Player.h"

using namespace std;

//initialisation de allegro
void init_alleg(int sizex, int sizey);

int main()
{
    init_alleg(XSCREEN, YSCREEN);



    return 0;
}


//initialisation de allegro
void init_alleg(int sizex, int sizey)
{
    allegro_init();

    install_keyboard();
    install_mouse();

    install_timer();
    srand(time(NULL));

    set_color_depth(desktop_color_depth());
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED, sizex, sizey, 0, 0))
    {
        allegro_message("erreur gfx");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
}
