class Animal {
  public:
    void animalSound() {
    cout << "The animal makes a sound \n" ;
  }
};

class Pig : public Animal {
  public:
    void animalSound() {
    cout << "The pig says: wee wee \n" ;
  }
};

class Dog : public Animal {
  public:
    void animalSound() {
    cout << "The dog says: bow wow \n" ;
  }
};
