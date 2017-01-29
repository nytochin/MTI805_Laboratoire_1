#pragma once

#include "opencv/highgui.h"
#include "opencv2/opencv.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/objdetect/objdetect.hpp"

#include <sstream>
#include <iostream>

using namespace cv;
using namespace std;

VideoCapture videoCapture;
Rect selection, trackWindow;
Mat frame, hsv, hue, mask, prob, hist, histimg = Mat::zeros(200, 320, CV_8UC3), backproj;
int vmin = 10, vmax = 256, smin = 30;

namespace Lab1 {

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
			//
			//TODO: Add the constructor code here
			//
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

	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::ComponentModel::IContainer^  components;
	protected:

	private:
		/// <summary>
		bool detectingLines = false;
		bool detectingCircles = false;	
		bool detectingFaces = false;
		bool blurActivatedLines = false;
		bool blurActivatedCircles = false;
		bool trackingActivated = false;
		bool trackingFaceFound = false;
		

	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::TrackBar^  trackBar1;
	private: System::Windows::Forms::TrackBar^  trackBar2;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::PictureBox^  pictureBox3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TrackBar^  trackBar4;
	private: System::Windows::Forms::TrackBar^  trackBar3;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::PictureBox^  pictureBox4;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::TextBox^  textBox6;
	private: System::Windows::Forms::TrackBar^  trackBar5;
	private: System::Windows::Forms::TrackBar^  trackBar6;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label9;

