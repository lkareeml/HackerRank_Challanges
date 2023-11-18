#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

void converter(char * s, char* s_out, int n){
    int j = 0;
    for(int i = 4;i < n;i++){
        if(s[0] == 'S'){
            if(isupper(s[i])){
                s_out[j] = ' ';
                printf("%c",s_out[j]);
                j++;
                s_out[j] = s[i] + 32;
            }else{
                if(s[i] == '\0' || s[i] == '(' || s[i] == ')'){
                    break;
                    }
                s_out[j] = s[i];
            }
            printf("%c",s_out[j]);
            j++;
        }
        if(s[0] == 'C'){
            if(s[i] != '\0' && s[i] != ' ' && s[i] != 32){
                s_out[j] = s[i];
            }
            else if(s[i] == 32){
                i++;
                s_out[j] = (s[i] - 32);
            }
            else if(s[i] == '\0' && s[2] == 'M'){
                s_out[j] = '(';
                printf("%c",s_out[j]);
                j++;
                s_out[j] = ')';
                printf("%c",s_out[j]);
                break;
            }else{break;}
            printf("%c",s_out[j]);
            j++;
        }
        
    }
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT
    // OPERATION :  S (split) or C (combine) 
    // semi-colon 
    /// M indicates method, C indicates class, and V indicates variable
    S;M;plasticCup()            >   plastic cup
    S;C;LargeSoftwareBook       >   large software book
    S;V;pictureFrame            >   picture frame
    C;V;mobile phone            >   mobilePhone
    C;C;coffee machine          >   CoffeeMachine
    C;M;white sheet of paper    >   whiteSheetOfPaper()
    */
    int n = 60;
    char s_input[n];
    char s_output[n];
    fgets(s_input, n, stdin);
    //scanf("%[^\n]s",&s_input1);
    converter(&s_input,&s_output,n);
    return 0;
}
