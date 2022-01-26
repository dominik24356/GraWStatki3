#include<iostream>
#include<random>
#include<ctime>
#include<stdlib.h>
#include<conio.h>
#include<iomanip>
#include<Windows.h>
#include<string>
#include <MMSystem.h>

using namespace std;

// Mini - algorytmy 
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------


//---------------------------------------------------
void Kolorowanie(char tekst,int kolor)
{

		HANDLE hOut;
		hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		if (kolor == 1) {
			
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);  // seledynowy
		}
		else if(kolor==2)
		{
		
			SetConsoleTextAttribute(hOut, FOREGROUND_RED);  // czerwony
		}
		else if (kolor == 3)
		{
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);  //zloty
		}
		else if (kolor == 4)
		{
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN ); //zielony
		}
		else if (kolor == 5)
		{
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY); //srebrny
		}
		

		cout <<tekst;
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);


	
}

void Kolorowanie(string tekst, int kolor)
{

	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (kolor == 1) {

		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);  // seledynowy
	}
	else if (kolor == 2)
	{

		SetConsoleTextAttribute(hOut, FOREGROUND_RED);  // czerwony
	}
	else if (kolor == 3)
	{
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);  //zloty
	}
	else if (kolor == 4)
	{
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN ); //zielony
	}
	else if (kolor == 5)
	{
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY); //srebrny
	}


	cout << tekst;
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);



}
//---------------------------------------------------
int OznaczenieKolumn(char x)
{
	// PROJEKT NALEZY DO DOMINIKA SZCZEPANIKA | INFORMATYKA, WYDZIAL MATEMATYKI STOSOWANEJ | GROPA 2/4

	switch (x)
	{
	case 'a':
	{
		return 0;
		break;
	}
	case 'b':
	{
		return 1;
		break;
	}
	case 'c':
	{
		return 2;
		break;
	}
	case 'd':
	{
		return 3;
		break;
	}
	case 'e':
	{
		return 4;
		break;
	}
	case 'f':
	{
		return 5;
		break;
	}
	case 'g':
	{
		return 6;
		break;
	}
	case 'h':
	{
		return 7;
		break;
	}
	case 'i':
	{
		return 8;
		break;
	}
	case 'j':
	{
		return 9;
		break;
	}
	default:

		return 10;
	}
}

//---------------------------------------------------
void Instrukcja()
{
	Kolorowanie("                                                      INSTRUKCJA\n", 3); cout << endl;
	Kolorowanie("                                           Statek - ",3); Kolorowanie((char)0xFE, 1); Kolorowanie("  Miejsce Zabronione - ",3); Kolorowanie((char)0x1E, 2); cout << endl;
	Kolorowanie("     Podaj miejsce pierwszego elementu statku, a nastepnie jego kierunek (jesli statek jest dluzszy od 1-masztowca)", 3); cout << endl;
	Kolorowanie("                                           kierunki : 1-gora 2-prawo 3-dol 4-lewo", 3);cout << "\n\n";
	Kolorowanie("                                       Przyklad prawidlowego uzupelniania : \"G5 | 2\"", 3);cout << endl;
	Kolorowanie("                      Czyli stawiamy pierwszy element na polu G5 a nastepnie zapelniamy nim pola w prawo ", 3);cout << endl;
}

void Instrukcja2()
{
	cout << "\n\n";
	Kolorowanie("                                                  INSTRUKCJA\n", 3); cout << endl;
	Kolorowanie("                                      Przyklad prawidlowego strzalu : \"G5\"", 3); cout << endl;
	Kolorowanie("                                           Czyli strzelamy w pole G5", 3); cout << endl;
	Kolorowanie("                                    ----------------------------------------", 3);

}

