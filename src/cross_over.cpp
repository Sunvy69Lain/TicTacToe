#include "cross_over.hpp"

Color red = {255, 0, 70, 200};

// Constructor:
CrossOver::CrossOver(float win_size)
    : R_start(win_size / 15), R_end(win_size - (win_size / 15)), C_start(win_size / 15), C_end(win_size - (win_size / 15)), speed(16)
{
    // Horizontal cross overs:
    CrossR0_start = {R_start, ((win_size / 3) + 15) / 2};
    CrossR0_end = {R_start, ((win_size / 3) + 15) / 2};

    CrossR1_start = {R_start, win_size / 2};
    CrossR1_end = {R_start, win_size / 2};

    CrossR2_start = {R_start, win_size - (((win_size / 3) + 15) / 2)};
    CrossR2_end = {R_start, win_size - (((win_size / 3) + 15) / 2)};

    // Virtical cross overs:
    CrossC0_start = {((win_size / 3) + 15) / 2, C_start};
    CrossC0_end = {((win_size / 3) + 15) / 2, C_start};

    CrossC1_start = {win_size / 2, C_start};
    CrossC1_end = {win_size / 2, C_start};

    CrossC2_start = {win_size - (((win_size / 3) + 15) / 2), C_start};
    CrossC2_end = {win_size - (((win_size / 3) + 15) / 2), C_start};

    // Diagonal cross overs:
    CrossD1_start = {win_size / 11, win_size / 11};
    CrossD1_current = CrossD1_start;
    CrossD1_end = {win_size - (win_size / 11), win_size - (win_size / 11)};

    CrossD2_start = {win_size / 11, win_size - (win_size / 11)};
    CrossD2_current = CrossD2_start;
    CrossD2_end = {win_size - (win_size / 11), win_size / 11};
};

// Update methods:
void CrossOver::AnimateAll()
{
    AnimateRow0();
    AnimateRow1();
    AnimateRow2();
    AnimateColumn0();
    AnimateColumn1();
    AnimateColumn2();
    AnimateDiagonal1();
    AnimateDiagonal2();
}
void CrossOver::AnimateRow0()
{
    if (CrossR0_end.x < R_end)
        CrossR0_end.x += speed;
    if (CrossR0_end.x > R_end)
        CrossR0_end.x = R_end;
}
void CrossOver::AnimateRow1()
{
    if (CrossR1_end.x < R_end)
        CrossR1_end.x += speed;
    if (CrossR1_end.x > R_end)
        CrossR1_end.x = R_end;
}
void CrossOver::AnimateRow2()
{
    if (CrossR2_end.x < R_end)
        CrossR2_end.x += speed;
    if (CrossR2_end.x > R_end)
        CrossR2_end.x = R_end;
}
void CrossOver::AnimateColumn0()
{
    if (CrossC0_end.y < C_end)
        CrossC0_end.y += speed;
    if (CrossC0_end.y > C_end)
        CrossC0_end.y = C_end;
}
void CrossOver::AnimateColumn1()
{
    if (CrossC1_end.y < C_end)
        CrossC1_end.y += speed;
    if (CrossC1_end.y > C_end)
        CrossC1_end.y = C_end;
}
void CrossOver::AnimateColumn2()
{
    if (CrossC2_end.y < C_end)
        CrossC2_end.y += speed;
    if (CrossC2_end.y > C_end)
        CrossC2_end.y = C_end;
}
void CrossOver::AnimateDiagonal1()
{
    if (CrossD1_current.x < CrossD1_end.x && CrossD1_current.y < CrossD1_end.y)
    {
        CrossD1_current.x += speed;
        CrossD1_current.y += speed;
    }
    if (CrossD1_current.x > CrossD1_end.x && CrossD1_current.y > CrossD1_end.y)
        CrossD1_current = CrossD1_end;
}
void CrossOver::AnimateDiagonal2()
{
    if (CrossD2_current.x < CrossD2_end.x && CrossD2_current.y > CrossD2_end.y)
    {
        CrossD2_current.x += speed;
        CrossD2_current.y -= speed;
    }
    if (CrossD2_current.x > CrossD2_end.x && CrossD2_current.y < CrossD2_end.y)
        CrossD2_current = CrossD2_end;
}

// Draw methods:
void CrossOver::DrawAll()
{
    DrawRow0();
    DrawRow1();
    DrawRow2();
    DrawColumn0();
    DrawColumn1();
    DrawColumn2();
    DrawDiagonal1();
    DrawDiagonal2();
}
void CrossOver::DrawRow0()
{
    AnimateRow0();
    DrawLineEx(CrossR0_start, CrossR0_end, 7, red);
}
void CrossOver::DrawRow1()
{
    AnimateRow1();
    DrawLineEx(CrossR1_start, CrossR1_end, 7, red);
}
void CrossOver::DrawRow2()
{
    AnimateRow2();
    DrawLineEx(CrossR2_start, CrossR2_end, 7, red);
}
void CrossOver::DrawColumn0()
{
    AnimateColumn0();
    DrawLineEx(CrossC0_start, CrossC0_end, 7, red);
}
void CrossOver::DrawColumn1()
{
    AnimateColumn1();
    DrawLineEx(CrossC1_start, CrossC1_end, 7, red);
}
void CrossOver::DrawColumn2()
{
    AnimateColumn2();
    DrawLineEx(CrossC2_start, CrossC2_end, 7, red);
}
void CrossOver::DrawDiagonal1()
{
    AnimateDiagonal1();
    DrawLineEx(CrossD1_start, CrossD1_current, 7, red);
}
void CrossOver::DrawDiagonal2()
{
    AnimateDiagonal2();
    DrawLineEx(CrossD2_start, CrossD2_current, 7, red);
}
