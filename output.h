/*
2021-04-27
Andr� Nordlund
anno1907
Datastrukturer och algoritmer DT046G
Labb 3
*/
/*
Du har tv� alternativ f�r att �stadkomma det:
1. Spara samtliga datapunkter fr�n programmet. Metod,N, tids�tg�ng, se-rie. Du beh�ver d� efterbehandla m�tserierna.
2. Spara medelv�rdet och standardavvikelsen f�r varje m�tpunkt. Du beh�ver�ven spara antal m�tningar och annan relevant data.
Exempel p� 2. https://gyazo.com/f78ddaa9e47b1cfe88620fceb8a92838
*/
#include <fstream>
#include <vector>
#ifndef OUTPUT_H
#define OUTPUT_H
/// <summary>
/// Clears file from data with given filename
/// </summary>
/// <param name="filename"></param>
void clearFiles(std::vector<std::string> fileNames);

/// <summary>
/// Writes given output to given filename
/// </summary>
/// <param name="filename"></param>
/// <param name="output"></param>
void write(std::string filename, std::string output);
#endif