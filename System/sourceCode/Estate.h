#ifndef ESTATE_H
#define ESTATE_H

#include <string>
#include <memory>
#include "ResidentialBuildings.h"
#include "Government.h"

class Estate : public ResidentialBuildings {
private:
    int garageSize;
    int numUnits;
    bool pool;

public:
    Estate(int x, int y, const std::string& district, int quality, int garageSize, bool hasPool, int residents, int floors, bool hasGarden, int units);

    Estate(const Estate& other)
        : ResidentialBuildings(other), numUnits(other.numUnits), garageSize(other.garageSize), pool(other.pool) {}


    // Clone function
    std::shared_ptr<BuildingComponent> clone() const override {
        return std::make_shared<Estate>(*this);
    }

    int getGarageSize() const;
    bool hasSwimmingPool() const;
    std::string getBuildingType() override;
    double getCost() override;
    double getMaintenanceCost() override;
    double getEnergyConsumption() override;
    double getWaterConsumption() override;
    void construct();
    void demolish() override;
    double getArea() override;
    int getOccupancy() override;
    std::string getType() const override {
        return "Estate"; // Return the specific type
    }
	int getNumResidents();
    void upgrade(std::shared_ptr<BuildingComponent> building) override;
};

#endif // ESTATE_H
