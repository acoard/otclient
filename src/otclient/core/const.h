/*
 * Copyright (c) 2010-2011 OTClient <https://github.com/edubart/otclient>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef OTCLIENT_CORE_CONST_H
#define OTCLIENT_CORE_CONST_H

#include <framework/util/color.h>

enum ThingAttributesGroup {
    THING_GROUP_NONE = 0,
    THING_GROUP_GROUND,
    THING_GROUP_CONTAINER,
    THING_GROUP_WEAPON,
    THING_GROUP_AMMUNITION,
    THING_GROUP_ARMOR,
    THING_GROUP_RUNE,
    THING_GROUP_TELEPORT,
    THING_GROUP_MAGICFIELD,
    THING_GROUP_WRITEABLE,
    THING_GROUP_KEY,
    THING_GROUP_SPLASH,
    THING_GROUP_FLUID,
    THING_GROUP_DOOR,
    THING_GROUP_LAST
};

enum ThingType {
    THING_ITEM,
    THING_CREATURE,
    THING_EFFECT,
    THING_SHOT
};

enum Direction {
    DIRECTION_NORTH,
    DIRECTION_EAST,
    DIRECTION_SOUTH,
    DIRECTION_WEST
};

enum SpriteMask {
    SpriteMaskRed = 0,
    SpriteMaskGreen,
    SpriteMaskBlue,
    SpriteMaskYellow,
    SpriteMaskNone = 255
};

static const Color OutfitColors[] = {
    Color(255,255,255),
    Color(255,212,191),
    Color(255,233,191),
    Color(255,255,191),
    Color(233,255,191),
    Color(212,255,191),
    Color(191,255,191),
    Color(191,255,212),
    Color(191,255,233),
    Color(191,255,255),
    Color(191,233,255),
    Color(191,212,255),
    Color(191,191,255),
    Color(212,191,255),
    Color(233,191,255),
    Color(255,191,255),
    Color(255,191,233),
    Color(255,191,212),
    Color(255,191,191),

    Color(128,128,128),
    Color(191,159,143),
    Color(191,175,143),
    Color(191,191,143),
    Color(175,191,143),
    Color(159,191,143),
    Color(143,191,143),
    Color(143,191,159),
    Color(143,191,175),
    Color(143,191,191),
    Color(143,175,191),
    Color(143,159,191),
    Color(143,143,191),
    Color(159,143,191),
    Color(175,143,191),
    Color(191,143,191),
    Color(191,143,175),
    Color(191,143,159),
    Color(191,143,143),

    Color(182,182,182),
    Color(191,127,95),
    Color(191,159,95),
    Color(191,191,95),
    Color(159,191,95),
    Color(127,191,95),
    Color(95,191,95),
    Color(95,191,127),
    Color(95,191,159),
    Color(95,191,191),
    Color(95,159,191),
    Color(95,127,191),
    Color(95,95,191),
    Color(127,95,191),
    Color(159,95,191),
    Color(191,95,191),
    Color(191,95,159),
    Color(191,95,127),
    Color(191,95,95),

    Color(145,145,145),
    Color(191,106,63),
    Color(191,148,63),
    Color(191,191,63),
    Color(148,191,63),
    Color(107,191,63),
    Color(63,191,63),
    Color(63,191,106),
    Color(63,191,148),
    Color(63,191,191),
    Color(63,148,191),
    Color(63,106,191),
    Color(63,63,191),
    Color(106,63,191),
    Color(148,63,191),
    Color(191,63,191),
    Color(191,63,148),
    Color(191,63,106),
    Color(191,63,63),

    Color(109,109,109),
    Color(255,85,0),
    Color(255,170,0),
    Color(255,255,0),
    Color(170,255,0),
    Color(84,255,0),
    Color(0,255,0),
    Color(0,255,84),
    Color(0,255,170),
    Color(0,255,255),
    Color(0,169,255),
    Color(0,85,255),
    Color(0,0,255),
    Color(85,0,255),
    Color(169,0,255),
    Color(254,0,255),
    Color(255,0,170),
    Color(255,0,85),
    Color(255,0,0),

    Color(72,72,72),
    Color(191,63,0),
    Color(191,127,0),
    Color(191,191,0),
    Color(127,191,0),
    Color(63,191,0),
    Color(0,191,0),
    Color(0,191,63),
    Color(0,191,127),
    Color(0,191,191),
    Color(0,127,191),
    Color(0,63,191),
    Color(0,0,191),
    Color(63,0,191),
    Color(127,0,191),
    Color(191,0,191),
    Color(191,0,127),
    Color(191,0,63),
    Color(191,0,0),

    Color(36,36,36),
    Color(127,42,0),
    Color(127,85,0),
    Color(127,127,0),
    Color(85,127,0),
    Color(42,127,0),
    Color(0,127,0),
    Color(0,127,42),
    Color(0,127,85),
    Color(0,127,127),
    Color(0,84,127),
    Color(0,42,127),
    Color(0,0,127),
    Color(42,0,127),
    Color(84,0,127),
    Color(127,0,127),
    Color(191,0,85),
    Color(127,0,42),
    Color(127,0,0)
};

#endif
