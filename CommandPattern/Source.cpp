#include<iostream>

using namespace std;

//абстрактная фабрика
#define Linux

class Widget
{

public:

	virtual void draw() = 0;
};

class LinuxButton :public Widget
{

public:
	void draw() override
	{
		cout << "Linux Button\n";
	}
};

class LinuxMenu :public Widget
{

public:
	void draw() override
	{
		cout << "LinuxMenu\n";
	}
};

class WindowsButton :public Widget
{

public:
	void draw() override
	{
		cout << "Windows Button\n";
	}
};

class WindowsMenu :public Widget
{

public:
	void draw() override
	{
		cout << "WindowsMenu\n";
	}
};

class Factory
{

public:
	virtual Widget* CreateButton() = 0;
	virtual Widget* createMenu() = 0;


};

class LinuxFactory :public Factory
{

public:
	Widget* CreateButton() override
	{
		return new LinuxButton;
	}
	Widget* createMenu() override
	{
		return new LinuxMenu;
	}
};

class WindowsFactory :public Factory
{

public:
	Widget* CreateButton() override
	{
		return new WindowsButton;
	}
	Widget* createMenu() override
	{
		return new WindowsMenu;
	}
};

class Client
{
	Factory* f;
public:
	Client(Factory*f)
	{
		this->f = f;
	}
	void drawInterface()
	{
		Widget* w = f->CreateButton();
		w->draw();
		displayYesNoWindow();
		displayOKWindow();
	}


	void displayYesNoWindow()
	{
		Widget* w[2] = { f->CreateButton(), f->CreateButton() };
		w[0]->draw();
		w[1]->draw();

	}

	void displayOKWindow()
	{
		Widget* w[2] = { f->createMenu(), f->createMenu() };
		w[0]->draw();
		w[1]->draw();

	}
};


int main()
{
#ifdef Linux
	Factory* f = new LinuxFactory;
#else
	Factory* f = new WindowsFactory;
#endif
	Client* c = new Client(f);
	c->drawInterface();

}