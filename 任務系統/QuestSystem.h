class Quest {
private:
    string description;
    int reward;

public:
    Quest( string description, int reward ) : description( description ), reward( reward ) {}

    void completeQuest( Player& player );
};
