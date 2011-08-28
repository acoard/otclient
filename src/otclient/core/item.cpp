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

#include "item.h"
#include "datmanager.h"
#include "spritemanager.h"
#include "thing.h"
#include <framework/platform/platform.h>

Item::Item() : Thing(THING_ITEM)
{
    m_count = 0;
    m_lastTicks = g_platform.getTicks();
    m_animation = 0;
}

void Item::draw(int x, int y)
{
    const ThingAttributes& attributes = g_dat.getItemAttributes(m_id);
    int xdiv = 0, ydiv = 0, zdiv = 0;


    if(attributes.animcount > 1) {
        if(g_platform.getTicks() - m_lastTicks > 500) {
            if(m_animation+1 == attributes.animcount)
                m_animation = 0;
            else
                m_animation++;

            m_lastTicks = g_platform.getTicks();
        }
    }

    if(attributes.group == THING_GROUP_SPLASH || attributes.group == THING_GROUP_FLUID) {
        //xdiv = m_count % attributes.xdiv;
        //ydiv = m_count / attributes.ydiv;

    }
    else if(attributes.stackable) {
        if(m_count < 5) {
            xdiv = m_count-1;
            ydiv = 0;
        }
        else if(m_count < 10) {
            xdiv = 0;
            ydiv = 1;
        }
        else if(m_count < 25) {
            xdiv = 1;
            ydiv = 1;
        }
        else if(m_count < 50) {
            xdiv = 2;
            ydiv = 1;
        }
        else if(m_count <= 100) {
            xdiv = 3;
            ydiv = 1;
        }
    }
    else if(!attributes.moveable) {
        xdiv = m_position.x % attributes.xdiv;
        ydiv = m_position.y % attributes.ydiv;
        zdiv = m_position.z % attributes.zdiv;
    }

    for(int b = 0; b < attributes.blendframes; b++)
        internalDraw(x, y, b, xdiv, ydiv, zdiv, m_animation);
}

const ThingAttributes& Item::getAttributes()
{
    return g_dat.getItemAttributes(m_id);
}
