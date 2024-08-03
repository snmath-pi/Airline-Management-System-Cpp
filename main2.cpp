#include <iostream>
#include <mysql.h>
#include <mysqld_error.h>
#include <windows.h>
#include <sstream>
// a very basic airline management system creating using c++ and mysql
// the database contains a table 'Airline' having FlightNumber, Dep, Des, and seats available
// the user books a flight of his choice, if the seat is available
// the amount of seats automatically reduce in the database
// to do this sql has been used to create, store and alter the seats when a user books them
// the amount reduces in the database and table as well

using namespace std;

const char *HOST = "localhost";
const char *USER = "root";
const char *PW = "password123";
const char *DB = "temp";


// c++ oops has been utilised to full extent
class Flight
{
private:
    string Fnum, Dep, Des;
    int Seat;

public:
    Flight(string fnum, string dep, string des, int seat) : Fnum(fnum), Dep(dep), Des(des), Seat(seat) {}
    string getFnum()
    {
        return Fnum;
    }
    string getDep()
    {
        return Dep;
    }

    string getDes()
    {
        return Des;
    }

    int getSeat()
    {
        return Seat;
    }
};

int main()
{
    MYSQL *conn;
    conn = mysql_init(NULL);
    if (!mysql_real_connect(conn, HOST, USER, PW, DB, 3306, NULL, 0))
    {
        cout << "Error: " << mysql_error(conn) << endl;
    }
    else
    {
        cout << "Logged in Database..." << endl;
    }
    Sleep(3000);

    bool exit = false;
    while (!exit)
    {
        system("cls");
        cout << endl;

        cout << "Welcome To Airlines Reservation System" << endl;
        cout << "**************************************" << endl;
        cout << "1. Reserve A Seat in a Flight: " << endl;
        cout << "2. Exit: " << endl;
        cout << "Enter your choice: ";
        int val;
        cin >> val;

        if (val == 1)
        {
            string flight;
            cout << endl;
            cout << "Enter flight Number: ";
            cin >> flight;
            int total;
            string check = "SELECT Seat FROM Airline WHERE Fnumber= '" + flight + "'";
            if (mysql_query(conn, check.c_str()))
            {
                cout << "Error: " << mysql_error(conn) << endl;
            }
            else
            {
                MYSQL_RES *res;
                res = mysql_store_result(conn);

                if (res)
                {
                    MYSQL_ROW row = mysql_fetch_row(res);
                    if (row)
                    {
                        total = atoi(row[0]);
                    }
                }
            }
            if (total > 0)
            {
                total--;
                stringstream sst;
                sst << total;
                string SST = sst.str();
                string update = "UPDATE Airline SET Seat = '" + SST + "' WHERE Fnumber='" + flight + "'";
                if (mysql_query(conn, update.c_str()))
                {
                    cout << "Error: " << mysql_error(conn) << endl;
                }
                else
                {
                    cout << "Seat Reserved Successfully in: " << flight << endl;
                    cout << "The Seats left in " << flight << "are: " << total<< endl;
                }
                Sleep(3000);
            }
            else
            {
                cout << "Sorry No Seat Available!" << endl;
            }
        }
        else
        {
            exit = true;
        }
    }

    return 0;
}
