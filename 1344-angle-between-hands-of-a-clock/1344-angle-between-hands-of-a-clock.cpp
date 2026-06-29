class Solution {
public:
    double angleClock(int hour, int minutes) 
    {
        if(hour == 12)
        {
            hour = 0;
        }    

        double hourAngle = hour * 30 + minutes * 0.5;
        double minuteAngle = minutes * 6;

        double difference = abs(hourAngle - minuteAngle);

        if(360 - difference  < difference)
        {
            return 360 - difference;
        }
        else
        {
            return difference;
        }
    }
};