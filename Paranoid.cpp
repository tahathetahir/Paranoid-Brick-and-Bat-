#include <iostream>
#include <time.h>
#include <cmath>
#include <conio.h>
#include "mygraphics.h"
#include "myconsole.h"
#include <fstream>
#include <Windows.h>
#include <string>


//---------------------------------------------GLOBAL VARIABLES------------------------------------
int arr[3][5];
float speed = 0.75;
int high_score;

//-------------------------------------FUNCTIONS FOR MOTION OF BALL--------------------------------
void upLeft(float& x1, float& y1, float& x2, float& y2)
{
	x1 -= 0.125 * speed;
	x2 -= 0.125 * speed;
	y1 -= 0.216 * speed;
	y2 -= 0.216 * speed;
}
void upLeftMost(float& x1, float& y1, float& x2, float& y2)
{
	x1 -= 0.216 * speed;
	x2 -= 0.216 * speed;
	y1 -= 0.125 * speed;
	y2 -= 0.125 * speed;
}
void upLRight(float& x1, float& y1, float& x2, float& y2)
{
	x1 += 0.125 * speed;
	x2 += 0.125 * speed;
	y1 -= 0.216 * speed;
	y2 -= 0.216 * speed;
}
void upRightMost(float& x1, float& y1, float& x2, float& y2)
{
	x1 += 0.216 * speed;
	x2 += 0.216 * speed;
	y1 -= 0.125 * speed;
	y2 -= 0.125 * speed;
}
void downLeft(float& x1, float& y1, float& x2, float& y2)
{
	x1 -= 0.125 * speed;
	x2 -= 0.125 * speed;
	y1 += 0.216 * speed;
	y2 += 0.216 * speed;
}
void downLeftMost(float& x1, float& y1, float& x2, float& y2)
{
	x1 -= 0.216 * speed;
	x2 -= 0.216 * speed;
	y1 += 0.125 * speed;
	y2 += 0.125 * speed;
}
void downRight(float& x1, float& y1, float& x2, float& y2)
{
	x1 += 0.125 * speed;
	x2 += 0.125 * speed;
	y1 += 0.216 * speed;
	y2 += 0.216 * speed;
}
void downRightMost(float& x1, float& y1, float& x2, float& y2)
{
	x1 += 0.216 * speed;
	x2 += 0.216 * speed;
	y1 += 0.125 * speed;
	y2 += 0.125 * speed;
}
void straightUp(float& x1, float& y1, float& x2, float& y2)
{

	y1 -= 0.25 * speed;
	y2 -= 0.25 * speed;
}
void straightDown(float& x1, float& y1, float& x2, float& y2)
{
	
	y1 += 0.25 * speed;
	y2 += 0.25 * speed;
}

int Random(int i, int j)
{
	int random = i * j + static_cast<unsigned int>(time(0));
	Sleep(300);
	random = ((random * 7621) + 1) % 32768; ;

	return random;

}

void character(int score, char plz[])
{
	
	int i = 0;
	//506--> 50 --> 5
	while (score > 0) {

	
		plz[i++] = score%10 + '0';
		score /= 10;
		

	}

	for (int p = 0; p < i/2; p++)
	{
		char temp = plz[p];
		plz[p] = plz[i - p - 1];
		plz[i - p - 1] = temp;
	}
	

	
	char str1[] = "SCORE : ";
	myDrawTextWithFont(700, 530, 40, str1, RGB(255, 255, 255), RGB(0, 0, 0));
	myDrawTextWithFont(800, 530, 40, plz, RGB(255, 255, 255), RGB(0, 0, 0));

}

void lifelost()
{
	bool life = 1;
	while (life)
	{
		char lifs[] = "Life Lost [L]";
		myDrawTextWithFont(300, 300, 80, lifs, RGB(255,0, 0), RGB(255,255, 255));


		char ch = CheckKeyPressed();

		if (ch == 'l' || ch == 'L')
		{
			myDrawTextWithFont(300, 300, 80, lifs, RGB(0, 0, 0), RGB(0, 0, 0));
			life = 0;
		}
	}
}

