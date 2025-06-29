#include <iostream>
#include <cstring>
using namespace std;

class entity
{
protected:
    string category;      
    int time_of_departure; 
public:
    entity(string category, int time_of_departure);
    ~entity();
};
entity::entity(string category, int time_of_departure)
{
    this->category = category;
    this->time_of_departure = time_of_departure;
}
entity::~entity()
{
}
class flight : public entity
{
protected:
    string plane;
    string pilot_name;
public:
    void time_of_departure();
    void availability();
    flight(string plane, string pilot_name, string category, int time_of_departure);
    ~flight();
};
void flight::time_of_departure()
{
    cout << "Flight has departured\n";
}
void flight::availability()
{
    cout << "Seats are available in flight\n";
}
flight::flight(string plane, string pilot_name, string category, int time_of_departure) : entity(category, time_of_departure)
{
    this->plane = plane;
    this->pilot_name = pilot_name;
}
flight::~flight()
{
}
class passengers : public entity
{
protected:
    string name;
    int phone_number;
    int seat_num;

public:
    void cancel();
    void ticket_info();
    passengers(string name, int phone_number, int seat_num, string category, int time_of_departure);
    ~passengers();
};
void passengers::cancel()
{
    cout << "Passenger has canceled the ticket\n";
}
void passengers::ticket_info()
{
    cout << "   Name: " << name << "\n";
    cout << "   Class: " << category << "\n";
    cout << "   Seat: " << seat_num << "\n";
    cout << "   Departure Time: " << time_of_departure << "\n";
    cout << "   Contact: 03" << phone_number << "\n";
    cout << "   Pilot Name: "<< "Ali Abbas\n";
}
passengers::passengers(string name, int phone_number, int seat_num, string category, int time_of_departure) : entity(category, time_of_departure)
{
    this->name = name;
    this->phone_number = phone_number;
    this->seat_num = seat_num;
}
passengers::~passengers()
{
}
class ticket : public entity
{
protected:
    string method; 
    double price;
    int seat_num;

public:
    void cancel();
    void upgrade_cate(string cat);
    ticket(string method, double price, int seat_num, string category, int time_of_departure);
    ~ticket();
};
void ticket::cancel()
{
    cout << "Ticket has been cancelled\n";
}
void ticket::upgrade_cate(string cat)
{
    cout << "Ticket " << seat_num << " has been upgraded to " << cat << "\n";
    category = cat;
}
ticket::ticket(string method, double price, int seat_num, string category, int time_of_departure) : entity(category, time_of_departure)
{
    this->method = method;
    this->price = price;
    this->seat_num = seat_num;
}
ticket::~ticket()
{
}
int main()
{

    cout << " *********** Ticket Booking ***********\n";

    string name, category;
    int phone_number, seat_num, time_of_departure;
    double price = 15000;
    cout << "\n   Input Your full Name: ";
    getline(cin, name);
    cout << "   Input Phone Number: +92";
    cin >> phone_number;
    cout << "   Input Departure Time in 0000 hour format: ";
    cin >> time_of_departure;
    cout << "   Input seat number to Book: ";
    cin >> seat_num;
    cout << "   Input Class for Booking: ";
    cin.ignore();
    getline(cin, category);

    char confirm;
    cout << "Confirm Booking for Seat Number " << seat_num << "(y/n): ";
    cin >> confirm;
    if (confirm == 'y')
    {
        passengers p1(name, phone_number, seat_num, category, time_of_departure);
        ticket t1("Online", price, seat_num, category, time_of_departure);
        cout << "\n *********** Ticket Confirmed ***********\n";
        p1.ticket_info();
    }
    else
        cout << "Booking Cancel\n";

    return 0;
}