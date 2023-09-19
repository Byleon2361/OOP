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
    Animal();
    ~Animal();
    int step; // шаг хода, у зайца - 1, у лисы - 2
    void move();
    virtual int change(int d); // d - direction
    virtual int changeAge();
    virtual int changeDirection();
    virtual void eat();   // 🍍
    virtual void death(); // ☠
    virtual void sex();   // 🥵
};