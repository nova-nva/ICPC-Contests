/**
 * METH
 * G - Primary Arithmetic
 * strings
 * (accepted)
 */

#include <bits/stdc++.h>
using namespace std;

int main(){
    string a, b; cin>>a>>b;
    while(a != "0" or b != "0"){
        if(a.size() < b.size()){
            int diff = b.size() - a.size();
            for(int i = 0; i<diff; i++){
                a = "0" + a;
            }
        }
        else if(a.size() > b.size()){
            int diff = a.size() - b.size();
            for(int i = 0; i<diff; i++){
                b = "0" + b;
            }
        }
        //cout<<a<<" "<<b<<endl;
        
        int carry = -1, cont = 0;
        for(int i = a.size() - 1; i>=0; i--){
            int suma;
            int aa = a[i] - '0', bb = b[i] - '0';
            if(carry == -1){
                suma = aa + bb;
                if(suma >= 10){
                    carry = 1;
                    cont++;
                }
                else carry = -1;
            }
            else{
                suma = aa + bb + 1;
                if(suma >= 10){
                    carry = 1;
                    cont++;
                }
                else carry = -1;
            }
        }
        if(cont == 0){
            cout<<"No carry operation."<<endl;
        }
        else if (cont == 1){
            cout<<"1 carry operation."<<endl;
        }
        else{
            cout<<cont<<" carry operations."<<endl;
        }
        cin>>a>>b;
    }
}