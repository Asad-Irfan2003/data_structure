#include <iostream>
using namespace std;



int* failure_function(string p){
    int m=p.length();
    int * lps=new int[m];
    lps[0]=0;
    int len=0,i=1;
    while(i<m){
        if(p[i]==p[len]){
            lps[i]=++len;
            i++;
        }
        else if(len>0){
            len=lps[len-1];
        }
        else lps[i++]=0;
    }
    return lps;
}
void kmp(string text, string pattern){
    int m=pattern.length(),n=text.length();
    int* lps=failure_function(pattern);
    int i=0,j=0;
    while(i<n){
        if(text[i]==pattern[j]){
            if(j==m-1){
                cout<<"Pattern found at: "<<i-j<<endl;
                j=lps[j];
            }
            else{
                i++;
                j++;
            }
        }
        else{
            if(j>0){
                j=lps[j-1];
            }
            else{
                i++;
            }
        }
    }
}