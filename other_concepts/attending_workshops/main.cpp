//
// Created by syafiq on 11/17/16.
//

#include <iostream>
#include<bits/stdc++.h>

using namespace std;

struct Counter
{
    int counter;
    int index;
    int end;

    Counter()
    {}

    Counter(int counter, int index, int end) : counter(counter), index(index), end(end)
    {}
};

struct Workshop
{
    int start, duration, end;

    Workshop()
    {}

    Workshop(int start, int duration) : start(start), duration(duration), end(start + duration)
    {
    }
};

struct Available_Workshops
{
    int size;
    Workshop *workshop;

    Available_Workshops()
    {}

    Available_Workshops(int size, Workshop *workshop) : size(size), workshop(workshop)
    {}
};


int CalculateMaxWorkshops(Available_Workshops *pWorkshops)
{
    const Workshop *workshop = pWorkshops->workshop;
    const int ws = pWorkshops->size;
    int vval = workshop[ws - 1].start;

    int mval = -1;
    queue<Counter> c;

    for(int i = -1, is = ws; ++i < is;)
    {
        c.push(Counter(1, i+1, workshop[i].end));
    }

    while(!c.empty())
    {
        const Counter *ct = &c.front();
        if(ct->index > ws)
        {
            mval = max(mval, ct->counter);
            c.pop();
        }
        else if(ct->end > vval)
        {
            mval = max(mval, ct->counter);
            c.pop();
        }
        else
        {
            int i = ct->index - 1;
            for(int is = ws; (++i < is);)
            {
                if(ct->end < workshop[i].start)
                {
                    break;
                }
            }
            for(int j = i - 1, cnt = ct->counter + 1, js = ws; ++j < js;)
            {
                c.push(Counter(cnt, j + 1, workshop[j].end));
            }
            c.pop();
        }
    }
    return mval;
}

Available_Workshops *initialize(int *starts, int *durations, int n)
{
    Workshop *workshop = new Workshop[n];

    for(int i = -1; ++i < n;)
    {
        workshop[i] = Workshop(starts[i], durations[i]);
    }

    struct {
        bool operator()(const Workshop &a, const Workshop &b)
        {
            return a.start < b.start;
        }
    } workshopComparator;

    sort(workshop, workshop+n, workshopComparator);

    return new Available_Workshops(n, workshop);
}

int main()
{
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int* start_time = new int[n];
    int* duration = new int[n];

    for(int i=0; i < n; i++){
        cin >> start_time[i];
    }
    for(int i = 0; i < n; i++){
        cin >> duration[i];
    }

    Available_Workshops * ptr;
    ptr = initialize(start_time,duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}