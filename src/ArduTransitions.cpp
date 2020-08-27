// Copyright (c) 2020 Jon Thysell <http://jonthysell.com>
// Licensed under the MIT License.

#include <Arduboy2.h>

#include "ArduTransitions.h"

void transition(const Arduboy2Base* arduboy, const uint16_t frames, const uint8_t color, void (*f)(const Arduboy2Base*, const float, const uint8_t))
{
    uint16_t startFrame = arduboy->frameCount;
    uint16_t endFrame = startFrame + frames;

    if (endFrame > startFrame)
    {
        while (true)
        {
            if (arduboy->nextFrame())
            {
                uint16_t currentFrame = arduboy->frameCount;

                if (currentFrame >= endFrame)
                {
                    break;
                }

                float percentage = (float)(currentFrame - startFrame) / (float)(endFrame - startFrame);

                f(arduboy, percentage, color);

                arduboy->display();
            }
            else
            {
                arduboy->idle();
            }
        }
    }

    arduboy->fillScreen(color);
    arduboy->display();
}

void wipeLeftFunc(const Arduboy2Base* arduboy, const float percentage, const uint8_t color)
{
    uint8_t partialWidth = (uint8_t)round(percentage * WIDTH);
    arduboy->fillRect(WIDTH - partialWidth, 0, partialWidth, HEIGHT, color);
}

void wipeLeft(const Arduboy2Base* arduboy, const uint16_t frames, const uint8_t color)
{
    transition(arduboy, frames, color, wipeLeftFunc);
}

void wipeRightFunc(const Arduboy2Base* arduboy, const float percentage, const uint8_t color)
{
    uint8_t partialWidth = (uint8_t)round(percentage * WIDTH);
    arduboy->fillRect(0, 0, partialWidth, HEIGHT, color);
}

void wipeRight(const Arduboy2Base* arduboy, const uint16_t frames, const uint8_t color)
{
    transition(arduboy, frames, color, wipeRightFunc);
}

void wipeUpFunc(const Arduboy2Base* arduboy, const float percentage, const uint8_t color)
{
    uint8_t partialHeight = (uint8_t)round(percentage * HEIGHT);
    arduboy->fillRect(0, HEIGHT - partialHeight, WIDTH, partialHeight, color);
}

void wipeUp(const Arduboy2Base* arduboy, const uint16_t frames, const uint8_t color)
{
    transition(arduboy, frames, color, wipeUpFunc);
}

void wipeDownFunc(const Arduboy2Base* arduboy, const float percentage, const uint8_t color)
{
    uint8_t partialHeight = (uint8_t)round(percentage * HEIGHT);
    arduboy->fillRect(0, 0, WIDTH, partialHeight, color);
}

void wipeDown(const Arduboy2Base* arduboy, const uint16_t frames, const uint8_t color)
{
    transition(arduboy, frames, color, wipeDownFunc);
}

void wipeUpLeftFunc(const Arduboy2Base* arduboy, const float percentage, const uint8_t color)
{
    uint8_t partialWidth = (uint8_t)round(percentage * WIDTH);
    uint8_t partialHeight = (uint8_t)round(percentage * HEIGHT);
    arduboy->fillTriangle(WIDTH - 2 * partialWidth, HEIGHT, 2 * WIDTH - partialWidth, 2 * HEIGHT - partialHeight, WIDTH, HEIGHT - 2 * partialHeight, color);
}

void wipeUpLeft(const Arduboy2Base* arduboy, const uint16_t frames, const uint8_t color)
{
    transition(arduboy, frames, color, wipeUpLeftFunc);
}

void wipeUpRightFunc(const Arduboy2Base* arduboy, const float percentage, const uint8_t color)
{
    uint8_t partialWidth = (uint8_t)round(percentage * WIDTH);
    uint8_t partialHeight = (uint8_t)round(percentage * HEIGHT);
    arduboy->fillTriangle(2 * partialWidth, HEIGHT, 2 * partialWidth - WIDTH, 2 * HEIGHT - partialHeight, 0, HEIGHT - 2 * partialHeight, color);
}

void wipeUpRight(const Arduboy2Base* arduboy, const uint16_t frames, const uint8_t color)
{
    transition(arduboy, frames, color, wipeUpRightFunc);
}

void wipeDownLeftFunc(const Arduboy2Base* arduboy, const float percentage, const uint8_t color)
{
    uint8_t partialWidth = (uint8_t)round(percentage * WIDTH);
    uint8_t partialHeight = (uint8_t)round(percentage * HEIGHT);
    arduboy->fillTriangle(WIDTH - 2 * partialWidth, 0, 2 * WIDTH - partialWidth, 2 * partialHeight - HEIGHT, WIDTH, 2 * partialHeight, color);
}

void wipeDownLeft(const Arduboy2Base* arduboy, const uint16_t frames, const uint8_t color)
{
    transition(arduboy, frames, color, wipeDownLeftFunc);
}

void wipeDownRightFunc(const Arduboy2Base* arduboy, const float percentage, const uint8_t color)
{
    uint8_t partialWidth = (uint8_t)round(percentage * WIDTH);
    uint8_t partialHeight = (uint8_t)round(percentage * HEIGHT);
    arduboy->fillTriangle(2 * partialWidth, 0, 2 * partialWidth - WIDTH, 2 * partialHeight - HEIGHT, 0, 2 * partialHeight, color);
}

void wipeDownRight(const Arduboy2Base* arduboy, const uint16_t frames, const uint8_t color)
{
    transition(arduboy, frames, color, wipeDownRightFunc);
}
