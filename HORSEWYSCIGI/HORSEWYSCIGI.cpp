#include <iostream>
#include <conio.h>//для захвату кнопкі
using namespace std;


const int rows = 27;
const int colum = 120;

char map[rows][colum] = {
	{ "                   #                   #                                                                               " },
	{ "                   #                   #                                                                               " },
	{ "                   #                   #                                                                               " },
	{ "                   #                   #                              X       X                                        " },
	{ "                   #                   #                                X   X    |     #   #  ####  #   #  #####       " },
	{ "                   #                   #                                  X      |     ##  #  #      # #     #         " },
	{ "                   #                   #                                  X      |     # # #  ####    #      #         " },
	{ "                   #                   #                                X   X    |     #  ##  #      # #     #         " },
	{ "###########################################################           X       X  | IS  #   #  ####  #   #    #         " },
	{ "                   #         |         #                             -----------------------------------------         " },
	{ "                   #                   #                                                                               " },
	{ "                   #                   #                                                                               " },
	{ "                   #-                 -#                                                                               " },
	{ "                   #-                 -#                                                                               " },
	{ "                   #                   #                                                                               " },
	{ "                   #                   #                                                                               " },
	{ "                   #         |         #                                                                               " },
	{ "###########################################################                 =======                                    " },
	{ "                   #                   #                                    |ENTER|  To insert (X or O)                " },
	{ "                   #                   #                                    =======                                    " },
	{ "                   #                   #                                                                               " },
	{ "                   #                   #                                  ========     =========                       " },
	{ "                   #                   #                                  |  W   |     |   ^   |                       " },
	{ "                   #                   #                             Use  | ASD  | AND | <-|-> |   To move             " },
	{ "                   #                   #                                  ========     =========                       " },
	{ "                   #                   #                                                              |ESC| to leave   " },
	{ "                                                                                                      ---------------> " }
};
char main_map[rows][colum];
void copyMap(char(*arr1)[colum], char (*arr2)[colum])
{
	for (int i = 0; i < rows; i++)
	{
		for (int k = 0; k < colum - 1; k++)
		{
			arr1[i][k] = arr2[i][k];
		}
	}
}
char menu[rows][colum] = {
	{ "                                                                                                                       " },
	{ "                                                                                                                       " },
	{ "           ###########  #                ###########                         #############                             " },
	{ "                #                             #                                    #                                   " },
	{ "                #       #  #####              #       #### #    #####              #       ####    ####                " },
	{ "                #       #  #                  #      #    #     #                  #      #    #  #    #               " },
	{ "                #       #  #        -----     #      #    #     #         -----    #      #    #  #####                " },
	{ "                #       #  #                  #      #    ##    #                  #      #    #  #                    " },
	{ "                #       #  #####              #       #### ###  #####              #       ####    ####                " },
	{ "                                                                                                                       " },
	{ "                                                                                                                       " },
	{ "                                                                                                                       " },
	{ "                                                                                                                       " },
	{ "                                                                                                                       " },
	{ "                                                                                                                       " },
	{ "                                                                                                                       " },
	{ "                                                   START GAME?                                                         " },
	{ "                                                                                                                       " },
	{ "                                   YES                                     NO                                          " },
	{ "                                 (ENTER)                                  (ESC)                                        " },
	{ "                                                                                                                       " },
	{ "                                                                                                                       " },
	{ "                                                                                                                       " },
	{ "                                                                                                                       " },
	{ "                                                                                                                       " },
	{ "                                                                                                                       " },
	{ "                                                                                                                       " }
};
char end_prog[rows][colum] = {
	{ "                                                                                                                       " },
	{ "                                                                                                                       " },
	{ "                                                                                                                       " },
	{ "                                                                                                               #       " },
	{ "                ############                                                                                   #       " },
	{ "               #                                                                                               #       " },
	{ "              #                                                                                                #       " },
	{ "              #                                                                                                #       " },
	{ "               #                                                                                               #       " },
	{ "                 #                                                                                             #       " },
	{ "                   #            ########    ########                #        #     #######     #        #      #       " },
	{ "                     #         #        #  #        #               #        #    #       #    #        #      #       " },
	{ "                       #       #        #  #        #               #        #   #         #   #        #      #       " },
	{ "                         #     #        #  #        #               #        #  #           #  #        #      #       " },
	{ "                          #    #########   #########                 #########  #           #  #        #      #       " },
	{ "                          #    #           #                                 #   #         #   #        #      #       " },
	{ "                         #     #           #                                 #    #       #     ##     ##              " },
	{ "             ############       ########    #######                  ########      #######        ##### ##     #       " },
	{ "                                                                                                                       " },
	{ "                                                                                                                       " },
	{ "                                                                                                                       " },
	{ "                                                                                                                       " },
	{ "                                                                                                                       " },
	{ "                                                                                                                       " },
	{ "                                                                                                                       " },
	{ "                                                                                                                       " },
	{ "                                                                                                                       " }
};