	private: System::Windows::Forms::TrackBar^  trackBar7;
	private: System::Windows::Forms::TrackBar^  trackBar8;
	private: System::Windows::Forms::TextBox^  textBox7;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::TextBox^  textBox8;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::PictureBox^  pictureBox5;
	private: System::Windows::Forms::PictureBox^  pictureBox6;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::TextBox^  textBox9;
	private: System::Windows::Forms::TrackBar^  trackBar9;
	private: System::Windows::Forms::PictureBox^  pictureBox7;
	private: System::Windows::Forms::ColorDialog^  colorDialog1;
			 
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			this->trackBar2 = (gcnew System::Windows::Forms::TrackBar());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->trackBar4 = (gcnew System::Windows::Forms::TrackBar());
			this->trackBar3 = (gcnew System::Windows::Forms::TrackBar());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->trackBar5 = (gcnew System::Windows::Forms::TrackBar());
			this->trackBar6 = (gcnew System::Windows::Forms::TrackBar());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->trackBar7 = (gcnew System::Windows::Forms::TrackBar());
			this->trackBar8 = (gcnew System::Windows::Forms::TrackBar());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->colorDialog1 = (gcnew System::Windows::Forms::ColorDialog());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox6 = (gcnew System::Windows::Forms::PictureBox());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->trackBar9 = (gcnew System::Windows::Forms::TrackBar());
			this->pictureBox7 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar8))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar9))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Calibri", 13));
			this->button1->Location = System::Drawing::Point(20, 32);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 31);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Start";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(224, 75);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 31);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Lines";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(236, 379);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 31);
			this->button3->TabIndex = 3;
			this->button3->Text = L"Circles";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(278, 686);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 31);
			this->button4->TabIndex = 4;
			this->button4->Text = L"Faces";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// pictureBox2
			// 
			this->pictureBox2->Location = System::Drawing::Point(20, 117);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(320, 240);
			this->pictureBox2->TabIndex = 5;
			this->pictureBox2->TabStop = false;
			// 
			// trackBar1
			// 
			this->trackBar1->Location = System::Drawing::Point(613, 18);
			this->trackBar1->Maximum = 100;
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Size = System::Drawing::Size(256, 45);
			this->trackBar1->TabIndex = 6;
			this->trackBar1->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar1_Scroll);
			// 
			// trackBar2
			// 
			this->trackBar2->Location = System::Drawing::Point(613, 69);
			this->trackBar2->Maximum = 300;
			this->trackBar2->Name = L"trackBar2";
			this->trackBar2->Size = System::Drawing::Size(256, 45);
			this->trackBar2->TabIndex = 7;
			this->trackBar2->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar2_Scroll);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(549, 18);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(58, 31);
			this->textBox1->TabIndex = 8;
			this->textBox1->Text = L"0";
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(549, 69);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(58, 31);
			this->textBox2->TabIndex = 9;
			this->textBox2->Text = L"0";
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox2_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(16, 79);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(202, 23);
			this->label1->TabIndex = 10;
			this->label1->Text = L"Hough Transform (Lines)";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(20, 117);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(75, 31);
			this->button5->TabIndex = 11;
			this->button5->Text = L"Blur";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// pictureBox3
			// 
			this->pictureBox3->Location = System::Drawing::Point(20, 421);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(320, 240);
			this->pictureBox3->TabIndex = 12;
			this->pictureBox3->TabStop = false;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(16, 383);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(214, 23);
			this->label2->TabIndex = 13;
			this->label2->Text = L"Hough Transform (Circles)";
			// 
			// trackBar4
			// 
			this->trackBar4->Location = System::Drawing::Point(897, 461);
			this->trackBar4->Maximum = 300;
			this->trackBar4->Minimum = 1;
			this->trackBar4->Name = L"trackBar4";
			this->trackBar4->Size = System::Drawing::Size(256, 45);
			this->trackBar4->TabIndex = 14;
			this->trackBar4->Value = 1;
			this->trackBar4->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar4_Scroll);
			// 
			// trackBar3
			// 
			this->trackBar3->Location = System::Drawing::Point(897, 420);
			this->trackBar3->Maximum = 300;
			this->trackBar3->Minimum = 1;
			this->trackBar3->Name = L"trackBar3";
			this->trackBar3->Size = System::Drawing::Size(256, 45);
			this->trackBar3->TabIndex = 15;
			this->trackBar3->Value = 1;
			this->trackBar3->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar3_Scroll);
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(833, 462);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(58, 31);
			this->textBox4->TabIndex = 16;
			this->textBox4->Text = L"1";
			this->textBox4->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox4_TextChanged);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(833, 420);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(58, 31);
			this->textBox3->TabIndex = 17;
			this->textBox3->Text = L"1";
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox3_TextChanged);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(20, 421);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(75, 31);
			this->button6->TabIndex = 18;
			this->button6->Text = L"Blur";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// pictureBox4
			// 
			this->pictureBox4->Location = System::Drawing::Point(20, 728);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(320, 240);
			this->pictureBox4->TabIndex = 19;
			this->pictureBox4->TabStop = false;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(16, 690);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(256, 23);
			this->label3->TabIndex = 20;
			this->label3->Text = L"Haar-cascade Detection (Faces)";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(368, 21);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(175, 23);
			this->label4->TabIndex = 21;
			this->label4->Text = L"Low Threshold Canny";
			this->label4->Click += gcnew System::EventHandler(this, &MyForm::label4_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(365, 72);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(178, 23);
			this->label5->TabIndex = 22;
			this->label5->Text = L"High Threshold Canny";
			this->label5->Click += gcnew System::EventHandler(this, &MyForm::label5_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(797, 512);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(30, 23);
			this->label6->TabIndex = 23;
			this->label6->Text = L"dp";
			this->label6->Click += gcnew System::EventHandler(this, &MyForm::label6_Click);
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(833, 504);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(58, 31);
			this->textBox5->TabIndex = 24;
			this->textBox5->Text = L"1";
			this->textBox5->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox5_TextChanged);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(758, 554);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(69, 23);
			this->label7->TabIndex = 25;
			this->label7->Text = L"minDist";
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(833, 546);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(58, 31);
			this->textBox6->TabIndex = 26;
			this->textBox6->Text = L"1";
			this->textBox6->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox6_TextChanged);
			// 
			// trackBar5
			// 
			this->trackBar5->Location = System::Drawing::Point(897, 504);
			this->trackBar5->Name = L"trackBar5";
			this->trackBar5->Size = System::Drawing::Size(256, 45);
			this->trackBar5->TabIndex = 27;
			this->trackBar5->Value = 1;
			this->trackBar5->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar5_Scroll);
			// 
			// trackBar6
			// 
			this->trackBar6->Location = System::Drawing::Point(897, 546);
			this->trackBar6->Maximum = 300;
			this->trackBar6->Minimum = 1;
			this->trackBar6->Name = L"trackBar6";
			this->trackBar6->Size = System::Drawing::Size(256, 45);
			this->trackBar6->TabIndex = 28;
			this->trackBar6->Value = 1;
			this->trackBar6->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar6_Scroll);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(698, 465);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(123, 23);
			this->label8->TabIndex = 30;
			this->label8->Text = L"Acc. Threshold";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(701, 428);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(83, 23);
			this->label9->TabIndex = 29;
			this->label9->Text = L"HT Canny";
			// 
			// trackBar7
			// 
			this->trackBar7->Location = System::Drawing::Point(897, 631);
			this->trackBar7->Maximum = 300;
			this->trackBar7->Minimum = 1;
			this->trackBar7->Name = L"trackBar7";
			this->trackBar7->Size = System::Drawing::Size(256, 45);
			this->trackBar7->TabIndex = 37;
			this->trackBar7->Value = 1;
			this->trackBar7->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar7_Scroll);
			// 
			// trackBar8
			// 
			this->trackBar8->Location = System::Drawing::Point(897, 589);
			this->trackBar8->Name = L"trackBar8";
			this->trackBar8->Size = System::Drawing::Size(256, 45);
			this->trackBar8->TabIndex = 36;
			this->trackBar8->Value = 1;
			this->trackBar8->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar8_Scroll);
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(833, 631);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(58, 31);
			this->textBox7->TabIndex = 35;
			this->textBox7->Text = L"1";
			this->textBox7->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox7_TextChanged);
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(731, 637);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(93, 23);
			this->label10->TabIndex = 34;
			this->label10->Text = L"maxRadius";
			// 
			// textBox8
			// 
			this->textBox8->Location = System::Drawing::Point(833, 589);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(58, 31);
			this->textBox8->TabIndex = 33;
			this->textBox8->Text = L"1";
			this->textBox8->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox8_TextChanged);
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(737, 599);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(90, 23);
			this->label11->TabIndex = 32;
			this->label11->Text = L"minRadius";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(393, 728);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(320, 240);
			this->pictureBox1->TabIndex = 38;
			this->pictureBox1->TabStop = false;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label12->Location = System::Drawing::Point(389, 690);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(205, 23);
			this->label12->TabIndex = 40;
			this->label12->Text = L"CAMShift (Face Tracking)";
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(651, 686);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(75, 31);
			this->button7->TabIndex = 39;
			this->button7->Text = L"Faces";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm::button7_Click);
			// 
			// pictureBox5
			// 
			this->pictureBox5->Location = System::Drawing::Point(697, 117);
			this->pictureBox5->Name = L"pictureBox5";
			this->pictureBox5->Size = System::Drawing::Size(320, 240);
			this->pictureBox5->TabIndex = 41;
			this->pictureBox5->TabStop = false;
			// 
			// pictureBox6
			// 
			this->pictureBox6->Location = System::Drawing::Point(357, 117);
			this->pictureBox6->Name = L"pictureBox6";
			this->pictureBox6->Size = System::Drawing::Size(320, 240);
			this->pictureBox6->TabIndex = 42;
			this->pictureBox6->TabStop = false;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(878, 21);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(167, 23);
			this->label13->TabIndex = 45;
			this->label13->Text = L"Kernel Size Gaussian";
			// 
			// textBox9
			// 
			this->textBox9->Location = System::Drawing::Point(1059, 18);
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(58, 31);
			this->textBox9->TabIndex = 44;
			this->textBox9->Text = L"0";
			this->textBox9->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox9_TextChanged);
			// 
			// trackBar9
			// 
			this->trackBar9->Location = System::Drawing::Point(1123, 18);
			this->trackBar9->Minimum = 1;
			this->trackBar9->Name = L"trackBar9";
			this->trackBar9->Size = System::Drawing::Size(107, 45);
			this->trackBar9->TabIndex = 43;
			this->trackBar9->Value = 1;
			this->trackBar9->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar9_Scroll);
			// 
			// pictureBox7
			// 
			this->pictureBox7->Location = System::Drawing::Point(357, 421);
			this->pictureBox7->Name = L"pictureBox7";
			this->pictureBox7->Size = System::Drawing::Size(320, 240);
			this->pictureBox7->TabIndex = 46;
			this->pictureBox7->TabStop = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 23);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->BackColor = System::Drawing::SystemColors::InactiveBorder;
			this->ClientSize = System::Drawing::Size(1391, 999);
			this->Controls->Add(this->pictureBox7);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->textBox9);
			this->Controls->Add(this->trackBar9);
			this->Controls->Add(this->pictureBox6);
			this->Controls->Add(this->pictureBox5);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->trackBar7);
			this->Controls->Add(this->trackBar8);
			this->Controls->Add(this->textBox7);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->textBox8);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->trackBar6);
			this->Controls->Add(this->trackBar5);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->pictureBox4);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->trackBar3);
			this->Controls->Add(this->trackBar4);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->trackBar2);
			this->Controls->Add(this->trackBar1);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Location = System::Drawing::Point(10, 25);
			this->Margin = System::Windows::Forms::Padding(5, 6, 5, 6);
			this->Name = L"MyForm";
			this->Text = L"Laboratory 1";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar8))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar9))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	void DrawCVImageColor(System::Windows::Forms::Control^ control, cv::Mat& colorImage)
	{
		System::Drawing::Graphics^ graphics = control->CreateGraphics();
		System::IntPtr ptr(colorImage.ptr());
		System::Drawing::Bitmap^ b = gcnew System::Drawing::Bitmap(colorImage.cols, colorImage.rows, colorImage.step, System::Drawing::Imaging::PixelFormat::Format24bppRgb, ptr);
		System::Drawing::RectangleF rect(0, 0, control->Width, control->Height);
		graphics->DrawImage(b, rect);
		delete graphics;
	}
	void DrawCVImageGray(System::Windows::Forms::Control^ control, cv::Mat& grayImage)
	{
		System::Drawing::Graphics^ graphics = control->CreateGraphics();
		System::IntPtr ptr(grayImage.ptr());
		System::Drawing::Bitmap^ b = gcnew System::Drawing::Bitmap(grayImage.cols, grayImage.rows, grayImage.step, System::Drawing::Imaging::PixelFormat::Format8bppIndexed, ptr);
		System::Drawing::RectangleF rect(0, 0, control->Width, control->Height);
		graphics->DrawImage(b, rect);
		delete graphics;
	}

	void detectLines(cv::Mat& frame) {
		Mat grayFrame;
		Mat blurredFrame;
		Mat edges;
		int lowThreshold = trackBar1->Value;
		int highThreshold = trackBar2->Value;
		int kernelSizeGaussian = trackBar9->Value;
		int kernelSizeCanny = 3;
		vector<Vec2f> lines;

		if (blurActivatedLines) {
			blur(frame, blurredFrame, cv::Size(kernelSizeGaussian, kernelSizeGaussian));
			DrawCVImageColor(pictureBox6, blurredFrame);
			cvtColor(blurredFrame, grayFrame, COLOR_BGR2GRAY); // Changing colorspace : from RGB to GRAY
		}
		else {
			DrawCVImageColor(pictureBox6, frame);
			cvtColor(frame, grayFrame, COLOR_BGR2GRAY); // Changing colorspace : from RGB to GRAY

		}	
			
		Canny(grayFrame, edges, lowThreshold, highThreshold, kernelSizeCanny); // Detecting the edges
		DrawCVImageGray(pictureBox5, edges);

		HoughLines(edges, lines, 1, CV_PI / 180, 100, 0, 0);

		for (size_t i = 0; i < lines.size(); i++) {
			float rho = lines[i][0]; // First point
			float theta = lines[i][1]; // Second point
			cv::Point pt1, pt2;
			double a = cos(theta), b = sin(theta);
			double x0 = a*rho, y0 = b*rho;

			pt1.x = cvRound(x0 + 1000 * (-b));
			pt1.y = cvRound(y0 + 1000 * (a));
			pt2.x = cvRound(x0 - 1000 * (-b));
			pt2.y = cvRound(y0 - 1000 * (a));

			line(frame, pt1, pt2, Scalar(0, 0, 255), 2, 8);
		}
		DrawCVImageColor(pictureBox2, frame);
	}
	void detectCircles(cv::Mat& frame) {
		Mat grayFrame;
		Mat blurredFrame;
		int highThresholdCanny = trackBar3->Value;
		int accumulatorThreshold = trackBar4->Value;
		double dp = trackBar5->Value;
		double minDist = trackBar6->Value;
		int minRadius = trackBar8->Value;
		int maxRadius = trackBar7->Value;

		vector<Vec3f> circles;

		/*

		void HoughCircles(InputArray image, OutputArray circles, int method, double dp, double minDist, double param1 = 100, double param2 = 100, int minRadius = 0, int maxRadius = 0)

		Parameters:
		image – 8 - bit, single - channel, grayscale input image.
		circles – Output vector of found circles.Each vector is encoded as a 3 - element floating - point vector(x, y, radius) .
		method – Detection method to use. Currently, the only implemented method is CV_HOUGH_GRADIENT, which is basically 21HT, described in[Yuen90].
		dp – Inverse ratio of the accumulator resolution to the image resolution. For example, if dp = 1, the accumulator has the same resolution as the input image. If dp = 2, the accumulator has half as big width and height.
		minDist – Minimum distance between the centers of the detected circles. If the parameter is too small, multiple neighbor circles may be falsely detected in addition to a true one.If it is too large, some circles may be missed.
		param1 – First method - specific parameter.In case of CV_HOUGH_GRADIENT, it is the higher threshold of the two passed to the Canny() edge detector(the lower one is twice smaller).
		param2 – Second method - specific parameter.In case of CV_HOUGH_GRADIENT, it is the accumulator threshold for the circle centers at the detection stage.The smaller it is, the more false circles may be detected.Circles, corresponding to the larger accumulator values, will be returned first.
		minRadius – Minimum circle radius.
		maxRadius – Maximum circle radius.

		*/

		cvtColor(frame, grayFrame, COLOR_BGR2GRAY); // Changing colorspace : from RGB to GRAY
		
		if (blurActivatedCircles) {
			blur(grayFrame, blurredFrame, cv::Size(5, 5));
			HoughCircles(blurredFrame, circles, CV_HOUGH_GRADIENT, dp, minDist, highThresholdCanny, accumulatorThreshold, minRadius, maxRadius);
		}
		else {
			HoughCircles(grayFrame, circles, CV_HOUGH_GRADIENT, dp, minDist, highThresholdCanny, accumulatorThreshold, minRadius, maxRadius);
		}

		for (size_t i = 0; i < circles.size(); i++) {
			cv::Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
			int radius = cvRound(circles[i][2]);
			circle(frame, center, 3, Scalar(0, 255, 0), -1, 8, 0);
			circle(frame, center, radius, Scalar(0, 0, 255), 3, 8, 0);
		}
		DrawCVImageColor(pictureBox3, frame);
	}

	void detectFaces(cv::Mat& frame, CascadeClassifier cc) {
		Mat grayFrame;
		cvtColor(frame, grayFrame, COLOR_RGB2GRAY);
		float scaleFactor = 1.3;
		int minNeighbors = 5;
		vector<Rect> faces;
		int detectionsNum = 0;
		Rect* faceRects;

		cc.detectMultiScale(grayFrame, faces, scaleFactor, minNeighbors);
		for (size_t i = 0; i < faces.size(); i++) {
			rectangle(frame, faces[i], Scalar(255, 0, 0), 2);
		}
		DrawCVImageColor(pictureBox4, frame);
	}

	void update_hue_image(cv::Mat& frame, Rect& selection) {
		int vmin = 65, vmax = 256, smin = 55;

		//convert to HSV color model
		cvtColor(frame, hsv, CV_BGR2HSV);

		//mask out-of-range values
		inRange(hsv,                               //source
			Scalar(0, smin, MIN(vmin, vmax), 0),  //lower bound
			Scalar(180, 256, MAX(vmin, vmax), 0), //upper bound
			mask);                             //destination

											   //extract the hue channel, split: src, dest channels
											   //create a histogram representation for the face
		int ch[] = { 0, 0 };
		mixChannels(&hsv, 1, &hue, 1, ch, 1);
	}

	void trackFaces(cv::Mat& frame, CascadeClassifier cc) {
		Mat grayFrame, hsvFrame;	
		float scaleFactor = 1.3;
		int minNeighbors = 5;
		vector<Rect> faces;
		Rect* faceRects;

		int hsize = 16;
		float hranges[] = { 0,180 };
		const float* phranges = hranges;

		if (!trackingFaceFound) {
			cvtColor(frame, grayFrame, COLOR_RGB2GRAY);
			cc.detectMultiScale(grayFrame, faces, scaleFactor, minNeighbors);
			if (faces.size() > 0) {
				trackingFaceFound = true;
				selection = faces[0];
				rectangle(frame, selection, Scalar(255, 0, 0), 2);
				cvtColor(frame, hsv, COLOR_BGR2HSV);
				
				// Object has been selected by user, set up CAMShift search properties once
				int channels[] = { 0 };

				hsv = Mat(frame.rows, frame.cols, CV_8UC3);
				mask = Mat(frame.rows, frame.cols, CV_8U);
				hue = Mat(frame.rows, frame.cols, CV_8U);
				prob = Mat(frame.rows, frame.cols, CV_8U);
												
				update_hue_image(frame, selection);
			
				Mat roi(hue, selection), maskroi(mask, selection);

				calcHist(&roi, 1, channels, maskroi, hist, 1, &hsize, &phranges);
				normalize(hist, hist, 0, 255, CV_MINMAX);

				trackWindow = selection;

				histimg = Scalar::all(0);
				int binW = histimg.cols / hsize;
				Mat buf(1, hsize, CV_8UC3);
				for (int i = 0; i < hsize; i++)
					buf.at<Vec3b>(i) = Vec3b(saturate_cast<uchar>(i*180. / hsize), 255, 255);
				cvtColor(buf, buf, COLOR_HSV2BGR);

				for (int i = 0; i < hsize; i++)
				{
					int val = saturate_cast<int>(hist.at<float>(i)*histimg.rows / 255);
					rectangle(histimg, cv::Point(i*binW, histimg.rows),
						cv::Point((i + 1)*binW, histimg.rows - val),
						Scalar(buf.at<Vec3b>(i)), -1, 8);
				}
			}
		}
		else {
			// Perform CAMShift
			update_hue_image(frame, trackWindow);

			int channels[] = { 0 };
			cvtColor(frame, hsv, COLOR_BGR2HSV);
			calcBackProject(&hue, 1, channels, hist, backproj, &phranges);
			backproj &= mask;
			RotatedRect trackBox = CamShift(backproj, trackWindow,
				TermCriteria(CV_TERMCRIT_EPS | CV_TERMCRIT_ITER, 10, 1));
			imwrite("test.jpg", Mat(frame, trackWindow));
			
			if (trackWindow.area() <= 1)
			{
				trackingFaceFound = false;
			}
			/*cv::Point p1, p2;
			p1.x = trackBox.center.x - trackBox.size.height / 2;
			p1.y = trackBox.center.y - trackBox.size.width / 2;
			p2.x = trackBox.center.x + trackBox.size.height / 2;
			p2.y = trackBox.center.y + trackBox.size.width / 2;
			rectangle(frame, p1, p2, CV_RGB(255, 0, 0), 3, CV_AA, 0);*/
			ellipse(frame, trackBox, Scalar(0, 0, 255), 3, LINE_AA);		
		}		
		DrawCVImageColor(pictureBox1, frame);
	}

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		if (button1->Text->Equals("Start")) {
			button1->Text = "Stop";
			videoCapture = VideoCapture(0);		
			timer1->Start();
		}
		else {
			button1->Text = "Start";
			timer1->Stop();
		}		
	}
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		CascadeClassifier face_cascade;
		string face_cascade_location = "haarcascade_frontalface_default.xml";
		if (!face_cascade.load(face_cascade_location)) {
			printf("--(!)Error loading\n");
		}
		Mat frame, frameLines, frameCircles, frameFaces, frameTrack;


		if (detectingLines) {
			videoCapture.read(frameLines);
			detectLines(frameLines);
		}
		if (detectingCircles) {
			videoCapture.read(frameCircles);
			/* Initialization of trackbar max value */
			textBox6->Text = System::Convert::ToString(frameCircles.rows / 8);
			trackBar7->Maximum = min(frameCircles.rows, frameCircles.cols) / 2;
			trackBar8->Maximum = min(frameCircles.rows, frameCircles.cols) / 2;

			detectCircles(frameCircles);
		}
		if (detectingFaces) {
			videoCapture.read(frameFaces);
			detectFaces(frameFaces, face_cascade);
		}
		if (trackingActivated) {
			videoCapture.read(frameTrack);
			trackFaces(frameTrack, face_cascade);
		}
	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		if (timer1->Enabled) {
			if (button2->Text->Equals("Lines")/* && !detectingCircles && !detectingFaces*/) {
				detectingLines = true;
				button2->Text = "Stop";
			}
			else {
				detectingLines = false;
				button2->Text = "Lines";
			}
		}
	}

