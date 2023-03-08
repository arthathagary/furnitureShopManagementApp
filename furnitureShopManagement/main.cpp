#include <iostream>
#include <fstream>
#include<string>
#include <cstring>
#include <vector>
using namespace std;

void admin();
void companyDetails();
void manageFurniture();
void addFurniture();
void modifyFurniture();
void file();
void showFurniture();
void soldDetails();
void addSoldDetails();
void showSoldDetails();

struct Furniture {
    char skuNo[20];
    int quantity, noOfFunitures;
    char name[50];
    float percost, persell;
};
Furniture furniture;




int main() {
    int Choice1;
    while (1) {
        cout << "\n\t\t================================\n\t\t      ***SUPRIME FURNITURE***\n\t    \t================================\n" << endl << "1) Login" << endl << "2) Exit" << endl << "Enter Your Choice: ";
        cin >> Choice1;
        switch (Choice1) {
        case 1:
            cout << "" << endl;
            admin();
            break;
        case 2:
            exit(0);
        default:
            cout << "Enter Valid Choice";
            break;
        }
    }


    return 0;
}


void admin() {
    while (1) {
        cout << "\n\t\t================================\n\t\t\t   Main Menu\n\t    \t================================\n\n";
        cout << "1) View Furniture Details" << endl << "2) Manage Furnitures" << endl << "3) Show Sales Details" << endl << "4) Company Details" << endl << "5) Exit" << endl << "Enter Your Choice: ";

        int Choice2;
        cin >> Choice2;

        if (Choice2 == 1) {
            showFurniture();
        }
        else if (Choice2 == 2) {
            manageFurniture();
        }
        else if (Choice2 == 3) {
            soldDetails();
        }
        else if (Choice2 == 4) {
            companyDetails();
        }
        else if (Choice2 == 5) {
            exit(0);
        }
        else {
            cout << "Enter Valid Choice";
        }
    }
}


void companyDetails() {
    cout << "\n\t\t================================\n\t\t\tCompany Details\n\t    \t================================\n\n";
    cout << endl << "Company Name: Suprime Furniture" << endl << endl;
}


void manageFurniture() {

    while (1) {
        cout << "\n\t\t================================\n\t\t     Manage Furniture Details\n\t    \t================================\n\n";
        cout << "1) Add Furnitures" << endl << "2) Modify Furnitures" << endl << "3) Main Menu" << endl << "4) Exit" << endl << "Enter Your Choice: ";
        int Choice3;
        cin >> Choice3;
        if (Choice3 == 1) {
            addFurniture();
        }
        else if (Choice3 == 2) {
            modifyFurniture();
        }
        else if (Choice3 == 3) {
            admin();
        }
        else if (Choice3 == 4) {
            exit(0);
        }
        else {
            cout << "Enter Valid Choice";
        }
    }
}

void addFurniture() {
    cout << "\n\t\t================================\n\t\t      Add Furniture Details\n\t    \t================================\n\n";
    cout << "How Many Furniture You Want To Add? ";
    cin >> furniture.noOfFunitures;

    for (int start = 0; start < furniture.noOfFunitures; start++) {
        cout << "\ninput SKU Number: \n";
        cin >> furniture.skuNo;


        cout << "\ninput furniture name: \n";
        cin >> furniture.name;
        cout << "\ninput quantity: \n";
        cin >> furniture.quantity;
        cout << "\ninput cost price of furniture: \n";
        cin >> furniture.percost;
        cout << "\ninput selling price of furniture: \n";
        cin >> furniture.persell;
        file();

    }

}


void file() {
    char file[20];
    strcpy(file, furniture.name);
    strcat(file, ".txt");
    ofstream FurnitureFile(file);
    FurnitureFile << "Furniture SKU Number:" << endl << furniture.skuNo << endl << endl << "Name: " << endl << furniture.name << endl << endl << "Quantity: " << endl << furniture.quantity << endl << endl << "Cost Price: " << endl << furniture.percost << endl << endl << "Sell Price: " << endl << furniture.persell;
    FurnitureFile.close();
}



