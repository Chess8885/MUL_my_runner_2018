/*
** EPITECH PROJECT, 2018
** display a window
** File description:
** disp
*/

#include <stdlib.h>
#include "my.h"

void duck_tick(t_game *game)
{
    if (game->duck.seconds >= 0.12) {
        game->duck.rect.left = game->duck.rect.left - 126;
        if (game->duck.rect.left <= 0)
            game->duck.rect.left = 637.5;
        sfClock_restart(game->duck.clock);
    }

    game->duck.time = sfClock_getElapsedTime(game->duck.clock);
    game->duck.seconds = game->duck.time.microseconds / 1000000.0;
    game->duck.pos.x = game->duck.pos.x + 0.00f;
}

void poll_events(t_game *game)
{
    while (sfRenderWindow_pollEvent(game->engine.window,
                                    &game->engine.event.event)) {
        if (game->engine.event.event.type == sfEvtClosed)
            sfRenderWindow_close(game->engine.window);
        if (game->engine.event.event.type == sfEvtMouseButtonPressed) {
            check_duck_is_clicked(game);
        }
    }
}

void check_duck_is_clicked(t_game *game)
{
    game->engine.mouse.position =
        sfMouse_getPosition((sfWindow*) game->engine.window);
    if (game->engine.mouse.position.x > game->duck.pos.x &&
        game->engine.mouse.position.x < game->duck.pos.x + 110 &&
        game->engine.mouse.position.y > game->duck.pos.y &&
        game->engine.mouse.position.y < game->duck.pos.y + 110) {
        game->duck.pos.x = 0;
        game->duck.pos.y = 500;
        game->score.nb_score += 1;
        sfText_setString(game->score.text, int_to_text(game->score.nb_score));
    }
}

void free_game(t_game *game)
{
    sfRenderWindow_destroy(game->engine.window);
    sfTexture_destroy(game->engine.background.texture);
    sfSprite_destroy(game->engine.background.sprite);
    sfSound_destroy(game->sound.music);
    sfSoundBuffer_destroy(game->sound.soundbuffer);
    sfClock_destroy(game->duck.clock);
    sfSprite_destroy(game->duck.sprite);
    sfTexture_destroy(game->duck.texture);
    sfText_destroy(game->score.text);
    sfFont_destroy(game->score.font);
}

int main(int ac, char **av)
{
    t_game game;

    if ((check_help(ac, av)) == -1)
        return (-1);
    if (init_game(&game) == -1) {
        my_putstr("Could not init game\n", 1);
        return (-1);
    }
    loop_game(&game);
    free_game(&game);
    return (0);
}
