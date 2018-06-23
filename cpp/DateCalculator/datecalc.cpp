#include <iostream>
#include <string>

using namespace std;

//It is very complex to keep users from picking incorrect days
//so I decided to make a different function for it
int returnDay(int month);
//will calculate the number of days since the first day A.D. and
//return the day of the week.  The first day of the week on the A.D.
//calendar is a Tuesday I did the math to confirm it
string calculator(int month, int day, int year);
    int numOfLeapYears(int year);//extra days from leap years affect day of week

int main()
{
    int month;
    do
    {
        cout << "Please select the number of one of the months:" << endl;
        cin >> month;
    }while((month < 1) && (month > 12));//force user to pick a real month

    int day = returnDay(month);

    //check for leap year and no selection of feb. 29 out of leap year
    char check;
    int year;
    do
    {
        cout << "\nPlease enter a year A.D.\n" << endl;
        cin >> year;
        if((year % 4 != 0) && (day == 29) && (month == 2))
        {
            //give options to change selections
            cout << "You have selected Feb. 29, but your selected year does not contain that date.\n";
            cout << "If you wish to change your entire selection, press n.\n";
            cout << "If you wish to change the month, press m.\n";
            cout << "If you wish to change the day, press d.\n";
            cout << "If you wish to change the year, press y.\n";
            cin >> check;
        }
        else
            check = 'a';//continue if all conditions are met

        if(check == 'n')// if user wishes to change everything
            main();
        else if(check == 'm')//if user wishes to change month
        {do
        {
            cout << "\nPlease select the number of one of the months:" << endl;
            cin >> month;
        }while((month < 1) && (month > 12));//force user to pick a real month
        }
        else if(check == 'd')
            int day = returnDay(month);
        else if(check == 'y')
            year = 0; //nothing needs to be done the "do" loop continues
        else if(check != 'a')
            cout << "\nThat is an invalid choice.\n";

        if(year < 0) //negative years will not be tolerated
        {
            cout << "\nYou have chosen an invalid year. Choose a different date.\n";
            main();
        }


    }while(check != 'a');//since 'y' is used for year, I used a different character to create the loop

    string answer = calculator(month, day, year);
    //tell the result
    cout << "The date that you have chosen,  " << month << "/" << day << "/" << year << "  is a " << answer << "." << endl;

    char again;
    cout << "Find a different date? type 'y' or 'n': ";
    cin >> again;

    if(again == 'y')
        main();
    else
        return 0;
}

int returnDay(int month)// will return a day of the month
{
    char check; //creates loop if an invalid date is chosen
    int day;
    do
    {
        cout << "\nPlease input a numerical day: ";
        cin >> day;

        //Any of these days are immpossible in respective months
        if((day < 0) || (day > 31))
        {
            cout << "\nThat is an invalid date.\n";
            check = 'n';
        }
        else if(((month == 4) || (month == 6) || (month == 9) || (month == 11)) && (day > 30))
        {
            cout << "\nThat is an invalid date.\n";
            check = 'n';
        }
        else if((month == 2) && (day > 29))
        {
            cout << "\nThat is an invalid date.\n";
            check = 'n';
        }
        else
            check = 'y'; //valid date
    }while(check != 'y');

    return day;
}

string calculator(int month, int day, int year)
{
    //this integer is the number of days between the selected date and the first day A.D.
    //it will change often as new variables, such as leap years and months, are added in.
    int numberOfDays = 0;
    //find number of days in past years
    numberOfDays = (year * 365); //365 days in a year
    //calculate for leap years
    numberOfDays += numOfLeapYears(year);
    /*add days for each month
    add only fully past months
    the 29th has already been added if
    the selected date is during a leap year*/
    if(month == 2) //feb
        numberOfDays += 31;//Days in Janurary
    else if(month == 3) //mar
        numberOfDays += 59;//Days in February and Janurary
    else if(month == 4) //apr
        numberOfDays += 90;//etc.
    else if(month == 5) //may
        numberOfDays += 120;
    else if(month == 6) //june
        numberOfDays += 151;
    else if(month == 7) //july
        numberOfDays += 181;
    else if(month == 8) //aug
        numberOfDays += 212;
    else if(month == 9) //sep
        numberOfDays += 243;
    else if(month == 10)//oct
        numberOfDays += 273;
    else if(month == 11)//nov
        numberOfDays += 304;
    else if(month == 12)//dec
        numberOfDays += 334;
    //Finally, add the number of days which have past in the month
    numberOfDays += day;
    /*Pope Gregory XIII subtracted ten days from
    the year 1582 in order to fix the problems caused
    by the Roman calendar, which was off by eleven
    minutes a year.  Afterwards, he adjusted the
    calendar so that the problem would not reoccur*/
    if(year >= 1582)
        numberOfDays -= 10;
    //this will find the number of days after Monday
    int date = (numberOfDays % 7);
    //return the day of the week
    if(date == 0)
        return "Monday";
    else if(date == 1)
        return "Tuesday";
    else if(date == 2)
        return "Wednesday";
    else if(date == 3)
        return "Thursday";
    else if(date == 4)
        return "Friday";
    else if(date == 5)
        return "Saturday";
    else if(date == 6)
        return "Sunday";
    else
        return "{An Error has occurred}"; //This will most likely not happen
}

int numOfLeapYears(int year)
{
    return (year / 4);
    /*this will always round down if
    there is a decimal, which is
    desireable*/
}