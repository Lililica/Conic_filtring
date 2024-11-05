#include "utils.hpp"

void draw_point(std::vector<Vector2> & v)
{
    for(Vector2 p : v)
    {
        DrawCircle(p.x, p.y, 3., RED);
    }
    if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        v.push_back(GetMousePosition());
    }
}