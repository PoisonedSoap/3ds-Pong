#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <3ds.h>
#include <citro2d.h>
#include "Paddle.h"

typedef struct Paddle PlayerPaddle;

void playerMove(PlayerPaddle *paddle, u32 key)
{
	if (key & KEY_DUP)
		if (paddle->yPos >= 0.0f)
			paddle->yPos -= 3.0f;
	if (key & KEY_DDOWN)
		if (paddle->yPos <= MAX_HEIGHT - paddle->width)
			paddle->yPos += 3.0f;
}