#pragma once
#include "File.h"
using namespace std;

enum class Actions {menu, list, leave};
class Graphic: public File{
public:
	Graphic(): File("data.db"){};
	void interface(Actions _state, string state){
		cout << "        LibraryBoard"<< endl;
		cout << "Location: " << state << endl;
		switch (_state)
		{
			case Actions::menu:
				cout << "Choose your action:" << endl;
				cout << " 1. List of books  2. Leave" << endl;
				break;
			case Actions::list:
				cout << endl;
				read('1', '3');
				cout << "Choose your action:" << endl;
				cout << " 1. Menu  2. Leave" << endl;
				break;
			case Actions::leave:
				cout << "Choose your action:" << endl;
				cout << "Are you sure you want to leave?" << endl;
				cout << " 1. Yes, sure  2. No" << endl;
				break;
		}
	}
};