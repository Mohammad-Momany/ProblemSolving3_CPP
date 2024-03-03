#include <iostream>
#include <string>

#include <vector>

using namespace std;

struct stClientBankData
{
    string AccountNumber;
    string Name;
    string Phone;
    string PinCode;
    double AccountBalance;
};

vector<string> SplitString(string S1, string Delim) {
    vector<string> vString;
    short pos = 0;
    string sWord; // define a string variable

    // use find() function to get the position of the delimiters
    while ((pos = S1.find(Delim)) != std::string::npos) {
        sWord = S1.substr(0, pos); // store the word
        if (sWord != "") {
            vString.push_back(sWord);
        }
        S1.erase(0, pos + Delim.length());  /* erase() until positon and move to next word. */
    }
    if (S1 != "") {
        vString.push_back(S1); // it adds last word of the string.
    }
    return vString;
}

stClientBankData ConvertLineToRecord(string ClientData, string Separator = "#//#") {

    stClientBankData Client;

    vector<string> VSplitedData = SplitString(ClientData, Separator);

    Client.AccountNumber = VSplitedData[0];
    Client.PinCode = VSplitedData[1];
    Client.Name = VSplitedData[2];
    Client.Phone = VSplitedData[3];
    Client.AccountBalance = stod(VSplitedData[4]);

    return Client;
}

void PrintClientRecord(stClientBankData Client) {
    cout << "\n\nThe following is the extracted client record:\n";
    cout << "\nAccount Number: " << Client.AccountNumber;
    cout << "\nPin Code      : " << Client.PinCode;
    cout << "\nName          : " << Client.Name;
    cout << "\nPhone         : " << Client.Phone;
    cout << "\nAccount Balance: " << Client.AccountBalance;
}
int main()
{
    stClientBankData ClientBankData;
    string stLine = "A150#//#1234#//#Mohammad Almomany#//#079999#//#5270.000000";

    cout << "\nLine Record is:\n";     
    cout << stLine;

    ClientBankData = ConvertLineToRecord(stLine);

    PrintClientRecord(ClientBankData);     

    system("pause>0"); 
    return 0;

}
