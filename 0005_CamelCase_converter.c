#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void converter(char * s, char* s_out, int n){
    int S_Flag = 0;
    int C_Flag = 0;
    int M_Flag = 0;
    int CC_Flag = 0;
    int j = 0;
    for(int i = 0;i < n;i++){
        if(s[i] == 'S' && s[i+1] == ';' && s[i+3] == ';' ){
            i+=3;
            S_Flag = 1;
            C_Flag = 0;
            continue;
        }
        if(s[i] == 'C' && s[i+1] == ';' &&  s[i+3] == ';'){
            if(s[i+2] == 77) 
            {
                M_Flag = 1;
                CC_Flag = 0;
            }
            else if(s[i+2] == 67)
            {
                CC_Flag = 1;
                M_Flag = 0;
            }
            C_Flag = 1;
            S_Flag = 0;    
            i+=3;
            continue;
        }
        
        if(S_Flag == 1 && C_Flag == 0){
            if(isupper(s[i]) && s[i-1] != ';'){
                s_out[j] = ' ';
                //printf("%c",s_out[j]);
                j++;
                s_out[j] = s[i] + 32;
            }
            else if(isupper(s[i]) && s[i-1] == ';'){
                s_out[j] = s[i] + 32;
            }
            else if(s[i+1] != '\0'){
                s_out[j] = s[i];
            }
            else if(s[i] == 10 && s[i+1] == '\0'){
                break;
            }
            //printf("%c",s_out[j]);
            j++;
        }
        if(S_Flag == 0 && C_Flag == 1){
            
            if(CC_Flag == 1 && s[i-1] == ';'){
                s_out[j] = (s[i] - 32);
                CC_Flag = 0;
            }
            else if(M_Flag == 1 && s[i] == 10){
                s_out[j] = '(';
                //printf("%c",s_out[j]);
                j++;
                s_out[j] = ')';
                //printf("%c",s_out[j]);
                j++;
                s_out[j] = 10;
                M_Flag = 0;
            }
            else if(s[i] != '\0' && s[i] != 32 && s[i] != 10){
                s_out[j] = s[i];
            }
            else if(s[i] == ' '){
                i++;
                s_out[j] = (s[i] - 32);
            }
            else if(s[i] == 10 && M_Flag == 0 && s[i+1] == '\0'){
                break;
            }else s_out[j] = s[i];
            //printf("%c",s_out[j]);
            j++;
        }
        
    }
}


int main() {
    // Enter your code here. Read input from STDIN. Print output to STDOUT
    int n = 300;
    char s_input[n];
    char s_output[n];
    for(int i =0; i < n ;i++){
        s_input[i] = getchar();
        if(s_input[i] < 10 || s_input[i] > 122) 
        {s_input[i] = 10;break;}
    }
    converter(&s_input,&s_output,n);
    //printf("%c",10);
    //printf("%c",67);
    
    for(int i =0; i < n ;i++){
        ///Filter ALL non characters / numbers / New line / Spaces
        if( (s_output[i]==10)||(s_output[i]>= 32 && s_output[i]<126)) 
        printf("%c",s_output[i]);
        
        if(s_output[i] < 10 || s_output[i] > 122)   break;
        if(s_output[i+1] == 10)
            if(s_output[i+2] == '\0')
                break;
    }
    return 0;
}