const int s_place_rows = 8;
const int s_place_colums = 20;
char search_place[s_place_rows][s_place_colums] = { { "         |         "},
												    { "                   "},
												    { "                   "},
												    { "-                 -"},
												    { "-                 -"},
											  	    { "                   "},
											  	    { "                   "},
												    { "         |         "} };

const int X_rows = 8;
const int X_colums = 20;
char X_arr[X_rows][X_colums] = {      { "                   "},
									  { "     X       X     "},
									  { "       X   X       "},
									  { "         X         "},
									  { "         X         "},
									  { "       X   X       "},
									  { "     X       X     "},
									  { "                   "} };

const int O_rows = 8;
const int O_colums = 20;
char O_arr[O_rows][O_colums] = {	  { "                   "},
									  { "       OOOOO       "},
									  { "     O       O     "},
									  { "    O         O    "},
									  { "    O         O    "},
									  { "     O       O     "},
									  { "       OOOOO       "},
									  { "                   "} };


const int win_rows = 6;
const int win_colums = 28;
char win_arr[win_rows][win_colums] = { { "                           "},
									   { " #       #  #   #   #      "},
									   { " #   #   #      ##  #      "},
									   { "  #  #  #   #   # # #      "},
									   { "  # # # #   #   #  ##      "},
									   { "   #   #    #   #   #      "} };
const int draw_rows = 6;
const int draw_colums = 44;
char draw_arr[draw_rows][draw_colums] = {    { "                                           " },
											 { "  ####   ####        #      #       #      "},
											 { "  #   #  #   #      # #     #   #   #      "},
											 { "  #   #  ####      #   #     #  #  #       "},
											 { "  #   #  #  #     #######    # # # #       "},
											 { "  ####   #    #  #       #    #   #        "} };









const int cross_colums1 = 60;
char crossRow_arr1[cross_colums1] = { "===========================================================" };
const int cross_rows2 = 27;
const int cross_colums2 = 3;
char crossRow_arr2[cross_rows2][cross_colums2] = {{ "||" },
												  { "||" },
												  { "||" },
												  { "||" },
												  { "||" },
												  { "||" },
												  { "||" },
												  { "||" },
												  { "||" },
												  { "||" },
												  { "||" },
												  { "||" },
												  { "||" },
												  { "||" },
												  { "||" },
												  { "||" },
												  { "||" },
												  { "||" },
												  { "||" },
												  { "||" },
												  { "||" },
												  { "||" },
												  { "||" },
												  { "||" },
												  { "||" },
												  { "||" },
												  { "||" }
};

const int d2_rows = 27;
const int d2_colum = 60;

