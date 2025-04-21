#pragma once
#include <raylib.h>
class CrossOver
{
public:
    CrossOver(float win_size);
    void AnimateAll();
    void AnimateRow0();
    void AnimateRow1();
    void AnimateRow2();
    void AnimateColumn0();
    void AnimateColumn1();
    void AnimateColumn2();
    void AnimateDiagonal1();
    void AnimateDiagonal2();
    void DrawAll();
    void DrawRow0();
    void DrawRow1();
    void DrawRow2();
    void DrawColumn0();
    void DrawColumn1();
    void DrawColumn2();
    void DrawDiagonal1();
    void DrawDiagonal2();

private:
    // Horizontal cross overs:
    Vector2 CrossR0_start;
    Vector2 CrossR0_end;
    Vector2 CrossR1_start;
    Vector2 CrossR1_end;
    Vector2 CrossR2_start;
    Vector2 CrossR2_end;
    // Vertical cros overs:
    Vector2 CrossC0_start;
    Vector2 CrossC0_end;
    Vector2 CrossC1_start;
    Vector2 CrossC1_end;
    Vector2 CrossC2_start;
    Vector2 CrossC2_end;
    // Diagonal cross overs:
    Vector2 CrossD1_start;
    Vector2 CrossD1_current;
    Vector2 CrossD1_end;
    Vector2 CrossD2_start;
    Vector2 CrossD2_current;
    Vector2 CrossD2_end;

    float R_start;
    float R_end;
    float C_start;
    float C_end;
    float speed;
};