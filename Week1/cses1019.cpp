#include <iostream>
using namespace std;

int main()
{
    string dna;
    cin >> dna;

    int dna_length = dna.size();
    int counter = 1;
    int max_counter = 1;

    string prev_char;
    string cur_char;

    for (int i = 0; i < dna_length; i++)
    {

        prev_char = dna[i];
        cur_char = dna[i + 1];

        if (prev_char != cur_char)
        {
            if (max_counter >= counter)
            {
                counter = 1;
            }

            else if (max_counter <= counter)
            {
                max_counter = counter;
                counter = 1;
            }
        }

        else if (prev_char == cur_char)
        {
            counter++;
        }
    }
    cout << max_counter << "\n";
}