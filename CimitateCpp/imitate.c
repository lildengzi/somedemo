/**
 * @file imitate.c
 * @author lil_DengZi
 * @brief c语言实现简单面向对象
 * @version 0.1
 * @date 2023-04-08
 * 
 * @copyright Copyright (c) 2023 lil_DengZi
 * 
 */

#include <stdio.h>
int get(struct Animal *animal);
void set(struct Animal *animal, int);
void MiAo(struct Cat *cat);

/**
 * @brief 面向对象有三大特性
 * 封装(hide) 继承(super) 多态(father)
 */
typedef struct Animal
{
    int m_name;
    int (*GET)(struct Animal*);
    void (*SET)(struct Animal*, int);
}Animal;

Animal AnimalConstructor(int name)
{
    Animal animal;
    animal.m_name = name;
    animal.GET = get;
    animal.SET = set;
    return animal;
}

int get(struct Animal *animal)
{
    return animal->m_name;
}

void set(struct Animal *animal, int name)
{
    animal->m_name = name;
}

typedef struct Cat
{
    Animal *super;
    int life;
    void (*yee)(struct Cat*);
}Cat;

Cat CatConstructor(struct Animal* father,int life)
{
    Cat cat;
    cat.life = life;
    cat.super = father;
    cat.yee = MiAo;
    return cat;
}

void MiAo(struct Cat *cat)
{
    printf("MiAo, MiAo");
}

int main()
{
    Animal a = AnimalConstructor(20);
    a.SET(&a, 30);
    Cat cat = CatConstructor(&a, 9);
    printf("%d\n", a.GET(&a));
    cat.yee(&cat);
    fflush(stdin);
    getchar();
    return 0;
}