// Copyright (c) 2020 Jon Thysell <http://jonthysell.com>
// Licensed under the MIT License.

#include <Arduboy2.h>

#ifndef ARDUTRANSITIONS_H
#define ARDUTRANSITIONS_H

void wipeLeft(const Arduboy2Base* arduboy, const uint16_t frames, const uint8_t color = WHITE);
void wipeRight(const Arduboy2Base* arduboy, const uint16_t frames, const uint8_t color = WHITE);
void wipeUp(const Arduboy2Base* arduboy, const uint16_t frames, const uint8_t color = WHITE);
void wipeDown(const Arduboy2Base* arduboy, const uint16_t frames, const uint8_t color = WHITE);
void wipeUpLeft(const Arduboy2Base* arduboy, const uint16_t frames, const uint8_t color = WHITE);
void wipeUpRight(const Arduboy2Base* arduboy, const uint16_t frames, const uint8_t color = WHITE);
void wipeDownLeft(const Arduboy2Base* arduboy, const uint16_t frames, const uint8_t color = WHITE);
void wipeDownRight(const Arduboy2Base* arduboy, const uint16_t frames, const uint8_t color = WHITE);

#endif
