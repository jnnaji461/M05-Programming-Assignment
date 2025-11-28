/* Program name: Beverage Classification System.cpp
Author: Judith Nnaji
Date: 11/29/2025
Purpose:
*/

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

// ===================================================================================
// Base Class: Beverage
// ===================================================================================
class Beverage {
protected:
    string name;
    string description;
    string servingSize;
    int calories;
    double price;

public:
    Beverage(string n, string d, string ss, int cals, double p)
        : name(n), description(d), servingSize(ss), calories(cals), price(p) {
    }

    virtual ~Beverage() {}

    // Getters
    string getName() const { return name; }
    string getDescription() const { return description; }
    string getServingSize() const { return servingSize; }
    int getCalories() const { return calories; }
    double getPrice() const { return price; }

    // Setters
    void setName(string n) { name = n; }
    void setDescription(string d) { description = d; }
    void setServingSize(string ss) { servingSize = ss; }
    void setCalories(int c) {
        if (c >= 0) calories = c;
        else calories = 0;
    }
    void setPrice(double p) {
        if (p >= 0) price = p;
        else price = 0.0;
    }

    virtual string toString() const {
        stringstream ss;
        ss << "Name: " << name
            << "\nDescription: " << description
            << "\nServing Size: " << servingSize
            << "\nCalories: " << calories
            << "\nPrice: $" << price;
        return ss.str();
    }
};

// ===================================================================================
// Derived Class: Coffee
// ===================================================================================
class Coffee : public Beverage {
private:
    string temperature;
    bool caffeinated;
    string roastType;
    string strength;
    string creamer;
    string sweetener;

public:
    Coffee(string n, string d, string ss, int cal, double p,
        string temp, bool caf, string roast, string strong,
        string crm, string swt)
        : Beverage(n, d, ss, cal, p), temperature(temp), caffeinated(caf),
        roastType(roast), strength(strong), creamer(crm), sweetener(swt) {
    }

    virtual ~Coffee() {}

    // Getters
    string getTemperature() const { return temperature; }
    bool getCaffeinated() const { return caffeinated; }
    string getRoastType() const { return roastType; }
    string getStrength() const { return strength; }
    string getCreamer() const { return creamer; }
    string getSweetener() const { return sweetener; }

    // Setters
    void setTemperature(string temp) { temperature = temp; }
    void setCaffeinated(bool caf) { caffeinated = caf; }
    void setRoastType(string roast) { roastType = roast; }
    void setStrength(string strong) { strength = strong; }
    void setCreamer(string crm) { creamer = crm; }
    void setSweetener(string swt) { sweetener = swt; }

    string toString() const override {
        stringstream ss;
        ss << "\n--- Coffee ---\n" << Beverage::toString()
            << "\nTemperature: " << temperature
            << "\nCaffeinated: " << (caffeinated ? "Yes" : "No")
            << "\nRoast Type: " << roastType
            << "\nStrength: " << strength
            << "\nCreamer: " << creamer
            << "\nSweetener: " << sweetener << "\n";
        return ss.str();
    }
};

// ===================================================================================
// Derived Class: Tea
// ===================================================================================
class Tea : public Beverage {
private:
    string type;
    string temperature;
    string creamer;
    string sweetener;
    bool lemon;

public:
    Tea(string n, string d, string ss, int cal, double p,
        string t, string temp, string crm, string sw, bool lem)
        : Beverage(n, d, ss, cal, p), type(t), temperature(temp),
        creamer(crm), sweetener(sw), lemon(lem) {
    }

    virtual ~Tea() {}

    // Getters
    string getType() const { return type; }
    string getTemperature() const { return temperature; }
    string getCreamer() const { return creamer; }
    string getSweetener() const { return sweetener; }
    bool getLemon() const { return lemon; }

    // Setters
    void setType(string t) { type = t; }
    void setTemperature(string temp) { temperature = temp; }
    void setCreamer(string crm) { creamer = crm; }
    void setSweetener(string sw) { sweetener = sw; }
    void setLemon(bool lem) { lemon = lem; }

