#include <iostream>
#include <array>
#include <fstream>


using namespace std;

void readFile(char[], int);
int key(char[], int);
void encrypt(char[], char[], int, int);
void dispArr(char[], int);
void decipher(char[], char[], int , int);
void revArr(char[], char[], int);

int main() {
	char in[11]; 
	char cipher[11]; 
	char deCipher[11]; 
	char rev[11]; 
	const int SIZE = 11;
	int offsetKey;
	
	cout << "======================================================\n";

	readFile(in, SIZE);

	cout << "Unencrypted array is: \t\t";

	dispArr(in, SIZE);


	offsetKey = key(in, SIZE);
	
	cout << "The offset key is: \t\t" << offsetKey << "\n";
	
	encrypt(in, cipher, SIZE, offsetKey);

	cout << "The encrypted array is: \t";

	dispArr(cipher, SIZE);

	decipher(cipher, deCipher, offsetKey, SIZE);

	cout << "The de-encrypted array is: \t";

	dispArr(deCipher, SIZE);

	revArr(in, rev, SIZE);
	cout << "The reversed array is: \t\t";

	dispArr(rev, SIZE);

	cout << "======================================================";
}

void readFile(char name[], const int SIZE) {


	fstream namefile;

	namefile.open("in.txt");

	if (!namefile.is_open()) 
	{
		cout << "Problem opening file!";
		
	}

	
	for (int i = 0; i < SIZE; i++)
		{
			namefile >> name[i];
			
		}
	
	
}

int key(char name[], const int SIZE) {
	int key = 0;
	for (int i = 0; i < SIZE; i++) {
		if (name[i] == 'e' || name[i] == 'i') {
			key++;
		}
	}
	
	return key;
}

void encrypt(char name[], char encrypted[], const int SIZE, int offset) {
	for (int i = 0; i < SIZE; i++) {
		encrypted[i] = name[i] + offset;
		
	}
}

void decipher(char encryped[], char deciphered[], int offsetk, const int SIZE) {
	for (int i = 0; i < SIZE; i++) {
		deciphered[i] = encryped[i] - offsetk;
	}
}


void revArr(char arr[], char rev[], const int SIZE) {
	
	for (int i = 0; i < SIZE; i++) {
		rev[SIZE - i - 1] = arr[i];
	}
}

void dispArr(char arr[], const int SIZE) {
	for (int i = 0; i < SIZE; i++) {
		cout << arr[i];
	}
	cout << "\n";
}