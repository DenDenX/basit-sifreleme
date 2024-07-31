#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
#define __ENCR_VERSION__ "0.2"
#define __LCNC_VERSION__ "0.0"



int bolumundenKalan (int bolunen, int bolen){
	if (bolunen > bolen){
		bolunen = bolunen - bolen;
		return bolumundenKalan(bolunen, bolen);
	}else if (bolunen == bolen){
		return 0;
	}else{
		return bolen - (bolen - bolunen);
	}
}

string sifreBoz     (string password){

	long long top = 0;
	int sifreLength = password.length();
	string yeniSifre = password;
	
	for (int i = 0; i < sifreLength; i++)
	{	
		top += (int)password[i];
	}

	top = bolumundenKalan(top, 256);


	char c;
	for (int i = 0; i < sifreLength; i++)
	{
		
		yeniSifre[i] = password[i] + top;
	}
	return yeniSifre;
	
}

void sifrele      (string &metin, string password){

	password = sifreBoz(password);
	for (int i = 0; i < metin.length(); i++){
		int index = bolumundenKalan(i, password.length());
		metin[i] += static_cast<char>((int)password[index] + index);
	}
	

}

void coz          (string &metin, string password)
{
	password = sifreBoz(password);
	for (int i = 0; i < metin.length(); i++)
	{
		int index = bolumundenKalan(i, password.length());
		metin[i] -= static_cast<char>((int)password[index] + index);
	}
}

void dosyaSifrele(string dosya, string password) {
    ifstream reader(dosya, ios::binary);
    ofstream writer("enc_" + dosya, ios::binary);
    vector<char> buffer(1024);
    while (reader.read(buffer.data(), buffer.size()) || reader.gcount() > 0) {
        string data(buffer.data(), reader.gcount());
        sifrele(data, password);
        writer.write(data.c_str(), data.size());
    }
}

void dosyaCozumle(string dosya, string password) {
    ifstream reader(dosya, ios::binary);
    ofstream writer("dec_" + dosya, ios::binary);
    vector<char> buffer(1024);
    while (reader.read(buffer.data(), buffer.size()) || reader.gcount() > 0) {
        string data(buffer.data(), reader.gcount());
        coz(data, password);
        writer.write(data.c_str(), data.size());
    }
}

int main(int argc, char* argv[])
{
if (argc ==1){
	cout << endl << endl <<
		"Welcome ..." << endl;
	cout << "Version Number: " << __ENCR_VERSION__ << endl << endl;

	cout << "Choose: (enc/de - crypt text from terminal options is not recommended)" << endl
		<< "1. Encrypt a short text from terminal." << endl
		<< "2. Decrypt a short text from terminal." << endl
		<< "3. Encrypt a file." << endl
		<< "4. Decrypt a file." << endl;

	int secenek;
	cin >> secenek;
	cin.ignore(); // Clear the newline character left by cin

	string arg1;
	string arg2;

	switch (secenek) {
		case 1:
			cout << "Enter text:\n"; 
			getline(cin, arg1);
			cout << "Enter password:\n"; 
			getline(cin, arg2);
			sifrele(arg1, arg2);
			cout << "Encrypted text: " << arg1 << endl;
			break;

		case 2:
			cout << "Enter text:\n";
			getline(cin, arg1);
			cout << "Enter password:\n";
			getline(cin, arg2);
			coz(arg1, arg2);
			cout << "Decrypted text: " << arg1 << endl;
			break;

		case 3:
			cout << "Enter file name to encrypt:\n";
			getline(cin, arg1);
			cout << "Enter password:\n";
			getline(cin, arg2);
			dosyaSifrele(arg1, arg2);
			cout << "File encrypted as enc_" << arg1 << endl;
			break;

		case 4:
			cout << "Enter file name to decrypt:\n";
			getline(cin, arg1);
			cout << "Enter password:\n";
			getline(cin, arg2);
			dosyaCozumle(arg1, arg2);
			cout << "File decrypted as dec_" << arg1 << endl;
			break;

		default:
			cout << "Invalid option selected." << endl;
			break;
	}

}else {
        if (argc != 4) {
            cout << "Usage: " << argv[0] << " opr fn pw" << endl;
            cout << "opr: Operation type (1 for encrypt, 2 for decrypt)" << endl;
            cout << "fn: File name" << endl;
            cout << "pw: Password" << endl;
            return 1;
        }

        int opr = atoi(argv[1]);
        string filename = argv[2];
        string password = argv[3];

        if (opr == 1) {
            dosyaSifrele(filename, password);
            cout << "File encrypted as enc_" << filename << endl;
        } else if (opr == 2) {
            dosyaCozumle(filename, password);
            cout << "File decrypted as dec_" << filename << endl;
        } else {
            cout << "Invalid operation type. Use 1 for encrypt and 2 for decrypt." << endl;
            return 1;
        }
    }

	return 0;
}
