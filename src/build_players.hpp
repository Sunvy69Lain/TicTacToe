#pragma once
#include <raylib.h>

class PlayerX
{
public:
    PlayerX(float offsetX, float offsetY, float Xsize)
    {
        float center = -Xsize / 2;

        // Line 1 coordinates:
        float start_x1 = offsetX + 0;
        float start_y1 = offsetY + 0;
        float end_x1 = offsetX + Xsize;
        float end_y1 = offsetY + Xsize;
        // Line 2 coordinates:
        float start_x2 = offsetX + 0;
        float start_y2 = offsetY + Xsize;
        float end_x2 = offsetX + Xsize;
        float end_y2 = offsetY + 0;

        // Coordinates of the 1st line for building X:
        line1_start = {start_x1 + center, start_y1 + center};
        line1_current = line1_start;
        line1_end = {end_x1 + center, end_y1 + center};
        // Coordinates of the 2nd line for building X:
        line2_start = {start_x2 + center, start_y2 + center};
        line2_current = line2_start;
        line2_end = {end_x2 + center, end_y2 + center};
    }

    Vector2 line1_start;
    Vector2 line1_current;
    Vector2 line1_end;
    Vector2 line2_start;
    Vector2 line2_current;
    Vector2 line2_end;
};

class PlayerO
{
public:
    PlayerO(float pos_x, float pos_y) : position{pos_x, pos_y}, Oarc_start(-135), Oarc_current(Oarc_start), Oarc_end(Oarc_start + 360)
    {
    }

    Vector2 position;
    float Oarc_start;
    float Oarc_current;
    float Oarc_end;
};