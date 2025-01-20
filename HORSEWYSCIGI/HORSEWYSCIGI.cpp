#include <iostream>
#include <conio.h>//захват нажатия кнопки
#include <windows.h>
using namespace std;
const int rows = 27;
const int colum = 120;
char arr_row[120];
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
	{ "                                                         MENU                                                          " },
	{ "                                                     1)  PLAY WITH FRIEND                                              " },
	{ "                                                     2)  PLAY WITH BOT                                                 " },
	{ "                                                     3)  EXIT                                                          " },
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
char end_prog[rows][colum] = {
	{ "                                                                                                                       " },
	{ "                                                                                                                       " },
	{ "                                                                                                                       " },
	{ "                                                                                                                       " },
	{ "                ############                                                                                           " },
	{ "               #                                                                                                       " },
	{ "              #                                                                                                        " },
	{ "              #                                                                                                        " },
	{ "               #                                                                                                       " },
	{ "                 #                                                                                                     " },
	{ "                   #            ########    ########                #        #     #######     #        #              " },
	{ "                     #         #        #  #        #               #        #    #       #    #        #              " },
	{ "                       #       #        #  #        #               #        #   #         #   #        #              " },
	{ "                         #     #        #  #        #               #        #  #           #  #        #              " },
	{ "                          #    #########   #########                 #########  #           #  #        #              " },
	{ "                          #    #           #                                 #   #         #   #        #              " },
	{ "                         #     #           #                                 #    #       #     ##     ##              " },
	{ "             ############       ########    #######                  ########      #######        ##### ##             " },
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
char X_arr[X_rows][X_colums] = { {"                   "},
									  { "     X       X     "},
									  { "       X   X       "},
									  { "         X         "},
									  { "         X         "},
									  { "       X   X       "},
									  { "     X       X     "},
									  { "                   "} };

const int O_rows = 8;
const int O_colums = 20;
char O_arr[O_rows][O_colums] = { {"                   "},
									  { "       OOOOO       "},
									  { "     O       O     "},
									  { "    O         O    "},
									  { "    O         O    "},
									  { "     O       O     "},
									  { "       OOOOO       "},
									  { "                   "} };


const int win_rows = 6;
const int win_colums = 27;
char win_arr[win_rows][win_colums] = { { "                          " },
									  { "#       #  #   #   #      "},
									  { "#   #   #      ##  #      "},
									  { " #  #  #   #   # # #      "},
									  { " # # # #   #   #  ##      "},
									  { "  #   #    #   #   #      "} };
const int draw_rows = 6;
const int draw_colums = 44;
char draw_arr[draw_rows][draw_colums] = { { "                                           " },
											 { "  ####   ####        #      #       #      "},
											 { "  #   #  #   #      # #     #   #   #      "},
											 { "  #   #  ####      #   #     #  #  #       "},
											 { "  #   #  #  #     #######    # # # #       "},
											 { "  ####   #    #  #       #    #   #        "} };

const int choose_rows = 7;
const int choose_colums = 28;
char choose_arr[choose_rows][choose_colums] = { { "X       X    //    OOOOO   " },
												  { "  X   X     //   O       O "},
												  { "    X       //  O         O"},
												  { "    X      //   O         O"},
												  { "  X   X    //    O       O "},
												  { "X       X //       OOOOO   "},
												  { "    1                2     "} };

const int choose_lvl_rows = 17;
const int choose_lvl_colums = 42;
char choose_lvl_arr[choose_lvl_rows][choose_lvl_colums] = { {"  #    ####    #    ####  #  #           "},
															{" ##    #      # #   #     #  #           "},
															{"# #    ####  #   #  ####  ####           "},
															{"  #    #     #####     #     #           "},
															{"  # *  ####  #   #  ####  ####           "},
															{"                                         "},
															{" ##    #   #  ####  ###   #  #   #  #   #"},
															{"#  #   ## ##  #     #  #     #   #  ## ##"},
															{"  #    # # #  ####  #  #  #  #   #  # # #"},
															{" #     #   #  #     #  #  #  #  ##  #   #"},
															{"####*  #   #  ####  ###   #  ### #  #   #"},
															{"                                         "},
															{" ##    #   #    #    ###   ###           "},
															{"#  #   #   #   # #   #  #  #  #          "},
															{"  #    #####  #   #  ###   #  #          "},
															{"#  #   #   #  #####  # #   #  #          "},
															{" ## *  #   #  #   #  #  #  ###           "},
};





const int cross_colums1 = 60;
char crossRow_arr1[cross_colums1] = { "===========================================================" };
const int cross_rows2 = 27;
const int cross_colums2 = 3;
char crossRow_arr2[cross_rows2][cross_colums2] = { {"||"},
												  {"||"},
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

char cross_d2[d2_rows][d2_colum] = { {"                                                       //  "},
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

char cross_d1[d1_rows][d1_colum] = { {"  //                                                       "},
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






void paint_map(char (*arr)[colum])//вывод карты
{
	cout << '\n';
	for (int i = 0; i < rows; i++)
	{
		for (int k = 0; k < colum; k++)
		{
			arr_row[k] = arr[i][k];
		}
		cout << arr_row << endl;
	}
}
int isWin(int (*miniMap)[3], char (*arr)[colum])//расчет победителя
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
			///////////
			return 1;
		}
		if (c == 1)
		{

			for (int j = 0; j < cross_rows2 - 1; j++)
			{
				for (int k = 0; k < cross_colums2 - 1; k++)
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
				for (int k = 0; k < cross_colums2 - 1; k++)
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
int isWin_miniMaks(int miniMap[3][3]) {
	bool noOne = true;
	for (int i = 0; i < 3; i++) {
		int r = 1;
		int c = 1;
		int d1 = 1;
		int d2 = 1;

		for (int k = 0; k < 3; k++) {
			r *= miniMap[i][k];
			c *= miniMap[k][i];
			d1 *= miniMap[k][k];
			d2 *= miniMap[2 - k][k];
			if (miniMap[i][k] == 0)
				noOne = false;
		}
		if (r == 1 || c == 1 || d1 == 1 || d2 == 1) {
			return 1;
		}
		if (r == 8 || c == 8 || d1 == 8 || d2 == 8) {
			return 2;
		}
	}
	if (noOne) {
		return 3;
	}
	return 0;
}
void easy_bot_move(int* score)
{
	int hit_colum;
	int hit_row;
	while (true)
	{
		hit_row = rand() % 3;
		hit_colum = rand() % 3;
		if ((*score) % 2 == 0 && miniMap[hit_row][hit_colum] == 0)//x
		{
			for (int i = 0; i < X_rows; i++)
			{
				for (int k = 0; k < X_colums - 1; k++)
					if (X_arr[i][k] != ' ')
						map[hit_row * 9 + i][hit_colum * 20 + k] = X_arr[i][k];
			}
			miniMap[hit_row][hit_colum] = 1;
			*score += 1;
			break;
		}
		else if ((*score) % 2 == 1 && miniMap[hit_row][hit_colum] == 0)//o
		{
			for (int i = 0; i < O_rows; i++)
			{
				for (int k = 0; k < O_colums - 1; k++)
					if (O_arr[i][k] != ' ')
						map[hit_row * 9 + i][hit_colum * 20 + k] = O_arr[i][k];
			}
			miniMap[hit_row][hit_colum] = 2;
			*score += 1;
			break;
		}
	}
}
bool bot_draw(int* score, int hit_row, int hit_colum)
{
	if ((*score) % 2 == 0 && miniMap[hit_row][hit_colum] == 0)//x
	{
		for (int i = 0; i < X_rows; i++)
		{
			for (int k = 0; k < X_colums - 1; k++)
				if (X_arr[i][k] != ' ')
					map[hit_row * 9 + i][hit_colum * 20 + k] = X_arr[i][k];
		}
		miniMap[hit_row][hit_colum] = 1;
		*score += 1;
		return 1;
	}
	else if ((*score) % 2 == 1 && miniMap[hit_row][hit_colum] == 0)//o
	{
		for (int i = 0; i < O_rows; i++)
		{
			for (int k = 0; k < O_colums - 1; k++)
				if (O_arr[i][k] != ' ')
					map[hit_row * 9 + i][hit_colum * 20 + k] = O_arr[i][k];
		}
		miniMap[hit_row][hit_colum] = 2;
		*score += 1;
		return 1;
	}
	return 0;
}

void medium_bot_move(int* score)
{
	int hit_colum = -1;
	int hit_row = -1;
	int hit_diog_1 = -1;
	int hit_diog_2 = -1;
	if (*score % 2 == 1)
	{
		for (int i = 0; i < 3; i++)
		{
			bool correct_row = false;
			bool correct_colum = false;
			bool correct_diog_1 = false;
			bool correct_diog_2 = false;
			hit_row = -1;
			hit_colum = -1;
			hit_diog_1 = -1;
			hit_diog_2 = -1;
			int count_x_O = 0;
			int count_y_O = 0;
			int count_diog_1x_O = 0;
			int count_diog_2x_O = 0;

			for (int k = 0; k < 3; k++)
			{
				// Проверка строк
				miniMap[i][k] == 2 ? count_x_O++ : 0;
				miniMap[i][k] == 0 ? correct_row = true : 0;

				// Проверка столбцов
				miniMap[k][i] == 2 ? count_y_O++ : 0;
				miniMap[k][i] == 0 ? correct_colum = true : 0;

				// Проверка первой диагонали
				miniMap[k][k] == 2 ? count_diog_1x_O++ : 0;
				miniMap[k][k] == 0 ? correct_diog_1 = true : 0;

				// Проверка второй диагонали
				miniMap[2 - k][k] == 2 ? count_diog_2x_O++ : 0;
				miniMap[2 - k][k] == 0 ? correct_diog_2 = true : 0;
			}

			// Проверка строк для выигрыша ноликов
			if (count_x_O == 2 && correct_row)
			{
				hit_row = i;
				break;
			}

			// Проверка столбцов для выигрыша ноликов
			if (count_y_O == 2 && correct_colum)
			{
				hit_colum = i;
				break;
			}

			// Проверка первой диагонали для выигрыша ноликов
			if (count_diog_1x_O == 2 && correct_diog_1)
			{
				hit_diog_1 = 1;
				break;
			}

			// Проверка второй диагонали для выигрыша ноликов
			if (count_diog_2x_O == 2 && correct_diog_2)
			{
				hit_diog_2 = 1;
				break;
			}
		}

		// Если нет возможности выиграть, блокируем крестики
		if (hit_row == -1 && hit_colum == -1 && hit_diog_1 == -1 && hit_diog_2 == -1)
		{
			for (int i = 0; i < 3; i++)
			{
				bool correct_row = false;
				bool correct_colum = false;
				bool correct_diog_1 = false;
				bool correct_diog_2 = false;
				hit_row = -1;
				hit_colum = -1;
				hit_diog_1 = -1;
				hit_diog_2 = -1;
				int count_x_X = 0;
				int count_y_X = 0;
				int count_diog_1x_X = 0;
				int count_diog_2x_X = 0;

				for (int k = 0; k < 3; k++)
				{
					// Проверка строк
					miniMap[i][k] == 1 ? count_x_X++ : 0;
					miniMap[i][k] == 0 ? correct_row = true : 0;

					// Проверка столбцов
					miniMap[k][i] == 1 ? count_y_X++ : 0;
					miniMap[k][i] == 0 ? correct_colum = true : 0;

					// Проверка первой диагонали
					miniMap[k][k] == 1 ? count_diog_1x_X++ : 0;
					miniMap[k][k] == 0 ? correct_diog_1 = true : 0;

					// Проверка второй диагонали
					miniMap[2 - k][k] == 1 ? count_diog_2x_X++ : 0;
					miniMap[2 - k][k] == 0 ? correct_diog_2 = true : 0;
				}

				// Проверка строк для блокировки крестиков
				if (count_x_X == 2 && correct_row)
				{
					hit_row = i;
					break;
				}

				// Проверка столбцов для блокировки крестиков
				if (count_y_X == 2 && correct_colum)
				{
					hit_colum = i;
					break;
				}

				// Проверка первой диагонали для блокировки крестиков
				if (count_diog_1x_X == 2 && correct_diog_1)
				{
					hit_diog_1 = 1;
					break;
				}

				// Проверка второй диагонали для блокировки крестиков
				if (count_diog_2x_X == 2 && correct_diog_2)
				{
					hit_diog_2 = 1;
					break;
				}
			}
		}
	}
	else
	{
		for (int i = 0; i < 3; i++)
		{
			bool correct_row = false;
			bool correct_colum = false;
			bool correct_diog_1 = false;
			bool correct_diog_2 = false;
			hit_row = -1;
			hit_colum = -1;
			hit_diog_1 = -1;
			hit_diog_2 = -1;
			int count_x_O = 0;
			int count_y_O = 0;
			int count_diog_1x_O = 0;
			int count_diog_2x_O = 0;

			for (int k = 0; k < 3; k++)
			{
				// Проверка строк
				miniMap[i][k] == 1 ? count_x_O++ : 0;
				miniMap[i][k] == 0 ? correct_row = true : 0;

				// Проверка столбцов
				miniMap[k][i] == 1 ? count_y_O++ : 0;
				miniMap[k][i] == 0 ? correct_colum = true : 0;

				// Проверка первой диагонали
				miniMap[k][k] == 1 ? count_diog_1x_O++ : 0;
				miniMap[k][k] == 0 ? correct_diog_1 = true : 0;

				// Проверка второй диагонали
				miniMap[2 - k][k] == 1 ? count_diog_2x_O++ : 0;
				miniMap[2 - k][k] == 0 ? correct_diog_2 = true : 0;
			}

			// Проверка строк для выигрыша ноликов
			if (count_x_O == 2 && correct_row)
			{
				hit_row = i;
				break;
			}

			// Проверка столбцов для выигрыша ноликов
			if (count_y_O == 2 && correct_colum)
			{
				hit_colum = i;
				break;
			}

			// Проверка первой диагонали для выигрыша ноликов
			if (count_diog_1x_O == 2 && correct_diog_1)
			{
				hit_diog_1 = 1;
				break;
			}

			// Проверка второй диагонали для выигрыша ноликов
			if (count_diog_2x_O == 2 && correct_diog_2)
			{
				hit_diog_2 = 1;
				break;
			}
		}

		// Если нет возможности выиграть, блокируем крестики
		if (hit_row == -1 && hit_colum == -1 && hit_diog_1 == -1 && hit_diog_2 == -1)
		{
			for (int i = 0; i < 3; i++)
			{
				bool correct_row = false;
				bool correct_colum = false;
				bool correct_diog_1 = false;
				bool correct_diog_2 = false;
				hit_row = -1;
				hit_colum = -1;
				hit_diog_1 = -1;
				hit_diog_2 = -1;
				int count_x_X = 0;
				int count_y_X = 0;
				int count_diog_1x_X = 0;
				int count_diog_2x_X = 0;

				for (int k = 0; k < 3; k++)
				{
					// Проверка строк
					miniMap[i][k] == 2 ? count_x_X++ : 0;
					miniMap[i][k] == 0 ? correct_row = true : 0;

					// Проверка столбцов
					miniMap[k][i] == 2 ? count_y_X++ : 0;
					miniMap[k][i] == 0 ? correct_colum = true : 0;

					// Проверка первой диагонали
					miniMap[k][k] == 2 ? count_diog_1x_X++ : 0;
					miniMap[k][k] == 0 ? correct_diog_1 = true : 0;

					// Проверка второй диагонали
					miniMap[2 - k][k] == 2 ? count_diog_2x_X++ : 0;
					miniMap[2 - k][k] == 0 ? correct_diog_2 = true : 0;
				}

				// Проверка строк для блокировки крестиков
				if (count_x_X == 2 && correct_row)
				{
					hit_row = i;
					break;
				}

				// Проверка столбцов для блокировки крестиков
				if (count_y_X == 2 && correct_colum)
				{
					hit_colum = i;
					break;
				}

				// Проверка первой диагонали для блокировки крестиков
				if (count_diog_1x_X == 2 && correct_diog_1)
				{
					hit_diog_1 = 1;
					break;
				}

				// Проверка второй диагонали для блокировки крестиков
				if (count_diog_2x_X == 2 && correct_diog_2)
				{
					hit_diog_2 = 1;
					break;
				}
			}
		}
	}

	if (hit_row != -1)
	{
		for (int j = 0; j < 3; j++)
		{
			bot_draw(score, hit_row, j);
		}
	}
	else if (hit_colum != -1)
	{
		for (int j = 0; j < 3; j++)
		{
			bot_draw(score, j, hit_colum);
		}
	}
	else if (hit_diog_1 != -1)
	{
		for (int j = 0; j < 3; j++)
		{
			bot_draw(score, j, j);
		}
	}
	else if (hit_diog_2 != -1)
	{
		for (int j = 0; j < 3; j++)
		{
			bot_draw(score, 2 - j, j);
		}
	}
	else
	{
		while (true)
		{
			hit_row = rand() % 3;
			hit_colum = rand() % 3;
			if (bot_draw(score, hit_row, hit_colum))
			{
				break;
			}
		}
	}
}

void choose_type_draw()
{
	char ch_arr[rows][colum] = { ' ' };
	for (int i = 0; i < rows; i++)
	{
		for (int k = 0; k < colum - 1; k++)
		{
			ch_arr[i][k] = ' ';
		}
	}
	for (int i = 0; i < choose_rows; i++)
	{
		for (int k = 0; k < choose_colums - 1; k++)
		{
			ch_arr[i + 10][k + 50] = choose_arr[i][k];

		}
	}
	paint_map(ch_arr);
}
void choose_bot_lvl_draw()
{
	system("cls");
	char r[choose_lvl_colums] = { ' ' };
	for (int i = 0; i < choose_lvl_rows; i++)
	{
		for (int k = 0; k < choose_lvl_colums; k++)
		{
			r[k] = choose_lvl_arr[i][k];
		}
		cout << r << endl;
	}
}
int move(char (*arr)[colum], char(&search_place)[s_place_rows][s_place_colums], int* coordinate_x, int* coordinate_y, int* score, bool* run) //передвижение и навигация
{

	int step_x = 20;
	int step_y = 9;

	char a = _getch();
	if (a == 27)
	{
		*run = false;
		return 0;
	}

	if (a == 77 || a == 100)
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
	if (a == 75 || a == 97)
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
	if (a == 80 || a == 115)
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
	if (a == 72 || a == 119)
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
bool draw_win_scene()
{
	char rund_b;
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
		return 1;
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
		return 1;
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
		rund_b = _getch();
		return 1;
	}
	return 0;
}
int play_with_friend()
{
	int score = 0;

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
		//////////////////////////////////////////////////////////////////////////
		if (draw_win_scene())
			return 0;
	}
	system("cls");
}
struct Move {
	int index_X;
	int index_Y;
	int score;
};
Move minimax(int miniMap[3][3], int depth, bool isMaximizing) {
	int winner = isWin_miniMaks(miniMap);
	if (winner == 1) return { -1, -1, 10 - depth };
	if (winner == 2) return { -1, -1, depth - 10 };
	if (winner == 3) return { -1, -1, 0 };

	if (isMaximizing) {
		Move bestMove = { -1, -1, -1000 };
		for (int i = 0; i < 3; ++i) {
			for (int k = 0; k < 3; k++) {
				if (miniMap[i][k] == 0) {
					miniMap[i][k] = 1;
					Move move = minimax(miniMap, depth + 1, false);
					miniMap[i][k] = 0;
					if (move.score > bestMove.score) {
						bestMove = { i, k, move.score };
					}
				}
			}
		}
		return bestMove;
	}
	else {
		Move bestMove = { -1, -1, 1000 };
		for (int i = 0; i < 3; ++i) {
			for (int k = 0; k < 3; k++) {
				if (miniMap[i][k] == 0) {
					miniMap[i][k] = 2;
					Move move = minimax(miniMap, depth + 1, true);
					miniMap[i][k] = 0;
					if (move.score < bestMove.score) {
						bestMove = { i, k, move.score };
					}
				}
			}
		}
		return bestMove;
	}
}
void hard_bot_move(int* score)
{
	Move bestMove = minimax(miniMap, 0, true);
	bot_draw(score, bestMove.index_X, bestMove.index_Y);
}
int play_with_bot()
{
	//сделать оформление выбора х\о и уровня сложности
	choose_bot_lvl_draw();
	char setlvl = _getch();
	system("cls");
	choose_type_draw();
	char checkChoise = _getch();
	system("cls");
	int XorOType = 0;
	checkChoise == 49 ? XorOType = 0 : 0;
	checkChoise == 50 ? XorOType = 1 : 0;
	int score = 0;
	int coordinate_x = 20;
	int coordinate_y = 9;
	paint_map(map);
	bool run = true;
	while (run)
	{
		if (score % 2 == XorOType)
		{
			move(map, search_place, &coordinate_x, &coordinate_y, &score, &run);
		}
		else
		{
			Sleep(300);
			switch (setlvl)
			{
			case 49:
				easy_bot_move(&score);
				break;
			case 50:
				medium_bot_move(&score);
				break;
			case 51:
				hard_bot_move(&score);
				break;
			}

		}
		whoNext(map, score);
		system("cls");
		paint_map(map);
		if (draw_win_scene())
			return 0;
	}
	system("cls");
}


void restart_minimap(int (*arr)[3]) //парезегрузка миникарты
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
	srand(time(0));
	copyMap(main_map, map);
	while (true)
	{
		system("cls");
		paint_map(menu);
		copyMap(map, main_map);
		restart_minimap(miniMap);
		char button = _getch();
		if (button == 49)
		{
			system("cls");
			play_with_friend();
		}
		else if (button == 50)
		{
			system("cls");
			play_with_bot();
		}
		else if (button == 27 || button == 51)
		{
			system("cls");
			paint_map(end_prog);
			return 0;
		}
	}
}