void modifyFurniture() {
    cout << "\n\t\t================================\n\t\t    Modify Furniture Details\n\t    \t================================\n\n";
    cout << "\nInput Furniture Name to modify\n";
    cin >> furniture.name;
    char file[20];
    strcpy(file, furniture.name);
    strcat(file, ".txt");
    fstream fout(file, ios::in | ios::out);
    if (!fout)
    {
        cout << "file couldn't be opened. Furniture Name not found. \n";
    }
    else {
        cout << "file found! \n";
        cout << "\nupdate product name: \n";
        cin >> furniture.name;
        cout << "\nupdate total product quantity: \n";
        cin >> furniture.quantity;
        cout << "\nupdate percost of product: \n";
        cin >> furniture.percost;
        cout << "\nupdate persell of product: \n";
        cin >> furniture.persell;

        fout << "Furniture SKU Number:" <<endl<<furniture.skuNo<< endl<<endl<< "Name: " << endl<< furniture.name << endl <<endl<< "Quantity: " <<endl<< furniture.quantity << endl<<endl << "Cost Price: " <<endl<< furniture.percost << endl<<endl << "Sell Price: " <<endl<< furniture.persell;
        fout.close();
    }
    //     if (remove(file) != 0) {
    //     // print error message
    //     cerr << "File deletion failed";
    //   }
    //   else {
    //     cout << "File deleted successfully";
    //   }


    char newFile[50];
    strcpy(newFile, furniture.name);
    strcat(newFile, ".txt");


    /*    Deletes the file if exists */
    if (rename(file, newFile) != 0)
        perror("Error renaming file");
    else
        cout << "File renamed successfully";

}


void showFurniture() {
    cout << "\nInput Funrniture Name to view\n";
    cin >> furniture.name;
    cout << "" << endl;
    cout << "\n\t\t================================\n\t\t\tFurniture Details\n\t    \t================================\n";
    string myText;
    char file[20];
    strcpy(file, furniture.name);
    strcat(file, ".txt");
    // Read from the text file
    ifstream FurnitureFile1(file);

    // Use a while loop together with the getline() function to read the file line by line
    while (getline(FurnitureFile1, myText)) {
        // Output the text from the file
        cout << myText << endl;
    }
    cout << "" << endl;
    // Close the file
    FurnitureFile1.close();
}


void addSoldDetails() {

    ifstream file;


    char filename[20];
    char filename2[20];

    int line_number = 8;


    cout << "Enter Furniture Name:  ";
    cin >> filename2;


    if (line_number <= 0)
    {
        cout << "Line number must be >= 1" << endl;
    }

    strcpy(filename, filename2);
    strcat(filename, ".txt");
    file.open(filename);


    if (file.fail())
    {
        cout << "File failed to open." << endl;

    }

    int current_line = 0;
    string line;

    while (!file.eof())
    {
        current_line++;
        getline(file, line);

        if (current_line == line_number)
            break;
    }

    if (current_line < line_number)
    {
        cout << "Line not found!" << endl;
        cout << "File contains " << current_line;
        cout << " lines total." << endl;
    }

    else cout << "Available Quantity: " << line << endl;

    file.close();

    int lineInInt = stoi(line);
    int sold;
    cout << "Quantity of sold furniture: " << endl;
    cin >> sold;
    int quan = lineInInt - sold;

    string strQuan = to_string(quan);
    int line_number2 = 8;

    string text;
    fstream readFile;
    readFile.open(filename);

    //  getline(strQuan, text);
    text = strQuan;

    if (readFile.fail())
    {
        cout << "Error opening file." << endl;

    }


    vector<string> lines;
    string line2;


    while (getline(readFile, line2))
        lines.push_back(line2);


    readFile.close();


    if (line_number2 > lines.size())
    {
        cout << "Line " << line_number2;
        cout << " not in file." << endl;


        cout << "File has " << lines.size();
        cout << " lines." << endl;
    }


    ofstream write_file;


    write_file.open(filename);

    if (write_file.fail())
    {
        cout << "Error opening file." << endl;
    }

    line_number2--;

    for (int i = 0; i < lines.size(); i++)
    {

        if (i != line_number2)
            write_file << lines[i] << endl;
        else
            write_file << text << endl;
    }

    write_file.close();

    //try new
    fstream fp;
    fp.open("SalesDetails.txt", ios::out | ios::app);
    fp << "Furniture Name: " << filename2 << endl << "How many sold: " << sold << endl << "Available Quantity: " << strQuan << endl << endl;
    fp.close();
}

void soldDetails() {
    while (1) {
        cout << "\n\t\t================================\n\t\t     Manage Sales Details\n\t    \t================================\n\n";
        cout << "1) Add Sold Details" << endl << "2) View Sold Details" << endl << "3) Main Menu" << endl << "4) Exit" << endl << "Enter Your Choice: ";
        int choice4;
        cin >> choice4;
        if (choice4 == 1) {
            addSoldDetails();
        }
        else if (choice4 == 2) {
            showSoldDetails();
        }
        else if (choice4 == 3) {
            admin();
        }
        else if (choice4 == 4) {
            exit(0);
        }
        else {
            cout << "Enter Valid Choice";
        }
    }
}

void showSoldDetails() {
    string showSales;

    // Read from the text file
    ifstream MyReadFile("SalesDetails.txt");

    // Use a while loop together with the getline() function to read the file line by line
    while (getline(MyReadFile, showSales)) {
        // Output the text from the file
        cout << "" << endl;
        cout << showSales << endl;
    }

    // Close the file
    MyReadFile.close();
}


