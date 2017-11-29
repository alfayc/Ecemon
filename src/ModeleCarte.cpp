//Don't forget to include what's necessary
#include "ModeleCarte.h"

using namespace std;

ModeleCarte::ModeleCarte()
{
    //ctor
}

ModeleCarte::~ModeleCarte()
{
    //dtor
}

// écrit la carte dans un fichier
void ModeleCarte::Write_file(ofstream& fichier)
{
    fichier << endl << m_CardNum << endl;
    fichier << m_Nom << endl;
    fichier << m_Description << endl;
}

// lit la carte dans un fichier
void ModeleCarte::Read_file(ifstream& fichier)
{
    fichier.ignore(1, '\n');

    getline(fichier, m_Nom);

    getline(fichier, m_Description);
}

