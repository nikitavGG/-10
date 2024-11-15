// MyForm.h
#pragma once

namespace ConsoleApplication5 {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class MyForm : public System::Windows::Forms::Form
    {
    public:
        MyForm(void)
        {
            InitializeComponent();
        }

    protected:
        ~MyForm()
        {
            if (components)
            {
                delete components;
            }
        }
    private: System::Windows::Forms::DataGridView^ dataGridView1;
    private: System::Windows::Forms::Button^ generateButton;
    private: System::Windows::Forms::Button^ calculateButton;
    private: System::Windows::Forms::TextBox^ mTextBox;
    private: System::Windows::Forms::TextBox^ cTextBox;
    private: System::Windows::Forms::Label^ mLabel;
    private: System::Windows::Forms::Label^ cLabel;


    private:
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
            this->generateButton = (gcnew System::Windows::Forms::Button());
            this->calculateButton = (gcnew System::Windows::Forms::Button());
            this->mTextBox = (gcnew System::Windows::Forms::TextBox());
            this->cTextBox = (gcnew System::Windows::Forms::TextBox());
            this->mLabel = (gcnew System::Windows::Forms::Label());
            this->cLabel = (gcnew System::Windows::Forms::Label());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
            this->SuspendLayout();
            // 
            // dataGridView1
            // 
            this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dataGridView1->Location = System::Drawing::Point(20, 80);
            this->dataGridView1->Name = L"dataGridView1";
            this->dataGridView1->Size = System::Drawing::Size(431, 223);
            this->dataGridView1->TabIndex = 0;
            // 
            // generateButton
            // 
            this->generateButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->generateButton->Location = System::Drawing::Point(20, 329);
            this->generateButton->Name = L"generateButton";
            this->generateButton->Size = System::Drawing::Size(162, 76);
            this->generateButton->TabIndex = 1;
            this->generateButton->Text = L"Згенерувати";
            this->generateButton->Click += gcnew System::EventHandler(this, &MyForm::GenerateTable);
            // 
            // calculateButton
            // 
            this->calculateButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->calculateButton->Location = System::Drawing::Point(288, 329);
            this->calculateButton->Name = L"calculateButton";
            this->calculateButton->Size = System::Drawing::Size(163, 76);
            this->calculateButton->TabIndex = 2;
            this->calculateButton->Text = L"Розрахувати";
            this->calculateButton->Click += gcnew System::EventHandler(this, &MyForm::CalculateWages);
            // 
            // mTextBox
            // 
            this->mTextBox->Location = System::Drawing::Point(60, 20);
            this->mTextBox->Name = L"mTextBox";
            this->mTextBox->Size = System::Drawing::Size(100, 20);
            this->mTextBox->TabIndex = 3;
            // 
            // cTextBox
            // 
            this->cTextBox->Location = System::Drawing::Point(60, 50);
            this->cTextBox->Name = L"cTextBox";
            this->cTextBox->Size = System::Drawing::Size(100, 20);
            this->cTextBox->TabIndex = 4;
            // 
            // mLabel
            // 
            this->mLabel->Location = System::Drawing::Point(20, 20);
            this->mLabel->Name = L"mLabel";
            this->mLabel->Size = System::Drawing::Size(100, 23);
            this->mLabel->TabIndex = 5;
            this->mLabel->Text = L"M:";
            // 
            // cLabel
            // 
            this->cLabel->Location = System::Drawing::Point(20, 53);
            this->cLabel->Name = L"cLabel";
            this->cLabel->Size = System::Drawing::Size(100, 23);
            this->cLabel->TabIndex = 6;
            this->cLabel->Text = L"C:";
            // 
            // MyForm
            // 
            this->ClientSize = System::Drawing::Size(889, 508);
            this->Controls->Add(this->dataGridView1);
            this->Controls->Add(this->generateButton);
            this->Controls->Add(this->calculateButton);
            this->Controls->Add(this->mTextBox);
            this->Controls->Add(this->cTextBox);
            this->Controls->Add(this->mLabel);
            this->Controls->Add(this->cLabel);
            this->Name = L"MyForm";
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion

    private: System::Void GenerateTable(System::Object^ sender, System::EventArgs^ e) {
        int M = Convert::ToInt32(mTextBox->Text);
        dataGridView1->ColumnCount = 4;
        dataGridView1->Columns[0]->Name = "Табельний номер";
        dataGridView1->Columns[1]->Name = "Вага вантажу";
        dataGridView1->Columns[2]->Name = "Відстань";
        dataGridView1->Columns[3]->Name = "Сума заробітна плата";

        dataGridView1->Rows->Clear();

        for (int i = 0; i < M; i++) {
            dataGridView1->Rows->Add();
            dataGridView1->Rows[i]->Cells[0]->Value = i + 1;  // Табельний номер
            dataGridView1->Rows[i]->Cells[1]->Value = 0;  // Вага вантажу
            dataGridView1->Rows[i]->Cells[2]->Value = 0;  // Відстань
            dataGridView1->Rows[i]->Cells[3]->Value = 0;  // Зарплата
        }
    }

    private: System::Void CalculateWages(System::Object^ sender, System::EventArgs^ e) {
        double C = Convert::ToDouble(cTextBox->Text);
        for (int i = 0; i < dataGridView1->RowCount - 1; i++) {
            double P = Convert::ToDouble(dataGridView1->Rows[i]->Cells[1]->Value);
            double D = Convert::ToDouble(dataGridView1->Rows[i]->Cells[2]->Value);
            double wage = P * D * C;
            dataGridView1->Rows[i]->Cells[3]->Value = wage;
        }
    }
};
}