void Instructions(void)
{

	bool instructions = false;
	char INo[] = "INSTRUCTIONS [I]";
	if (!instructions)
	{
		myDrawTextWithFont(250, 100, 80, INo, RGB(255, 255, 255), RGB(0, 0, 255));

		char back[] = "BACK [B]";
		char Instructions[100] = "Hello CHAMP !";
		char inst[] = "It is too";
		char ins[] = "simple!!";

		char ons[] = " Just dont ";
		char onsi[] = " let the ball  ";
		char pop[] = "land on the";
		char popi[] = "ground unless";
		char peep[] = "it's your ";
		char peepi[] = " bat ;)";

		myDrawTextWithFont(10, 20, 30, back, RGB(255, 255, 255), RGB(255,0 , 0));
		myDrawTextWithFont(80, 200, 30, Instructions, RGB(255, 255, 255), RGB(255, 0, 0));
		myDrawTextWithFont(230, 200, 30, inst, RGB(255, 255, 255), RGB(0, 0, 0));
		myDrawTextWithFont(310, 200, 30, ins, RGB(255, 255, 255), RGB(0, 0, 0));
		myDrawTextWithFont(80, 240, 30, ons, RGB(255, 255, 255), RGB(0, 0, 0));
		myDrawTextWithFont(180, 240, 30, onsi, RGB(255, 255, 255), RGB(0, 0, 0));
		myDrawTextWithFont(290, 240, 30, pop, RGB(255, 255, 255), RGB(0, 0, 0));
		myDrawTextWithFont(410, 240, 30, popi, RGB(255, 255, 255), RGB(0, 0, 0));
		myDrawTextWithFont(80, 280, 30, peep, RGB(255, 255, 255), RGB(0, 0, 0));
		myDrawTextWithFont(160, 280,30, peepi, RGB(255, 255, 255), RGB(0, 255, 0));
	}
	while (!instructions)
	{

		char ch = CheckKeyPressed();

		if (ch == 'b' || ch == 'B')
		{
			system("cls");
			instructions = true;
		}
	}
}



void over()
{
	bool chal = false;

	char bye[] = "Loserrrr !!!";

	myDrawTextWithFont(250, 100, 80, bye, RGB(255, 255, 255), RGB(0, 0, 255));


	char men[] = "MENU [M]";

	myDrawTextWithFont(250, 300, 50, men, RGB(255, 255, 255), RGB(0, 0, 255));

	while (!chal)
	{

		char ch = CheckKeyPressed();

		if (ch == 'm' || ch == 'M')
		{
			system("cls");
			chal = true;
			
		}
	}


}

bool Powerups(int i, int j)
{
	int random = i * j + static_cast<unsigned int>(time(0));

	random = ((random * 7621) + 1) % 32768; ;

	if (random % 2 == 0)
		return true;
	else
		return false;
}


void renderBricks()
{
	int x2, y2, x1 = 15, y1 = 15, width = 20, length = 200, pad = 20, vertical_pad = 10, temp = x1;

	int color11 = 0;
	int color2 = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			x2 = x1 + length;
			y2 = y1 + width;


			int temp = Random(i, j) % 6 + 1;

			if (temp == 6 || temp == 5)
			{
				if ((i + j) % 2 == 0)
				{
					arr[i][j] = temp;
				}
				else
				{
					arr[i][j] = temp - j;
				}
			}
			else
			{

				arr[i][j] = temp;
			}

			myRect(x1, y1, x2, y2, RGB(0, 0, 0), RGB(0, 0, 0));

			switch (arr[i][j])
			{
			case 1:
				myRect(x1, y1, x2, y2, RGB(0, 0, 0), RGB(255, 0, 0));
				break;
			case 2:
				myRect(x1, y1, x2, y2, RGB(0, 0, 0), RGB(255, 255, 0));
				break;
			case 3:
				myRect(x1, y1, x2, y2, RGB(0, 0, 0), RGB(0, 255, 255));
				break;
			case 4:
				myRect(x1, y1, x2, y2, RGB(0, 0, 0), RGB(255, 0, 255));
				break;
			case 5:
				myRect(x1, y1, x2, y2, RGB(255, 255, 255), RGB(118, 31, 32));
				break;
			case 6:
				myRect(x1, y1, x2, y2, RGB(255, 255, 255), RGB(0, 255, 0));
				break;
			}


			x1 = x2 + pad;
		}


		color11 = 255 - color11;
		color2 = color2 - 0;
		y1 = y2 + vertical_pad;
		x1 = temp;
	}
}

