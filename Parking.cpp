#include <ctime>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Parking
{
public:
    void printDateTime()
    {
        time_t now = time(0);
        string date_time = ctime(&now);

        vector<string> res = split(date_time);
        string date = res.at(0);
        int hour = stoi(res.at(3).substr(0, 2));
        int minute = stoi(res.at(3).substr(3, 2));
        if (date == "Sun")
        {
            cout << "CURRENTLY: PARKING ON THE RIGHT SIDE." << endl;
        }
        else if (date == "Mon" || date == "Wed" || date == "Fri")
        {
            if (hour > 18)
            {
                cout << "CURRENTLY: PARKING ON THE LEFT SIDE." << endl;
                print_reminder_to_move(-1, -1);
            }
            else
            {
                cout << "CURRENTLY: PARKING ON THE RIGHT SIDE." << endl;
                int diff_hour = 19 - hour;
                int diff_minute = 60 - minute;
                print_reminder_to_move(diff_hour, diff_minute);
            }
            cout << "TONIGHT:   PARKING ON THE LEFT SIDE." << endl;

        }
        else
        {
            if (hour > 18)
            {
                cout << "CURRENTLY: PARKING ON THE RIGHT SIDE." << endl;
                print_reminder_to_move(-1, -1);
            }
            else
            {
                cout << "CURRENTLY: PARKING ON THE LEFT SIDE." << endl;
                int diff_hour = 19 - hour;
                int diff_minute = 60 - minute;
                print_reminder_to_move(diff_hour, diff_minute);
            }
            cout << "TONIGHT:   PARKING ON THE RIGHT SIDE." << endl;

        }
    }
private:
    void print_reminder_to_move(int diff_hour, int diff_minute)
    {
        if (diff_hour == -1 && diff_minute == -1)
        {
            cout << "YOU'RE ALL SET. NO MOVING NEEDED." << endl;
        }
        if (diff_hour == 1)
        {
            cout << "In " << to_string(diff_minute) << " minutes, move your car to the other side." << endl;
        }
        else
        {
            --diff_hour;
            string h = diff_hour > 1 ? " hours" : " hour";
            cout << "In " << to_string(diff_hour) << h << " and " << to_string(diff_minute) << " minutes, move your car to the other side." << endl;
        }
    }

    vector<string> split(const string &original)
    {
        vector<string> res;
        string curr;
        for (char c : original)
        {
            if (c == ' ')
            {
                res.push_back(curr);
                curr.clear();
                continue;
            }
            curr += c;
        }
        return res;
    }
};

int main()
{
    Parking p;
    p.printDateTime();
}