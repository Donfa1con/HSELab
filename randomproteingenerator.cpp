#include "deque/protein.h"
#include "aminoacid.h"
#include "deque/protein.h"
#include "randomproteingenerator.h"
#include <cstdlib>
#include <iostream>
#include <ctime>

Protein randomProteinGenerator() {
   const QString possibleCharacters("ACDEFGHIKLMNPQRSTVWY");
   std::srand(unsigned(std::time(0)));
   int randomStringLength = std::rand() % 100 + 1;
   AminoAcid randomAminoAcid("A");
   Protein randomProtein;

   for(int i=0; i<randomStringLength; ++i) {
       int index = std::rand() % possibleCharacters.length();
       QChar AminoAcidName = possibleCharacters.at(index);
       randomAminoAcid.setName(AminoAcidName);
       randomProtein.pushBack(randomAminoAcid);
   }
   return randomProtein;
}
