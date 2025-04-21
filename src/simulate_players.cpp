#include "simulate_players.hpp"

void SimulatePlayers::AnimateX(PlayerX *X)
{
    float speed = 4;

    if (X->line1_current.x < X->line1_end.x && X->line1_current.y < X->line1_end.y)
    {
        X->line1_current.x += speed;
        X->line1_current.y += speed;
        if (X->line1_current.x > X->line1_end.x && X->line1_current.y > X->line1_end.y)
            X->line1_current = X->line1_end;
    }

    if (X->line2_current.x < X->line2_end.x && X->line2_current.y > X->line2_end.y)
    {
        X->line2_current.x += speed;
        X->line2_current.y -= speed;
        if (X->line2_current.x > X->line2_end.x && X->line2_current.y < X->line2_end.y)
            X->line2_current = X->line2_end;
    }
}

void SimulatePlayers::DrawX(PlayerX *X)
{
    AnimateX(X);
    DrawLineEx(X->line1_start, X->line1_current, 10, BLUE);
    DrawLineEx(X->line2_start, X->line2_current, 10, BLUE);
}
void SimulatePlayers::DrawAllX()
{

    DrawXindex00();
    DrawXindex01();
    DrawXindex02();
    DrawXindex10();
    DrawXindex11();
    DrawXindex12();
    DrawXindex20();
    DrawXindex21();
    DrawXindex22();
}
void SimulatePlayers::DrawXindex00() { DrawX(&X_00); } // Draw X for board index [0][0]
void SimulatePlayers::DrawXindex01() { DrawX(&X_01); } // Draw X for board index [0][1]
void SimulatePlayers::DrawXindex02() { DrawX(&X_02); } // Draw X for board index [0][2]
void SimulatePlayers::DrawXindex10() { DrawX(&X_10); } // Draw X for board index [1][0]
void SimulatePlayers::DrawXindex11() { DrawX(&X_11); } // Draw X for board index [1][1]
void SimulatePlayers::DrawXindex12() { DrawX(&X_12); } // Draw X for board index [1][2]
void SimulatePlayers::DrawXindex20() { DrawX(&X_20); } // Draw X for board index [2][0]
void SimulatePlayers::DrawXindex21() { DrawX(&X_21); } // Draw X for board index [2][1]
void SimulatePlayers::DrawXindex22() { DrawX(&X_22); } // Draw X for board index [2][2]

void SimulatePlayers::AnimateO(PlayerO *O)
{
    if (O->Oarc_current < O->Oarc_end)
    {
        O->Oarc_current += 20;
        if (O->Oarc_current > O->Oarc_end)
            O->Oarc_current = O->Oarc_end;
    }
}
void SimulatePlayers::DrawO(PlayerO *O)
{
    AnimateO(O);
    DrawArc(O->position, Osize * 0.65f, O->Oarc_start, O->Oarc_current, 100, 10, BLUE);
}
void SimulatePlayers::DrawAllO()
{
    DrawOindex00();
    DrawOindex01();
    DrawOindex02();
    DrawOindex10();
    DrawOindex11();
    DrawOindex12();
    DrawOindex20();
    DrawOindex21();
    DrawOindex22();
}
void SimulatePlayers::DrawOindex00() { DrawO(&O_00); } // Draw O for board index [0][0]
void SimulatePlayers::DrawOindex01() { DrawO(&O_01); } // Draw O for board index [0][1]
void SimulatePlayers::DrawOindex02() { DrawO(&O_02); } // Draw O for board index [0][2]
void SimulatePlayers::DrawOindex10() { DrawO(&O_10); } // Draw O for board index [1][0]
void SimulatePlayers::DrawOindex11() { DrawO(&O_11); } // Draw O for board index [1][1]
void SimulatePlayers::DrawOindex12() { DrawO(&O_12); } // Draw O for board index [1][2]
void SimulatePlayers::DrawOindex20() { DrawO(&O_20); } // Draw O for board index [2][0]
void SimulatePlayers::DrawOindex21() { DrawO(&O_21); } // Draw O for board index [2][1]
void SimulatePlayers::DrawOindex22() { DrawO(&O_22); } // Draw O for board index [2][2]
