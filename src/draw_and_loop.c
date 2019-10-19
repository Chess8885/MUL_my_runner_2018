/*
** EPITECH PROJECT, 2018
** my_hunter
** File description:
** draw and loop
*/

#include "my.h"

int init_engine_next(t_game *game)
{
    sfSprite_setTexture(game->engine.background.sprite_background,
                        game->engine.background.background, sfTrue);
    sfSprite_setTexture(game->engine.background.sprite,
                        game->engine.background.texture, sfTrue);
    sfSprite_setTexture(game->engine.background.sprite_second,
                        game->engine.background.texture_second, sfTrue);
    sfSprite_setTexture(game->engine.background.sprite_third,
                        game->engine.background.texture_third, sfTrue);
    game->engine.background.pos_clone1.x = 800;
    game->engine.background.pos_clone2.x = 800;
    game->engine.background.pos_clone3.x = 800;
    game->engine.background.pos_third.y = 0;
    game->engine.background.pos_clone3.y = 0;
    return (0);
}

void loop_game(t_game *game)
{
    while (sfRenderWindow_isOpen(game->engine.window)) {
        draw_game(game);
        draw_game_next(game);
        move_background(game);
        move_background_next(game);
        duck_tick(game);
        poll_events(game);
    }
}

void draw_game_next(t_game *game)
{
    sfSprite_setPosition(game->engine.background.sprite_second,
                        game->engine.background.pos_clone2);
    sfRenderWindow_drawSprite(game->engine.window,
                        game->engine.background.sprite_second, NULL);
    sfSprite_setPosition(game->engine.background.sprite_third,
                        game->engine.background.pos_third);
    sfRenderWindow_drawSprite(game->engine.window,
                        game->engine.background.sprite_third, NULL);
    sfSprite_setPosition(game->engine.background.sprite_third,
                        game->engine.background.pos_clone3);
    sfRenderWindow_drawSprite(game->engine.window,
                        game->engine.background.sprite_third, NULL);
    sfSprite_setTextureRect(game->duck.sprite, game->duck.rect);
    sfSprite_setPosition(game->duck.sprite, game->duck.pos);
    sfRenderWindow_drawSprite(game->engine.window, game->duck.sprite, NULL);
    sfRenderWindow_drawText(game->engine.window, game->score.text, 0);
    sfRenderWindow_display(game->engine.window);
    sfRenderWindow_clear(game->engine.window, sfBlack);
}

void draw_game(t_game *game)
{
    sfRenderWindow_drawSprite(game->engine.window,
                        game->engine.background.sprite_background, NULL);
    sfSprite_setPosition(game->engine.background.sprite,
                        game->engine.background.pos_texture);
    sfRenderWindow_drawSprite(game->engine.window,
                        game->engine.background.sprite, NULL);
    sfSprite_setPosition(game->engine.background.sprite,
                        game->engine.background.pos_clone1);
    sfRenderWindow_drawSprite(game->engine.window,
                        game->engine.background.sprite, NULL);
    sfSprite_setPosition(game->engine.background.sprite_second,
                        game->engine.background.pos_second);
    sfRenderWindow_drawSprite(game->engine.window,
                        game->engine.background.sprite_second, NULL);
}
