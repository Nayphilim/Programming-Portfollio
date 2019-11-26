#pragma once
#include "DeckBuilder.h";
#include <msclr\marshal_cppstd.h>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <iterator>
#include <fstream>



namespace MtGDeckBuilder {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace std;
	using namespace MySql::Data::MySqlClient;

	
	struct card {
		int amount;
		string cardName;
		string typeLine;
		string manaCost;

	};

	string selectedCard;
	string deckName;
	string format;
	vector<card> creatures;
	vector<card> spells;
	vector<card> artifacts;
	vector<card> enchantments;
	vector<card> lands;



	/// <summary>
	/// Summary for DeckBuilder
	/// </summary>
	public ref class DeckBuilder : public System::Windows::Forms::Form
	{
	public:
		DeckBuilder(void)
		{
			InitializeComponent();

			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~DeckBuilder()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  cardSearchBox;
	protected:

	private: System::Windows::Forms::Button^  cardSearchButton;
	private: System::Windows::Forms::PictureBox^  cardPicture;

	private: System::Windows::Forms::RichTextBox^  deckViewer;
	private: System::Windows::Forms::StatusStrip^  statusStrip1;
	private: System::Windows::Forms::ToolStripStatusLabel^  statusLabel;
	private: System::Windows::Forms::MenuStrip^  menuStrip;

	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  newToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  saveToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;
	private: System::Windows::Forms::ComboBox^  formatComboBox;
	private: System::Windows::Forms::Label^  formatLabel;


	private: System::ComponentModel::BackgroundWorker^  backgroundWorker1;
	private: System::Windows::Forms::TextBox^  deckNameBox;

	private: System::Windows::Forms::Label^  deckNameLabel;
	private: System::Windows::Forms::Button^  addCardButton;
	private: System::Windows::Forms::RichTextBox^  cardAmount;









	private: System::Windows::Forms::ImageList^  imageList1;
	private: System::Windows::Forms::DataGridView^  cardSearchView;
	private: System::Windows::Forms::RichTextBox^  cardDetails;
	private: System::Windows::Forms::Button^  removeCardButton;


	private: System::Windows::Forms::ToolStripMenuItem^  loadToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  exportPlainTextToolStripMenuItem;


	private: System::ComponentModel::IContainer^  components;










	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->cardSearchBox = (gcnew System::Windows::Forms::TextBox());
			this->cardSearchButton = (gcnew System::Windows::Forms::Button());
			this->cardPicture = (gcnew System::Windows::Forms::PictureBox());
			this->deckViewer = (gcnew System::Windows::Forms::RichTextBox());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->statusLabel = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->menuStrip = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->newToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exportPlainTextToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->loadToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->formatComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->formatLabel = (gcnew System::Windows::Forms::Label());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->deckNameBox = (gcnew System::Windows::Forms::TextBox());
			this->deckNameLabel = (gcnew System::Windows::Forms::Label());
			this->addCardButton = (gcnew System::Windows::Forms::Button());
			this->cardAmount = (gcnew System::Windows::Forms::RichTextBox());
			this->imageList1 = (gcnew System::Windows::Forms::ImageList(this->components));
			this->cardSearchView = (gcnew System::Windows::Forms::DataGridView());
			this->cardDetails = (gcnew System::Windows::Forms::RichTextBox());
			this->removeCardButton = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cardPicture))->BeginInit();
			this->statusStrip1->SuspendLayout();
			this->menuStrip->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cardSearchView))->BeginInit();
			this->SuspendLayout();
			// 
			// cardSearchBox
			// 
			this->cardSearchBox->Location = System::Drawing::Point(613, 87);
			this->cardSearchBox->Name = L"cardSearchBox";
			this->cardSearchBox->Size = System::Drawing::Size(227, 20);
			this->cardSearchBox->TabIndex = 0;
			// 
			// cardSearchButton
			// 
			this->cardSearchButton->Location = System::Drawing::Point(845, 86);
			this->cardSearchButton->Name = L"cardSearchButton";
			this->cardSearchButton->Size = System::Drawing::Size(51, 21);
			this->cardSearchButton->TabIndex = 2;
			this->cardSearchButton->Text = L"Search";
			this->cardSearchButton->UseVisualStyleBackColor = true;
			this->cardSearchButton->Click += gcnew System::EventHandler(this, &DeckBuilder::cardSearchButton_Click);
			// 
			// cardPicture
			// 
			this->cardPicture->Location = System::Drawing::Point(12, 81);
			this->cardPicture->MaximumSize = System::Drawing::Size(215, 284);
			this->cardPicture->Name = L"cardPicture";
			this->cardPicture->Size = System::Drawing::Size(215, 284);
			this->cardPicture->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->cardPicture->TabIndex = 3;
			this->cardPicture->TabStop = false;
			// 
			// deckViewer
			// 
			this->deckViewer->BackColor = System::Drawing::SystemColors::Window;
			this->deckViewer->Location = System::Drawing::Point(233, 87);
			this->deckViewer->Name = L"deckViewer";
			this->deckViewer->ReadOnly = true;
			this->deckViewer->Size = System::Drawing::Size(374, 417);
			this->deckViewer->TabIndex = 5;
			this->deckViewer->Text = L"";
			// 
			// statusStrip1
			// 
			this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->statusLabel });
			this->statusStrip1->Location = System::Drawing::Point(0, 505);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(909, 22);
			this->statusStrip1->TabIndex = 6;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// statusLabel
			// 
			this->statusLabel->Name = L"statusLabel";
			this->statusLabel->Size = System::Drawing::Size(186, 17);
			this->statusLabel->Text = L"Welcome to the MtG Deck Builder";
			// 
			// menuStrip
			// 
			this->menuStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->fileToolStripMenuItem });
			this->menuStrip->Location = System::Drawing::Point(0, 0);
			this->menuStrip->Name = L"menuStrip";
			this->menuStrip->Size = System::Drawing::Size(909, 24);
			this->menuStrip->TabIndex = 7;
			this->menuStrip->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->newToolStripMenuItem,
					this->saveToolStripMenuItem, this->exportPlainTextToolStripMenuItem, this->loadToolStripMenuItem, this->exitToolStripMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// newToolStripMenuItem
			// 
			this->newToolStripMenuItem->Name = L"newToolStripMenuItem";
			this->newToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->newToolStripMenuItem->Text = L"New";
			this->newToolStripMenuItem->Click += gcnew System::EventHandler(this, &DeckBuilder::newToolStripMenuItem_Click);
			// 
			// saveToolStripMenuItem
			// 
			this->saveToolStripMenuItem->Name = L"saveToolStripMenuItem";
			this->saveToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->saveToolStripMenuItem->Text = L"Save";
			this->saveToolStripMenuItem->Click += gcnew System::EventHandler(this, &DeckBuilder::saveToolStripMenuItem_Click);
			// 
			// exportPlainTextToolStripMenuItem
			// 
			this->exportPlainTextToolStripMenuItem->Name = L"exportPlainTextToolStripMenuItem";
			this->exportPlainTextToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->exportPlainTextToolStripMenuItem->Text = L"Export Plain Text";
			this->exportPlainTextToolStripMenuItem->Click += gcnew System::EventHandler(this, &DeckBuilder::exportPlainTextToolStripMenuItem_Click);
			// 
			// loadToolStripMenuItem
			// 
			this->loadToolStripMenuItem->Name = L"loadToolStripMenuItem";
			this->loadToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->loadToolStripMenuItem->Text = L"Load";
			this->loadToolStripMenuItem->Click += gcnew System::EventHandler(this, &DeckBuilder::loadToolStripMenuItem_Click);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &DeckBuilder::exitToolStripMenuItem_Click);
			// 
			// formatComboBox
			// 
			this->formatComboBox->FormattingEnabled = true;
			this->formatComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"standard", L"commander", L"modern" });
			this->formatComboBox->Location = System::Drawing::Point(281, 28);
			this->formatComboBox->Name = L"formatComboBox";
			this->formatComboBox->Size = System::Drawing::Size(121, 21);
			this->formatComboBox->TabIndex = 8;
			this->formatComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &DeckBuilder::formatComboBox_SelectedIndexChanged);
			// 
			// formatLabel
			// 
			this->formatLabel->AutoSize = true;
			this->formatLabel->Location = System::Drawing::Point(233, 31);
			this->formatLabel->Name = L"formatLabel";
			this->formatLabel->Size = System::Drawing::Size(42, 13);
			this->formatLabel->TabIndex = 9;
			this->formatLabel->Text = L"Format:";
			// 
			// deckNameBox
			// 
			this->deckNameBox->Location = System::Drawing::Point(13, 44);
			this->deckNameBox->Name = L"deckNameBox";
			this->deckNameBox->Size = System::Drawing::Size(214, 20);
			this->deckNameBox->TabIndex = 10;
			// 
			// deckNameLabel
			// 
			this->deckNameLabel->AutoSize = true;
			this->deckNameLabel->Location = System::Drawing::Point(13, 27);
			this->deckNameLabel->Name = L"deckNameLabel";
			this->deckNameLabel->Size = System::Drawing::Size(64, 13);
			this->deckNameLabel->TabIndex = 11;
			this->deckNameLabel->Text = L"Deck Name";
			// 
			// addCardButton
			// 
			this->addCardButton->Location = System::Drawing::Point(122, 479);
			this->addCardButton->Name = L"addCardButton";
			this->addCardButton->Size = System::Drawing::Size(75, 23);
			this->addCardButton->TabIndex = 12;
			this->addCardButton->Text = L"Add";
			this->addCardButton->UseVisualStyleBackColor = true;
			this->addCardButton->Click += gcnew System::EventHandler(this, &DeckBuilder::addCardButton_Click);
			// 
			// cardAmount
			// 
			this->cardAmount->Location = System::Drawing::Point(203, 479);
			this->cardAmount->Name = L"cardAmount";
			this->cardAmount->Size = System::Drawing::Size(24, 22);
			this->cardAmount->TabIndex = 13;
			this->cardAmount->Text = L"1";
			// 
			// imageList1
			// 
			this->imageList1->ColorDepth = System::Windows::Forms::ColorDepth::Depth8Bit;
			this->imageList1->ImageSize = System::Drawing::Size(16, 16);
			this->imageList1->TransparentColor = System::Drawing::Color::Transparent;
			// 
			// cardSearchView
			// 
			this->cardSearchView->AllowUserToAddRows = false;
			this->cardSearchView->AllowUserToDeleteRows = false;
			this->cardSearchView->AllowUserToResizeColumns = false;
			this->cardSearchView->AllowUserToResizeRows = false;
			this->cardSearchView->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->cardSearchView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->cardSearchView->Location = System::Drawing::Point(613, 114);
			this->cardSearchView->Name = L"cardSearchView";
			this->cardSearchView->ReadOnly = true;
			this->cardSearchView->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->cardSearchView->Size = System::Drawing::Size(283, 387);
			this->cardSearchView->TabIndex = 28;
			this->cardSearchView->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &DeckBuilder::cardSearchView_CellContentClick);
			// 
			// cardDetails
			// 
			this->cardDetails->Location = System::Drawing::Point(13, 372);
			this->cardDetails->Name = L"cardDetails";
			this->cardDetails->Size = System::Drawing::Size(214, 101);
			this->cardDetails->TabIndex = 29;
			this->cardDetails->Text = L"";
			// 
			// removeCardButton
			// 
			this->removeCardButton->Location = System::Drawing::Point(41, 479);
			this->removeCardButton->Name = L"removeCardButton";
			this->removeCardButton->Size = System::Drawing::Size(75, 23);
			this->removeCardButton->TabIndex = 30;
			this->removeCardButton->Text = L"Remove";
			this->removeCardButton->UseVisualStyleBackColor = true;
			this->removeCardButton->Click += gcnew System::EventHandler(this, &DeckBuilder::removeCardButton_Click);
			// 
			// DeckBuilder
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(909, 527);
			this->Controls->Add(this->removeCardButton);
			this->Controls->Add(this->cardDetails);
			this->Controls->Add(this->cardSearchView);
			this->Controls->Add(this->cardAmount);
			this->Controls->Add(this->addCardButton);
			this->Controls->Add(this->deckNameLabel);
			this->Controls->Add(this->deckNameBox);
			this->Controls->Add(this->formatLabel);
			this->Controls->Add(this->formatComboBox);
			this->Controls->Add(this->statusStrip1);
			this->Controls->Add(this->menuStrip);
			this->Controls->Add(this->deckViewer);
			this->Controls->Add(this->cardPicture);
			this->Controls->Add(this->cardSearchButton);
			this->Controls->Add(this->cardSearchBox);
			this->Name = L"DeckBuilder";
			this->Text = L"MtG Deck Builder";
			this->Load += gcnew System::EventHandler(this, &DeckBuilder::DeckBuilder_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cardPicture))->EndInit();
			this->statusStrip1->ResumeLayout(false);
			this->statusStrip1->PerformLayout();
			this->menuStrip->ResumeLayout(false);
			this->menuStrip->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cardSearchView))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();



		}

	private: System::Void cardSearchButton_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ input = cardSearchBox->Text;
		String^ constring = L"datasource=localhost;port=3306;username=root;password=password";
		MySqlConnection^ conDatabase = gcnew MySqlConnection(constring);

		//default output when search empty
		if (input == "") {
			MySqlCommand^ cmdDataBase = gcnew MySqlCommand("SELECT name, type_line FROM mtgcards.`scryfall-default-cards` WHERE type_line NOT LIKE 'Token%';", conDatabase); //get all cards
			try {
				//fill datagridview with data from command 
				MySqlDataAdapter^ sda = gcnew MySqlDataAdapter();
				sda->SelectCommand = cmdDataBase;
				DataTable^ dbDataset = gcnew DataTable();
				sda->Fill(dbDataset);
				BindingSource^ bSource = gcnew BindingSource();

				bSource->DataSource = dbDataset;
				cardSearchView->DataSource = bSource;
				sda->Update(dbDataset);
			}
			catch (Exception^ex) {
				MessageBox::Show(ex->Message);
			}
		}
		else {
			MySqlCommand^ cmdDataBase = gcnew MySqlCommand("SELECT name, type_line FROM mtgcards.`scryfall-default-cards` WHERE name LIKE '%" + input + "%' AND type_line NOT LIKE 'Token%';", conDatabase);
			try {
				//fill datagridview with data from command 
				MySqlDataAdapter^ sda = gcnew MySqlDataAdapter();
				sda->SelectCommand = cmdDataBase;
				DataTable^ dbDataset = gcnew DataTable();
				sda->Fill(dbDataset);
				BindingSource^ bSource = gcnew BindingSource();

				bSource->DataSource = dbDataset;
				cardSearchView->DataSource = bSource;
				sda->Update(dbDataset);
			}
			catch (Exception^ex) {
				MessageBox::Show(ex->Message);

			}
		}




	}
	private: System::Void DeckBuilder_Load(System::Object^  sender, System::EventArgs^  e) {
		cardPicture->Load("pics/card_back.jpg");
	}








	private: System::Void cardSearchView_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
		Object^ value = cardSearchView->Rows[e->RowIndex]->Cells[0]->Value;
		String^ cardName = value->ToString();
		String^ input = cardSearchBox->Text;
		String^ constring = L"datasource=localhost;port=3306;username=root;password=password";
		MySqlConnection^ conDatabase = gcnew MySqlConnection(constring);
		MySqlDataReader^ myReader;
		int const MAX = 3;
		String^ cardType;
		String^ cardOracle;
		String^ cardDetailsPrint;
		String^ systemCardImageURI;

		msclr::interop::marshal_context context;
		selectedCard = context.marshal_as <string>(cardName); //converts from system string to standard string


		MySqlCommand^ cmdDataBase = gcnew MySqlCommand("SELECT type_line, oracle_text, image_uris FROM mtgcards.`scryfall-default-cards` WHERE name='" + cardName + "';", conDatabase); //get details of specific card
		try {
			conDatabase->Open();
			myReader = cmdDataBase->ExecuteReader();
			while (myReader->Read()) {
				cardType = myReader->GetString(0); //gets card type
				cardOracle = myReader->GetString(1); //gets card oracle text
				systemCardImageURI = myReader->GetString(2);
			}

		}
		catch (Exception^ex) {
			MessageBox::Show(ex->Message);

		}

		cardDetailsPrint = cardName + " | " + cardType + "\n\n" + cardOracle;
		cardDetails->Text = cardDetailsPrint; //prints card details to text box

		string cardImageURI = context.marshal_as <string>(systemCardImageURI); //converts from system string to standard string

		//gets image url
		cardImageURI.erase(0, 9);
		int end = cardImageURI.find("\"");
		cardImageURI = cardImageURI.substr(0, end);
		systemCardImageURI = gcnew String(cardImageURI.c_str());

		cardPicture->Load(systemCardImageURI);







	}


	private: System::Void addCardButton_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ amountSS = cardAmount->Text;
		int amount;
		String^ constring = L"datasource=localhost;port=3306;username=root;password=password";
		MySqlConnection^ conDatabase = gcnew MySqlConnection(constring);
		MySqlDataReader^ myReader;
		String^ cardType;
		String^ manaCost;

		msclr::interop::marshal_context context;
		string amountS = context.marshal_as <string>(amountSS); //converts from system string to standard string
		istringstream iss(amountS); //converts from string to int
		iss >> amount;

		String^ cardName = gcnew String(selectedCard.c_str());

		MySqlCommand^ cmdDataBase = gcnew MySqlCommand("SELECT type_line, mana_cost FROM mtgcards.`scryfall-default-cards` WHERE name='" + cardName + "';", conDatabase); //get details of specific card
		try {
			conDatabase->Open();
			myReader = cmdDataBase->ExecuteReader();
			while (myReader->Read()) {
				cardType = myReader->GetString(0);
				manaCost = myReader->GetString(1);
			}

		}
		catch (Exception^ex) {
			MessageBox::Show(ex->Message);

		}

		

		addToDeck(amount, cardName, cardType, manaCost); //adds card to the decklist
		deckViewer->LoadFile("temp/temp.txt", RichTextBoxStreamType::PlainText); //loads decklist into text box
		
		


	}







	private: System::Void removeCardButton_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ amountSS = cardAmount->Text;
		int amount;
		String^ constring = L"datasource=localhost;port=3306;username=root;password=password";
		MySqlConnection^ conDatabase = gcnew MySqlConnection(constring);
		MySqlDataReader^ myReader;
		String^ cardType;
		String^ manaCost;
		String^ cmc;

		msclr::interop::marshal_context context;
		string amountS = context.marshal_as <string>(amountSS); //converts from system string to standard string
		istringstream iss(amountS); //converts from string to int
		iss >> amount;

		String^ cardName = gcnew String(selectedCard.c_str());

		MySqlCommand^ cmdDataBase = gcnew MySqlCommand("SELECT type_line, mana_cost, cmc FROM mtgcards.`scryfall-default-cards` WHERE name='" + cardName + "';", conDatabase); //get details of specific card
		try {
			conDatabase->Open();
			myReader = cmdDataBase->ExecuteReader();
			while (myReader->Read()) {
				cardType = myReader->GetString(0);
				manaCost = myReader->GetString(1);
				cmc = myReader->GetString(2);
			}

		}
		catch (Exception^ex) {
			MessageBox::Show(ex->Message);

		}
		
		removeFromDeck(amount, cardName, cardType, manaCost); //removes card from deck 
	}


	private: System::Void saveToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		saveDeckList();
	}
	private: System::Void plainTextToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		saveDeckListPlainText();
	}
	private: System::Void plainTextToolStripMenuItem_Hover(System::Object^  sender, System::EventArgs^  e) {
		statusLabel->Text = "This will save the deck in a easy to read format which is compatible with most online stores and deck builders";
	}


	private: System::Void loadToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		if (MessageBox::Show("Any unsaved data will be lost", "Are you sure?", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == Windows::Forms::DialogResult::Yes) {
			clearDeckList();
			loadDeckList();
		}
	}
	private: System::Void newToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		if (MessageBox::Show("Any unsaved data will be lost", "Are you sure?", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == Windows::Forms::DialogResult::Yes) {

			deckNameBox->Text = "";
			clearDeckList();
		}
	}
	private: System::Void formatComboBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		String^ formatS = formatComboBox->Text;
		msclr::interop::marshal_context context;
		format = context.marshal_as <string>(formatS);
	}
	private: System::Void exportPlainTextToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		saveDeckListPlainText();
	}
	private: System::Void exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		if (MessageBox::Show("Any unsaved data will be lost", "Are you sure?", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == Windows::Forms::DialogResult::Yes) {
			DeckBuilder::Close();
		}
	}

			 void addToDeck(int amount, String^ selectedCard, String^ typeLine, String^ manaCost) {
				 int n;
				 int const MAX = 7;
				 string allTypes[MAX] = { "Creature", "Artifact Creature", "Instant", "Sorcery", "Artifact", "Enchantment", "Land" };
				 string cost = "";
				 string cardType = "";
				 string cardName = "";
				 card card;



				 msclr::interop::marshal_context context;
				 if (selectedCard != nullptr) {
					 cardName = context.marshal_as <string>(selectedCard);
				 }
				 if (typeLine != nullptr) {
					 cardType = context.marshal_as <string>(typeLine); //converts from system string to standard string
				 }
				 if (manaCost != nullptr) {
					 cost = context.marshal_as <string>(manaCost);
				 }

				 card.amount = amount;
				 card.cardName = cardName;
				 card.manaCost = cost;
				 card.typeLine = cardType;


				 for (int i = 0; i <= MAX; i++) {
					 if (cardType.find(allTypes[i]) != string::npos) {
						 n = i;
						 break;
					 }
				 }

				 switch (n) {
				 case 0: //is creature
					 if (checkForDuplicate(cardName, amount)) { //checks if card is already in deck
						 break;
					 }
					 else {
						 creatures.push_back(card);
						 break;
					 }


				 case 1: //is artifact creature
					 if (checkForDuplicate(cardName, amount)) {
						 break;
					 }
					 else {
						 creatures.push_back(card);
						 break;
					 }
				 case 2: //is instant
					 if (checkForDuplicate(cardName, amount)) {
						 break;
					 }
					 else {
						 spells.push_back(card);
						 break;
					 }
				 case 3: //is sorcery
					 if (checkForDuplicate(cardName, amount)) {
						 break;
					 }
					 else {
						 spells.push_back(card);
						 break;
					 }
				 case 4: //is artifact
					 if (checkForDuplicate(cardName, amount)) {
						 break;
					 }
					 else {
						 artifacts.push_back(card);
						 break;
					 }
				 case 5: //is Enchantment
					 if (checkForDuplicate(cardName, amount)) {
						 break;
					 }
					 else {
						 enchantments.push_back(card);
						 break;
					 }
				 case 6: //is Land
					 if (checkForDuplicate(cardName, amount)) {
						 break;
					 }
					 else {
						 lands.push_back(card);
						 break;
					 }

				 }

				 checkIfCardLegal(cardName, amount, cardType, format); //check if the card is legal in the selected format and returns a tooltip for the user
				 updateDeckList();


			 }

			 void removeFromDeck(int amount, String^ selectedCard, String^ typeLine, String^ manaCost) {
				 int n;
				 int pos;
				 int const MAX = 7;
				 string allTypes[MAX] = { "Creature", "Artifact Creature", "Instant", "Sorcery", "Artifact", "Enchantment", "Land" };
				 string cost = "";
				 string cardType = "";
				 string cardName = "";
				 string CMC = "";
				 card card;

				 msclr::interop::marshal_context context;
				 if (selectedCard != nullptr) {
					 cardName = context.marshal_as <string>(selectedCard);
				 }
				 if (typeLine != nullptr) {
					 cardType = context.marshal_as <string>(typeLine); //converts from system string to standard string
				 }
				 if (manaCost != nullptr) {
					 cost = context.marshal_as <string>(manaCost);
				 }


				 card.amount = amount;
				 card.cardName = cardName;
				 card.manaCost = cost;
				 card.typeLine = cardType;


				 for (int i = 0; i <= MAX; i++) {
					 if (cardType.find(allTypes[i]) != string::npos) {
						 n = i;
						 break;
					 }
				 }

				 switch (n) {
				 case 0: //is creature
					 if (cardInDeck(cardName, amount)) { //checks if card is in deck
						 break;
					 }
					 else {
						 break;
					 }
				 case 1: //is artifact creature
					 if (cardInDeck(cardName, amount)) {
						 break;
					 }
					 else {
						 break;
					 }
				 case 2: //is instant
					 if (cardInDeck(cardName, amount)) {
						 break;
					 }
					 else {
						 break;
					 }
				 case 3: //is sorcery
					 if (cardInDeck(cardName, amount)) {
						 break;
					 }
					 else {
						 break;
					 }
				 case 4: //is artifact
					 if (cardInDeck(cardName, amount)) {
						 break;
					 }
					 else {
						 break;
					 }
				 case 5: //is Enchantment
					 if (cardInDeck(cardName, amount)) {
						 break;
					 }
					 else {
						 break;
					 }
				 case 6: //is Land
					 if (cardInDeck(cardName, amount)) {
						 break;
					 }
					 else {
						 break;
					 }

				 }

				 cleanDeckList();
				 updateDeckList();


			 }

			 void updateDeckList() {
				 ofstream temp;
				 temp.open("temp/temp.txt", ios::trunc); //clear temp file
				 temp.close();
				 temp.open("temp/temp.txt", ios::app);

				 if (creatures.size() != 0) {
					 temp << "Creatures\n\n";
					 for (vector<card>::iterator p = creatures.begin(); p != creatures.end(); ++p) {
						 temp << p->amount;
						 temp << " " + p->cardName + " " + p->typeLine + " " + p->manaCost + "\n";
					 }
				 }
				 if (spells.size() != 0) {
					 temp << "\nSpells\n\n";
					 for (vector<card>::iterator p = spells.begin(); p != spells.end(); ++p) {
						 temp << p->amount;
						 temp << " " + p->cardName + " " + p->typeLine + " " + p->manaCost + "\n";
					 }
				 }
				 if (artifacts.size() != 0) {
					 temp << "\nArtifacts\n\n";
					 for (vector<card>::iterator p = artifacts.begin(); p != artifacts.end(); ++p) {
						 temp << p->amount;
						 temp << " " + p->cardName + " " + p->typeLine + " " + p->manaCost + "\n";
					 }
				 }
				 if (enchantments.size() != 0) {
					 temp << "\nEnchantments\n\n";
					 for (vector<card>::iterator p = enchantments.begin(); p != enchantments.end(); ++p) {
						 temp << p->amount;
						 temp << " " + p->cardName + " " + p->typeLine + " " + p->manaCost + "\n";
					 }
				 }
				 if (lands.size() != 0) {
					 temp << "\nLands\n\n";
					 for (vector<card>::iterator p = spells.begin(); p != spells.end(); ++p) {
						 temp << p->amount;
						 temp << " " + p->cardName + " " + p->typeLine + "\n";
					 }
				 }
				 temp.close();

			 }

			 bool checkForDuplicate(string cardName, int amount) {
				 for (vector<card>::iterator p = creatures.begin(); p != creatures.end(); ++p) {
					 if (p->cardName == cardName) { //if card being added is in the vector
						 p->amount += amount; //increase the amount of that card
						 return true;
					 }
				 }
				 for (vector<card>::iterator p = spells.begin(); p != spells.end(); ++p) {
					 if (p->cardName == cardName) { //if card being added is in the vector
						 p->amount += amount; //increase the amount of that card
						 return true;
					 }
				 }
				 for (vector<card>::iterator p = artifacts.begin(); p != artifacts.end(); ++p) {
					 if (p->cardName == cardName) { //if card being added is in the vector
						 p->amount += amount; //increase the amount of that card
						 return true;
					 }
				 }
				 for (vector<card>::iterator p = enchantments.begin(); p != enchantments.end(); ++p) {
					 if (p->cardName == cardName) { //if card being added is in the vector
						 p->amount += amount; //increase the amount of that card
						 return true;
					 }
				 }
				 for (vector<card>::iterator p = lands.begin(); p != lands.end(); ++p) {
					 if (p->cardName == cardName) { //if card being added is in the vector
						 p->amount += amount; //increase the amount of that card
						 return true;
					 }
				 }
				 return false;
			 }

			 bool cardInDeck(string cardName, int amount) {
				 for (vector<card>::iterator p = creatures.begin(); p != creatures.end(); ++p) {
					 if (p->cardName == cardName) { //if card being removed is in the vector
						 p->amount -= amount; //decrease the amount of that card
						 return true;
					 }
				 }
				 for (vector<card>::iterator p = spells.begin(); p != spells.end(); ++p) {
					 if (p->cardName == cardName) {
						 p->amount -= amount;

						 return true;
					 }
				 }
				 for (vector<card>::iterator p = artifacts.begin(); p != artifacts.end(); ++p) {
					 if (p->cardName == cardName) {
						 p->amount -= amount;

						 return true;
					 }
				 }
				 for (vector<card>::iterator p = enchantments.begin(); p != enchantments.end(); ++p) {
					 if (p->cardName == cardName) {
						 p->amount -= amount;

						 return true;
					 }
				 }
				 for (vector<card>::iterator p = lands.begin(); p != lands.end(); ++p) {
					 if (p->cardName == cardName) {
						 p->amount -= amount;

						 return true;
					 }
				 }
				 return false;
			 }

			 void cleanDeckList() {
				 for (int i = 0; i < creatures.size(); i++) {
					 if (creatures[i].amount <= 0) {
						 creatures.erase(creatures.begin() + i);
					 }
				 }
			 }

			 void clearDeckList() {
				 creatures.clear();
				 spells.clear();
				 artifacts.clear();
				 enchantments.clear();
				 lands.clear();
				 updateDeckList();

			 }

			 void checkIfCardLegal(string cardName, int amount, string cardType, string format) {
				 String^ constring = L"datasource=localhost;port=3306;username=root;password=password";
				 MySqlConnection^ conDatabase = gcnew MySqlConnection(constring);
				 MySqlDataReader^ myReader;
				 String^ legalitiesS;
				 String^ cardNameS = gcnew String(cardName.c_str());
				 MySqlCommand^ cmdDataBase = gcnew MySqlCommand("SELECT legalities FROM mtgcards.`scryfall-default-cards` WHERE name='" + cardNameS + "';", conDatabase); //get details of specific card
				 try {
					 conDatabase->Open();
					 myReader = cmdDataBase->ExecuteReader();
					 while (myReader->Read()) {
						 legalitiesS = myReader->GetString(0);
					 }

				 }
				 catch (Exception^ex) {
					 MessageBox::Show(ex->Message);

				 }

				 msclr::interop::marshal_context context;
				 string legalities = context.marshal_as <string>(legalitiesS);
				 
				 if (legalities.find("\"" + format + "\":" + " \"not_legal\"") != string::npos) {
					 statusLabel->Text =  "Deck is not legal as " + cardNameS + " is illegal in this format";
				 }
				 if (cardType.find("Basic Land") != string::npos) {
				 }
				 else {
					 if (format == "standard" || format == "modern") {
						 if (amount > 4) {
							 statusLabel->Text = "Deck is not legal as you can not have more than 4 copies of " + cardNameS;
						 }
					 }
					 if (format == "commander") {
						 if (amount > 1) {
							 statusLabel->Text = "Deck is not legal as you can not have more than 1 copy of " + cardNameS;
						 }
					 }
				 }

			 }

			 void saveDeckListPlainText() {

				 if (deckName == "") {
					 MessageBox::Show("Please enter a name for your deck and try again");
				 }
				 else {
					 msclr::interop::marshal_context context;
					 string deckName = context.marshal_as <string>(deckName); //converts from system string to standard string
					 ofstream file;
					 file.open("decks/" + deckName + ".txt", ios::trunc); //clear temp file
					 file.close();
					 file.open("decks/" + deckName + ".txt", ios::app);


					 if (creatures.size() != 0) {
						 for (vector<card>::iterator p = creatures.begin(); p != creatures.end(); ++p) {
							 file << p->amount;
							 file << " " + p->cardName + "\n";
						 }
					 }
					 if (spells.size() != 0) {
						 for (vector<card>::iterator p = spells.begin(); p != spells.end(); ++p) {
							 file << p->amount;
							 file << " " + p->cardName + "\n";
						 }
					 }
					 if (artifacts.size() != 0) {
						 for (vector<card>::iterator p = artifacts.begin(); p != artifacts.end(); ++p) {
							 file << p->amount;
							 file << " " + p->cardName + "\n";
						 }
					 }
					 if (enchantments.size() != 0) {
						 for (vector<card>::iterator p = enchantments.begin(); p != enchantments.end(); ++p) {
							 file << p->amount;
							 file << " " + p->cardName + "\n";
						 }
					 }
					 if (lands.size() != 0) {
						 for (vector<card>::iterator p = spells.begin(); p != spells.end(); ++p) {
							 file << p->amount;
							 file << " " + p->cardName + "\n";
						 }
					 }
					 file.close();
					 MessageBox::Show("Decks are located in the deck builder file in the \"decks\" folder", "Deck saved to file");
				 }
			 }

			 void saveDeckList() {


				 if (deckName == "") {
					 MessageBox::Show("Please enter a name for your deck and try again");
				 }
				 else {
					 msclr::interop::marshal_context context;
					 string deckNameS = context.marshal_as <string>(deckName); //converts from system string to standard string
					 ofstream file;
					 file.open("program decks/" + deckNameS + ".txt", ios::trunc); //clear temp file
					 file.close();
					 file.open("program decks/" + deckNameS + ".txt", ios::app);
					 if (creatures.size() != 0) {
						 file << "Creatures\n\n";
						 for (vector<card>::iterator p = creatures.begin(); p != creatures.end(); ++p) {
							 file << p->amount;
							 file << "cardName:" + p->cardName + "typeLine:" + p->typeLine + "manaCost:" + p->manaCost + "\n";
						 }
					 }
					 if (spells.size() != 0) {
						 file << "\nSpells\n\n";
						 for (vector<card>::iterator p = spells.begin(); p != spells.end(); ++p) {
							 file << p->amount;
							 file << " " + p->cardName + " " + p->typeLine + " " + p->manaCost + "\n";
						 }
					 }
					 if (artifacts.size() != 0) {
						 file << "\nArtifacts\n\n";
						 for (vector<card>::iterator p = artifacts.begin(); p != artifacts.end(); ++p) {
							 file << p->amount;
							 file << " " + p->cardName + " " + p->typeLine + " " + p->manaCost + "\n";
						 }
					 }
					 if (enchantments.size() != 0) {
						 file << "\nEnchantments\n\n";
						 for (vector<card>::iterator p = enchantments.begin(); p != enchantments.end(); ++p) {
							 file << p->amount;
							 file << " " + p->cardName + " " + p->typeLine + " " + p->manaCost + "\n";
						 }
					 }
					 if (lands.size() != 0) {
						 file << "\nLands\n\n";
						 for (vector<card>::iterator p = spells.begin(); p != spells.end(); ++p) {
							 file << p->amount;
							 file << " " + p->cardName + " " + p->typeLine + "\n";
						 }
					 }
					 file << "end";
					 file.close();
					 MessageBox::Show("Deck saved succesfully", "Deck saved to file");
				 }
			 }


			 void loadDeckList() {
				 Stream^ myStream;
				 OpenFileDialog^ openFileDialog = gcnew OpenFileDialog();
				 openFileDialog->Filter = "txt files (*.txt)|*.txt|All files (*.*)|*.*";
				 openFileDialog->FilterIndex = 2;
				 openFileDialog->RestoreDirectory = true;
				 String^ deckName;
				 String^ filePathS;
				 card card;
				 string line;
				 int pos;



				 if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) { //open file explorer as long as no error occurs
					 if ((myStream = openFileDialog->OpenFile()) != nullptr) {
						 filePathS = openFileDialog->InitialDirectory + openFileDialog->FileName;
						 deckName = openFileDialog->SafeFileName;
						 myStream->Close();
					 }


				 }
				 else {
					 filePathS = "";
				 }

				 msclr::interop::marshal_context context;
				 string filePath = context.marshal_as <string>(filePathS); //converts from system string to standard string

				 //get deck name without file type
				 string sDeckName = context.marshal_as <string>(deckName);
				 pos = sDeckName.find(".txt");
				 sDeckName = sDeckName.substr(0, pos);
				 deckName = gcnew String(sDeckName.c_str());
				 deckNameBox->Text = deckName;

				 ifstream file(filePath);


				 while (getline(file, line)) {
					 if (line == "end") {
						 break;
					 }
					 else {
						 if (line == "Creatures" || line == "") {
							 continue;
						 }
						 else {
							 if (line == "Spells") {
								 break;
							 }
							 else {
								 pos = line.find("cardName:");
								 string amountS = line.substr(0, pos - 9);
								 istringstream iss(amountS);
								 iss >> card.amount;
								 line.erase(0, pos);

								 pos = line.find("typeLine:");
								 card.cardName = line.substr(9, pos - 9);
								 line.erase(0, pos);

								 pos = line.find("manaCost:");
								 card.typeLine = line.substr(9, pos - 9);
								 line.erase(0, pos);

								 pos = line.find(" ");
								 card.manaCost = line.substr(9, pos - 9);
								 line.erase(0, pos);

								 creatures.push_back(card);

							 }
						 }

					 }
				 }
				 file.close();


				 updateDeckList();
				 deckViewer->LoadFile("temp/temp.txt", RichTextBoxStreamType::PlainText); //loads decklist into text box
			 }


	};
}
