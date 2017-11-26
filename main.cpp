#include "defines.h"
#include "Player.h"

/**
  * il aurait fallu depuis le début faire une classe bouton avec une fonction bool clicked() mais bon
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
    bool endGame = false;

    p_input.dragging = false;
    p_input.prevClick = false;

    load_sprites(sprites);

    buffer = create_bitmap(XSCREEN, YSCREEN);

    while (!key[KEY_ESC] && !endGame)
    {
        for (int i=0;i<2;i++)
        {
            players[i].StartTurn();

            p_input.whoTurn = i;

            players[i].Turn(players[!i], buffer, sprites, p_input);

            if (key[KEY_ESC])
                break;

            players[i].EndTurn(players[!i]);

            if (!players[0].GetHP() || !players[1].GetHP())
            {
                endGame = true;
                cout << endl << "partie terminée!!" << endl;
            }
        }

    }



    return 0;
}


void load_sprites(Sprites& sprites)
{
    sprites.souris = load_bitmap(FSOURIS, nullptr);ERR_CHARG(sprites.souris)
    sprites.buttonEndTurn = load_bitmap(FENDTURN, nullptr);ERR_CHARG(sprites.buttonEndTurn)
    sprites.buttonPlayer= load_bitmap(FPLAYER, nullptr);ERR_CHARG(sprites.buttonPlayer)
    sprites.cardBack = load_bitmap(FCARDB, NULL); ERR_CHARG(sprites.cardBack)
    sprites.cardTemplate = load_bitmap(FCARDT, NULL); ERR_CHARG(sprites.cardTemplate)
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
