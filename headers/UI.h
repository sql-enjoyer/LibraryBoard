#pragma once
#include "File.h"
#include "Graphic.h"
using namespace std;

class UI: public Graphic{
private:
	string state;
	string answer;

	void check(Actions _state, string state, Actions last = Actions::menu){
		while(this->state == state){
			cout << "Your choise: ";
			cin >> answer;
			cout << endl;
			try{
				stoi(answer);
			}
			catch(...){
				cout << "Hey! Choose a correct action!" << endl;
				continue;
			}

			switch(_state){
				case Actions::list:
					switch(stoi(answer)){
						case 1:
							menu();
							break;
						case 2:
							leave(Actions::list);
							break;
						default:
							cout << "Wrong action!" << endl;
							break;
					}
					break;
				case Actions::leave:
					switch(stoi(answer)){
						case 1:
							abort();
						case 2:
							switch(last){
								case Actions::menu:
									menu();
									break;
								case Actions::list:
									list();
									break;
							}
							break;
						default:
							cout << "Wrong action!" << endl;
							break;
					}
					break;
				case Actions::menu:
					switch(stoi(answer)){
						case 1:
							list();
							break;
						case 2:
							leave(Actions::menu);
							break;
						default:
							cout << "Wrong action!" << endl;
							break;
					}
					break;
			}

		}
	}
public:
	UI(){
	menu();
	};
	void list(){
		state = "List";
		interface(Actions::list, state);
		check(Actions::list, "List");
	}

	void leave(Actions last){
		state = "Leave";
		interface(Actions::leave, state);
		check(Actions::leave, state, last);
	}

	void menu(){
		state = "Menu";
		interface(Actions::menu, state);
		check(Actions::menu, state);
	}
};
