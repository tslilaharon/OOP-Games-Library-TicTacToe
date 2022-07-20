#pragma once
#include <iostream>

class Move
{
public:
    Move() {};
    Move(int x, int y) { m_x = x; m_y = y; }
   
    void setX(int x) { m_x = x; }
    int getX()const { return m_x; }

    void setY(int y) { m_y = y; }
    int getY()const { return m_y; }

private:
    int m_x;
    int m_y;
};