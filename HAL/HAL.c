/*
 * HAL.c
 *
 *  Created on: Dec 29, 2019
 *      Author: Matthew Zhong
 */

#include <HAL/HAL.h>

/**
 * Constructs a new HAL object. The HAL constructor should simply call the constructors of each
 * of its sub-members with the proper inputs.
 *
 * @return a properly constructed HAL object.
 */
HAL HAL_construct()
{
    // The HAL object which will be returned at the end of construction
    HAL hal;

    // Initialize all LEDs by calling their constructors with correctly-defined arguments.
    hal.boosterpackRed   = LED_construct(BOOSTERPACK_LED_RED_PORT  , BOOSTERPACK_LED_RED_PIN  );
    hal.boosterpackGreen = LED_construct(BOOSTERPACK_LED_GREEN_PORT, BOOSTERPACK_LED_GREEN_PIN);
    hal.boosterpackBlue  = LED_construct(BOOSTERPACK_LED_BLUE_PORT , BOOSTERPACK_LED_BLUE_PIN );

    // Initialize all Buttons by calling their constructors with correctly-defined arguments.
    hal.boosterpackS1 = Button_construct(BOOSTERPACK_S1_PORT, BOOSTERPACK_S1_PIN);  // Boosterpack S1
    hal.boosterpackS2 = Button_construct(BOOSTERPACK_S2_PORT, BOOSTERPACK_S2_PIN);  // Boosterpack S2

    // Initialize the LCD by calling its constructor with user-defined foreground and background colors.
    hal.gfx = GFX_construct(GRAPHICS_COLOR_WHITE, GRAPHICS_COLOR_BLACK);

    // Once we have finished building the HAL, return the completed struct.
    return hal;
}

/**
 * Upon every new cycle of the main super-loop, we MUST UPDATE the status of
 * all inputs. In this program, this function is called only once in the
 * Application_loop() function. Since the Application_loop() function is called
 * once per loop of the while (true) loop in main, we are effectively polling
 * all inputs once per loop.
 *
 * @param hal_p:  The HAL whose input modules we wish to refresh
 */
void HAL_refresh(HAL* hal_p)
{
    // Refresh Boosterpack buttons
    Button_refresh(&hal_p->boosterpackS1);
    Button_refresh(&hal_p->boosterpackS2);
}
