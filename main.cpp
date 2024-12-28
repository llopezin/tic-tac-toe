#include <iostream>
#include <string>
#include <array>

using namespace std;

struct Player
{
    string name;
    string mark;
};

void printLine(string line[3])
{
    for (int i = 0; i < 3; i++)
    {
        cout << line[i];
    }
}

void printBoard(string lines[3][3], string letters)
{
    cout << "  123" << endl;

    for (int i = 0; i < 3; i++)
    {
        cout << letters[i] << ":";
        printLine(lines[i]);
        cout << endl;
    }
}

int runTurn(Player players[2], int *playerIndex, string lines[3][3], int *counter)
{
    string lineLetters = "abc";

    cout << "Is turn for player " + players[*playerIndex].name << endl;
    cout << "Enter line letter followed by column number (ex. b2)" << endl;

    printBoard(lines, lineLetters);

    string selectedCell;
    cin >> selectedCell;

    if (selectedCell.length() != 2)
    {
        cout << "Please enter line letter followed by column number" << endl;
        return 0;
    }

    int selectedLine = lineLetters.find(selectedCell[0]);
    int selectedColumn = stoi(string(1, selectedCell[1])) - 1;

    bool badLetter = selectedLine == string::npos;
    if (badLetter)
    {
        cout << "Line letter must be a, b, or c." << endl;
        return 0;
    }

    bool badColumn = selectedColumn < 0 || selectedColumn > 2;
    if (badColumn)
    {
        cout << "Number must be 1, 2, or 3." << endl;
        return 0;
    }

    bool isValidCell = lines[selectedLine][selectedColumn] == "_";
    if (isValidCell)
    {
        lines[selectedLine][selectedColumn] = players[*playerIndex].mark;
        *playerIndex = (*playerIndex + 1) % 2;
        (*counter)++;
    }
    else
    {
        cout << "Select an empty cell" << endl;
    }

    return 0;
}

int main()
{
    Player players[2] = {{name : "1", mark : "x"}, {name : "2", mark : "o"}};

    string lines[3][3] = {
        {"_", "_", "_"},
        {"_", "_", "_"},
        {"_", "_", "_"}};

    int playerIndex = 0;
    int counter = 0;

    while (counter < 9)
    {
        cout << "New turn" << endl;
        runTurn(players, &playerIndex, lines, &counter);
    }

    return 0;
}