void renderBricks1()
{
	int x2, y2, x1 = 15, y1 = 15, width = 20, length = 200, pad = 20, vertical_pad = 10, temp = x1;

	int color11 = 0;
	int color2 = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			x2 = x1 + length;
			y2 = y1 + width;

			
				int temp= Random(i,j)%3 + 1;
				arr[i][j] = temp;


			myRect(x1, y1, x2, y2, RGB(0, 0, 0), RGB(0, 0, 0));

			switch (arr[i][j])
			{
			case 1:
				myRect(x1, y1, x2, y2, RGB(0, 0, 0), RGB(255, 0, 0));
				break;
			case 2:
				myRect(x1, y1, x2, y2, RGB(0, 0, 0), RGB(255, 0, 255));
				break;
			case 3:
				myRect(x1, y1, x2, y2, RGB(0, 0, 0), RGB(0, 255, 255));
				break;
			}
			
			
			x1 = x2 + pad;
		}


		color11 = 255 - color11;
		color2 = color2 - 0;
		y1 = y2 + vertical_pad;
		x1 = temp;
	}
}

int Menu() {

	system("cls");

	bool menu = false;
	//-----------------------------------------MENU------------------------------------------------

	char Menu[36] = "WELCOME TO PARANOID", In[] = "START GAME [S]", INo[] = "INSTRUCTIONS [I]", Exit[] = "Exit[Q]";

	myDrawTextWithFont(10, 150, 80, Menu, RGB(255, 255, 255), RGB(0, 0, 0));
	myDrawTextWithFont(10, 240, 60, In, RGB(255, 255, 255), RGB(255, 204, 0));
	myDrawTextWithFont(10, 320, 60, INo, RGB(255, 255, 255), RGB(0, 0, 255));
	myDrawTextWithFont(10, 400, 60, Exit, RGB(255, 255, 255), RGB(255, 0, 0));


	int color = 0, color1 = 0;

	
	bool bounced_menu = TRUE;
	float X1 = 850, Y1 = 300, X2 = 860, Y2 = 310;


	while (!menu)
	{


		myLine(700, 10, 1000, 10, RGB(color1, 255, color));
		myLine(1000, 10, 1000, 550, RGB(color1, 255, color));
		myLine(1000, 550, 700, 550, RGB(color1, 255, color));
		myLine(700, 550, 700, 10, RGB(color1, 255, color));

		if (bounced_menu)
		{
			myEllipse(X1, Y1, X2, Y2, RGB(0, 0, 0), RGB(0, 0, 0));
			Y1 -= 10;
			Y2 -= 10;
			myEllipse(X1, Y1, X2, Y2, RGB(0, 255, 0), RGB(0, 255, 0));
		}
		else
		{
			myEllipse(X1, Y1, X2, Y2, RGB(0, 0, 0), RGB(0, 0, 0));
			Y1 += 10;
			Y2 += 10;
			myEllipse(X1, Y1, X2, Y2, RGB(0, 255, 0), RGB(0, 255, 0));
		}
		if (Y2 == 550)
		{
			bounced_menu = true;
			color = 255 - color;
		}
		if (Y2 == 20)
		{
			color1 = 255 - color1;
			bounced_menu = false;
		}

		char ch = CheckKeyPressed();

		if (ch == 's' || ch == 'S')
		{
			system("cls");
			menu = true;

			renderBricks();
		}
		else if (ch == 'i' || ch == 'I')
		{
			system("cls");
			Instructions();

			myDrawTextWithFont(10, 100, 80, Menu, RGB(255, 255, 255), RGB(0, 0, 0));
			myDrawTextWithFont(10, 240, 60, In, RGB(255, 255, 255), RGB(0, 255, 0));
			myDrawTextWithFont(10, 320, 60, INo, RGB(255, 255, 255), RGB(0, 0, 255));
			myDrawTextWithFont(10, 400, 60, Exit, RGB(255, 255, 255), RGB(255, 0, 0));


		}
		else if (ch == 'q' || ch == 'Q')
		{
			system("cls");
			return 0;
		}

	}
}

