#include "grid_lines.hpp"

GridLines::GridLines(float win_size)
{
    lineH1_start = {win_size / 20, win_size / 3};
    lineH1_end = {win_size - (win_size / 20), win_size / 3};
    lineH2_start = {win_size / 20, win_size - (win_size / 3)};
    lineH2_end = {win_size - (win_size / 20), win_size - (win_size / 3)};
    lineV1_start = {win_size / 3, win_size / 20};
    lineV1_end = {win_size / 3, win_size - (win_size / 20)};
    lineV2_start = {win_size - (win_size / 3), win_size / 20};
    lineV2_end = {win_size - (win_size / 3), win_size - (win_size / 20)};
}

void GridLines::Draw()
{
    DrawLineEx(lineH1_start, lineH1_end, 6, BLACK);
    DrawLineEx(lineH2_start, lineH2_end, 6, BLACK);
    DrawLineEx(lineV1_start, lineV1_end, 6, BLACK);
    DrawLineEx(lineV2_start, lineV2_end, 6, BLACK);
}