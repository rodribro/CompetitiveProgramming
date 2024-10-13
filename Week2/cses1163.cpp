#include <iostream>
#include <set>

using namespace std;

int main()
{
    int street_length;
    int n_traff_sets;
    cin >> street_length >> n_traff_sets;

    int t_light;
    int dif_to_prev;
    int dif_to_next;

    set<int> positions = {0, street_length};
    multiset<int> lengths = {street_length};

    for (int i = 0; i < n_traff_sets; i++)
    {
        cin >> t_light;
        // cout << "New T Light: " << t_light << endl;

        // Get iterator for the inserted element
        auto it = positions.insert(t_light).first;

        // auto prev_it = prev(it);
        //  cout << "Prev pos: " << *prev_it << endl;
        // auto next_it = next(it);
        //  cout << "Next pos: " << *next_it << endl;
        dif_to_prev = t_light - *prev(it);
        // cout << "Dif 2 Prev: " << dif_to_prev << endl;
        dif_to_next = *next(it) - t_light;
        // cout << "Dif 2 Next: " << dif_to_next << endl;

        lengths.insert(dif_to_prev);
        lengths.insert(dif_to_next);

        /*
        Check if the difference between next and prev
        of the element we want to insert exists, if so
        we remove that length and replace it with newer ones
        */
        // int dif_next_prev = *next(it) - *prev(it);
        // if (lengths.contains(*next(it) - *prev(it)))
        //{
        // auto to_del = lengths.find(dif_next_prev);
        // cout << "Length to erase: " << *to_del << endl;
        lengths.erase(lengths.find(*next(it) - *prev(it)));
        //}

        // cout << "Cur. lengths: ";
        /*
        for (auto it = lengths.begin(); it != lengths.end(); it++)
        {
            cout << *it << " ";
        }
        cout << endl;
        */
        // int big_len = *lengths.rbegin();
        cout << *lengths.rbegin() << " ";
    }
}
