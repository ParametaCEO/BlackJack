#ifndef PLAYER_H
#define PLAYER_H


class Player
{
    public:
        Player(unsigned int argChips = 0);
        virtual ~Player();
        Player(const Player& other);
        Player& operator=(const Player& other);

        unsigned int GetChips() { return iChips; }
        void SetChips(unsigned int val) { iChips = val; }

        unsigned int putBet(unsigned int betSize);
        unsigned int allIn();

    protected:

    private:
        unsigned int iChips;
};

#endif // PLAYER_H
