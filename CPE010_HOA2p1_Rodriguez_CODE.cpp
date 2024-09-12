#include <iostream>
#include <string>

class GroceryItem {

private:
    std::string name;
    double price;
    int quantity;
    
public:
    //constructor
	GroceryItem(std::string name, double price, int quantity) {
        this->name = name;
        this->price = price;
        this->quantity = quantity;
    }
    
	//Deconstructor
    ~GroceryItem() {
        std::cout << "Deleting " << name << std::endl;
    }
	
	//Copy constructor
    GroceryItem(const GroceryItem& other) {
	this->name = other.name;
	this->price = other.price;
	this->quantity = other.quantity;
	}
    
	//Copy assignment
    GroceryItem& operator=(const GroceryItem& other) {
        if (this != &other) {
            name = other.name;
            price = other.price;
            quantity = other.quantity;
        }
        return *this;
    }

    double calculateSum() const {
        return price * quantity;
    }

    std::string getName() const {
        return name;
    }

    double getPrice() const {
        return price;
    }

    int getQuantity() const {
        return quantity;
    }
};

class Fruit : public GroceryItem {
public:
    Fruit(const std::string& name, double price, int quantity) : GroceryItem(name, price, quantity) {}
};

class Vegetable : public GroceryItem {
public:
    Vegetable(const std::string& name, double price, int quantity) : GroceryItem(name, price, quantity) {}
};

double TotalSum(GroceryItem** groceryList, int size) {
    double total = 0.0;
    for (int i = 0; i < size; ++i) {
        total += groceryList[i]->calculateSum();
    }
    return total;
}

int main() {
	//Making GroceryList
    GroceryItem* groceryList[] = {
        new Fruit("Apple", 10.0, 7),
        new Fruit("Banana", 10.0, 8),
        new Vegetable("Broccoli", 60.0, 12),
        new Vegetable("Lettuce", 50.0, 10)
    };

    int groceryListSize = sizeof(groceryList) / sizeof(groceryList[0]);

    // Display items
    for (int i = 0; i < groceryListSize; ++i) {
        std::cout << groceryList[i]->getName() << ": PHP " << groceryList[i]->getPrice() << " x " << groceryList[i]->getQuantity() << " = PHP " << groceryList[i]->calculateSum() << std::endl;
    }

    // Calculate total sum
    double totalSum = TotalSum(groceryList, groceryListSize);
    std::cout << "Total sum: PHP " << totalSum << std::endl;

    // Delete Lettuce
    delete groceryList[3];

    return 0;
}
