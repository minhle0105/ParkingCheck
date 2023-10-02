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
        int length = date_time.size();
        vector<string> res = split(date_time);
        string date = res.at(0);
        int hour = stoi(date_time.substr(length - 14, 2));
        int minute = stoi(date_time.substr(length - 11, 2));
        if (date == "Sun")
        {
            print_reminder_current("RIGHT");
        }
        else if (date == "Mon" || date == "Wed" || date == "Fri")
        {
            if (hour > 18)
            {
                print_reminder_current("LEFT");
                print_reminder_to_move(-1, -1);
            }
            else
            {
                print_reminder_current("RIGHT");
                int diff_hour = 19 - hour;
                int diff_minute = 60 - minute;
                print_reminder_to_move(diff_hour, diff_minute);
                print_reminder_for_tonight("LEFT");
            }
        }
        else
        {
            if (hour > 18)
            {
                print_reminder_current("RIGHT");
                print_reminder_to_move(-1, -1);
            }
            else
            {
                print_reminder_current("LEFT");
                int diff_hour = 19 - hour;
                int diff_minute = 60 - minute;
                print_reminder_to_move(diff_hour, diff_minute);
                print_reminder_for_tonight("RIGHT");
            }
        }
    }
private:
    void print_reminder_to_move(int diff_hour, int diff_minute)
    {
        if (diff_hour == -1 && diff_minute == -1)
        {
            cout << "YOU'RE ALL SET. NO MOVING NEEDED." << endl;
        }
        else if (diff_hour == 1)
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

    void print_reminder_current(const string &side)
    {
        cout << "CURRENTLY: PARKING ON THE " << side << " SIDE." << endl;
    }

    void print_reminder_for_tonight(const string &side)
    {
        cout << "TONIGHT:   PARKING ON THE " << side << " SIDE." << endl;
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
    return 0;
}
