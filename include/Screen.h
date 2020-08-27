#ifndef SCREEN_H
#define SCREEN_H
#include <string>

using namespace std;


class Screen
{
    public:
        Screen(string strPrompt);
        Screen();
        virtual ~Screen();

        string GetstrTextTable() { return strTextTable; }
        void SetstrTextTable(string val) { strTextTable = val; }
        string GetstrMessage() { return strMessage; }
        void SetstrMessage(string val) { strMessage = val; }
        string GetstrHand() { return strHand; }
        void SetstrHand(string val) { strHand = val; }
        string GetstrCommand() { return strCommand; }
        void SetstrCommand(string val) { strCommand = val; }

        string displayScreen(string val);

    protected:

    private:
        string strTextTable;
        string strMessage;
        string strHand;
        string strCommand;
};

#endif // SCREEN_H
