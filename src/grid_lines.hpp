#pragma once
#include <raylib.h>

class GridLines
{
public:
    GridLines(float win_size);
    void Draw();

private:
    // 1st horizantal grid line:
    Vector2 lineH1_start;
    Vector2 lineH1_end;
    // 2nd horizontal grid line:
    Vector2 lineH2_start;
    Vector2 lineH2_end;
    // 1st vertical grid line:
    Vector2 lineV1_start;
    Vector2 lineV1_end;
    // 2nd vertical grid line:
    Vector2 lineV2_start;
    Vector2 lineV2_end;
};