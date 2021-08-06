
int findPartitionPivot(const vector<int> &input){
    if(input.size() <= 3)
        return -1;

    int sum = 0;
    for(int i = 0; i < input.size(); i++)
        sum += input[i];

    int leftSum = input[0];
    int rightSum;

    /* shift the removed item to the end of array */
    for(int pivotIndex = 1; pivotIndex < input.size() - 1; pivotIndex ++)
    {
        rightSum = sum -  leftSum - input[pivotIndex];
        if(rightSum == leftSum)
            return pivotIndex;
        leftSum += input[pivotIndex];
    }
    return -1;
}

int main()
{
    vector<int> products = {2, 3, 1, 6, 2, 1, 3};
    cout << findPartitionPivot(products);

    return 0;
}