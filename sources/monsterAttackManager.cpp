#include "memory"
#include "adventurer.h"
#include "monster.h"

monsterAttackManager::monsterAttackManager(){}

double monsterAttackManager::attack(groundElement *elem)
{
    auto mnstr=dynamic_cast<monster*>(elem);

    double force = mnstr->forcePoints();
    double randomnb = pickRandom();

    if(randomnb > mnstr->getHability())
    {
        force*=0.9;
    }
    return force;
}

bool monsterAttackManager::receiveAttack(groundElement *elem,double force)
{
    auto mnstr=dynamic_cast<monster*>(elem);
    double pvmonstre = mnstr->lifePoints();

    if(force > pvmonstre)
    {
        return true;
    }
    else{
        mnstr->setLifePoints(pvmonstre - force);
        return false;
    }
}