#pragma once
class Animal
{
public:
    // координаты зверя на поле
    int x;
    int y;
    int direction; // направление (направления кодируются 0 (север), 1 (восток), 2 (юг), 3(запад))
    int stability;
    int age;

protected:
    int step; // шаг хода, у зайца - 1, у лисы - 2
    int deathAge;
    int saturation;     // насыщение
    void change(int d); // d - direction
    int changeDirection();
    virtual int changeAge() = 0;
    virtual void eat() = 0;   // 🍍
    virtual void death() = 0; // ☠
    virtual void sex() = 0;   // 🥵
};