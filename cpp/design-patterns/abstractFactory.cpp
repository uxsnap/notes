#include <iostream>
#include <string>

using namespace std;

struct Dessert {
  virtual ~Dessert() {}
  virtual string getState() const = 0;  
};

struct IceCream : Dessert {
  string getState() const override { return "cold"; }
};

struct Cake : Dessert {
  string getState() const override { return "tender"; }
};

struct Flavour {
  virtual ~Flavour() {}
  virtual string getTaste() const = 0;
};

struct Strawberry : Flavour {
  string getTaste() const override { return "strawberry"; }
};


struct Caramel : Flavour {
  string getTaste() const override { return "caramel"; }
};

struct TastyDishFactory {
  virtual Dessert * createDessert() const = 0;
  virtual Flavour * createFlavour() const = 0;
};

struct StrawberryIceCreamFactory : TastyDishFactory {
  Dessert * createDessert() const override {
    return new IceCream();
  }

  Flavour * createFlavour() const override {
    return new Strawberry();
  }
};


struct CaramelCakeFactory : TastyDishFactory {
  Dessert * createDessert() const override {
    return new Cake();
  }

  Flavour * createFlavour() const override {
    return new Caramel();
  }
};

void tasteIt(TastyDishFactory *tdf) {
  const Dessert *d = tdf->createDessert();
  const Flavour *f = tdf->createFlavour();

  cout << d->getState() << " and " << f->getTaste() << endl;

  delete d;
  delete f;
}

int main() {
  StrawberryIceCreamFactory * ccf = new StrawberryIceCreamFactory();

  tasteIt(ccf);

  return 0;
}

