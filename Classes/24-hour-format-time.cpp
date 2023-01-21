#include<iostream>
#include<string>
using namespace std;

class Time
{
    private:
        int hour;
            int min;
            int sec;
        char mode;

    public:
                            //Defaullt Constructor
        Time()      
        {
            sec = 0;
                min = 0;
                    hour = 0;
                mode = 'A';
            cout << "\nDefaullt Constructor --> ";
        }
                            //Perimerized Constructor no. 01

        Time(int h, int m, int s, char md)       
        {
            sec = s;
                min = m;
                    hour = h;
                        mode = md; 
        }
                             //Perimerized Constructor no. 02

        Time(int h, int m, int s)        
        {
            hour = h;
                min = m;
                    sec = s;
        }
                            //Copy Constructor

        Time(const Time & y)          
        {
            sec = y.sec;
                min = y.min;
                    hour = y.hour ;
        }
                            //Getters

        int getHours()
        {
            return hour;
        }   

        int getMinutes()
        {
            return min;
        }   

        int getSeconds()
        {
            return sec;
        }   

        int getMode()
        {
            return mode;
        }
                            //Setters

        void setHours(int h)
        {
            hour = h;
        }   

        void setMinutes(int m)
        {
            min = m;
        }

        void setSeconds(int s)                            
        {
            sec = s;
        }

        void setMode(char md)
        {
            mode = md;
        }

        void displayTime()
        {
            cout << hour 
                << " : " 
                    << min << " : " 
                << sec << "  " 
            << mode << endl;
        }

                            //Conversions

        double convertToSeconds()
        {
            int Sec;
                Sec = (hour * 60 * 60) + (min * 60) + sec;
                    cout <<"\nSeconds : " << Sec;
        }

        double convertToMinutes()
        {
            int Min;
		        Min = (hour * 60) + min;           
		            cout <<"\t\tMinutes : " << Min;
        }

        double convertToHours()
        {
            int Hours;
		        Hours = hour;
		            cout << "\t\tHours : " << Hours << endl << endl;
        }

        void convertTo24HourFormat()
        {
            
            if(mode == 'P')
            {
                hour = hour + 12;
            }
            cout << "\n24 Hour Format Time --> " 
                    << hour << " : " << min 
                        << " : " << sec << endl; 
        }
                            //Increments


        void incrementSeconds(int s)
        {
            int NoSec = sec + s;

		        if(sec >= 60)
		        {
                    min = min + 1;
		        }

		        if(min > 59)
		        {
			        hour = hour + 1;
		        }
		            sec = NoSec - 60;
                
        }

        void incrementMinutes(int m)
        {
            int min = min + m;
		
		        if(min > 59)
		        {			
			        hour++;
			        min = 0;
		        }

        }

};

    int main()
    {

    Time ob1;
        Time ob2(10, 20, 30, 'A');
            Time ob3(11, 12, 13);
                Time ob4 = ob3;

    ob2.getHours();
        ob2.getMinutes();
            ob2.getSeconds();
                ob2.getMode();

    ob2.setHours(10);
        ob2.setMinutes(20);
            ob2.setSeconds(30);
                ob2.setMode('P');

    ob2.displayTime();

	ob2.convertTo24HourFormat();
        ob2.convertToSeconds();
	        ob2.convertToMinutes();
        	    ob2.convertToHours();

	ob2.incrementSeconds(63);
        ob2.incrementMinutes(65);

    }