void Instrukcja3()
{
	Kolorowanie("                                           Statek - ", 3); Kolorowanie((char)0xFE, 1); Kolorowanie("  Miejsce Zabronione - ", 3); Kolorowanie((char)0x1E, 2); cout << endl;

}
//----------------------------------------------------
void TworzenieStrefyBuforu(int dlogosc_statku,int Plansza[10][10],int kierunek,int x,int y)
{
	// TWORZENIE STREFY BUFOROWEJ
	for (int i = 0; i < 3; i += 2)
	{

		for (int m = 0; m <= (dlogosc_statku + 1); m++)
		{


			switch (kierunek)
			{
			case 1:
			{

				if ((((y + 1 - m) <= 9) && ((y + 1 - m) >= 0)) && (((x - 1 + i) >= 0) && ((x - 1 + i) <= 9)))
				{
					Plansza[y + 1 - m][x - 1 + i] = -1;

				}

				break;
			}
			case 2:
			{
				if ((((y - 1 + i) <= 9) && ((y - 1 + i) >= 0)) && (((x - 1 + m) >= 0) && ((x - 1 + m) <= 9)))
				{
					Plansza[y - 1 + i][x - 1 + m] = -1;
				}

				break;

			}

			case 3:
			{

				if ((((y - 1 + m) <= 9) && ((y - 1 + m) >= 0)) && (((x - 1 + i) >= 0) && ((x - 1 + i) <= 9)))
				{
					Plansza[y - 1 + m][x - 1 + i] = -1;
				}

				break;
			}
			case 4:
			{

				if ((((y - 1 + i) <= 9) && ((y - 1 + i) >= 0)) && (((x + 1 - m) >= 0) && ((x + 1 - m) <= 9)))
				{
					Plansza[y - 1 + i][x + 1 - m] = -1;
				}

				break;
			}

			default:
			{
				break;
			}
			}



		}

	}

	// dalszy ciag tworzenia buforu

	switch (kierunek)
	{

		//kierunek gora -1
		case 1:
		{
			if (0 <= (y + 1) && (y + 1) <= 9)
			{
				Plansza[y + 1][x] = -1;
			}

			if (0 <= (y - dlogosc_statku) && (y - dlogosc_statku) <= 9)
			{
				Plansza[y - dlogosc_statku][x] = -1;
			}

			break;
		}

		//kierunek prawo -2
		case 2:
		{
			if (0 <= (x - 1) && (x - 1) <= 9)
			{
				Plansza[y][x - 1] = -1;
			}

			if (0 <= (x + dlogosc_statku) && (x + dlogosc_statku) <= 9)
			{
				Plansza[y][x + dlogosc_statku] = -1;
			}

			break;
		}
		//kierunek dol -3
		case 3:
		{
			if (0 <= (y - 1) && (y - 1) <= 9)
			{
				Plansza[y - 1][x] = -1;
			}

			if (0 <= (y + dlogosc_statku) && (y + dlogosc_statku) <= 9)
			{
				Plansza[y + dlogosc_statku][x] = -1;
			}
			break;
		}
		//kierunek lewo -4
		case 4:
		{
			if (0 <= (x + 1) && (x + 1) <= 9)
			{
				Plansza[y][x+1] = -1;
			}

			if (0 <= (x- dlogosc_statku) && (x - dlogosc_statku) <= 9)
			{
				Plansza[y][x-dlogosc_statku] = -1;
			}
			break;
		}


	}
}
//Czyszczenie Planszy
void CzyszczeniePlanszy(int Plansza[10][10])
{
	for (int i = 0; i < 10; i++)
	{

		for (int j = 0; j < 10; j++)
		{
			
			Plansza[i][j] = 0;
			


		}
		
	}

}

// losowanie od 0 do 9
int Wybieranie_Miejsca_Losowo()
{
	
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(0,9);

	
	
	int wylosowane_miejsce= dis(gen);
	return wylosowane_miejsce;
}

// losowanie od 1 do 4
int Wybieranie_Kierunku_Losowo()
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(1, 4);


	int wylosowany_kierunek = dis(gen);

	return wylosowany_kierunek;
}
// ALGORYTMY DO GRY
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------


void WyswietlStatki(int Plansza[10][10])
{


	for (int i = 0; i < 10; i++)
	{

		for (int j = 0; j < 10; j++)
		{
			cout.width(3);
			if (Plansza[i][j] != 0 && Plansza[i][j] != -1)
				cout << "X";
			else {
				cout << "O";
			}


		}
		cout << endl;
	}
}

void WyswietlStatkiDokladniee(int Plansza[10][10])
{
	for (int i = 0; i < 10; i++)
	{

		for (int j = 0; j < 10; j++)
		{
			cout.width(3);
			if(Plansza[i][j]!=0 && Plansza[i][j]!=-1)
			{
				Kolorowanie(Plansza[i][j],1); // kolor seledynowy [miejsca polozenia statku]
			}
			else if(Plansza[i][j] == -1)
			{
				Kolorowanie(Plansza[i][j], 2); // kolor czerwony [miejsca buforu statku]
			}
			else
			{
				cout << Plansza[i][j]; // zwykle wyswietlanie pustych miejsc
			}
			
		}
		cout << endl;
	}
}



void WyswietlStatkiDokladnie(int Plansza[10][10])
{
	cout << "\n\n";



	cout << "                                              ";
	for (int i = 1; i <= 10; i++)
	{
		cout << " ";
		switch (i)
		{
		case 1:
		{
			Kolorowanie("A",4);
			break;
		}
		case 2:
		{
			Kolorowanie("B", 4);
			break;
		}
		case 3:
		{
			Kolorowanie("C", 4);
			break;
		}
		case 4:
		{
			Kolorowanie("D", 4);
			break;
		}
		case 5:
		{
			Kolorowanie("E", 4);
			break;
		}
		case 6:
		{
			Kolorowanie("F", 4);
			break;
		}
		case 7:
		{
			Kolorowanie("G", 4);
			break;
		}
		case 8:
		{
			Kolorowanie("H", 4);
			break;
		}
		case 9:
		{
			Kolorowanie("I", 4);
			break;
		}
		case 10:
		{
			Kolorowanie("J", 4);
			break;
		}
		default:
			break;
		}
		cout << " ";
	}
	

	cout << endl;

	for (int i = 0; i < 10; i++)
	{


		if (i != 9) {
			cout << "                                          ";
		}
		else
			cout << "                                         ";

		Kolorowanie("[", 4); Kolorowanie(to_string( i + 1),4);  Kolorowanie("]", 4);
		for (int j = 0; j < 10; j++)
		{
			cout.width(3);

			if (Plansza[i][j] != 0 && Plansza[i][j] != -1)
			{
				Kolorowanie((char)0xFE, 1);

			}
			else if (Plansza[i][j] == -1)
			{
				Kolorowanie((char)0x1E, 2);
			}
			else {
				cout << (char)0xCF;
			}

		}
		cout << endl;
	}

	cout << "\n\n";
}



