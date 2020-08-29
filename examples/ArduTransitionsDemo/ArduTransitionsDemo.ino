// Copyright (c) 2020 Jon Thysell <http://jonthysell.com>
// Licensed under the MIT License.

#include <Arduboy2.h>

#include <ArduTransitions.h>

#define FRAMERATE 60

Arduboy2 arduboy;

void setup()
{
    arduboy.begin();
    arduboy.setFrameRate(FRAMERATE);
    arduboy.initRandomSeed();
    arduboy.fillScreen(WHITE);
}

#define transitionTest(transitionFunc) \
arduboy.clear(); \
arduboy.setCursor(WIDTH / 4, HEIGHT / 4); \
arduboy.println(F(#transitionFunc)); \
arduboy.display(); \
transitionFunc(&arduboy, 2 * FRAMERATE, WHITE); \

void loop()
{
    if (!(arduboy.nextFrame()))
    {
      return;
    }

    transitionTest(wipeLeft);
    transitionTest(wipeRight);
    transitionTest(wipeUp);
    transitionTest(wipeDown);
    transitionTest(wipeUpLeft);
    transitionTest(wipeUpRight);
    transitionTest(wipeDownLeft);
    transitionTest(wipeDownRight);
}
