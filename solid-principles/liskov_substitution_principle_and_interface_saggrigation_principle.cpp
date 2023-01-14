/* The Liskov Substitution Principle states that subclasses should be substitutable for their base classes. */


class Bird
{
	virtual void eat() = 0;
	virtual void fly() = 0;
};

class Duck : public Bird
{
	void eat() { std::cout << "can eat"}
	void fly() { std::cout << "can fly"}
};

/* Here duck satisfies the liskov substitution principle as duck satisfies all the functionlaity that bird has so duck can be substitutable for Bird */

class Ostrich : public Bird
{
	void eat() { std::cout << "can eat"}
	void fly() { throw std::exception("The function is not supported")}
};

/* Here ostrich didnt satisfy the LSV principle as ostrict cannot fly so he cannot satisfies all the functionality of bird and that is why ostrich cannot be substitutable for bird */

/* In this case to satisfy the LSV for above example we need to split Bird interface and which is nothing but next principle called as interface saggrigation principle. */
/* we split Bird interface into two interface one is Bird and other is FlyingBird to satisfy LSV using interface saggrigation principle.*/



class Bird
{
	virtual void eat() = 0;	
};

class FylingBird : public Bird
{
	virtual void fly() = 0;
};

class Duck : public FylingBird
{
	void eat() { std::cout << "can eat"}
	void fly() { std::cout << "can fly"}
};


class Ostrich : public Bird
{
	void eat() { std::cout << "can eat"}
	void fly() { throw std::exception("The function is not supported")}
};

/* The Segregation means keeping things separated, and the Interface Segregation Principle is about separating the interfaces which we did in this example . The main thing whne you desing interface you need to make sure that the users of that interfcae should use all its functionality and should come into the situtaion  that some of the functionality of interface is not belongs to them. In that case interface uses either will throw an error for such functionality or keep it blank which tells that the interface deisng is not good and it is breaking interface saggrigation principle */