void rozmiescStatkiAutomatycznie(int Plansza[10][10])
{

	//-------------------------------------------
	int ilosc_statkow;
	int x, y; // x-kolumny y-wiersze
	int kierunek; // 1gora 2prawo 3dol 4lewo
	bool Sprawdzanie_Przestrzeni; 
	int Plansza_Optymalizacja[10][10]{};
	//-------------------------------------------
	 
	


	// petla od dlogosci statkow
	for (int dlogosc_statku = 4; dlogosc_statku >= 1; dlogosc_statku--)
	{
		// Ilosc statkow danego typu : 4-masztowiec=1 | 3-masztowiec=2 | 2-masztowiec=3 | 1-masztowiec=4 

		if (dlogosc_statku == 4)
		{
			ilosc_statkow = 1;
		}
		if (dlogosc_statku == 3)
		{
			ilosc_statkow = 2;
		}
		if (dlogosc_statku == 2)
		{
			ilosc_statkow = 3;
		}
		if (dlogosc_statku == 1)
		{
			ilosc_statkow = 4;
		}


		// petla od ilosci statkow
		for (ilosc_statkow; ilosc_statkow > 0; ilosc_statkow--)
		{

			


			// PROGRAM POWTARZA SIE JESLI NAPOTKA PRZESZKODE I WYBIERA INNE MIEJSCE
			do {


				// WYBIERANIE KIERUNKU

				bool Sprawdzanie_Miejsca = false;
				while (Sprawdzanie_Miejsca == false)
				{

					//generator wybierania miejsca (losowo)

					// X - kolumny
					// Y - wiersze
					x = Wybieranie_Miejsca_Losowo();
					y = Wybieranie_Miejsca_Losowo();




					//SPRAWDZANIE MIEJSCA
					if (Plansza[y][x] == 0 && Plansza_Optymalizacja[y][x] == 0)
					{
						Sprawdzanie_Miejsca = true;
					}
					
				}


				

				
				//jesli dlugosc statku jest wieksza niz 1 musimy wybrac kierunek
				if (dlogosc_statku != 1)
				{
					//Tablica do optymalizacji | jesli kierunek bedzie zly to nie sprawdzamy go wiecej
					int Pozostale_Kierunki[4] = { 1,1,1,1 };
					bool Sprawdzanie_Kierunku;

					// SPRAWDZANIE Potencjalnie mo¿liwych kierunków
					for (int i = 1; i <= 4; i++)// i - to w tym przypadku kierunki które testujemy
					{
						if (i == 1)
						{
							if (y - (dlogosc_statku - 1) < 0)
							{
								Sprawdzanie_Kierunku = false;
							}
							else
								Sprawdzanie_Kierunku = true;

						}


						if (i == 2)
						{
							if (x + (dlogosc_statku - 1) > 9)
							{
								Sprawdzanie_Kierunku = false;
							}
							else
								Sprawdzanie_Kierunku = true;
						}


						if (i == 3)
						{
							if (y + (dlogosc_statku - 1) > 9)
							{
								Sprawdzanie_Kierunku = false;
							}
							else
								Sprawdzanie_Kierunku = true;
						}


						if (i == 4)
						{
							if (x - (dlogosc_statku - 1) < 0)
							{
								Sprawdzanie_Kierunku = false;
							}
							else
								Sprawdzanie_Kierunku = true;
						}

						//jesli kierunek byl zly - pozbywamy sie go z puli
						if (Sprawdzanie_Kierunku == false)
						{
							Pozostale_Kierunki[i - 1] = 0;
						}
					}



					// Wybieranie kierunku (z tych co pozostaly)
					do 
					{
						kierunek = Wybieranie_Kierunku_Losowo();

					} while (Pozostale_Kierunki[kierunek - 1] == 0);


					// sprawdzanie przestrzeni w tym kierunku
					Sprawdzanie_Przestrzeni = true;


					// petla sprawdza czy w danym kierunku nie znajdzie sie przeszkoda
					for (int i = 1; i <= dlogosc_statku - 1; i++)
					{

						//losowanie nowego kierunku
						while (Pozostale_Kierunki[kierunek - 1] == 0)
						{
							kierunek = Wybieranie_Kierunku_Losowo();
						}

						// Jesli podczas sprawdzania napotkamy przeszkode, [sprawdzanie przestrzeni] bedzie falszywe

						// do gory
						if (kierunek == 1)
						{
							if (Plansza[y - i][x] != 0)
							{
								Sprawdzanie_Przestrzeni = false;

							}
						}

						// w prawo
						if (kierunek == 2)
						{
							if (Plansza[y][x + i] != 0)
							{
								Sprawdzanie_Przestrzeni = false;

							}
						}

						// w dol
						if (kierunek == 3)
						{
							if (Plansza[y + i][x] != 0)
							{
								Sprawdzanie_Przestrzeni = false;

							}
						}

						// w lewo
						if (kierunek == 4)
						{
							if (Plansza[y][x - i] != 0)
							{
								Sprawdzanie_Przestrzeni = false;

							}
						}

						//jesli w przestrzeni pojawil sie obiekt - pozbywamy sie kierunku z puli i resetujemy petle
						if (Sprawdzanie_Przestrzeni == false)
						{
							Pozostale_Kierunki[kierunek - 1] = 0;
							Sprawdzanie_Przestrzeni = true;
							i = 0; // reset petli for (bo nowy kierunek musimy sprawdzaæ od nowa)
						}

						//jesli nic nie zostalo z kierunkow musimy wybrac inne miejce [ WA¯NY ELEMENT W FUNKCJI ]
						int suma_kierunkow = 0;
						for (int j = 0; j < 4; j++)
						{
							suma_kierunkow += Pozostale_Kierunki[j];
						}
						if (suma_kierunkow == 0)
							break;

					}

				}
				else
				{
					Sprawdzanie_Przestrzeni = true;
				}

				// jesli sprawdzanie przestrzeni nie powiodlo sie
				if(Sprawdzanie_Przestrzeni==false)
				Plansza_Optymalizacja[y][x] = 1; // to puste pole nie jest warte ponownego sprawdzania poniewaz nie ma wlasciwego kierunku
			}
			while (Sprawdzanie_Przestrzeni == false);

				//-------------------------------------------------------------------------------------


				TworzenieStrefyBuforu(dlogosc_statku,Plansza,kierunek,x,y);


				// WPISYWANIE STATKU

				for (int i = 0; i < dlogosc_statku; i++)
				{
					if (kierunek == 1) // do gory
					{
						Plansza[y - i][x] = dlogosc_statku;

					}

					if (kierunek == 2) // w prawo
					{
						Plansza[y][x + i] = dlogosc_statku;
					}

					if (kierunek == 3) // w dol
					{
						Plansza[y + i][x] = dlogosc_statku;
					}

					if (kierunek == 4) // w lewo
					{
						Plansza[y][x - i] = dlogosc_statku;
					}
				}

				
				


		}


	}


















}

