#include <iostream>
#include <string>

class Comparable {
public:
    virtual bool compare(const Comparable& other) const = 0; // Pure virtual function
    virtual ~Comparable() = default; // Virtual destructor
};

class Person : public Comparable {
private:
    std::string name;
    int age;

public:
    Person(const std::string& name, int age) : name(name), age(age) {}

    // Override the compare method
    bool compare(const Comparable& other) const override {
        // Downcast to Person to access age
        const Person* otherPerson = dynamic_cast<const Person*>(&other);
        if (otherPerson) {
            return this->age > otherPerson->age; // Compare based on age
        }
        return false; // If cast fails, return false
    }

    void display() const {
        std::cout << "Name: " << name << ", Age: " << age << '\n';
    }
};

int main() {
    Person ali("Ali", 30);
    Person omar("Omar", 20);

    ali.display();
    omar.display();

    if (ali.compare(omar)) {
        std::cout << "Ali is older than Omar.\n";
    } else {
        std::cout << "Omar is older than or the same age as Ali.\n";
    }

    return 0;
}
