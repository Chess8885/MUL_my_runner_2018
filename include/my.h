/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** my.h
*/

#include <SFML/Graphics.h>
#include <SFML/System/Clock.h>
#include <SFML/System/Export.h>
#include <SFML/System/Types.h>
#include <SFML/System/Time.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Export.h>
#include <SFML/Audio/Sound.h>
#include <SFML/Config.h>
#include <SFML/Audio/Types.h>
#include <SFML/Audio/Export.h>
#include <SFML/Audio/SoundStatus.h>
#include <SFML/Audio/SoundBuffer.h>
#include <SFML/System/Clock.h>
#include <SFML/System/Export.h>
#include <SFML/System/Vector2.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Window/Event.h>
#include <string.h>

struct s_event {
    sfEvent event;
};

typedef struct s_event t_event;

struct s_mouse {
    sfVector2i position;
};

typedef struct s_mouse t_mouse;

struct s_background {
    sfTexture *background;
    sfSprite *sprite_background;
    sfTexture *texture;
    sfSprite *sprite;
    sfTexture *texture_second;
    sfSprite *sprite_second;
    sfTexture *texture_third;
    sfSprite *sprite_third;
    sfVector2f pos_texture;
    sfVector2f pos_second;
    sfVector2f pos_third;
    sfVector2f pos_clone1;
    sfVector2f pos_clone2;
    sfVector2f pos_clone3;
};

typedef struct s_background t_background;

struct s_duck {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfClock *clock;
    sfTime time;
    double seconds;
    sfIntRect rect;
};

typedef struct s_duck t_duck;

struct s_engine {
    sfVideoMode video_mode;
    sfRenderWindow *window;
    t_event event;
    t_mouse mouse;
    t_background background;
};

typedef struct s_engine t_engine;

struct s_score {
    sfText *text;
    sfVector2f score_pos;
    sfFont *font;
    sfColor color;
    int nb_score;
};

typedef struct s_score t_score;

struct s_sound {
    sfSoundBuffer *soundbuffer;
    sfSound *music;
};

typedef struct s_sound t_sound;

struct s_game {
    t_engine engine;
    t_score score;
    t_sound sound;
    t_duck duck;
};

typedef struct s_game t_game;

char *int_to_text(int nb);
void my_putchar(char c);
int my_strlen(const char *str);
void my_putstr(const char *str, int filedes);
int check_help(int ac, char **av);
int my_strcmp(char const *s1, char const *s2);
void poll_events(t_game *game);
void draw_game(t_game *game);
void duck_tick(t_game *game);
void check_duck_is_clicked(t_game *game);
int init_engine(t_game *game);
int init_engine_next(t_game *game);
int init_score(t_game *game);
int init_duck(t_game *game);
int init_sound(t_game *game);
int init_game(t_game *game);
void loop_game(t_game *game);
void draw_game(t_game *game);
void draw_game_next(t_game *game);
void move_background(t_game *game);
void move_background_next(t_game *game);
void set_background(t_game *game);
