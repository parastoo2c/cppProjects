#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;
int count = 0;

// creating an array to look for requested information in the database

struct userAccount
{
    string username;
    string nationality;
    int age = 0;
    float accountBalance = 0;
};

void prompt(struct userAccount array[])
{
    cout << "Please enter information to database in the format of <username> <nationality> <age> <accountBalance>, separated each user by a newline\n";
    for (int i = 0; i < 10; i++)
    {
        cin >> array[i].username;
        cin >> array[i].nationality;
        cin >> array[i].age;
        cin >> array[i].accountBalance;
        count++;
    }
}

void highestBalance(struct userAccount array[])
{
    float largest = 0.00;
    for(int i = 0; i <= count; i++)
    {
        if(array[i].accountBalance > largest)
        {
            largest = array[i].accountBalance;
        }
    }
    cout << "Q: What is the highest account balance among all users?\n";
    cout << fixed << setprecision(2);
    cout << "A: $" << largest << "\n\n";
}

void sum(struct userAccount array[])
{
    float sum = 0;
    for(int i = 0; i <= count; i++)
    {
        sum += array[i].accountBalance;
    }
    cout << "Q: What is the sum of account balance of all users?\n";
    cout << fixed << setprecision(1);
    cout << "A: $" << sum << "\n\n";
}

void nationality (struct userAccount array[])
{
    string a = "Japan";
    int japanCount = 0;
    cout << "How many users come from Japan?\n";
    for(int i = 0; i <= count; i++)
    {
        int res = a.compare(array[i].nationality);
        if(res == 0)
        {
            japanCount += 1;
        }
    }
    cout << "A: " << japanCount << "\n\n";
}

void underaged (struct userAccount array[])
{
    int placeholder = 0;
    for(int i = 0; i <= count; i++)
    {
        if(array[i].age < 18)
        {
            placeholder = 1;
            break;
        }
    }

    cout << "Do we have any user younger than 18?\n";
    if(placeholder = 0)
    {
        cout << "A: No\n\n";
    }else
    {
        cout << "A: Yes\n\n";
    }
}

int main()
{
    struct userAccount array[10];
    prompt(array);
    highestBalance(array);
    sum(array);
    nationality(array);
    underaged(array);
}
