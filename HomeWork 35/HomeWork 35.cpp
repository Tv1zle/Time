#include <iostream>


class Time
{
    int seconds;
    int minutes;
    int hours;
public:
    Time()
    {
        seconds = 0;
        minutes = 0;
        hours = 0;
    }

    Time(int h, int m, int s)
    {
        hours = h;
        minutes = m;
        seconds = s;
    }

    void SetSeconds(int s)
    {
        seconds = s;
    }

    void SetMinutes(int m)
    {
        minutes = m;
    }

    void SetHours(int h)
    {
        hours = h;
    }
    
    int GetSeconds()
    {
        return seconds;
    }

    int GetMinutes()
    {
        return minutes;
    }

    int GetHours()
    {
        return hours;
    }

    Time operator+(int b)
    {
        for ( ; b > 60; b-=60)
        {
            if (seconds + b >= 60)
            {
                seconds -= 60;
                if (minutes == 59)
                {
                    minutes = 0;
                    if (hours == 23)
                    {
                        hours = 0;
                        minutes = 0;
                        seconds = 0;
                    }
                    hours++;
                }
                minutes++;
            }
        }
        this->seconds + b;
        return *this;
    }

    friend std::ostream& operator<< (std::ostream& out, const Time& time);
    friend std::istream& operator>> (std::istream& in, Time& time);
};


std::ostream& operator<< (std::ostream& out, const Time& time)
{
    out << "\nHours:" << time.hours << "\nMinutes:" << time.minutes << "\nSeconds:" << time.seconds;
    return out;
}


std::istream& operator>> (std::istream& in, Time& time)
{
    in >> time.hours;
    in >> time.minutes;
    in >> time.seconds;

    return in;
}


int main()
{
    Time a(20, 14, 10);
    std::cout << a;


}