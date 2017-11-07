#include "deque/protein.h"
#include "aminoacid.h"
#include "randomproteingenerator.h"
#include <cstdlib>
#include <iostream>
#include <ctime>


Protein randomProteinGenerator() {
   const QString possibleCharacters("ACDEFGHIKLMNPQRSTVWY");
   std::srand(unsigned(std::time(0)));
   int randomStringLength = std::rand() % 100 + 1;
   Protein randomProtein;

   for(int i=0; i<randomStringLength; ++i) {
        AminoAcid *randomAminoAcid = new AminoAcid;
        int index = std::rand() % possibleCharacters.length();
        QString AminoAcidName = possibleCharacters.at(index);
        randomAminoAcid->setName(AminoAcidName);
        randomProtein.pushBack(randomAminoAcid);
   }
   return randomProtein;
}
