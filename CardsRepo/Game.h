#ifndef GAME_H
#define GAME_H

#include <string>
#include "Screen.h"
#include "Round.h"

using namespace std;


class Game
{
    public:
        Game();
        virtual ~Game();

        string GetstrCommands() { return strCommands; }
        void SetstrCommands(string val) { strCommands = val; }
        Screen GetgameScreen() { return gameScreen; }
        void SetgameScreen(Screen val) { gameScreen = val; }
        Round GetgameRound() { return gameRound; }
        void SetgameRound(Round val) { gameRound = val; }

        int runCommand(string strCmd);
        string displayScreen(string val);

    protected:

    private:
        string strCommands;
        Screen gameScreen;
        Round gameRound;
};

#endif // GAME_H
