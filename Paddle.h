#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <3ds.h>
#include <citro2d.h>

#define MAX_WIDTH 400
#define MAX_HEIGHT 240

struct Paddle
{
	float xPos;
	float yPos;
	float height;
	float width;
};

void paddleMake(struct Paddle* paddle, float x, float y, float height, float width)
{
	paddle->xPos = x;
	paddle->yPos = y;
	paddle->height = height;
	paddle->width = width;
}

void paddleDraw(struct Paddle* paddle, u32 color)
{
	C2D_DrawRectSolid(paddle->xPos, paddle->yPos, 0, paddle->height, paddle->width, color);
}