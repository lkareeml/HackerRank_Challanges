///This function Gets arguments : score array with scores for each game, 
///The Goal of the function is to count the number of times to break the minimum score and getting less
/// and same for the max 
///Example : score = [10 5 20 20 4 5 2 25 1] >>> min breaking times will be 4 time, max breaked count is 2

int* breakingRecords(int scores_count, int* scores, int* result_count) {
    int min_Record_Break_Count = 0;
    int max_Record_Break_Count = 0;
    int current_Min = scores[0];
    int current_Max = scores[0];
    int i =0;
    for(i =1;i<scores_count;i++){
        if(scores[i] < current_Min){
            min_Record_Break_Count++;
            current_Min = scores[i];
        }
        else if(scores[i] > current_Max){
            max_Record_Break_Count++;
            current_Max = scores[i];
        }
    }
    *result_count = 2;
    int *result_array = malloc(2 * sizeof(int));
    result_array[0] = max_Record_Break_Count;
    result_array[1] = min_Record_Break_Count;
    return result_array;
}
