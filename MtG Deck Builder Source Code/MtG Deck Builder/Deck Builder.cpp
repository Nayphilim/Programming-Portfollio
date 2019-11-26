#include "Deck Builder.h"
#include <iostream>
#include <string>




using namespace std;
using namespace System;


[STAThreadAttribute]

int main() {

	System:: Windows::Forms::Application::EnableVisualStyles();
	System::Windows::Forms::Application::Run(gcnew MtGDeckBuilder::DeckBuilder());


		return 0;
	}






