#include <iostream>
#include <vector>
using namespace std;

void subsequence(vector<int> input, int index = 0, vector<int> output = {})
{
    if (index == input.size())
    {
        for (auto it : output)
            cout << it << " ";
        cout << endl;
        return;
    }
    subsequence(input, index + 1, output);
    output.push_back(input[index]);
    subsequence(input, index + 1, output);
}

int main()
{
    vector<int> a{1, 2, 3};
    subsequence(a);

    return 0;
}