    string toString() const override {
        stringstream ss;
        ss << "\n--- Tea ---\n" << Beverage::toString()
            << "\nType: " << type
            << "\nTemperature: " << temperature
            << "\nCreamer: " << creamer
            << "\nSweetener: " << sweetener
            << "\nLemon: " << (lemon ? "Yes" : "No") << "\n";
        return ss.str();
    }
};

// ===================================================================================
// Derived Class: Soda
// ===================================================================================
class Soda : public Beverage {
private:
    string brand;
    string type;
    bool diet;

public:
    Soda(string n, string d, string ss, int cal, double p,
        string b, string t, bool dFlag)
        : Beverage(n, d, ss, cal, p), brand(b), type(t), diet(dFlag) {
    }

    virtual ~Soda() {}

    // Getters
    string getBrand() const { return brand; }
    string getType() const { return type; }
    bool getDiet() const { return diet; }

    // Setters
    void setBrand(string b) { brand = b; }
    void setType(string t) { type = t; }
    void setDiet(bool d) { diet = d; }

    string toString() const override {
        stringstream ss;
        ss << "\n--- Soda ---\n" << Beverage::toString()
            << "\nBrand: " << brand
            << "\nType: " << type
            << "\nDiet: " << (diet ? "Yes" : "No") << "\n";
        return ss.str();
    }
};

// ===================================================================================
// Derived Class: Energy Drink
// ===================================================================================
class EnergyDrink : public Beverage {
private:
    string brand;
    string stimulant;
    string sweetener;

public:
    EnergyDrink(string n, string d, string ss, int cal, double p,
        string b, string stim, string sw)
        : Beverage(n, d, ss, cal, p), brand(b), stimulant(stim), sweetener(sw) {
    }

    virtual ~EnergyDrink() {}

    // Getters
    string getBrand() const { return brand; }
    string getStimulant() const { return stimulant; }
    string getSweetener() const { return sweetener; }

    // Setters
    void setBrand(string b) { brand = b; }
    void setStimulant(string stim) { stimulant = stim; }
    void setSweetener(string sw) { sweetener = sw; }

    string toString() const override {
        stringstream ss;
        ss << "\n--- Energy Drink ---\n" << Beverage::toString()
            << "\nBrand: " << brand
            << "\nStimulant: " << stimulant
            << "\nSweetener: " << sweetener << "\n";
        return ss.str();
    }
};

// ===================================================================================
// MAIN PROGRAM
// ===================================================================================
int main() {
    cout << "BEVERAGE CLASSIFICATION SYSTEM\n";
    cout << "===============================\n";

    Coffee coffee("Caramel Latte", "Rich espresso with caramel", "16 oz", 250, 4.99,
        "Hot", true, "Medium Roast", "Strong", "Half & Half", "Sugar");

    Tea tea("Green Tea", "Refreshing antioxidant tea", "12 oz", 0, 2.49,
        "Green", "Hot", "None", "Honey", false);

    Soda soda("Cola Classic", "Carbonated soft drink", "20 oz", 210, 1.99,
        "Coca-Cola", "Cola", false);

    EnergyDrink energy("PowerMax", "High-energy performance drink", "16 oz", 180, 3.49,
        "PowerMax", "Caffeine + Taurine", "Sucralose");

    cout << coffee.toString();
    cout << tea.toString();
    cout << soda.toString();
    cout << energy.toString();

    // Demonstrate setters
    cout << "\n=== DEMONSTRATING SETTERS ===\n";
    coffee.setPrice(5.49);
    tea.setLemon(true);
    soda.setDiet(true);
    energy.setSweetener("Stevia");

    cout << "\nUpdated Coffee Price: $" << coffee.getPrice() << endl;
    cout << "Tea now has Lemon: " << (tea.getLemon() ? "Yes" : "No") << endl;
    cout << "Soda is now Diet: " << (soda.getDiet() ? "Yes" : "No") << endl;
    cout << "Energy Drink Sweetener: " << energy.getSweetener() << endl;

    return 0;
}