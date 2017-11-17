//Don't forget to include what's necessary
#include "ModeleCreature.h"

ModeleCreature::ModeleCreature()
{
    //ctor
}

ModeleCreature::ModeleCreature(int a)
    :m_AD(2), m_HP(10), m_Nom("premiere"), m_Description("")
{

}

ModeleCreature::~ModeleCreature()
{
    //dtor
}
