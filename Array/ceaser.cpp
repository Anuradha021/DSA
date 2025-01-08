using namespace std;
#include<iostream>
void caesarCipher(string &text ,int shift){

    for(int i =0;i<text.length();i++){
      char ch = text[i];
    
    if(ch>='A'&& ch<='Z'){
        ch = (ch -'A'+shift)%26 +'A';
        text[i]=ch;
    }
    else if(ch>='a' && ch<='z'){
        ch = (ch -'a'+shift)%26 +'a';
        text[i]= ch;
    }
    }
}
int main(){
    string text;int shift;
    cout<<"enter text"<<endl;
    cin>>text;
    cout << "Enter shift value: ";
    cin >> shift;
    caesarCipher(text, shift);
    cout << "Encrypted text: " << text << endl;
    return 0;
}
