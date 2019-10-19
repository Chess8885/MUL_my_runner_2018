/*
** EPITECH PROJECT, 2019
** my_runner
** File description:
** background animation parallax
*/

#include "my.h"

void move_background_next(t_game *game)
{
    if (game->engine.background.pos_texture.x <= -800) {
        game->engine.background.pos_texture.x = 800;
    }
    if (game->engine.background.pos_second.x <= -800) {
        game->engine.background.pos_second.x = 800;
    }
    if (game->engine.background.pos_third.x <= -800) {
        game->engine.background.pos_third.x = 800;
    }
    if (game->engine.background.pos_clone1.x <= -800) {
        game->engine.background.pos_clone1.x = 800;
    }
    if (game->engine.background.pos_clone2.x <= -800) {
        game->engine.background.pos_clone2.x = 800;
    }
    if (game->engine.background.pos_clone3.x <= -800) {
        game->engine.background.pos_clone3.x = 800;
    }
}

void move_background(t_game *game)
{
    game->engine.background.pos_texture.x -= 0.05;
    game->engine.background.pos_second.x -= 0.08;
    game->engine.background.pos_third.x -= 1.3;
    game->engine.background.pos_clone1.x -= 0.05;
    game->engine.background.pos_clone2.x -= 0.08;
    game->engine.background.pos_clone3.x -= 1.3;
}
