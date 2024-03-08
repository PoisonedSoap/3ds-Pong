#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <3ds.h>
#include <citro2d.h>
#include "Paddle.h"

#define MAX_WIDTH 400
#define MAX_HEIGHT 240

typedef struct Ball
{
	float xPos;
	float yPos;
	float radius;
	float xDelta;
	float yDelta;
} Ball;

void ballMake(Ball* ball, float x, float y, float r, float dx, float dy)
{
	ball->xPos = x;
	ball->yPos = y;
	ball->radius = r;
	ball->xDelta = dx;
	ball->yDelta = dy;
}

void ballDraw(Ball* ball, u32 color)
{
	C2D_DrawCircleSolid(ball->xPos, ball->yPos, 0, ball->radius, color);
}

void ballMove(Ball* ball)
{
	if ((ball->yPos < ball->radius / 2.0f) || (ball->yPos > 240 - ball->radius / 2.0f))
		ball->yDelta *= -1;

	 ball->yPos += ball->yDelta;
}

void ballBounce(Ball* ball, struct Paddle* padA, struct Paddle* padB)
{
	if ((ball->xPos < padA->xPos + padA->height && ball->xPos > padA->xPos) && (ball->yPos < padA->yPos + padA->width && ball->yPos > padA->yPos))
		ball->xDelta *= -1;

	if ((ball->xPos < padB->xPos + padB->height && ball->xPos > padB->xPos) && (ball->yPos < padB->yPos + padB->width && ball->yPos > padB->yPos))
		ball->xDelta *= -1;

	ball->xPos += ball->xDelta;
}

void ballReset(Ball* ball)
{
	if (ball->xPos > MAX_WIDTH || ball->xPos < 0.0f)
	{
		ball->xPos = 200.0f;
		ball->yPos = 120.0f;
	}
}

