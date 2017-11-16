#include "defines.h"
#include "Player.h"

/**
  *
  */


using namespace std;

//initialisation de allegro
void init_alleg(int sizex, int sizey);

int main()
{
    init_alleg(XSCREEN, YSCREEN); //doit être avant d'utiliser des fonctions d'alleg (create_bitmap par exemple)

    BITMAP *buffer, *playerView, *souris;
    Player player1, player2;

    buffer = create_bitmap(XSCREEN, YSCREEN);
    playerView = create_bitmap(XSCREEN, YSCREEN/2);
    souris = load_bitmap("Res/mario_mouse_cursor.bmp", NULL);ERR_CHARG(souris)

    while (!key[KEY_ESC])
    {
        player1.Draw(playerView, true);
        blit(playerView, buffer, 0, 0, 0, YSCREEN/2, XSCREEN, YSCREEN/2);
        player2.Draw(playerView, false);
        blit(playerView, buffer, 0, 0, 0, 0, XSCREEN, YSCREEN/2);

        draw_sprite(buffer, souris, mouse_x, mouse_y);
        cout << mouse_x << " " << mouse_y << endl;

        blit(buffer, screen, 0, 0, 0, 0, XSCREEN, YSCREEN);

        rest(20);
    }



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
