class Solution {
public:
    int dayOfYear(string date, int months[]) {
        int month = stoi(date.substr(0, 2));
        int day = stoi(date.substr(3, 2));

        int total = 0;
        for (int i = 0; i < month - 1; i++) {
            total += months[i];
        }
        return total + day;
    }

    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {
        int months[12] = {31, 28, 31, 30, 31, 30,
                          31, 31, 30, 31, 30, 31};

        int aliceStart = dayOfYear(arriveAlice, months);
        int aliceEnd = dayOfYear(leaveAlice, months);
        int bobStart = dayOfYear(arriveBob, months);
        int bobEnd = dayOfYear(leaveBob, months);

        int start = max(aliceStart, bobStart);
        int end = min(aliceEnd, bobEnd);

        return max(0, end - start + 1);
    }
};