#ifndef PLAYER_H
#define PLAYER_H


class Player
{
    public:
        Player(unsigned int argChips);
        virtual ~Player();
        Player(const Player& other);
        Player& operator=(const Player& other);

        unsigned int GetChips() { return iChips; }
        void SetChips(unsigned int val) { iChips = val; }

    protected:

    private:
        unsigned int iChips;
};

#endif // PLAYER_H
