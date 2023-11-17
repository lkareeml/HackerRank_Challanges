void miniMaxSum(int arr_count, int* arr) {
    double min =0,max =0;

if((arr[0] + arr[1] + arr[2] + arr[3]) > max)
    max = (arr[0] + arr[1] + arr[2] + arr[3]);
else if((arr[0] + arr[2] + arr[3] + arr[4]) > max)
    max = (arr[0] + arr[2] + arr[3] + arr[4]);
else if((arr[0] + arr[1] + arr[2] + arr[4]) >max)
    max = (arr[0] + arr[1] + arr[2] + arr[4]);
else if((arr[0] + arr[1] + arr[3] + arr[4]) > max)
    max = (arr[0] + arr[1] + arr[3] + arr[4]);   
else if((arr[1] + arr[2] + arr[3] + arr[4]) > max) 
    max = (arr[1] + arr[2] + arr[3] + arr[4]);
 
 min = max;
 
if((arr[0] + arr[1] + arr[2] + arr[3]) < min)
    max = (arr[0] + arr[1] + arr[2] + arr[3]);
else if((arr[0] + arr[2] + arr[3] + arr[4]) < min)
    max = (arr[0] + arr[2] + arr[3] + arr[4]);
else if((arr[0] + arr[1] + arr[2] + arr[4]) < min)
    max = (arr[0] + arr[1] + arr[2] + arr[4]);
else if((arr[0] + arr[1] + arr[3] + arr[4]) < min)
    max = (arr[0] + arr[1] + arr[3] + arr[4]);   
else if((arr[1] + arr[2] + arr[3] + arr[4]) < min) 
    max = (arr[1] + arr[2] + arr[3] + arr[4]);  
    printf("%d %d",min,max);
}