using namespace std;

int main()
{
	

	//-----------------------------------DECLARATIONS---------------------------------------------
	bool close = false;
	float bat_x1 = 480, bat_y1 = 470, bat_x2 = 580, bat_y2 = 480;
	float x1 = 15, y1 = 15, width = 20, length = 200, pad = 20, vertical_pad = 10;
	bool bounced = false;
	float ball_x1 = 545, ball_y1 = 255, ball_x2 = 555, ball_y2 = 265;
	bool bricks[3][5];
	bool vanished = true;

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 5; j++)
			bricks[i][j] = true;

		

	bool bat_bounce[5] = { false };
	bool wall_bounce[5] = { false };
	bool brick_wall_bounce[5] = { false };
	bool brick_to_wall[5] = { false };
	brick_wall_bounce[2] = true;

	int live[5], lives = 3;

	int color11 = 0,
		color2 = 0,
		color3 = 0;

	bool update = true, update1 = true;
	bool menu = false;
	bool instructions = true;

	float bricks_x1[3][9];
	float bricks_x2[3][9];
	float bricks_y1[3][9];
	float bricks_y2[3][9];

	bool high_score_update = false;
	int score = 0;
	bool change = true;
	bool destroyed = true;
	bool lost = false;

	bool first_is_broken = false;
	char high_s[10] = {'\0'};
	bool put_black = false;


		//------------------------------------initializing coordinate loops--------------------------
		int  x2, y2, temp = x1;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				x2 = x1 + length;
				y2 = y1 + width;

				bricks_x1[i][j] = x1;
				bricks_x2[i][j] = x2;
				bricks_y1[i][j] = y1;
				bricks_y2[i][j] = y2;

				x1 = x2 + pad;
			}
			y1 = y2 + vertical_pad;
			x1 = temp;
		}

		
		//------------------------------------GAME LOOP------------------------------------------------



		while (!close)
		{

			if (!menu) {
				int quit = Menu();


				if (!quit)
				{
					return 0;
				}
				menu = true;
				lives = 3;
				update1 = true;
			}


			if (lives == 0)
			{
				system("cls");
				over();
				
				if (high_score < score) {

					high_score_update = true;
					high_score = score;
					character(high_score, high_s);
					
				}
				score = 0;
				speed = 0.75;
				for (int i = 0; i < 3; i++)
					for (int j = 0; j < 5; j++)
						bricks[i][j] = true;


				menu = false;
			}

			//---------------------------------WINDOW CLOSE-------------------------------------------
			char ch = '0';
			if (_kbhit())
			{
				ch = _getch();
			}
			if (ch == 'q')
			{
				close = true;
			}



			//---------------------------------RENDERING BOUNDARY-------------------------------------------
			myLine(10, 10, 10, 500, RGB(255, 255, 255));
			myLine(10, 500, 1100, 500, RGB(255, 255, 255));
			myLine(1100, 500, 1100, 10, RGB(255, 255, 255));
			myLine(1100, 10, 10, 10, RGB(255, 255, 255));





			//---------------------------------------LIVES--------------------------------------------------
			for (int i = 0; i < lives; i++)
			{

				myEllipse(100 + i * 50, 530, 140 + i * 50, 570, RGB(255, 255, 255), RGB(0, 255, 0));

			}
			if (lost)
			{



				for (int i = 6; i - lives >= 0; i--)
				{
					myEllipse(100 + i * 50, 530, 140 + i * 50, 570, RGB(0, 0, 0), RGB(0, 0, 0));
				}
				lost = false;
			}

			char str[] = "LIVES : ";

			if (update1) {
				myDrawTextWithFont(10, 530, 40, str, RGB(255, 255, 255), RGB(0, 0, 0));
				update1 = false;
			}


			char scores[10] = {'\0'};
			
			int size = 10;
			
			if (high_score_update) {
				high_score_update = false;
				char Arr[]=  "high score : ";
				myDrawTextWithFont(10, 600, 40, Arr, RGB(255, 255, 255), RGB(0, 0, 0));
				myDrawTextWithFont(100, 600, 40, high_s, RGB(255, 255, 255), RGB(0, 0, 0));
			}
			if (change)
			{
			character( score,  scores);

				change = false;
			}

			


			//-----------------------------------COLLISION WITH BAT-----------------------------------------
			if (ball_y2 >= bat_y1)
				if (ball_x1 >= bat_x1-6 && ball_x2 <= bat_x2+6)
				{
					for (int k = 0; k < 5; k++)
					{
						brick_wall_bounce[k] = false;
						bat_bounce[k] = 0;
						brick_to_wall[k] = 0;
						wall_bounce[k] = 0;
					}

					bounced = true;
					
					if (ball_x1 >= bat_x1 - 6) {
					if (ball_x2 <= (bat_x1 +20))
						bat_bounce[0] = true;
					else if (ball_x2 <= (bat_x1 + 40))
						bat_bounce[1] = true;
					else if (ball_x2 <= (bat_x1 + 60))
						bat_bounce[2] = true;
					else if (ball_x2 <= (bat_x1 + 80))
						bat_bounce[3] = true;
					else if (ball_x2 <= (bat_x2 + 6))
						bat_bounce[4] = true;
					}
				}
				else
				{

					if (ball_y2 >= bat_y2) {
						lives--;

						lost = true;
						bounced = false;

						for (int k = 0; k < 5; k++)
						{
							bat_bounce[k] = false;
							wall_bounce[k] = false;
							brick_to_wall[k] = false;
							brick_wall_bounce[k] = false;
						}
						brick_wall_bounce[2] = true;

						lifelost();

						myRect(bat_x1, bat_y1, bat_x2, bat_y2, RGB(0, 0, 0), RGB(0, 0, 0));

						myEllipse(ball_x1, ball_y1, ball_x2, ball_y2, RGB(0, 0, 0), RGB(0, 0, 0));

						update = true;
						update1 = true;

						ball_x1 = 545, ball_y1 = 255, ball_x2 = 555, ball_y2 = 265;
						bat_x1 = 480, bat_y1 = 470, bat_x2 = 580, bat_y2 = 480;
					}
					
				}

			//--------------------------------------collision with walls------------------------------------
			if (ball_x2 >= 1100 || ball_x1 <= 10)
			{

				//--------------------------------UPWARD
				if (bounced) {
					if (bat_bounce[0])
					{
						wall_bounce[0] = bat_bounce[0];
						bat_bounce[0] = false;
					}
					else if (bat_bounce[1])
					{
						wall_bounce[1] = bat_bounce[1];
						bat_bounce[1] = false;
					}
					else if (bat_bounce[3])
					{
						wall_bounce[2] = bat_bounce[3];
						bat_bounce[3] = false;
					}
					else if (bat_bounce[4])
					{
						wall_bounce[3] = bat_bounce[4];
						bat_bounce[4] = false;
					}
				}
				else {
					//----------------------------DOWNWARD
					if (brick_wall_bounce[0])
					{
						brick_to_wall[0] = brick_wall_bounce[0];
						brick_wall_bounce[0] = false;
					}
					else if (brick_wall_bounce[1])
					{
						brick_to_wall[1] = brick_wall_bounce[1];
						brick_wall_bounce[1] = false;
					}
					else if (brick_wall_bounce[3])
					{
						brick_to_wall[2] = brick_wall_bounce[3];
						brick_wall_bounce[3] = false;
					}
					else if (brick_wall_bounce[4])
					{
						brick_to_wall[3] = brick_wall_bounce[4];
						brick_wall_bounce[4] = false;
					}
				}
			}
			
			//------------------------------checking if all bricks are destroyed---------------------------
			
			if (first_is_broken) {
				destroyed = true;
				for (int i = 0; i < 3; i++)
				{

					for (int j = 0; j < 5; j++)
					{
						if (bricks[i][j])
						{
							destroyed = false;
							break;
						}
						if (!destroyed)
						{
							break;
						}
					}
					if (!destroyed)
					{
						break;
					}
				}

				if (destroyed)
				{
					renderBricks();
					myRect(bat_x1, bat_y1, bat_x2, bat_y2, RGB(0, 0, 0), RGB(0, 0, 0));
					ball_x1 = 545, ball_y1 = 255, ball_x2 = 555, ball_y2 = 265;
					bat_x1 = 480, bat_y1 = 470, bat_x2 = 580, bat_y2 = 480;
					speed += 0.5;

					for (int k = 0; k < 5; k++)
					{
						brick_to_wall[k] = false;
						bat_bounce[k] = false;
						wall_bounce[k] = false;
						brick_wall_bounce[k] = false;
					}
					bounced = false;
					brick_wall_bounce[2] = true;
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 5; j++)
							bricks[i][j] = true;
					}

					first_is_broken = false;
				}
			}
				
		

			//---------------------------------collision with bricks----------------------------------------
			int x1 = 15, y1 = 15, width = 20, length = 200, pad = 20, vertical_pad = 10, temp2 = y2, temp1 = y1;
			if (bounced)
			{
				for (int i = 0; i < 3; i++)
				{
					for (int j = 0; j < 5; j++)
					{


						x2 = x1 + length;
						y2 = y1 + width;

						if ((bricks[i][j] && ball_x1 >= x1 && ball_x2 <= x2 && ball_y1 >= y1 && ball_y2 <= y2))
						{
							bounced = false;


							if (bat_bounce[0] || wall_bounce[3])
							{
								brick_wall_bounce[4] = true;
							}
							else if (bat_bounce[1] || wall_bounce[2])
							{
								brick_wall_bounce[3] = true;
							}
							else if (bat_bounce[3] || wall_bounce[1])
							{
								brick_wall_bounce[1] = true;
							}
							else if (bat_bounce[4] || wall_bounce[0])
							{
								brick_wall_bounce[0] = true;
							}
							else if (bat_bounce[2])
							{
								brick_wall_bounce[2] = true;
							}

							for (int k = 0; k < 5; k++)
							{
								brick_to_wall[k] = false;
								bat_bounce[k] = false;
								wall_bounce[k] = false;
							}

							bricks[i][j] = false;
							change = true;

							//-----------------score calculation:
							switch (arr[i][j])
							{
							case 1:
								score += 50;
								break;
							case 2:
								score += 100;
								break;
							case 3:
								score += 150;
								break;
							case 4:
								score += 200;
								break;
							case 5:

								if (j - 1 >= 0)
									bricks[i][j - 1] = false;
								if (j + 1 < 5)
									bricks[i][j + 1] = false;

								if (i - 1 >= 0)
									bricks[i - 1][j] = false;
								if (i + 1 < 2)
									bricks[i + 1][j] = false;
								score += 200;


								break;
							case 6:
								score += 100;
								if (lives < 6)
									lives++;
								break;
							}



							first_is_broken = true;
							put_black = true;
						}


						x1 = x2 + pad;
					}

					y1 = y2 + vertical_pad;
					x1 = temp;
				}
			}
			//--------------------------------------upper wall Bounce--------------------------------------
				if (ball_y1 <= 10)
				{
					bounced = false;


					if (bat_bounce[0] || wall_bounce[3])
					{
						brick_wall_bounce[4] = true;
					}
					else if (bat_bounce[1] || wall_bounce[2])
					{
						brick_wall_bounce[3] = true;
					}
					else if (bat_bounce[3] || wall_bounce[1])
					{
						brick_wall_bounce[1] = true;
					}
					else if (bat_bounce[4] || wall_bounce[0])
					{
						brick_wall_bounce[0] = true;
					}
					else if (bat_bounce[2])
					{
						brick_wall_bounce[2] = true;
					}

					for (int k = 0; k < 5; k++)
					{
						brick_to_wall[k] = false;
						bat_bounce[k] = false;
						wall_bounce[k] = false;
					}
				}

			//------------------------------------MULTIPLE BRICKS COLLISION---------------------------------
				if (!bounced)
				{
					x2, y2, x1 = 15, y1 = 15, width = 20, length = 200, pad = 20, vertical_pad = 10, temp = x1;

					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 5; j++)
						{
							x2 = x1 + length;
							y2 = y1 + width;

							if ((bricks[i][j] && ball_x1 >= x1 && ball_x2 <= x2 && ball_y1 >= y1 && ball_y2 <= y2))
							{
								bounced = true;
								
								if (brick_wall_bounce[0])
									bat_bounce[4] = true;
								else if (brick_wall_bounce[1])
									bat_bounce[3] = true;
								else if (brick_wall_bounce[2])
									bat_bounce[2] = true;
								else if (brick_wall_bounce[3])
									bat_bounce[1] = true;
								else if (brick_wall_bounce[4])
									bat_bounce[0] = true;



								for (int k = 0; k < 5; k++)
								{
									brick_to_wall[k] = false;
									brick_wall_bounce[k] = false;
									wall_bounce[k] = false;
								}


								bricks[i][j] = false;
								change = true;

								//-----------------score calculation:
								switch (arr[i][j])
								{
								case 1:
									score += 50;
									break;
								case 2:
									score += 100;
									break;
								case 3:
									score += 150;
									break;
								case 4:
									score += 100;
									break;
								case 5:

									if (j - 1 >= 0)
										bricks[i][j - 1] = false;
									if (j + 1 < 5)
										bricks[i][j + 1] = false;

									if (i - 1 >= 0)
										bricks[i - 1][j] = false;
									if (i + 1 < 2)
										bricks[i + 1][j] = false;
									score += 200;

									break;
								case 6:
									score += 100;
									if (lives < 6)
										lives++;
									break;
								}



								first_is_broken = true;
								put_black = true;
							}
							

							x1 = x2 + pad;
						}
						
						y1 = y2 + vertical_pad;
						x1 = temp;
					}
					
				}
				
			

			//------------------------------------RENDERING BALL--------------------------------------------

			if (!bounced)
			{


				if (ball_y2 < bat_y2)
				{



					myEllipse(ball_x1, ball_y1, ball_x2, ball_y2, RGB(0, 0, 0), RGB(0, 0, 0));

					if (brick_wall_bounce[0] || brick_to_wall[3])
					{
						downRightMost(ball_x1, ball_y1, ball_x2, ball_y2);
					}
					else if (brick_wall_bounce[1] || brick_to_wall[2])
					{
						downRight(ball_x1, ball_y1, ball_x2, ball_y2);
					}
					else if (brick_wall_bounce[3] || brick_to_wall[1])
					{
						downLeft(ball_x1, ball_y1, ball_x2, ball_y2);
					}
					else if (brick_wall_bounce[4] || brick_to_wall[0])
					{
						downLeftMost(ball_x1, ball_y1, ball_x2, ball_y2);
					}
					else if (brick_wall_bounce[2])
					{
						straightDown(ball_x1, ball_y1, ball_x2, ball_y2);
					}

					myEllipse(ball_x1, ball_y1, ball_x2, ball_y2, RGB(0, 255, 0), RGB(0, 255, 0));
				}
			}





			//----------------------------------REVERSING DIRECTION OF MOTION-------------------------------
			if (bounced)
			{


				
					myEllipse(ball_x1, ball_y1, ball_x2, ball_y2, RGB(0, 0, 0), RGB(0, 0, 0));

					if (bat_bounce[0] || wall_bounce[3])
					{
						upLeftMost(ball_x1, ball_y1, ball_x2, ball_y2);
					}
					else if (bat_bounce[1] || wall_bounce[2])
					{
						upLeft(ball_x1, ball_y1, ball_x2, ball_y2);
					}
					else if (bat_bounce[3] || wall_bounce[1])
					{
						upLRight(ball_x1, ball_y1, ball_x2, ball_y2);
					}
					else if (bat_bounce[4] || wall_bounce[0])
					{
						upRightMost(ball_x1, ball_y1, ball_x2, ball_y2);
					}
					else if (bat_bounce[2])
					{
						straightUp(ball_x1, ball_y1, ball_x2, ball_y2);
					}


					myEllipse(ball_x1, ball_y1, ball_x2, ball_y2, RGB(0, 255, 0), RGB(0, 255, 0));
				
			}

			
			


			//-----------------------------------RENDERING BAT----------------------------------------------

			if (_kbhit())
			{
				char ch = _getch();
				if (ch == 'a' || ch == 'A')
				{
					myRect(bat_x1, bat_y1, bat_x2, bat_y2, RGB(0, 0, 0), RGB(0, 0, 0));
					if (bat_x1 - 10 >= 10) {
						bat_x1 -= 10*(speed+0.5);
						bat_x2 -= 10*(speed+0.5);
					}
				}
				else if (ch == 'd' || ch == 'D')
				{
					myRect(bat_x1, bat_y1, bat_x2, bat_y2, RGB(0, 0, 0), RGB(0, 0, 0));
					if (bat_x2 + 10 < 1100) {
						bat_x1 += 10*(speed);
						bat_x2 += 10*(speed);
					}
				}
				else if (ch == 'Q' || ch == 'q')
				{
					return 0;
				}
				else if (ch == 'p' || ch == 'P')
				{
					bool pause = true;
					while (pause)
					{
						if (_kbhit)
						{
							ch = _getch();

							if (ch == 'p' || ch == 'P')
							{
								pause = false;
							}
						}
					}
				}
			}
			myRect(bat_x1, bat_y1, bat_x2, bat_y2, RGB(255, 255, 255), RGB(139, 0, 139));
			//------------------------------------Putting black bricks

			if (put_black) {
				x2, y2, x1 = 15, y1 = 15, width = 20, length = 200, pad = 20, vertical_pad = 10, temp = x1;

				int color11 = 0;
				int color2 = 0;
				for (int i = 0; i < 3; i++)
				{
					for (int j = 0; j < 5; j++)
					{
						x2 = x1 + length;
						y2 = y1 + width;


						if (!bricks[i][j])
						{
							myRect(x1, y1, x2, y2, RGB(0, 0, 0), RGB(0, 0, 0));

						}

						x1 = x2 + pad;
					}
					color11 = 255 - color11;
					color2 = color2 - 0;
					y1 = y2 + vertical_pad;
					x1 = temp;
				}
				put_black = false;
			}

			

		}
	
	
}