private: System::Void trackBar1_Scroll(System::Object^  sender, System::EventArgs^  e) {
	System::String^ text = trackBar1->Value.ToString();
	textBox1->Text = text;
}
private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	 
	int value = int::Parse(textBox1->Text);
	trackBar1->Value = value;
}
private: System::Void textBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	int value = int::Parse(textBox2->Text);
	trackBar2->Value = value;
}
private: System::Void trackBar2_Scroll(System::Object^  sender, System::EventArgs^  e) {
	System::String^ text = trackBar2->Value.ToString();
	textBox2->Text = text;
}
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
	if (!blurActivatedLines) {
		button5->Text = "Unblur";
		blurActivatedLines = true;
	}
	else {
		button5->Text = "Blur";
		blurActivatedLines = false;
	}
}
private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	if (timer1->Enabled) {
		if (button3->Text->Equals("Circles")/* && !detectingLines && !detectingFaces*/) {
			detectingCircles = true;
			button3->Text = "Stop";
		}
		else {
			detectingCircles = false;
			button3->Text = "Circles";
		}
	}
}
private: System::Void trackBar4_Scroll(System::Object^  sender, System::EventArgs^  e) {
	System::String^ text = trackBar4->Value.ToString();
	textBox4->Text = text;
}
private: System::Void trackBar3_Scroll(System::Object^  sender, System::EventArgs^  e) {
	System::String^ text = trackBar3->Value.ToString();
	textBox3->Text = text;
}
private: System::Void textBox4_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	int value = int::Parse(textBox4->Text);
	trackBar4->Value = value;
}
private: System::Void textBox3_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	int value = int::Parse(textBox3->Text);
	trackBar3->Value = value;
}