void rozmiescStatkiRecznie(int Plansza[10][10])
{



	int ilosc_statkow;
	int x, y;
	int kierunek; // 1gora 2prawo 3dol 4lewo


	for (int dlogosc_statku = 4; dlogosc_statku >= 1; dlogosc_statku--)
	{

		if (dlogosc_statku == 4)
		{
			ilosc_statkow = 1;
		}
		if (dlogosc_statku == 3)
		{
			ilosc_statkow = 2;
		}
		if (dlogosc_statku == 2)
		{
			ilosc_statkow = 3;
		}
		if (dlogosc_statku == 1)
		{
			ilosc_statkow = 4;
		}

		for (ilosc_statkow; ilosc_statkow > 0; ilosc_statkow--)
		{
			bool sprawdzanie_miejsca = false;
			bool sprawdzanie_kierunku = false;


			// Wyswietlanie ekranu na nowo ---
			system("CLS");
			WyswietlStatkiDokladnie(Plansza);
			Instrukcja();
			//--------------------------------

			// WYBIERANIE MIEJSCA
			while (sprawdzanie_miejsca != true)
			{
				system("CLS");
				WyswietlStatkiDokladnie(Plansza);
				Instrukcja();


				// kolumny oznaczamy literami 
				char kolumna;
				int wiersz;
				cout << endl;
				cout << "                                      ";
				cout << "Typ statku ktory stawiasz -> ["; Kolorowanie(to_string(dlogosc_statku), 4); Kolorowanie(" - masztowiec",4); cout<<"]" << endl;
				if (ilosc_statkow != 1)
				{
					cout << "                                               ";
					cout << "Pozostalo -> ["; Kolorowanie(to_string( ilosc_statkow), 4); cout << "] statki tego typu" << endl;
				}
				else
				{
					cout << "                                               ";
					cout << "Pozostal "; Kolorowanie(to_string(ilosc_statkow), 4); cout << " statek tego typu" << endl;
				}

				cout << "                                                       ";
				cout << "Kolumna : ";
				kolumna = _getch();
				cout << kolumna;
				cout << endl;
				cout << "                                                       ";
				cout << "Wiersz : ";
				cin >>wiersz;
				

				if ((((wiersz-1) <= 9) && (0 <= (wiersz-1))) && ((0 <= OznaczenieKolumn(kolumna)) && (OznaczenieKolumn(kolumna) <= 9)))
				{
					if (Plansza[wiersz-1][OznaczenieKolumn(kolumna)] == 0)
					{
						sprawdzanie_miejsca = true;
						x = OznaczenieKolumn(kolumna);
						y = wiersz - 1;
						break;
					}
					else
					{
						PlaySound(TEXT("dzwiek_blad.wav"), NULL, SND_ASYNC);
						cout << "                                       ";
						cout << "Miejsce jest juz zajete lub niedozwolone !" << endl;
						Sleep(1500);
						
					}
				}
				else
				{
					PlaySound(TEXT("dzwiek_blad.wav"), NULL, SND_ASYNC);
					cout << "                               ";
					cout << "Kolumny oznaczamy od A do J a wiersze od 1 do 10 ! Jeszcze raz" << endl;
					Sleep(2900);
					
				}

			}



			// KIERUNEK

			if (dlogosc_statku == 1)
			{

				sprawdzanie_kierunku = true;
			}

			while (sprawdzanie_kierunku != true)
			{
			kierunek_1:
				system("CLS");
				WyswietlStatkiDokladnie(Plansza);
				Instrukcja();
				cout << "\n\n";
				cout << "                                                       ";
				
				cout << "Kierunek : ";

				char kierunek_test;
				kierunek_test=_getch();

				kierunek = kierunek_test-'0'; // zmienieamy string na int np '1' = 1 ;
				
				


				//sprawdzanie kierunku 1

				if (kierunek == 1)
				{
					if (y - (dlogosc_statku - 1) < 0)
						sprawdzanie_kierunku = false;
					else
						sprawdzanie_kierunku = true;

				}
				else if (kierunek == 2)
				{
					if (x + (dlogosc_statku - 1) > 9)
						sprawdzanie_kierunku = false;
					else
						sprawdzanie_kierunku = true;
				}
				else if (kierunek == 3)
				{
					if (y + (dlogosc_statku - 1) > 9)
						sprawdzanie_kierunku = false;
					else
						sprawdzanie_kierunku = true;
				}
				else if (kierunek == 4)
				{
					if (x - (dlogosc_statku - 1) < 0)
						sprawdzanie_kierunku = false;
					else
						sprawdzanie_kierunku = true;
				}
				else {
					sprawdzanie_kierunku = false;
				}

				
				if (sprawdzanie_kierunku == false)
				{
					PlaySound(TEXT("dzwiek_blad.wav"), NULL, SND_ASYNC);
					cout << endl;
					cout << "                                       ";
					Kolorowanie("Wybrales zly kierunek, sproboj jeszcze raz !",2);
					Sleep(2500);
				}
			}


			//sprawdzanie kierunku 2

			for (int i = 1; i <= dlogosc_statku - 1; i++)
			{
				if (kierunek == 1) // do gory
				{
					if (Plansza[y - i][x] != 0)
					{
						PlaySound(TEXT("dzwiek_blad.wav"), NULL, SND_ASYNC);
						cout << "                                 ";
						cout << "W kierunku ktory wybrales znajduja sie pola niedozwolone !";
						Sleep(1500);
						goto kierunek_1;
					}
				}

				if (kierunek == 2) // w prawo
				{
					if (Plansza[y][x + i] != 0)
					{
						PlaySound(TEXT("dzwiek_blad.wav"), NULL, SND_ASYNC);
						cout << "                                 ";
						cout << "W kierunku ktory wybrales znajduja sie pola niedozwolone !";
						Sleep(1500);
						goto kierunek_1;
					}
				}

				if (kierunek == 3) // w dol
				{
					if (Plansza[y + i][x] != 0)
					{
						PlaySound(TEXT("dzwiek_blad.wav"), NULL, SND_ASYNC);
						cout << "                                 ";
						cout << "W kierunku ktory wybrales znajduja sie pola niedozwolone !";
						Sleep(1500);
						goto kierunek_1;
					}
				}

				if (kierunek == 4) // w lewo
				{
					if (Plansza[y][x - i] != 0)
					{
						PlaySound(TEXT("dzwiek_blad.wav"), NULL, SND_ASYNC);
						cout << "                                 ";
						cout << "W kierunku ktory wybrales znajduja sie pola niedozwolone !";
						Sleep(1500);
						goto kierunek_1;
					}
				}
			}



			// TWORZENIE STREFY BUFOROWEJ
			TworzenieStrefyBuforu(dlogosc_statku, Plansza, kierunek, x, y);

			// WPISYWANIE STATKU

			for (int i = 0; i < dlogosc_statku; i++)
			{
				if (kierunek == 1) // do gory
				{
					Plansza[y - i][x] = dlogosc_statku;



				}

				if (kierunek == 2) // w prawo
				{
					Plansza[y][x + i] = dlogosc_statku;



				}

				if (kierunek == 3) // w dol
				{
					Plansza[y + i][x] = dlogosc_statku;



				}

				if (kierunek == 4) // w lewo
				{
					Plansza[y][x - i] = dlogosc_statku;

				}
			}







		}
	}


	// CZYSZCZENIE KONSOLI Z WIDOKU USTAWIANIA STATKOW PO ZAKONCZENIU

	system("CLS");

}



