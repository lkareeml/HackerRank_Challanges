///This Function Takes Array Size as {arr_count} and an Array {arr} 
/// and Prints the ration of The number of {Potitive numbers / Array size} then {Negative numbers / Array size} then {Zeros / Array size}
void plusMinus(int arr_count, int* arr) {
    char p_count=0,z_count=0;
    for(char i =0;i<arr_count;i++){
        if(arr[i]>0){p_count++;}
        else if(arr[i]==0){z_count++;}
    }
    printf("%f\n%f\n%f\n",(float)p_count/(float)arr_count,(float)(arr_count-p_count-z_count)/(float)arr_count ,(float)z_count/(float)arr_count );
}
