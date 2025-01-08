using namespace std;
#include<iostream>
void encrypt(char message[],int key[2][2]){
char cipher[3];
for(int i =0;i<2;i++){
    cipher[i]=((key[i][0]* (message[0] -'A'))+  (key[i][1]* (message[1] -'A')))%26 +'A';
}
cipher[2]='\0';
cout<<"Encrpted cipher text is: "<<cipher<<endl;
}
int main() {
    char message[3];
    int key[2][2];

    cout << "Enter 2-letter message (uppercase): ";
    cin >> message;
      cout << "Enter 2x2 key matrix (integers):\n";
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            cin >> key[i][j];
            encrypt(message, key);

    return 0;
}