private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
	if (timer1->Enabled) {
		if (button4->Text->Equals("Faces")/* && !detectingLines && !detectingFaces*/) {
			detectingFaces = true;
			button4->Text = "Stop";
		}
		else {
			detectingFaces = false;
			button4->Text = "Faces";
		}
	}
}
private: System::Void label4_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label6_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void trackBar5_Scroll(System::Object^  sender, System::EventArgs^  e) {
	System::String^ text = trackBar5->Value.ToString();
	textBox5->Text = text;
}
private: System::Void trackBar6_Scroll(System::Object^  sender, System::EventArgs^  e) {
	System::String^ text = trackBar6->Value.ToString();
	textBox6->Text = text;
}
private: System::Void textBox5_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	int value = int::Parse(textBox5->Text);
	trackBar5->Value = value;
}
private: System::Void textBox6_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	int value = int::Parse(textBox6->Text);
	trackBar6->Value = value;
}
private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
	if (!blurActivatedCircles) {
		button6->Text = "Unblur";
		blurActivatedCircles = true;
	}
	else {
		button6->Text = "Blur";
		blurActivatedCircles = false;
	}
}
private: System::Void trackBar8_Scroll(System::Object^  sender, System::EventArgs^  e) {
	System::String^ text = trackBar8->Value.ToString();
	textBox8->Text = text;
}
private: System::Void trackBar7_Scroll(System::Object^  sender, System::EventArgs^  e) {
	System::String^ text = trackBar7->Value.ToString();
	textBox7->Text = text;
}
private: System::Void textBox8_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	int value = int::Parse(textBox8->Text);
	trackBar8->Value = value;
}
private: System::Void textBox7_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	int value = int::Parse(textBox7->Text);
	trackBar7->Value = value;
}
private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) {
	if (timer1->Enabled) {
		if (button7->Text->Equals("Faces")/* && !detectingLines && !detectingFaces*/) {
			trackingActivated = true;
			button7->Text = "Stop";
		}
		else {
			trackingActivated = false;
			button7->Text = "Faces";
		}
	}
}
private: System::Void label5_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void trackBar9_Scroll(System::Object^  sender, System::EventArgs^  e) {
	System::String^ text = trackBar9->Value.ToString();
	textBox9->Text = text;
}
private: System::Void textBox9_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	int value = int::Parse(textBox9->Text);
	trackBar9->Value = value;
}
};

}
