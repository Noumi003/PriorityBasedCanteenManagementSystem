#include <iostream>
using namespace std;

// Priority levels for customers
const int CS = 6;
const int BBA = 5;
const int MASS_COM = 4;

const int ADMIN = 3;
const int MANAGER = 2;
const int TECHNICIAN = 1;
const int STUDENT = 0;

// Node structure representing each customer in the queue
struct Node
{
    string customer;
    int priority;
    Node *next;

    // Constructor for initializing a node with customer name and priority
    Node(string s, int p)
    {
        priority = p;
        customer = s;
        next = NULL;
    }
};

// Queue structure for handling priority queues for customers
struct Queue
{
    Node *front;
    Node *rear;

    // Constructor for initializing an empty queue
    Queue()
    {
        front = NULL;
        rear = NULL;
    }

    // Check if the queue is empty
    bool isEmpty()
    {
        return (front == NULL && rear == NULL);
    }

    // Add a new customer to the queue based on priority
    void enqueue(string s, int priority)
    {
        Node *newNode = new Node(s, priority);
        if (isEmpty() || priority > front->priority)
        {
            newNode->next = front;
            front = newNode;
        }
        else
        {
            Node *temp = front;
            while (temp->next != NULL && temp->next->priority >= priority)
            {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    // Remove and return the customer with the highest priority
    string dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty" << endl;
            return "";
        }
        Node *temp = front;
        string customer = front->customer;
        front = front->next;
        delete temp;
        return customer;
    }
};

// Time structure to manage canteen operating hours and time increments
struct Time
{
    int hour;
    int minute;

    // Constructor for initializing the start time
    Time()
    {
        hour = 8;
        minute = 0;
    }

    // Increment time by 15 minutes
    void incrementTime()
    {
        minute += 15;
        if (minute >= 60)
        {
            hour++;
            minute -= 60;
        }
    }

    // Check if the canteen is open (8:00 AM to 4:00 PM)
    bool isOpen()
    {
        return (hour >= 8 && hour < 16);
    }

    // Display the current time in HH:MM format
    void displayTime()
    {
        cout << "Time: ";
        if (hour < 10)
            cout << "0";
        cout << hour << ":";
        if (minute < 10)
            cout << "0";
        cout << minute << endl;
    }
};

// Counter structure to handle customers from different queues (faculty, staff, students)
struct Counter
{
    Queue facultyQueue;
    Queue staffQueue;
    Queue studentQueue;
    Time currentTime;

    // Enqueue customers based on their priority group (faculty, staff, or student)
    void enqueueCustomer(string name, int priority)
    {
        if (priority >= CS || priority >= BBA || priority >= MASS_COM)
        {
            facultyQueue.enqueue(name, priority);
        }
        else if (priority >= ADMIN || priority >= MANAGER || priority >= TECHNICIAN)
        {
            staffQueue.enqueue(name, priority);
        }
        else if (priority == STUDENT)
        {
            studentQueue.enqueue(name, priority);
        }
        else
        {
            cout << "Invalid priority." << endl;  // Handle invalid priority
        }
    }

    // Serve customers based on queue priority
    void serveCustomers()
    {
        if (!currentTime.isOpen())
        {
            cout << "Canteen is closed." << endl;
            return;
        }

        bool served = false;

        // Serve customers from faculty queue first, then staff, then students
        while (!served && (!facultyQueue.isEmpty() || !staffQueue.isEmpty() || !studentQueue.isEmpty()))
        {
            if (!facultyQueue.isEmpty())
            {
                string faculty = facultyQueue.dequeue();
                cout << "Serving faculty: " << faculty << endl;
                served = true;
            }

            if (!staffQueue.isEmpty())
            {
                string staff = staffQueue.dequeue();
                cout << "Serving staff: " << staff << endl;
                served = true;
            }

            if (!studentQueue.isEmpty())
            {
                string student = studentQueue.dequeue();
                cout << "Serving student: " << student << endl;
                served = true;
            }
        }

        currentTime.incrementTime();
        currentTime.displayTime();

        if (facultyQueue.isEmpty() && staffQueue.isEmpty() && studentQueue.isEmpty())
        {
            cout << "No customers left." << endl;
        }
    }
};

// Main function to simulate the canteen queue system
int main()
{
    Counter c;

    c.currentTime.displayTime();

    if (c.currentTime.isOpen())
    {
        cout << "Canteen is open." << endl;
    }

    // Enqueueing faculty, staff, and students
    c.enqueueCustomer("Sir Abdur Rehman", CS);
    c.enqueueCustomer("Sir Umair", BBA);
    c.enqueueCustomer("Sir Nadeem", BBA);
    c.enqueueCustomer("Sir Faheem", MASS_COM);
    c.enqueueCustomer("Sir Anas", CS);

    c.enqueueCustomer("Ahmed", TECHNICIAN);
    c.enqueueCustomer("Ali", ADMIN);
    c.enqueueCustomer("Hassan", MANAGER);
    c.enqueueCustomer("Gul", ADMIN);
    c.enqueueCustomer("Huzaifa", TECHNICIAN);

    c.enqueueCustomer("Nouman", STUDENT);
    c.enqueueCustomer("Rafay", STUDENT);
    c.enqueueCustomer("Abdullah", STUDENT);
    c.enqueueCustomer("Zayn", STUDENT);
    c.enqueueCustomer("Hamza", STUDENT);

    // Serve all customers in the queue
    while (!c.facultyQueue.isEmpty() || !c.staffQueue.isEmpty() || !c.studentQueue.isEmpty())
    {
        c.serveCustomers();
    }

    return 0;
}
