#include <iostream>
#include <string>

struct IceCream {
  virtual std::string getState() const = 0;
  virtual ~IceCream() {}
};

struct ChocolateIceCream : IceCream {
  std::string getState() const override { return "cold and chocolate"; }
};

struct VanillaIceCream : IceCream {
  std::string getState() const override { return "cold and tender"; }
};

struct IceCreamCreator {
  virtual ~IceCreamCreator() {}
  virtual IceCream * create() const = 0;

  std::string getState() const {
    IceCream * iceCream = create();

    std::string state = iceCream->getState();

    delete iceCream;
    
    return state;
  }
};

struct ChocolateIceCreamFabric : IceCreamCreator {
  IceCream * create() const override {
    return new ChocolateIceCream();
  }
};


struct VanillaIceCreamFabric : IceCreamCreator {
  IceCream * create() const override {
    return new VanillaIceCream();
  }
};

void tasteIceCream(IceCreamCreator*);

int main() {
  IceCreamCreator * iceCreamCreator = new ChocolateIceCreamFabric();
  tasteIceCream(iceCreamCreator);
  delete iceCreamCreator;
}

void tasteIceCream(IceCreamCreator* icc) {
  std::cout << icc->getState();
}
