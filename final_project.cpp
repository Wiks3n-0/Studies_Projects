#include <iostream>
#include <cmath>

using namespace std;

int size_of_array_to_create;
int sample_array[] = {9,8,7,6,5,4,3,2,1,0};

void print_solution(int * array){
    for(int i = 0; i<= size_of_array_to_create; i++){
        cout << array[i] << " ";
    }
}

// returns pointer to an array of size given as input 
int * create_array(int size_of_array){
    int * solution_array = new int[size_of_array];
    for(int i = 0; i <= size_of_array; i++){
        solution_array[i] = 0;
    }
    return solution_array;
}

// gets array to swap elements in and two indexes of numbers that'll be switched
void swap(int * array, int a, int b){
    int temp = *(array + a);
    *(array + a) = *(array + b);
    *(array + b) = temp;
}

//works for static array for now, for dynamic as well
int index_of_smallest_element(int * array, int arr_size, int start_of_search){
    int min_index = start_of_search;
    for(int i = start_of_search; i <= arr_size; i++){
        if (*(array+i) < *(array+min_index)){
            min_index = i;
        }
    }
    return min_index;
}

// works
int * selection_sort(int * array_to_sort){
    for(int i = 0; i <= size_of_array_to_create; i++){
        swap(array_to_sort,i,index_of_smallest_element(array_to_sort, size_of_array_to_create,i));
    }
    return array_to_sort;
}

void xor_swap(int * array, int a, int b){
    if(array[a] == array[b]){
    }
}

int dlugosc_euklidesowa(int * arr, int srednia){
    int result = 0;
    for(int i = 0; i <= size_of_array_to_create; i++){
        result += (arr[i]-srednia) * (arr[i]-srednia);
    }
    return sqrt(result);
}

int odchylenie_std(int * array){
    int srednia;
    for(int i = 0; i <= size_of_array_to_create; i++){
        srednia += array[i];
    }

    srednia = srednia / size_of_array_to_create;

    int licznik = dlugosc_euklidesowa(array, srednia);
    return licznik/sqrt(size_of_array_to_create);
}

int main(){
    int get_number_of_problem; // to take care of
    cin >> size_of_array_to_create; 
    size_of_array_to_create -= 1;
    int * solution_array = create_array(size_of_array_to_create);

    for(int i = 0; i <= size_of_array_to_create; i++){
        cin >> solution_array[i]; 
    }



    // problem 1 
    // cout << index_of_smallest_element(solution_array, size_of_array_to_create, 0);

    
    // problem 2 
    selection_sort(solution_array);
    print_solution(solution_array);
    cout << "\n";
    //problem 3
    cout << dlugosc_euklidesowa(solution_array, 0) << "\n";
    
    // problem 4
    cout << odchylenie_std(solution_array) << " odchyl";


    return 0;
}