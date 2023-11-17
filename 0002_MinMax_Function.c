void miniMaxSum(int arr_count, int* arr) {
    long long int  min =0,max =0;

if((arr[0] + arr[1] + arr[2] + arr[3]) > max)
    max = (arr[0] + arr[1] + arr[2] + arr[3]);
if((arr[0] + arr[2] + arr[3] + arr[4]) > max)
    max = (arr[0] + arr[2] + arr[3] + arr[4]);
if((arr[0] + arr[1] + arr[2] + arr[4]) > max)
    max = (arr[0] + arr[1] + arr[2] + arr[4]);
if((arr[0] + arr[1] + arr[3] + arr[4]) > max)
    max = (arr[0] + arr[1] + arr[3] + arr[4]);   
if((arr[1] + arr[2] + arr[3] + arr[4]) > max) 
    max = (arr[1] + arr[2] + arr[3] + arr[4]);
 
 min = max;
 
if((arr[0] + arr[1] + arr[2] + arr[3]) < min)
    min = (arr[0] + arr[1] + arr[2] + arr[3]);
if((arr[0] + arr[2] + arr[3] + arr[4]) < min)
    min = (arr[0] + arr[2] + arr[3] + arr[4]);
if((arr[0] + arr[1] + arr[2] + arr[4]) < min)
    min = (arr[0] + arr[1] + arr[2] + arr[4]);
if((arr[0] + arr[1] + arr[3] + arr[4]) < min)
    min = (arr[0] + arr[1] + arr[3] + arr[4]);   
if((arr[1] + arr[2] + arr[3] + arr[4]) < min) 
    min = (arr[1] + arr[2] + arr[3] + arr[4]);  

    printf("%lld %lld",min,max);
}