void WyswietlStatkiObokSiebie(int PlanszaGracza[10][10], int PlanszaKomputera[10][10])
{
	cout << endl;
	cout << "                   ";
	for (int i = 1; i <= 10; i++)
	{
		cout << " ";
		switch (i)
		{
		case 1:
		{
			Kolorowanie("A",2);
			break;
		}
		case 2:
		{
			Kolorowanie("B", 2);
			break;
		}
		case 3:
		{
			Kolorowanie("C", 2);
			break;
		}
		case 4:
		{
			Kolorowanie("D", 2);
			break;
		}
		case 5:
		{
			Kolorowanie("E", 2);
			break;
		}
		case 6:
		{
			Kolorowanie("F", 2);
			break;
		}
		case 7:
		{
			Kolorowanie("G", 2);
			break;
		}
		case 8:
		{
			Kolorowanie("H", 2);
			break;
		}
		case 9:
		{
			Kolorowanie("I", 2);
			break;
		}
		case 10:
		{
			Kolorowanie("J", 2);
			break;
		}
		default:
			break;
		}
		cout << " ";
	}
	cout << "                  ";

	for (int i = 1; i <= 10; i++)
	{
		cout << " ";
		switch (i)
		{
		case 1:
		{
			Kolorowanie("A", 4);
			break;
		}
		case 2:
		{
			Kolorowanie("B", 4);
			break;
		}
		case 3:
		{
			Kolorowanie("C", 4);
			break;
		}
		case 4:
		{
			Kolorowanie("D", 4);
			break;
		}
		case 5:
		{
			Kolorowanie("E", 4);
			break;
		}
		case 6:
		{
			Kolorowanie("F", 4);
			break;
		}
		case 7:
		{
			Kolorowanie("G", 4);
			break;
		}
		case 8:
		{
			Kolorowanie("H", 4);
			break;
		}
		case 9:
		{
			Kolorowanie("I", 4);
			break;
		}
		case 10:
		{
			Kolorowanie("J", 4);
			break;
		}
		default:
			break;
		}
		cout << " ";
	}

	cout << endl;

	for (int i = 0; i < 10; i++)
	{

		//wyswietlanie statkow komputera - po lewej stronie 
		if (i != 9) {
			cout << "               ";
		}
		else
			cout << "              ";

		Kolorowanie("[", 2); Kolorowanie(to_string(i + 1), 2);Kolorowanie( "]",2);
		for (int j = 0; j < 10; j++)
		{
			cout.width(3);

			if (PlanszaKomputera[i][j] ==5 )
			{

				Kolorowanie((char)0xFE,2);

			}
			else if(PlanszaKomputera[i][j]==6)
			{
				Kolorowanie((char)0x6F,1);
			}
			else
			{
				cout<<(char)0x9E;
			}
		}




		//wyswietlanie statkow gracza - po prawej stronie
		if (i != 9)
		{
			cout << "               ";
		}
		else
			cout << "              ";
		Kolorowanie("[", 4); Kolorowanie(to_string(i + 1), 4); Kolorowanie("]", 4);
		for (int k = 0; k < 10; k++)
		{

			cout.width(3);
			if (PlanszaGracza[i][k] >=1 && PlanszaGracza[i][k]<=4)
			{
				cout << (char)0xFE;
			}
			else if(PlanszaGracza[i][k]==5)
			{
				Kolorowanie((char)0xFE, 2);
			}
			else if (PlanszaGracza[i][k] == 6)
			{
				Kolorowanie((char)0x6F, 1);
			}
			else
			{
				cout << (char)0x9E;
			}
		}


		cout << endl;
	}



}

