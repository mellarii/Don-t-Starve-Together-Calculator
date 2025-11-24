#ifndef CHARACTERS_H
#define CHARACTERS_H

class Character {
    private:
    float totalCharDmgBonus;
    public:
    Character();


    void selectOther();
    void selectWess();
    void selectWolvgang();
    void selectWigfrid();

    float getCharacterDmgBonus() const;
};


#endif // CHARACTERS_H