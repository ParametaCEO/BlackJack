#ifndef ROUND_H
#define ROUND_H


class Round
{
    public:
        Round();
        virtual ~Round();

        unsigned int GetiPot() { return iPot; }
        void SetiPot(unsigned int val) { iPot = val; }
        bool GetbPush() { return bPush; }
        void SetbPush(bool val) { bPush = val; }
        bool GetbFullStand() { return bFullStand; }
        void SetbFullStand(bool val) { bFullStand = val; }

    protected:

    private:
        unsigned int iPot;
        bool bPush;
        bool bFullStand;
};

#endif // ROUND_H
