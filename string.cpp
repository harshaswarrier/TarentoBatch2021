/*
2. - Accept a String input
- Accept a String of valid chars
- Remove all the characters that are not present in the valid chars from the input string
- Print the cleansed String and the count of characters removed
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str, valid, rem;
    int i, j, k, c[100], cn=0;
    getline(cin, str);//read inputs
    getline(cin, valid);
    int n = str.length();
    int m= valid.length();
    for(i=0; i<n; i++){
        int f=0;//flag
        for(j=0; j<m; j++){
            if(str[i]==valid[j]){
                f=1;//search in valid string
                break;
            }
        }
        //if not valid
        if (f==0){
            int t=0;
            for(k =0; k<cn; k++){
                if(rem[k]==str[i]){
                    c[k]+=1;//if already in removed elements
                    t=1;//update count and flag
                    break;
                }
            }
            if(t==0){
                rem[k]=str[i];//add to removed elements list
                c[k]=1;
                cn+=1;//count for removed elements
            }
            for(int p=i; p<n-1; p++){
                str[p]=str[p+1];//removing element from str
            }
            n=n-1;//remove last repeated element
        }
    }
    //removing consecutive appearance of invalid characters
    for(i=0; i<n; i++){
        for(j=0; j<cn; j++){
            if(str[i]==rem[j]){
                c[j]++;
               for(int p=i; p<n-1; p++){
                    str[p]=str[p+1];
               }
               n=n-1;
            }
    
        }
    }
    //outputs
    for(i=0; i<n; i++){
        std::cout<<str[i];
    }
    std::cout<<"\n";
    for(i=0; i<cn; i++){
        std::cout<<c[i]<<" "<<rem[i]<<" was removed\n";
    }
    return 0;
}
