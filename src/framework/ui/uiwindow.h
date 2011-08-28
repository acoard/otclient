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

#ifndef UIWINDOW_H
#define UIWINDOW_H

#include "uiwidget.h"

class UIWindow : public UIWidget
{
public:
    virtual void setup();
    virtual void render();

    void setTitle(const std::string& title) { m_title = title; }
    std::string getTitle() const { return m_title; }

protected:
    virtual void onStyleApply(const OTMLNodePtr& styleNode);
    virtual void onGeometryUpdate(const Rect& oldRect, const Rect& newRect);
    virtual void onFocusChange(bool focused, FocusReason reason);
    virtual bool onMousePress(const Point& mousePos, MouseButton button);
    virtual bool onMouseRelease(const Point& mousePos, MouseButton button);
    virtual bool onMouseMove(const Point& mousePos, const Point& mouseMoved);

private:
    std::string m_title;
    bool m_moving;
    Point m_movingReference;

    // styling
    BorderImagePtr m_headImage;
    ImagePtr m_bodyImage;
    int m_headHeight;
    int m_headMargin;
    AlignmentFlag m_titleAlign;
};

#endif
