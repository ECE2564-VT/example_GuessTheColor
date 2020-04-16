/*
 * App_GuessTheColor.h
 *
 *  Created on: Dec 29, 2019
 *      Author: Matthew Zhong
 */

#ifndef APP_GUESSTHECOLOR_H_
#define APP_GUESSTHECOLOR_H_

#include <HAL/HAL.h>
#include <HAL/Graphics.h>
#include <HAL/Timer.h>

#define TITLE_SCREEN_WAIT   1000
#define RESULT_SCREEN_WAIT  2000

#define NUM_TEST_OPTIONS    4
#define NUM_RANDOM_NUMBERS  5

enum _GameState
{
    TITLE_SCREEN, INSTRUCTIONS_SCREEN, GAME_SCREEN, RESULT_SCREEN
};
typedef enum _GameState GameState;

enum _Cursor
{
    CURSOR_0 = 0, CURSOR_1 = 1, CURSOR_2 = 2, CURSOR_3 = 3
};
typedef enum _Cursor Cursor;

/**
 * The top-level Application object, initialized in the main() entry point and
 * passed around to basically every other function. Holds state variables
 * which YOU define as part of your application's state.
 */
struct _App_GuessTheColor
{
    GameState state;  // Determines which screen is currently shown
    SWTimer timer;    // General-purpose timer for when screens must disappear

    // Booleans to determine which colors the user has picked
    bool redSelected;
    bool greenSelected;
    bool blueSelected;

    // Cursor tracker variable
    Cursor cursor;

    // List of predetermined random numbers
    int randomNumbers[NUM_RANDOM_NUMBERS];
    int randomNumberChoice;
};
typedef struct _App_GuessTheColor App_GuessTheColor;

// Boilerplate constructor function for the Application
App_GuessTheColor App_GuessTheColor_construct(HAL* hal_p);
void App_GuessTheColor_loop(App_GuessTheColor* app_p, HAL* hal_p);

// Handle callback functions used for each state of the App_GuessTheColor_loop()
// function. State transitions are embedded inside of each of these functions.
void App_GuessTheColor_handleTitleScreen(App_GuessTheColor* app, HAL* hal);
void App_GuessTheColor_handleInstructionsScreen(App_GuessTheColor* app, HAL* hal_p);
void App_GuessTheColor_handleGameScreen(App_GuessTheColor* app, HAL* hal_p);
void App_GuessTheColor_handleResultScreen(App_GuessTheColor* app, HAL* hal_p);

// Helper functions which clear the screen and draw the text for each state
void App_GuessTheColor_showTitleScreen(GFX* gfx_p);
void App_GuessTheColor_showInstructionsScreen(App_GuessTheColor* app_p, GFX* gfx_p);
void App_GuessTheColor_showGameScreen(App_GuessTheColor* app_p, GFX* gfx_p);
void App_GuessTheColor_showResultScreen(App_GuessTheColor* app_p, HAL* hal_p);

// Helper function which reduces the number of redraws required when moving the
// cursor.
void App_GuessTheColor_updateGameScreen(App_GuessTheColor* app_p, GFX* gfx_p);

// Used to reset the internal game variables
void App_GuessTheColor_initGameVariables(App_GuessTheColor* app_p, HAL* hal_p);

#endif /* APP_GUESSTHECOLOR_H_ */
