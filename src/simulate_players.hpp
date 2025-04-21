#pragma once
#include <raylib.h>
#include "functions.hpp"
#include "build_players.hpp"

class SimulatePlayers
{
public:
    SimulatePlayers(float win_size, float Xsize, float Osize)
        : win_size(win_size), Xsize(Xsize), Osize(Osize), align(90),
          X_00(align, align, Xsize),
          X_01(win_size / 2, align, Xsize),
          X_02(win_size - align, align, Xsize),
          X_10(align, win_size / 2, Xsize),
          X_11(win_size / 2, win_size / 2, Xsize),
          X_12(win_size - align, win_size / 2, Xsize),
          X_20(align, win_size - align, Xsize),
          X_21(win_size / 2, win_size - align, Xsize),
          X_22(win_size - align, win_size - align, Xsize),
          O_00(align, align),
          O_01(win_size / 2, align),
          O_02(win_size - align, align),
          O_10(align, win_size / 2),
          O_11(win_size / 2, win_size / 2),
          O_12(win_size - align, win_size / 2),
          O_20(align, win_size - align),
          O_21(win_size / 2, win_size - align),
          O_22(win_size - align, win_size - align)
    {
    }
    void AnimateX(PlayerX *X);
    void DrawX(PlayerX *X);
    void DrawAllX();
    void DrawXindex00();
    void DrawXindex01();
    void DrawXindex02();
    void DrawXindex10();
    void DrawXindex11();
    void DrawXindex12();
    void DrawXindex20();
    void DrawXindex21();
    void DrawXindex22();

    void AnimateO(PlayerO *O);
    void DrawO(PlayerO *O);
    void DrawAllO();
    void DrawOindex00();
    void DrawOindex01();
    void DrawOindex02();
    void DrawOindex10();
    void DrawOindex11();
    void DrawOindex12();
    void DrawOindex20();
    void DrawOindex21();
    void DrawOindex22();

private:
    float win_size;
    float Xsize;
    float Osize;
    float align;

public:
    // Building each X:
    PlayerX X_00; // Player X for board index [0][0]
    PlayerX X_01; // Player X for board index [0][1]
    PlayerX X_02; // Player X for board index [0][2]
    PlayerX X_10; // Player X for board index [1][0]
    PlayerX X_11; // Player X for board index [1][1]
    PlayerX X_12; // Player X for board index [1][2]
    PlayerX X_20; // Player X for board index [2][0]
    PlayerX X_21; // Player X for board index [2][1]
    PlayerX X_22; // Player X for board index [2][2]

    // Building each O:
    PlayerO O_00; // Player O for board index [0][0]
    PlayerO O_01; // Player O for board index [0][1]
    PlayerO O_02; // Player O for board index [0][2]
    PlayerO O_10; // Player O for board index [1][0]
    PlayerO O_11; // Player O for board index [1][1]
    PlayerO O_12; // Player O for board index [1][2]
    PlayerO O_20; // Player O for board index [2][0]
    PlayerO O_21; // Player O for board index [2][1]
    PlayerO O_22; // Player O for board index [2][2]
};
