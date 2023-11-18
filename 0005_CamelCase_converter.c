#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

void converter(char * s, char* s_out, int n){
    int S_Flag = 0;
    int C_Flag = 0;
    int M_Flag = 0;
    int j = 0;
    for(int i = 0;i < n;i++){
        
        if(s[i] == 'S' && s[i+1] == ';'){
            i+=3;
            S_Flag = 1;C_Flag = 0;
            continue;
        }
        if(s[i] == 'C' && s[i+1] == ';'){
            if(s[i+2] == 'M') 
                M_Flag =1;
            else 
                M_Flag = 0;
            C_Flag = 1;
            S_Flag = 0;    
            i+=3;
            continue;
        }
        
        if(S_Flag == 1 && C_Flag == 0){
            if(isupper(s[i]) && s[i-1] != ';'){
                s_out[j] = ' ';
                printf("%c",s_out[j]);
                j++;
                s_out[j] = s[i] + 32;
            }
            else if(isupper(s[i]) && s[i-1] == ';'){
                s_out[j] = s[i] + 32;
            }
            else{
            if(s[i] == '\0' || s[i] == '(' || s[i] == ')'){
                    break;
                }
                s_out[j] = s[i];
            }
            printf("%c",s_out[j]);
            j++;
        }
        if(S_Flag == 0 && C_Flag == 1){
            if(s[i] != '\0' && s[i] != ' ' && s[i] != 32){
                s_out[j] = s[i];
            }
            else if(s[i] == ' '){
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
    // Enter your code here. Read input from STDIN. Print output to STDOUT
    int n = 300;
    char s_input[n];
    char s_output[n];
    char temp;

    for(int i =0; i < n ;i++){
        s_input[i] = getchar();
        if(s_input[i] < 10 || s_input[i] > 122) 
        {s_input[i] = '\0';break;}
        //if(s_input[i] > 11 && s_input[i] < 32)
        //{s_input[i] = '\0';break;}
        //if(s_input[i] == 10) break;
    }
    converter(&s_input,&s_output,n);
    return 0;
}
