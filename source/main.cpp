#include <stdio.h>
#include <string>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <unistd.h>
#include <bits/stdc++.h>
#include "input.h"
#include "snake.h"
#include "snake_map.h"
#include <utility>
#include "macros.h"

// MAIN.CPP

using namespace std;

Snake snake;
SnakeMap snake_map(&snake);

void initialize()
{
    input_init();
    input_enter_off();
}

//checks if the game is over/the snake is dead

bool is_game_end()
{
    bool result = false;
    pair<int, int> snake_head = snake.snake_head;
    if (snake_head.first < 0 || snake_head.first >= MAP_WIDTH || snake_head.second < 0 || snake_head.second >= MAP_HEIGHT)
    {
        result = true;
    }
    if (snake.is_dead)
    {
        result = true;
    }
    return result;
}

//shows this message when game is over

void game_over()
{
    cout << "GAME OVER!" << endl;
}

//begins the game
//updates the snake movement 
//checks if game is over, ends the game when it is

void start_game()
{
    while (true)
    {
        snake.update_movement();
        if (is_game_end())
        {
            game_over();
            break;
        }
        snake_map.redraw();

        usleep(PAUSE_LENGTH);

        snake.validate_direction();
    }
}

int main()
{
    initialize();
    start_game();
    return 0;
}
