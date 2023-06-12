#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdexcept>
#include <vector>
#include <msclr/marshal_cppstd.h>
#include "Flight.h"

namespace Flights {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::ListBox^ listBox1;
	private: System::Windows::Forms::Button^ button1;


	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(23, 20);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(217, 17);
			this->label1->TabIndex = 0;
			this->label1->Text = L"File with information about flights:";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(26, 51);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(214, 22);
			this->textBox1->TabIndex = 1;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(26, 108);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(186, 17);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Target date (DD.MM.YYYY):";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(29, 138);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(157, 22);
			this->textBox2->TabIndex = 3;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(26, 174);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(127, 17);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Target destination:";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(29, 204);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(157, 22);
			this->textBox3->TabIndex = 5;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(29, 352);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(93, 17);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Found flights:";
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 16;
			this->listBox1->Location = System::Drawing::Point(29, 382);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(120, 84);
			this->listBox1->TabIndex = 8;
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(26, 257);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(96, 40);
			this->button1->TabIndex = 9;
			this->button1->Text = L"FIND";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(591, 516);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}

	private:
		/// <summary>
		/// Event handler for the button click event.
		/// </summary>
		System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
			std::string filePath = msclr::interop::marshal_as<std::string>(textBox1->Text);
			std::ifstream file(filePath); 
			try
			{
				if (!file.is_open()) {
					throw "Failed to open the file";
				}
			}
			catch (...) {
				MessageBox::Show("Failed to open the file!", "ERROR!");
			}
			file.close();

			try
			{
				if (textBox2->Text == "") {
					throw "Empty line!";
				}
				if (textBox3->Text == "") {
					throw "Empty line!";
				}
			}
			catch (...) {
				MessageBox::Show("Fill all information!", "ERROR!");
			}
			std::string targetDate = msclr::interop::marshal_as<std::string>(textBox2->Text);
			std::string targetDestination = msclr::interop::marshal_as<std::string>(textBox3->Text);

			// Get the flight numbers from processFlightsData
			std::vector<std::string> foundFlightNumbers = processFlightsData(filePath, targetDate, targetDestination);

			// Clear the existing items in listBox1
			listBox1->Items->Clear();

			// Add the found flight numbers to listBox1
			for (const std::string& flightNumber : foundFlightNumbers) {
				listBox1->Items->Add(gcnew String(flightNumber.c_str()));
			}
		}


	
	};
}