char cross_d2[d2_rows][d2_colum] = {    {"                                                       //  "},
										{"                                                     //    "},
										{"                                                   //      "},
										{"                                                 //        "},
										{"                                               //          "},
										{"                                             //            "},
										{"                                           //              "},
										{"                                         //                "},
										{"                                       //                  "},
										{"                                     //                    "},
										{"                                   //                      "},
										{"                                 //                        "},
										{"                               //                          "},
										{"                            ///                            "},
										{"                          //                               "},
										{"                        //                                 "},
										{"                      //                                   "},
										{"                    //                                     "},
										{"                  //                                       "},
										{"                //                                         "},
										{"              //                                           "},
										{"            //                                             "},
										{"          //                                               "},
										{"        //                                                 "},
										{"      //                                                   "},
										{"    //                                                     "},
										{"  //                                                       "},
};
const int d1_rows = 27;
const int d1_colum = 60;

char cross_d1[d1_rows][d1_colum] = {    {"  //                                                       "},
										{"    //                                                     "},
										{"      //                                                   "},
										{"        //                                                 "},
										{"          //                                               "},
										{"            //                                             "},
										{"              //                                           "},
										{"                //                                         "},
										{"                  //                                       "},
										{"                    //                                     "},
										{"                      //                                   "},
										{"                         //                                "},
										{"                           //                              "},
										{"                             ///                           "},
										{"                                //                         "},
										{"                                  //                       "},
										{"                                    //                     "},
										{"                                      //                   "},
										{"                                        //                 "},
										{"                                          //               "},
										{"                                            //             "},
										{"                                              //           "},
										{"                                                //         "},
										{"                                                  //       "},
										{"                                                    //     "},
										{"                                                      //   "},
										{"                                                        // "},
};

int miniMap[3][3];










