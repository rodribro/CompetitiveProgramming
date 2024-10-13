#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main()
{
    int n_songs;
    cin >> n_songs;
    int max_seq = 0;
    int start = 0;

    vector<int> song_order;
    map<int, int> songs_pos;

    int song;
    for (int i = 0; i < n_songs; i++)
    {
        cin >> song;
        song_order.push_back(song);
    }

    for (int i = 0; i < n_songs; i++)
    {
        song = song_order[i];

        if (songs_pos.contains(song))
        {
            if (songs_pos[song] < start)
            {
                songs_pos[song] = i;
            }

            else
            {
                start = songs_pos[song] + 1;
                songs_pos[song] = i;
            }
        }
        else
        {
            songs_pos[song] = i;
        }

        max_seq = max(max_seq, i - start + 1);
    }
    cout << max_seq << endl;
}