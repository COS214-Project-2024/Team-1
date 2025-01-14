#ifndef FAMILY_H
#define FAMILY_H

#include "Citizen.h"
#include <vector>
#include <memory>
#include <iostream>
#include <algorithm>

class Family : public AbstractCitizen, std::enable_shared_from_this<Family> {
private:
    std::string district;
    std::vector<std::shared_ptr<AbstractCitizen>> members;
    std::shared_ptr<void> cityContext;
    std::shared_ptr<Government> government;

public:
//-----Family Composite stuff-----//
    Family(std::shared_ptr<CityContext> cityContext, std::shared_ptr<Government> government, std::string district = "-");
    ~Family() override;
    void add(std::shared_ptr<AbstractCitizen> citizen) override;
    void remove(std::shared_ptr<AbstractCitizen> citizen) override;
    
    int getSatisfaction() const override;
    int getESoL() const override;
    int getASoL() const override;
    double getCurrentIncome() const override;
    std::string getDistrict() const;
    void setDistrict(std::string district);
    
    void goOnStrike() override;
    void resolveStrike() override;
    void moveDistrict(const std::string& district);
    double getMonthlyExpenditure() const;


    void goToWork();
    void goToShops();
    void getSchooled();
    void getEducated();
    void getHealed();

//-----Context Observer-----//
    void updateContext() override;
 
//-----Government: Observer, Visitor-----//
    //void applyTax(double taxRate) override;
    double calculateTax() override;
    void payTax(double amount) override;
    void update(const std::string& resourceType, int quantity) override;
    void accept(TaxCollector& collector) override;

};

#endif // FAMILY_H
