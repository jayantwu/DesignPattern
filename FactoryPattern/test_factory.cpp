#include <iostream>
#include <string>
#include <memory>
using namespace std;
//抽象产品类AbstractProduct
class AbstractSportProduct
{
public:
	AbstractSportProduct(){
 
	}
    virtual ~AbstractSportProduct() = default;
	//抽象方法：
	virtual void printName(){};  //子类去实现，并使用
	virtual void play(){};
};



//具体产品类Basketball
class Basketball :public AbstractSportProduct
{
public:
	Basketball(){
		printName();
		play();
	}
    ~Basketball()=default;
	//具体实现方法
	void printName(){
		cout << "Jungle get Basketball\n";
	}
	void play(){
		cout << "Jungle play Basketball\n";
	}
};
 
//具体产品类Football
class Football :public AbstractSportProduct
{
public:
	Football(){
		printName();
		play();
	}
    ~Football()=default;
	//具体实现方法
	void printName(){
		cout << "Jungle get Football\n";
	}
	void play(){
		cout << "Jungle play Football\n";
	}
};
 
//具体产品类Volleyball
class Volleyball :public AbstractSportProduct
{
public:
	Volleyball(){
		printName();
		play();
	}
    ~Volleyball()=default;
	//具体实现方法
	void printName(){
		cout << "Jungle get Volleyball\n";
	}
	void play(){
		cout << "Jungle play Volleyball\n";
	}
};




class Factory
{
public:
	shared_ptr<AbstractSportProduct> getSportProduct(string productName)
	{
		shared_ptr<AbstractSportProduct> pro = nullptr;   // abstract product pointer
		if (productName == "Basketball"){
			pro = shared_ptr<Basketball>(new Basketball());  //多态
		}
		else if (productName == "Football"){
			pro = shared_ptr<Football>(new Football());
		}
		else if (productName == "Volleyball"){
			pro = shared_ptr<Volleyball>(new Volleyball());
		}
		return pro;
	}
};

int main()
{
	cout << "简单工厂模式\n";
	// only need to pass a product name (string) to the factory, the factory will produce a product
	//定义工厂类对象
	shared_ptr<Factory> fac = shared_ptr<Factory>(new Factory());
	shared_ptr<AbstractSportProduct> product = nullptr;
 
	product = fac->getSportProduct("Basketball");
 
	product = fac->getSportProduct("Football");
 
	product = fac->getSportProduct("Volleyball");	

	return 0;
}




//abstract product
//concrete product
//factory