void paint_map(char (*arr)[colum])//вывад мапы
{
	cout << '\n';
	for (int i = 0; i < rows; i++)
	{
		for (int k = 0; k < colum; k++)
		{
			cout << arr[i][k];
		}
		cout << '\n';
	}
}
int isWin(int (*miniMap)[3], char (*arr)[colum])//падлік пераможца
{
	bool noOne = true;
	for (int i = 0; i < 3; i++)
	{
		int r = 1;
		int c = 1;
		int d1 = 1;
		int d2 = 1;

		for (int k = 0; k < 3; k++)
		{
			r *= miniMap[i][k];
			c *= miniMap[k][i];
			d1 *= miniMap[k][k];
			d2 *= miniMap[2 - k][k];
			if (miniMap[i][k] == 0)
				noOne = false;

		}
		if (r == 1)
		{
			for (int k = 0; k < cross_colums1 - 1; k++)
			{
				arr[i * 9 + 3][k] = crossRow_arr1[k];
			}
			///////////.........................................................................
			return 1;
		}
		if (c == 1)
		{

			for (int j = 0; j < cross_rows2 - 1; j++)
			{
				for (int k = 0; k < cross_colums2; k++)
				{
					arr[j][i * 20 + 8 + k] = crossRow_arr2[j][k];
				}
			}
			return 1;
		}
		if (d1 == 1)
		{

			for (int j = 0; j < d1_rows; j++)
			{
				for (int k = 0; k < d1_colum - 4; k++)
				{
					if (cross_d1[j][k] != ' ')
						arr[j][k] = cross_d1[j][k];
				}
			}
			return 1;
		}
		if (d2 == 1)
		{
			for (int j = 0; j < d2_rows; j++)
			{
				for (int k = 0; k < d2_colum - 3; k++)
				{
					if (cross_d2[j][k] != ' ')
						arr[j][k] = cross_d2[j][k];
				}
			}
			return 1;
		}
		if (r == 8)
		{
			for (int k = 0; k < cross_colums1 - 1; k++)
			{
				arr[i * 9 + 3][k] = crossRow_arr1[k];
			}
			return 2;
		}
		if (c == 8)
		{
			for (int j = 0; j < cross_rows2 - 1; j++)
			{
				for (int k = 0; k < cross_colums2; k++)
				{
					arr[j][i * 20 + 8 + k] = crossRow_arr2[j][k];
				}
			}
			return 2;
		}
		if (d1 == 8)
		{
			for (int j = 0; j < d1_rows; j++)
			{
				for (int k = 0; k < d1_colum - 4; k++)
				{
					if (cross_d1[j][k] != ' ')
						arr[j][k] = cross_d1[j][k];
				}
			}
			return 2;
		}
		if (d2 == 8)
		{
			for (int j = 0; j < d2_rows; j++)
			{
				for (int k = 0; k < d2_colum - 3; k++)
				{
					if (cross_d2[j][k] != ' ')
						arr[j][k] = cross_d2[j][k];
				}
			}
			return 2;
		}
	}
	if (noOne)
	{
		return 3;
	}

	return 0;





}
int move(char (*arr)[colum], char(*search_place)[s_place_colums], int* coordinate_x, int* coordinate_y, int* score, bool* run) //рух і навігацыя
{

	int step_x = 20;
	int step_y = 9;

	char a = _getch();
	if (a == 27)
	{
		*run = false;
		return 0;
	}
	if (a == 77)
	{
		if (*coordinate_x < colum - step_x - 60)
		{
			
			for (int i = 0; i < s_place_rows; i++)
			{
				for (int k = 0; k < s_place_colums - 1; k++)
					if (search_place[i][k] != ' ')
						arr[*coordinate_y + i][*coordinate_x + step_x + k] = search_place[i][k];
			}

			for (int i = 0; i < s_place_rows; i++)
			{
				for (int k = 0; k < s_place_colums - 1; k++)
					if (search_place[i][k] != ' ')
						arr[*coordinate_y + i][*coordinate_x + k] = ' ';
			}
			*coordinate_x += step_x;



		}
	}
	if (a == 75)
	{
		if (*coordinate_x > 0)
		{
			for (int i = 0; i < s_place_rows; i++)
			{
				for (int k = 0; k < s_place_colums - 1; k++)
					if (search_place[i][k] != ' ')
						arr[*coordinate_y + i][*coordinate_x - step_x + k] = search_place[i][k];
			}
			for (int i = 0; i < s_place_rows; i++)
			{
				for (int k = 0; k < s_place_colums - 1; k++)
					if (search_place[i][k] != ' ')
						arr[*coordinate_y + i][*coordinate_x + k] = ' ';
			}
			*coordinate_x -= step_x;
		}
	}
	if (a == 80)
	{
		if (*coordinate_y < rows - step_y)
		{
			for (int i = 0; i < s_place_rows; i++)
			{
				for (int k = 0; k < s_place_colums - 1; k++)
					if (search_place[i][k] != ' ')
						arr[*coordinate_y + step_y + i][*coordinate_x + k] = search_place[i][k];
			}
			for (int i = 0; i < s_place_rows; i++)
			{
				for (int k = 0; k < s_place_colums - 1; k++)
					if (search_place[i][k] != ' ')
						arr[*coordinate_y + i][*coordinate_x + k] = ' ';
			}
			*coordinate_y += step_y;
		}
	}
	if (a == 72)
	{
		if (*coordinate_y > 0)
		{
			for (int i = 0; i < s_place_rows; i++)
			{
				for (int k = 0; k < s_place_colums - 1; k++)
					if (search_place[i][k] != ' ')
						arr[*coordinate_y - step_y + i][*coordinate_x + k] = search_place[i][k];
			}
			for (int i = 0; i < s_place_rows; i++)
			{
				for (int k = 0; k < s_place_colums - 1; k++)
					if (search_place[i][k] != ' ')
						arr[*coordinate_y + i][*coordinate_x + k] = ' ';
			}
			*coordinate_y -= step_y;
		}
	}
	if (a == 13)//o/x
	{
		if ((*score) % 2 == 0 && miniMap[*coordinate_y / 9][*coordinate_x / 20] == 0)//x
		{
			for (int i = 0; i < X_rows; i++)
			{
				for (int k = 0; k < X_colums - 1; k++)
					if (X_arr[i][k] != ' ')
						arr[*coordinate_y + i][*coordinate_x + k] = X_arr[i][k];
			}
			miniMap[*coordinate_y / 9][*coordinate_x / 20] = 1;
			*score += 1;
		}
		else if ((*score) % 2 == 1 && miniMap[*coordinate_y / 9][*coordinate_x / 20] == 0)//o
		{
			for (int i = 0; i < O_rows; i++)
			{
				for (int k = 0; k < O_colums - 1; k++)
					if (O_arr[i][k] != ' ')
						arr[*coordinate_y + i][*coordinate_x + k] = O_arr[i][k];
			}
			miniMap[*coordinate_y / 9][*coordinate_x / 20] = 2;
			*score += 1;
		}

	}
	return 1;
}

