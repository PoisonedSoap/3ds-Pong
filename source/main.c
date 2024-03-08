#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <3ds.h>
#include <citro2d.h>
#include "PlayerPaddle.h"
#include "EnemyPaddle.h"
#include "Ball.h"

#define MAX_WIDTH 400
#define MAX_HEIGHT 240

PlayerPaddle player;
EnemyPaddle enemy;
Ball ball;

int main(int argc, char* argv[])
{
	gfxInitDefault();
	C3D_Init(C3D_DEFAULT_CMDBUF_SIZE);
	C2D_Init(C2D_DEFAULT_MAX_OBJECTS);
	C2D_Prepare();
	PrintConsole topScreen;
	consoleInit(GFX_BOTTOM, &topScreen);

	paddleMake(&player, 50.0f, 120.0f, 10.0f, 50.0f);
	paddleMake(&enemy, 350.0f, 120.0f, 10.0f, 50.0f);
	ballMake(&ball, 200.0f, 120.0f, 5.0, -4.0f, 4.0f);

	C3D_RenderTarget* top = C2D_CreateScreenTarget(GFX_TOP, GFX_LEFT);
	u32 clrWhite = C2D_Color32(0xFF, 0xFF, 0xFF, 0xFF);
	u32 clrClear = C2D_Color32(0x00, 0x00, 0x00, 0x00);


	// Main loop
	while (aptMainLoop())
	{
		gspWaitForVBlank();
		hidScanInput();

		// Your code goes here
		u32 kDown = hidKeysDown();
		u32 kHeld = hidKeysHeld();
		if (kDown & KEY_START)
			break; // break in order to return to hbmenu

		C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
		C2D_TargetClear(top, clrClear);
		C2D_SceneBegin(top);

		//Create Paddles and Ball
		paddleDraw(&player, clrWhite);
		paddleDraw(&enemy, clrWhite);
		ballDraw(&ball, clrWhite);

		playerMove(&player, kHeld);
		enemyMove(&enemy, &ball);
		ballMove(&ball);
		ballBounce(&ball, &player, &enemy);
		ballReset(&ball);

		consoleSelect(&topScreen);
		C3D_FrameEnd(0);
	}

	C2D_Fini();
	C3D_Fini();
	gfxExit();
	return 0;
}
