///*Створити структуру Videogame, яка має наступні поля:
//	-Назву гри;
//	-Назва розробника гри;
//	-Жанр гри;
//	-Ціна гри;
//	-Короткий опис гри;
//Реалізувати програму, в якій буде меню з наступними пунктами:
//	-Показати всі ігри;
//	-Найти гру по назві;
//	-Показати всі ігри по розробнику;
//	-Показати всі ігри по жанру;
//	-Показати всі ігри в діапазоні цін;
//	-(Не обов’язково) Додати нову гру;
//	-(Не обов’язково) Видалити гру по назві;
//Створіть масив на кучі із цих відеоігор. Нехай спочатку буде 5 ігор. Можете скористатись списковою ініціалізацією.
//Якщо ви хочете реалізувати два останні пункти, то спочатку магазин має бути пустий (вказівник = nullptr). Кожний пункт меню – це функція. */
//#include <iostream>
//#include <ctime>
//using namespace std;
//
//struct Videogame
//{
//	char name[50] = " ";
//	char developers[50] = " ";
//	char genre[30] = " ";
//	double price;
//	char shortDescription[300] = " ";
//};
//
//int ShowMenu();
//void ShowGames(const Videogame const gamesArr[]);
//void SearchGame(const Videogame const gamesArr[], const char const searchGame[50]);
//void SearchGameByDeveloper(const Videogame const gamesArr[], const char const userDevelop[50]);
//void SearchGameByGenre(const Videogame const gamesArr[], const char const userGenre[50]);
//void SearchGameByPrice(const Videogame const gamesArr[], double startPrice, double finishPrice);
//
//int main()
//{
//	Videogame fifa = { "FIFA 2020", "EA Sports", "Sport simulator", 34, "FIFA 20 is a football simulation video game published by Electronic Arts as part of the FIFA series. It is the 27th installment in the FIFA series" };
//	Videogame cs = { "Counter-Strike 1.6", "Valve", "FPS", 6, "Counter-Strike 1.6 is a multiplayer first-person shooter video games, in which teams of terrorists battle with counter-terrorist forces" };
//	Videogame fallout = { "Fallout 4", "Bethesda Game Studios", "Action/RPG", 28.5, "Fallout 4 is set within an open world post-apocalyptic environment that encompasses the city of Boston" };
//	Videogame rust = { "Rust", "Team Garry", "Survivle", 20, "The objective of Rust is to survive in the wilderness using gathered or stolen materials. " };
//	Videogame hoi = { "Heards of Iron 4", "Paradox Development Studio", "Strategy", 17, "Hearts of Iron IV is the sequel to Paradox Development Studio's game Hearts of Iron 3. It covers the time period from 1936 to 1948" };
//
//	Videogame* gamesArr = new Videogame[5]{ fifa, cs, fallout, rust, hoi };
//
//	int menuOption = 0;
//
//	do
//	{
//		menuOption = ShowMenu();
//
//		switch (menuOption)
//		{
//		case 1:
//			ShowGames(gamesArr);
//			break;
//		case 2:
//		{
//			char userGame[50] = " ";
//			cout << "Input game name: ";
//			cin.ignore();
//			cin.getline(userGame, 50);
//			SearchGame(gamesArr, userGame);
//			break;
//		}
//		case 3:
//		{
//			char userDevelop[50];
//			cout << "Input develop: ";
//			cin.ignore();
//			cin.getline(userDevelop, 50);
//			SearchGameByDeveloper(gamesArr, userDevelop);
//			break;
//		}
//		case 4:
//		{
//			char userGenre[50] = " ";
//			cout << "Input genre: ";
//			cin.ignore();
//			cin.getline(userGenre, 50);
//			SearchGameByGenre(gamesArr, userGenre);
//			break;
//		}
//		case 5:
//		{
//			double* startPrice = new double;
//			double* finishPrice = new double;
//			cout << "Input price from ($): ";
//			cin >> *startPrice;
//			cout << "Input price to ($): ";
//			cin >> *finishPrice;
//			SearchGameByPrice(gamesArr, *startPrice, *finishPrice);
//			delete startPrice, finishPrice;
//			startPrice = finishPrice = nullptr;
//			break;
//		}
//		case 6:
//			return 0;
//		}
//	} while (menuOption != 6);
//
//	return 0;
//}
//
//int ShowMenu()
//{
//	int menuOption;
//	do
//	{
//		cout << "===================================\n";
//		cout << "|1. Show all games		  |\n";
//		cout << "|2. More information about game   |\n";
//		cout << "|3. Show all games by developers  |\n";
//		cout << "|4. Show all games by genre	  |\n";
//		cout << "|5. Show all games by price	  |\n";
//		cout << "|6. Exit                          |\n";
//		cout << "===================================\n";
//		cout << "Input a option(1-6): ";
//		cin >> menuOption;
//		if (menuOption < 1 || menuOption>6)
//		{
//			cout << "Error, input right option (1-6)\n";
//			system("pause");
//			system("cls");
//		}
//	} while (menuOption < 1 || menuOption>6);
//	return menuOption;
//}
//
//void ShowGames(const Videogame const gamesArr[])
//{
//	for (int i = 0; i < 5; i++)
//		cout << gamesArr[i].name << endl;
//	cout << endl;
//}
//
//void SearchGame(const Videogame const gamesArr[], const char const searchGame[50])
//{
//	bool isGame = false;
//	for (int i = 0; i < 5; i++)
//	{
//		if (strstr(gamesArr[i].name, searchGame) != nullptr)
//		{
//			cout << "\nTitle: " << gamesArr[i].name << endl;
//			cout << "Developers: " << gamesArr[i].developers << endl;
//			cout << "Genre: " << gamesArr[i].genre << endl;
//			cout << "Price: " << gamesArr[i].price << "$\n";
//			cout << "Short description to the game: " << gamesArr[i].shortDescription << endl << endl;
//			isGame = true;
//		}
//	}
//	if (isGame == false)
//		cout << "\nThere aren't game by that name in my list\n";
//}
//
//void SearchGameByDeveloper(const Videogame const gamesArr[], const char const userDevelop[50])
//{
//	bool isDevelopers = false;
//
//	for (int i = 0; i < 5; i++)
//	{
//		if (strstr(gamesArr[i].developers, userDevelop) != nullptr)
//		{
//			cout << userDevelop << " had that game: \n";
//			isDevelopers = true;
//			break;
//		}
//	}
//
//	for (int i = 0; i < 5; i++)
//		if (strstr(gamesArr[i].developers, userDevelop) != nullptr)
//			cout << "\t" << gamesArr[i].name << endl;
//
//	if (isDevelopers == false)
//		cout << "\nSorry, there aren't that developer in my list\n";
//}
//
//void SearchGameByGenre(const Videogame const gamesArr[], const char const userGenre[50])
//{
//	bool isGenre = false;
//
//	for (int i = 0; i < 5; i++)
//	{
//		if (strstr(gamesArr[i].genre, userGenre) != nullptr)
//		{
//			cout << "There are that game by " << userGenre << " genre: \n";
//			isGenre = true;
//			break;
//		}
//	}
//
//	for (int i = 0; i < 5; i++)
//		if (strstr(gamesArr[i].genre, userGenre) != nullptr)
//			cout << "\t" << gamesArr[i].name << endl;
//
//	if (isGenre == false)
//		cout << "\nSorry, there aren't that genre in my list\n";
//}
//
//void SearchGameByPrice(const Videogame const gamesArr[], double startPrice, double finishPrice)
//{
//	bool isPrice = false;
//	for (int i = 0; i < 5; i++)
//	{
//		if (gamesArr[i].price >= startPrice && gamesArr[i].price <= finishPrice)
//		{
//			cout << "\t" << gamesArr[i].name << " and that price: " << gamesArr[i].price << "$\n";
//			isPrice = true;
//		}
//	}
//	if (isPrice == false)
//		cout << "\nSorry, there aren't game by your price in list\n";
//}