// Zagraj albo wyjdz z gry
int EkranStartowy()
{
	int CzyStart = 0;

	while (CzyStart != 1 && CzyStart != 2)
	{
		for (int i = 0; i < 5; i++)
		{
			cout << endl;
		}
		cout.width(90);

		Kolorowanie("Gra W Statki by Dominik  \"domixx\" Szczepanik,  VERSION 3.00 | 2022", 3); cout << endl;

		cout.width(90);
		cout << "------------------------------------------------------------------" << endl;
		for (int i = 0; i < 3; i++)
		{
			cout << endl;
		}
		cout.width(60);

		Kolorowanie("1 - ZAGRAJ", 4); cout << endl;


		for (int i = 0; i < 5; i++)
		{
			cout << endl;
		}
		cout.width(61);
		Kolorowanie("2 - ZAKONCZ",2);
		CzyStart = _getch();
		PlaySound(TEXT("dzwiek_Zatwierdenie.wav"), NULL, SND_ASYNC);
		switch (CzyStart)
		{
		case '1':
		{
			CzyStart = 1;
			break;
		}
		case '2':
		{
			CzyStart = 2;
			break;
		}

		default:
			break;
		}
		system("cls");

		if(CzyStart!=1 && CzyStart!=2)
			PlaySound(TEXT("dzwiek_blad.wav"), NULL, SND_ASYNC);
	}

	return CzyStart;
}

// Pytanie o ustawianie wlasnej planszy statkami (losowo lub recznie)
int EkranStartowy2()
{
	int Odpowiedz = 0;

	while (Odpowiedz != 1 && Odpowiedz != 2) {

		for (int i = 0; i < 5; i++)
		{
			cout << endl;
		}
		cout.width(90);
		Kolorowanie("Chcesz rozmiescic swoje statki automatycznie czy wlasnorecznie ? ",3);
		for (int i = 0; i < 5; i++)
		{
			cout << endl;
		}
		cout.width(65);


		Kolorowanie("1 - AUTOMATYCZNIE ", 1);cout << endl;
		for (int i = 0; i < 5; i++)
		{
			cout << endl;
		}
		cout.width(65);


		Kolorowanie("2 - WLASNORECZNIE ", 4);cout << endl;


		Odpowiedz = _getch();
		PlaySound(TEXT("dzwiek_Zatwierdenie.wav"), NULL, SND_ASYNC);// dziek zatwierdzania 

		switch (Odpowiedz)
		{
		case '1':
		{
			Odpowiedz = 1;
			break;
		}
		case '2':
		{
			Odpowiedz = 2;
			break;
		}

		default:
			break;
		}
		
		if (Odpowiedz != 1 && Odpowiedz != 2)
		{
			PlaySound(TEXT("dzwiek_blad.wav"), NULL, SND_ASYNC);
		}


		system("cls");
	}


	return Odpowiedz;

}


