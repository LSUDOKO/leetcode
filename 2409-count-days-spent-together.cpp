class Solution {
public:

    int findDayOfYear(const string& day, const vector<int>& cumMonthDays) {
        int month = stoi(day.substr(0, 2));
        int date  = stoi(day.substr(3));
        return cumMonthDays[month - 1] + date;
    }

    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {
        vector<int> monthDays = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        vector<int> cumMonthDays(13, 0);
        cumMonthDays[1] = 31; 
        for(int i = 1; i <= 12; i++) {
            cumMonthDays[i] = cumMonthDays[i-1] + monthDays[i-1];
        }

        int arriveAliceDay  = findDayOfYear(arriveAlice, cumMonthDays);
        int leaveAliceDay   = findDayOfYear(leaveAlice, cumMonthDays);
        int arriveBobDay    = findDayOfYear(arriveBob, cumMonthDays);
        int leaveBobDay     = findDayOfYear(leaveBob, cumMonthDays);

        int overLapDays = min(leaveAliceDay, leaveBobDay) - max(arriveAliceDay, arriveBobDay) + 1;

        return overLapDays < 0 ? 0 : overLapDays;
    }
};