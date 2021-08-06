#include <vector>
#include <iostream>

using namespace std;

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}


int removeDuplicates(vector<int> &input){
    if(input.size() <= 1)
        return 0;
    /* sort the array  in O(nLogn) */
    sort(input.begin(), input.end());

    int *removedPointer = nullptr;
    int removedNumber = 0;

    /* shift the removed item to the end of array */
    for(int i = 0, j = 1; j < input.size();)
    {

        if(input[i] == input[j]){
            if(!removedPointer)
                removedPointer = &input[j];
            removedNumber ++;
            j ++;
            continue;
        }
        /* not equal */
        if(removedPointer) {
            swap(&input[j], removedPointer);
            removedPointer ++;
        }
        i ++;
        j ++;
    }
    input.resize(input.size() - removedNumber);
    return removedNumber;
}


int main()
{
    vector<int> products = {1,2,2,3,4,4 ,5,6,6};
    removeDuplicates(products);
    return 0;
}