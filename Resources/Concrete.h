#ifndef CONCRETE_H
#define CONCRETE_H

#include "Resource.h"
#include <string>

class Concrete : public Resource {
public:
    Concrete(int quantity) : Resource(quantity) {}

    std::string getName() override;
};

#endif // CONCRETE_H