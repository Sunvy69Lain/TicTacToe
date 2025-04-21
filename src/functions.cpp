#include "functions.hpp"

void DrawArc(Vector2 center, float radius, float startAngle, float endAngle, int segments, float thickness, Color color)
{
    float angleStep_unit = (endAngle - startAngle) / segments;

    for (int currentStep = 0; currentStep < segments; currentStep++)
    {
        float angleStep_start = (startAngle + (currentStep * angleStep_unit)) * DEG2RAD;
        float angleStep_end = (startAngle + ((currentStep + 1) * angleStep_unit)) * DEG2RAD;

        // Segment line coordinates:
        Vector2 lineStart =
            {
                center.x + radius * cosf(angleStep_start), // x axis of the radius's tip in the angle's starting step.
                center.y + radius * sinf(angleStep_start)  // y axis of the radius's tip in the angle's starting step.
            };

        Vector2 lineEnd =
            {
                center.x + radius * cosf(angleStep_end), // x axis of the radius's tip in the angle's ending step.
                center.y + radius * sinf(angleStep_end)  // y axis of the radius's tip in the angle's ending step.
            };

        // Drawing segments:
        DrawLineEx(lineStart, lineEnd, thickness, GREEN);
        // Smoothening arc:
        DrawCircleV(lineStart, thickness / 2.0f, color);
        DrawCircleV(lineEnd, thickness / 2.0f, color);
    }
}