// Ekran podczas wlasciwej rozgrywki
void EkranGry(int PlanszaGracza[10][10], int PlanszaKomputera[10][10])
{
	//naglowki


	cout << "               ";
	for (int i = 0; i < 35; i++)
	{
		Kolorowanie("-",2);
	}

	cout << "             ";
	for (int i = 0; i < 35; i++)
	{
		Kolorowanie("-",4);
	}


	cout << endl;
	cout << "               ";
	Kolorowanie("|",2);
	cout << "         ";
	Kolorowanie("Plansza Komputera",2);
	cout << "       ";
	Kolorowanie("|",2);
	cout << "             ";
	Kolorowanie("|",4);
	cout << "         ";
	Kolorowanie("Plansza Gracza",4);
	cout << "          ";
	Kolorowanie("|",4);
	cout << endl;
	cout << "               ";
	for (int i = 0; i < 35; i++)
	{
		Kolorowanie("-",2);
	}
	cout << "             ";
	for (int i = 0; i < 35; i++)
	{
		Kolorowanie("-",4);
	}
	cout << endl;

	WyswietlStatkiObokSiebie(PlanszaGracza,PlanszaKomputera);

	


}




// GRA - Gra W Statki
// -------------------------------------------------------------------------------------------------------------------------------------------------------------------
void gra(int PlanszaGracza[10][10], int PlanszaKomputera[10][10])
{

	// ekranstarwowy=1 (graj) | ekranstartowy=2 (wyjdz z gry)
	if (EkranStartowy() == 2)
		exit(1);

	// ekranstartowy2=1 (rozmiesc swoje statki losowo) | ekranstartowy2=2 (rozmiesc swoje statki recznie)
	if (EkranStartowy2() == 1)
	{
		bool Czy_zatwierdzic_uklad=false;
		char odpowiedz;
		while (Czy_zatwierdzic_uklad != true)
		{
			rozmiescStatkiAutomatycznie(PlanszaGracza);
			system("cls");
			WyswietlStatkiDokladnie(PlanszaGracza);
			
			do 
			{
				system("cls");
				WyswietlStatkiDokladnie(PlanszaGracza);
				Instrukcja3();
				cout << "                         ";
				Kolorowanie("Czy podany uklad ci odpowiada ? Jesli tak nacisnij T jesli nie to N\n\n", 3);cout;
				odpowiedz = _getch();

				
				
				if (odpowiedz == 't') 
				{
					PlaySound(TEXT("dzwiek_Zatwierdenie.wav"), NULL, SND_ASYNC); // dzwiek zatwierdzenia
					Czy_zatwierdzic_uklad = true;
				}
				else if (odpowiedz == 'n')
				{
					PlaySound(TEXT("dzwiek_Zatwierdenie.wav"), NULL, SND_ASYNC); // dzwiek zatwierdzenia
					Czy_zatwierdzic_uklad = false;
					CzyszczeniePlanszy(PlanszaGracza);
				}
				else
				{
					PlaySound(TEXT("dzwiek_blad.wav"), NULL, SND_ASYNC);
					cout << "                                              ";
					Kolorowanie("Blad podczas wpisywania ! ",2);
					CzyszczeniePlanszy(PlanszaGracza);
					Sleep(2000);
					
				}

			} while (Czy_zatwierdzic_uklad != false && Czy_zatwierdzic_uklad != true);

		}


	}
	else
	{
		rozmiescStatkiRecznie(PlanszaGracza);
	}
		
	rozmiescStatkiAutomatycznie(PlanszaKomputera);
	
	int kolumna;
	char kolumna_test;
	int wiersz;
	int x,x_komp;
	int y,y_komp;
	int Plansza_do_trafien[10][10]{};//plansza do trafien gracza (gracz nie moze strzelac w to samo miejsce 2 razy
	int Plansza_do_trafien_komputera[10][10]{};
	int punkty_gracza = 20;
	int punkty_przeciwnika = 20;

	bool Czy_koniec_gry = false;
	int Kto_wygral=0; //wygrana : 1-gracz 2-komputer

	PlaySound(TEXT("dzwiek_start_gry.wav"), NULL, SND_ASYNC);
	while (Czy_koniec_gry==false ) 
	{
		//odswiezenie ekranu

		system("cls");
		EkranGry(PlanszaGracza, Plansza_do_trafien);
		Instrukcja2();
		cout << "\n                                   ";
		cout << "punkty gracza = "; Kolorowanie(to_string( punkty_gracza), 4); cout << " | punkty komputera = "; Kolorowanie(to_string(punkty_przeciwnika), 2); cout << "\n\n";
		cout << "                                                 ";
		cout << "Podaj kolumne : ";

		kolumna_test=_getch();
		kolumna = OznaczenieKolumn(kolumna_test);
		cout << kolumna_test;
		cout << endl;
		cout << "                                                 ";
		cout << "Podaj wiersz : ";
		int wiersz_test;
		cin >> wiersz_test;
		wiersz = wiersz_test - 1;

		// wyswietlanie komunikatu bledu podczas wpisywania
		if (kolumna < 0 || kolumna > 9 || wiersz < 0 || wiersz > 9 || Plansza_do_trafien[wiersz][kolumna]!=0)
		{
			PlaySound(TEXT("dzwiek_blad.wav"), NULL, SND_ASYNC);
			cout << endl;
			cout << "                                   ";
			Kolorowanie("Blad podczas wpisywania ! lub juz strzelales w to pole wczesniej",2);
			Sleep(4000);


		}
		else 
		{

			


			//strzelamy my
			PlaySound(TEXT("dzwiek_ladowanie.wav"), NULL, SND_ASYNC);
			cout << "                                                 ";
			Kolorowanie("Strzelasz ty !", 5);cout << endl;
			Sleep(2000);
			x = kolumna;
			y = wiersz;


			//jesli trafimy
			if (PlanszaKomputera[y][x] != -1 && PlanszaKomputera[y][x] != 0)
			{
				cout << "                                                 ";
				PlaySound(TEXT("dzwiek_trafienia.wav"), NULL, SND_ASYNC);
				Kolorowanie("Trafiles !", 4);cout << endl;
				Sleep(2000);
				Plansza_do_trafien[y][x] = 5;
				punkty_przeciwnika--;
				if (punkty_przeciwnika == 0)
				{
					system("cls");
					EkranGry(PlanszaGracza, Plansza_do_trafien);
					Instrukcja2();
					Sleep(3000);
					Czy_koniec_gry = true;
					Kto_wygral = 1; //wygrana gracza
				}
			}
			else //jesli chybimy
			{
				cout << "                                                 ";
				PlaySound(TEXT("dzwiek_Strzal_w_Wode.wav"), NULL, SND_ASYNC);
				Kolorowanie("Chybiles !", 2);cout << endl;
				Sleep(2000);
				Plansza_do_trafien[y][x] = 6;
			}

			if (Kto_wygral == 0) 
			{
				// strzal komputera
				PlaySound(TEXT("dzwiek_ladowanie.wav"), NULL, SND_ASYNC);
				cout << "                                                 ";
				Kolorowanie("Strzela Komputer", 5);cout << endl;
				Sleep(2000);

				do {
					x_komp = Wybieranie_Miejsca_Losowo();
					y_komp = Wybieranie_Miejsca_Losowo();
				} while (Plansza_do_trafien_komputera[y_komp][x_komp] != 0); // poza tym nie mozna strzelac w bufor !!!!

				// jesli komputer trafi
				if (PlanszaGracza[y_komp][x_komp] != -1 && PlanszaGracza[y_komp][x_komp] != 0)
				{
					PlaySound(TEXT("dzwiek_trafienia.wav"), NULL, SND_ASYNC);
					cout << "                                                 ";
					Kolorowanie("Przeciwnik trafil twoj statek !",2);
					Sleep(2000);
					Plansza_do_trafien_komputera[y_komp][x_komp] = 1;
					PlanszaGracza[y_komp][x_komp] = 5;
					punkty_gracza--;
					if (punkty_gracza == 0)
					{
						system("cls");
						EkranGry(PlanszaGracza, Plansza_do_trafien);
						Instrukcja2();
						Sleep(3000);
						Czy_koniec_gry = true;
						Kto_wygral = 2; //wygrana komputera
					}
				}
				else //jesli komputer chybi
				{
					PlanszaGracza[y_komp][x_komp] = 6;
					PlaySound(TEXT("dzwiek_Strzal_w_Wode.wav"), NULL, SND_ASYNC);
					cout << "                                                 ";
					Kolorowanie("Przeciwnik nie trafil !",3);
					Sleep(2000);
					Plansza_do_trafien_komputera[y_komp][x_komp] = 2;
				}
			}

		}

	}

	if (Kto_wygral == 1)// wygrywa gracz
	{
		system("cls");
		PlaySound(TEXT("dzwiek_wygrana"), NULL, SND_ASYNC);// dziek zatwierdzania 
		cout << "\n\n\n\n\n\n\n\n\n\n";
		cout << "                                                      ";
		Kolorowanie("WYGRALES !\n\n",4);
		cout << "                                                     ";
		Kolorowanie("GRATULACJE !",4);
		Sleep(5000);
	}
	else
	{

		system("cls");
		PlaySound(TEXT("dzwiek_przegrana"), NULL, SND_ASYNC);// dziek zatwierdzania 
		cout << "\n\n\n\n\n\n\n\n\n\n";
		cout << "                                                      ";
		Kolorowanie("PRZEGRALES !\n\n", 2);
		Sleep(5000);

	}












}



