#include "nonstandartacid.h"
#include <QDebug>


static std::vector<QString> LIST_NON_STANDART_ACIDS = {"3,3,5-triiodothyronine", "3,4-dihydroxyproline",
"3,5-dichlorothyrosine", "3,5-diiodotyrosine", "3-bromo-5-chlorotyrosine", "3-bromothyrosine",
"3-chlorothyrosine", "3-hydroxyproline", "3-iodotyrosine", "3-methylhistidine",
"4-hydroxyproline", "NG,N'G-dimethylarginine", "NG,NG-dimethylarginine", "NG-methylargynine",
"citrulline", "delta-hydroxylizine", "desmosine", "dithyrosine", "epsilon-(N,N)-dimethyllysine",
"epsilon-(N,N,N)-trimethyl-delta-hydroxylisine", "epsilon-(N,N,N)-trimethyllysine",
"epsilon-N-methyllysine", "gamma-carboxyglutamic", "gipuzine", "isodesmosin", "lisinoroleucine",
"thyroxine"};


NonStandartAcid::NonStandartAcid(QString const& name) {
    this->setName(name);
}

NonStandartAcid::NonStandartAcid(NonStandartAcid const& obj) {
    this->name = obj.name;
}

void NonStandartAcid::setName(const QString &name) {
    if(std::binary_search(LIST_NON_STANDART_ACIDS.begin(), LIST_NON_STANDART_ACIDS.end(), name)) {
        this->name = name;
    } else {
        throw(std::exception());
    }
}

QString NonStandartAcid::getLongName() {
    return name;
}
