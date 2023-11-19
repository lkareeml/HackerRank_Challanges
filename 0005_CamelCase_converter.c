#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int n = 300;
char sz[300];
char s_input[300];
char s_out[300];
    
void converter(char *s, char *s_out, int n){
    int S_Flag = 0;
    int C_Flag = 0;
    int CM_Flag = 0;
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
            if(s[i+2] == 77) {
                CM_Flag = 1;
                CC_Flag = 0;
            }
            else if(s[i+2] == 67){
                CC_Flag = 1;
                CM_Flag = 0;
            }
            C_Flag = 1;
            S_Flag = 0;    
            i+=3;
            continue;
        }
        
        if(S_Flag == 1 && C_Flag == 0){
            if(s[i] == 40 && s[i+1] == 41){
                if( s[i+2] == 10){
                    i = i + 2;
                }
            }
            if(isupper(s[i]) && s[i-1] != ';'){
                s_out[j] = 32;
                j++;
                s_out[j] = s[i] + 32;
            }
            else if(isupper(s[i]) && s[i-1] == ';'){
                s_out[j] = s[i] + 32;
            }
            else if(s[i] == 10 && s[i+1] == '\0'){
                break;
            }else{
                s_out[j] = s[i];
            }
            j++;
        }
        if(S_Flag == 0 && C_Flag == 1){
            
            if(CC_Flag == 1 && s[i-1] == ';'){
                s_out[j] = (s[i] - 32);
                CC_Flag = 0;
            }
            else if(CM_Flag == 1 && s[i] == 10){
                s_out[j] = '(';
                j++;
                s_out[j] = ')';
                j++;
                s_out[j] = 10;
                CM_Flag = 0;
            }
            else if(s[i] != '\0' && s[i] != 32 && s[i] != 10){
                s_out[j] = s[i];
            }
            else if(s[i] == ' '){
                i++;
                s_out[j] = (s[i] - 32);
            }
            else if(s[i] == 10 && CM_Flag == 0 && s[i+1] == '\0'){
                break;
            }else s_out[j] = s[i];
            j++;
        }  
    }
}

int main(){
    for(int i =0; i < n ;i++){
    s_input[i] = 0;
    s_out[i] = 0;
    }
    /// Input Filter
    for(int i =0; i < n ;i++){
        sz[i] = getchar();
        if(sz[i]==10||sz[i]==32||sz[i]==40||sz[i]==41||sz[i]==59) // NewLine - Space - ();
            s_input[i] = sz[i];
        else if(sz[i] > 64 && sz[i] < 91) // Upper Case Alphabit
            s_input[i] = sz[i];
        else if(sz[i] > 96 && sz[i] < 123)// Lower Case Alphabit
            s_input[i] = sz[i];
    }
    
    converter(s_input, s_out,n);
    
    for(int i =0; i < n ;i++){
        if(s_out[i]==32||s_out[i]==40||s_out[i]==41||s_out[i]==59) // NewLine - Space - ();
            printf("%c",s_out[i]);
        else if(s_out[i] > 64 && s_out[i] < 91) // Upper Case Alphabit
            printf("%c",s_out[i]);
        else if(s_out[i] > 96 && s_out[i] < 123)// Lower Case Alphabit
            printf("%c",s_out[i]);
        else if((s_out[i]==10) && (s_out[i+1] != 10)){
            if((s_out[i+1] > 64 && s_out[i+1] < 91) || (s_out[i+1] > 96 && s_out[i+1] < 123))
                printf("%c",s_out[i]);
        }
    }
    return 0;
}