// w main tylko wywolujemy gre i przekazujemy jej odpowiednie parametry
int main()
{
	int PlanszaKomputera[10][10]{};
	int PlanszaGracza[10][10]{};



	// FUNKCJA GRY W STATKI ---------------------------------------



	int Od_nowa; //  2 - zakoncz gre   1 - od nowa

	// gre mozna powtarzac
	do
	{
		gra(PlanszaGracza, PlanszaKomputera);
		
		system("cls");
		do {
			system("cls");

			cout << "\n\n\n\n\n\n\n\n\n\n";
			cout <<"                                               ";
			Kolorowanie("czy chcesz zagrac od nowa ?\n\n\n ",3);
			cout << "                                            ";
			Kolorowanie("Jesli tak - \"1\" Jesli nie - \"2\"",3);
			Od_nowa=_getch();
			//musimy zamienic litery na cyfry
			if (Od_nowa == '1')
			{
				Od_nowa = 1;
			}
			else if (Od_nowa == '2')
			{
				Od_nowa = 2;
			}
			else
			{
				Od_nowa = 3;// przykladowa bledna wartosc
			}

		} while (Od_nowa != 1 && Od_nowa != 2);

		//czyszczenie planszy dla nowej rozgrywki
		if (Od_nowa == 1)
		{
			CzyszczeniePlanszy(PlanszaGracza);
			CzyszczeniePlanszy(PlanszaKomputera);
			system("cls");
		}

	} while (Od_nowa == 1);



	system("cls");
	cout << "dzieki ze zagrales :)  nacisnij enter zeby wyjsc.";
		_getch();
	system("pause");
}