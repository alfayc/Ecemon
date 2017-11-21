#include "defines.h"
#include "Player.h"

/**
  * std::dynamic_cast
  */


using namespace std;

//initialisation de allegro
void init_alleg(int sizex, int sizey);
void load_sprites(Sprites& sprites);

int main()
{
    init_alleg(XSCREEN, YSCREEN); //doit être avant d'utiliser des fonctions d'alleg (create_bitmap par exemple)

    BITMAP *buffer;
    Sprites sprites;
    PlayerInput p_input;
    Player players[2];

    p_input.dragging = false;
    p_input.prevClick = false;

    load_sprites(sprites);

    buffer = create_bitmap(XSCREEN, YSCREEN);

    while (!key[KEY_ESC])
    {
        for (int i=0;i<2;i++)
        {
            players[i].StartTurn();

            players[i].Turn(players[!i], buffer, sprites, p_input);

            if (key[KEY_ESC])
                break;

            players[i].EndTurn();
        }

    }



    return 0;
}


void load_sprites(Sprites& sprites)
{
    sprites.souris = load_bitmap(SOURIS, nullptr);ERR_CHARG(sprites.souris)
    sprites.buttonEndTurn = load_bitmap(ENDTURN, nullptr);ERR_CHARG(sprites.buttonEndTurn)
}

//initialisation de allegro
void init_alleg(int sizex, int sizey)
{
    allegro_init();

    install_keyboard();
    install_mouse();

    install_timer();
    srand(time(nullptr));

    set_color_depth(desktop_color_depth());
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED, sizex, sizey, 0, 0))
    {
        allegro_message("erreur gfx");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
}
