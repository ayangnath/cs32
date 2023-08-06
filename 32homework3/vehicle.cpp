////
////  main.cpp
////  32homework3
////
////  Created by Ayan Nath on 2/9/23.
////
//
//#include <iostream>
//#include <string>
//using namespace std;
//
////  Created by Ayan Nath on 2/9/23.
////
////Your declarations and implementations would go here
//class Vehicle
//{
//public:
//    Vehicle(string id): m_id(id)
//    {
//    }
//
//    virtual ~Vehicle()
//    {
//    }
//
//    string id() const
//    {
//        return m_id;
//    }
//
//    virtual bool canHover() const
//    {
//        return true;
//    }
//
//    virtual string description() const = 0;
//private:
//    string m_id;
//};
//
//class Drone: public Vehicle
//{
//public:
//    Drone(string id): Vehicle(id)
//    {}
//    virtual ~Drone()
//    {
//        cout << "Destroying " + id() + ", a drone" << endl;
//    }
//    virtual string description() const
//    {
//        return "a drone";
//    }
//};
//
//class Balloon: public Vehicle
//{
//public:
//    Balloon(string id, double diameter): Vehicle(id)
//    {
//        m_diameter = diameter;
//    }
//    virtual ~Balloon()
//    {
//        cout << "Destroying the balloon " + id() << endl;
//    }
//    virtual string description() const
//    {
//        if (m_diameter < 8.0)
//            return "a small balloon";
//        
//        else return "a large balloon";
//    }
//private:
//    double m_diameter;
//};
//
//class Satellite: public Vehicle
//{
//public:
//    Satellite(string id): Vehicle(id)
//    {}
//    virtual ~Satellite()
//    {
//        cout << "Destroying the satellite " + id() << endl;
//    }
//    virtual bool canHover() const
//    {
//        return false;
//    }
//    virtual string description() const
//    {
//        return "a satellite";
//    }
//};
//
//
//void display(const Vehicle* v)
//{
//    cout << v->id() << " is " << v->description();
//    if (v->canHover())
//        cout << ", so it can hover";
//    cout << endl;
//}
//
//int main()
//{
//    Vehicle* fleet[4];
//    fleet[0] = new Drone("CB4UP");
//      // Balloons have an id and a diameter in meters  Balloons with a
//      // diameter under 8 meters are small balloons; those with a diameter
//      // 8 meters or more are large balloons
//    fleet[1] = new Balloon("99LB", 6.3);
//    fleet[2] = new Balloon("CN20230201", 30.2);
//    fleet[3] = new Satellite("EB8675309");
//
//    for (int k = 0; k < 4; k++)
//        display(fleet[k]);
//
//      // Clean up the vehicles before exiting
//    cout << "Cleaning up" << endl;
//    for (int k = 0; k < 4; k++)
//        delete fleet[k];
//}
