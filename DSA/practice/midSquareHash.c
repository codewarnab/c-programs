#include <stdio.h>

int midSquareHash(int key , int tableSize){
    int sqaure = key * key ;
    // Division(/) : Removes the digits to the right of the middle digits.
    //Modulus(%) : Removes the digits to the left of the middle digits.
    int midDigits = (sqaure / 100) % 100; // extract middle 2

    return midDigits % tableSize ;  // use modulo to fit within hash table size 
}

int main(){
    int keys[] = {23, 45, 67, 89, 12}; // Sample keys
    int n = sizeof(keys) / sizeof(keys[0]);
    int tableSize = 10; // Hash table size

    printf("Key\t Hash Value\n");
    for (int i = 0; i < n; i++){
        int hashValue = midSquareHash(keys[i], tableSize);
        printf("%d\t%d\n", keys[i], hashValue);
    }
    return 0;
}