void whoNext(char (*arr)[colum], int score) //выбор следующего хода х или о
{

	if (score % 2 == 0)
	{

		for (int i = 0; i < X_rows - 1; i++)
		{
			for (int k = 0; k < X_colums - 4; k++)

				arr[2 + i][65 + k] = X_arr[i][k];
		}
	}
	else
	{
		for (int i = 0; i < O_rows - 1; i++)
		{
			for (int k = 0; k < O_colums - 4; k++)
				arr[2 + i][65 + k] = O_arr[i][k];
		}
	}
}

int play()
{
	int score = 0;
	char rund_b;
	int coordinate_x = 20;
	int coordinate_y = 9;

	paint_map(map);
	bool run = true;
	while (run)
	{

		move(map, search_place, &coordinate_x, &coordinate_y, &score, &run);
		whoNext(map, score);
		system("cls");

		paint_map(map);

		if (isWin(miniMap, map) == 1)
		{
			system("cls");
			for (int i = 0; i < win_rows; i++)
			{
				for (int k = 0; k < win_colums; k++)
					map[3 + i][85 + k] = win_arr[i][k];
			}
			for (int i = 0; i < X_rows - 1; i++)
			{
				for (int k = 0; k < X_colums - 4; k++)
					map[2 + i][65 + k] = X_arr[i][k];
			}
			paint_map(map);
			rund_b = _getch();
			return 0;
		}
		else if (isWin(miniMap, map) == 2)
		{
			system("cls");

			for (int i = 0; i < win_rows; i++)
			{
				for (int k = 0; k < win_colums; k++)
					map[3 + i][85 + k] = win_arr[i][k];
			}


			for (int i = 0; i < O_rows - 1; i++)
			{
				for (int k = 0; k < O_colums - 4; k++)
					map[2 + i][65 + k] = O_arr[i][k];
			}
			paint_map(map);
			rund_b = _getch();
			return 0;
		}
		else if (isWin(miniMap, map) == 3)
		{
			system("cls");
			for (int i = 0; i < draw_rows; i++)
			{
				for (int k = 0; k < draw_colums; k++)
					map[3 + i][69 + k] = draw_arr[i][k];
			}
			paint_map(map);
			cout << "No one is win\n";////////////////////////////////////
			rund_b = _getch();
			return 0;
		}

	}
	system("cls");
}
void restart_minimap(int (*arr)[3]) //парезегрузка мінькі
{
	for (int i = 0; i < 3; i++)
	{
		for (int k = 0; k < 3; k++)
		{
			arr[i][k] = 0;
		}
	}
}
int main()
{

	copyMap(main_map, map);
	while (true)
	{
		system("cls");
		paint_map(menu);
		copyMap(map, main_map);
		restart_minimap(miniMap);
		char button = _getch();
		if (button == 13)
		{
			system("cls");
			play();
		}
		else if (button == 27)
		{
			system("cls");
			paint_map(end_prog);
			return 0;
		}
	}
}