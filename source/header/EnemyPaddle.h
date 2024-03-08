#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <3ds.h>
#include <citro2d.h>
#include "Paddle.h"
#include "Ball.h"

typedef struct Paddle EnemyPaddle;

void enemyMove(EnemyPaddle* paddle, Ball* ball)
{
	if (ball->yPos > paddle->yPos + paddle->width)
		if (paddle->yPos <= 240 - 50)
			paddle->yPos += 2.5f;
	if (ball->yPos < paddle->yPos + paddle->width)
		if (paddle->yPos >= 0)
			paddle->yPos -= 2.5f;
}
