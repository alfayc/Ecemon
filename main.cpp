#include "defines.h"
#include "Player.h"

/**
  *
  */


using namespace std;

//initialisation de allegro
void init_alleg(int sizex, int sizey);
void load_sprites(Sprites& sprites);

int main()
{
    init_alleg(XSCREEN, YSCREEN); //doit être avant d'utiliser des fonctions d'alleg (create_bitmap par exemple)

    Sprites sprites;
    Player players[2];

    load_sprites(sprites);

    buffer = create_bitmap(XSCREEN, YSCREEN);
    playerView = create_bitmap(XSCREEN, YSCREEN/2);

    while (!key[KEY_ESC])
    {
        for (int i=0;i<2;i++)
        {
            players[i].StartTurn();
            prevEnter = key[KEY_ENTER];

            players[i].Turn(players[!i], buffer, sprites);

            if (key[KEY_ESC])
                break;

            players[i].EndTurn();
        }

    }



    return 0;
}


void load_sprites(Sprites& sprites)
{
    sprites.souris = load_bitmap(SOURIS, NULL);ERR_CHARG(sprites.souris)
    sprites.buttonEndTurn = load_bitmap(ENDTURN, NULL);ERR_CHARG(sprites.buttonEndTurn)
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
